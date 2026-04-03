#pragma once

#define _USE_MATH_DEFINES
#include <vector>
#include <string>
#include <cctype>
#include "Helper/Tool.hpp"
#include "Helper/Judge.hpp"
#include "Helper/ConstValue.hpp"

// 用于将用户输入转换为token便于后续处理
class Tokenizer
{
public:
	// 存放词条基本类型
	enum class TokenType
	{
		NUMBER,      // 数字
		OPERATOR,    // 运算符
		FUNCTION,    // 函数
		COMMAND,     // 指令
		EOf,         // 输入结束
		UNKNOWN      // 未知类型
	};

	// 词条结构体
	struct Token
	{
		TokenType type;   // 词条基本类型
		std::string text; // 词条原始文本

		ConstValue::OperatorInfo op_info = {ConstValue::OperatorID::NONE,false,false};  // 运算符信息(当type为OPERATOR时有效)
		ConstValue::FunctionInfo func_info = {ConstValue::FunctionID::NONE , 0, false}; // 函数信息(当type为FUNCTION时有效)
		ConstValue::CommandInfo cmd_info = {ConstValue::CommandID::NONE};               // 指令信息(当type为COMMAND时有效)
		ConstValue::NumberInfo num_info = {0.0};                                        // 数字信息(当type为NUMBER时有效)

		Token() = default;                                             // 默认构造函数
		Token(TokenType t, const std::string& s) : type(t), text(s) {} // 构造函数

		// 若为数字类型，创建一个数字token
		static Token Number(double val, const std::string& s, bool is_deg)
		{
			Token token(TokenType::NUMBER, s);
			token.num_info.value = val;
			token.num_info.is_deg = is_deg;
			return token;
		} 

		// 若为指令类型，创建一个指令token
		static Token Command(ConstValue::CommandID cmd_id, const std::string& s)
		{
			Token token(TokenType::COMMAND, s);
			token.cmd_info.id = cmd_id;
			return token;
		}

		// 若为函数类型，创建一个函数token
		static Token Function(ConstValue::FunctionID func_id, const std::string&s , int arity, bool is_multi)
		{
			Token token(TokenType::FUNCTION, s);
			token.func_info.id = func_id;
			token.func_info.arity = arity;
			token.func_info.is_multi = is_multi;
			return token;
		}

		// 若为运算符类型，创建一个运算符token
		static Token Operator(ConstValue::OperatorID op_id, const std::string& s , bool is_unary, bool is_right_combinative)
		{
			Token token(TokenType::OPERATOR, s);
			token.op_info.id = op_id;
			token.op_info.is_unary = is_unary;
			token.op_info.is_right_combinative = is_right_combinative;
			return token;
		}
	};

	// 用于将输入的字符串分割为token
	std::vector<Token> tokenize(const std::string& s)
	{
		std::vector<Token> tokens;

		// ======================================================预处理===================================================
		// 空格预处理(去除所有空格部分)
		std::string s_;
		for(char c : s)
		{
			if(std::isspace(static_cast<unsigned char>(c)))
			{
				continue;
			}
			s_.push_back(c);
		}

		// 输入提前处理：将π替换为pi
		std::string input = s_; // 输入的字符串
		size_t p;
		while ((p = input.find(ConstValue::PI_SHOW_SYMBOL)) != std::string::npos)
		{
			input.replace(p, ConstValue::PI_SHOW_SYMBOL.size(), ConstValue::PI_SYMBOL); // 将π替换为pi
		}

		// 小写化输入字符
		std::string input_lower = input;
		for (auto& ch : input_lower)
		{
			ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
		}

		// 输入字符的基本数据
		size_t n = input_lower.size(); // 总大小
		size_t i = 0;                  // 全局索引

		// ======================================================隐函数====================================================
		// 隐函数，用于创建token
		auto make_token = [&](TokenType type, const std::string& text) -> Token
			{
				return Token(type, text);
			};

		// 隐式乘号添加函数
		auto push_implicit_mul_if_needed = [&]()
			{
				if (tokens.empty())
				{
					return;
				}

				// 若该token前token为 数字 | ')' | 函数，则添加*
				Token prev = tokens.back();
				bool prev_allows = (prev.type == TokenType::NUMBER || prev.op_info.id == ConstValue::OperatorID::RIGHT_PAREN || prev.type == TokenType::FUNCTION);
				if (prev_allows)
				{
					tokens.push_back(Token::Operator(ConstValue::OperatorID::MUL, "*", false, false));
				}
			};

		// ======================================================解析======================================================
		// 指令处理
		for (const auto &pair : ConstValue::get_command_map())
		{
			std::string cmd = pair.first;

			// 与用户输入匹配
			size_t in_idx = 0;
			size_t cmd_idx = 0;
			while (cmd_idx < cmd.size() && in_idx < input_lower.size())
			{
				if (in_idx >= input_lower.size()) // 若输入字符小于指令长度
				{
					break;
				}
				if (input_lower[in_idx] != cmd[cmd_idx]) // 若输入字符与指令不匹配
				{
					break;
				}

				// 更新索引
				in_idx++; 
				cmd_idx++;
			}

			if (cmd_idx == cmd.size()) // 若成功匹配指令
			{
				// 推入command
				tokens.push_back(Token::Command(pair.second.id, cmd));

				// 更新索引
				i = in_idx;
				break;
			}
		}

		// 算式处理
		while(i < n)
		{
			// 数字处理
			char ch = input_lower[i];
			if(std::isdigit(static_cast<unsigned char>(ch)) || ch == '.')
			{
				size_t j = i;         // 局部索引
				bool has_dot = false; // 数字是否存在小数点

				// 若首字符为小数点
				if(input_lower[j] == '.')
				{
					has_dot = true;
					j++;
				}

				// 截取前端数字部分
				while(j < n && std::isdigit(static_cast<unsigned char>(input_lower[j])))
				{
					j++;
				}

				// 若截取停止时为小数点，且之前从未出现
				if(!has_dot &&  j < n && input_lower[j] == '.')
				{
					has_dot = true;
					j++;

					// 截取后端数字部分
					size_t frac_start = j;
					while (j < n && std::isdigit(static_cast<unsigned char>(input_lower[j])))
					{
						j++;
					}
				}

				// 若结尾符为科学计算符
				if(j < n && (input_lower[j] == 'e'))
				{
					size_t expIdx = j;
					j++;

					if(j < n && (input_lower[j] == '+' || input_lower[j] == '-'))
					{
						j++;
					}

					if(j < n && std::isdigit(static_cast<unsigned char>(input_lower[j]))) // 若科学计数部分存在数字
					{
						while(j < n && std::isdigit(static_cast<unsigned char>(input_lower[j])))
						{
							j++;
						}
					}
					else // 回退到'e'位置
					{
						j = expIdx; 
					}
				}

				// 如果在数字结束后紧跟另一个小数点,则视为非法数字
				if (j < n && input_lower[j] == '.')
				{
					// 扫描到第一个非数字非小数点位置，整段视为错误
					size_t k = j + 1;
					while (k < n && (input_lower[k] == '.' || std::isdigit(static_cast<unsigned char>(input_lower[k]))))
					{
						k++;
					}

					std::string bad = input_lower.substr(i, k - i);
					tokens.push_back(make_token(TokenType::UNKNOWN, bad));

					i = k;
					continue;
				}

				// 截取获得数字字符串
				std::string num_str = input_lower.substr(i,j - i);
				double val = 0.0;

				try // 正常转换为数字
				{
					val = std::stod(num_str);
				}
				catch (...) // 异常未知转换
				{
					tokens.push_back(make_token(TokenType::UNKNOWN,num_str));
					i = j;
					continue;
				}

				// 检查是否有deg后缀
				bool is_deg = false;
				std::string deg_sym = ConstValue::DEG_SYMBOL;
				if(j + deg_sym.size() <= n && input_lower.substr(j , deg_sym.size()) == deg_sym)
				{
					is_deg = true;
					j += deg_sym.size();
				}

				// 重新定向字符串
				std::string final_num = input_lower.substr(i, j - i);

				// 正常数字token填入
				push_implicit_mul_if_needed();
				tokens.push_back(Token::Number(val, final_num, is_deg));
				
				i = j;
				continue;
			}

			// 函数及常量字符处理
			if (std::isalpha(static_cast<unsigned char>(ch)))
			{
				size_t j = i;
				while (j < n && (std::isalnum(static_cast<unsigned char>(input_lower[j])) || input_lower[j] == '_'))
				{
					j++;
				}

				// 获取指定字符串
				std::string id = input_lower.substr(i, j - i);

				// 处理deg输入
				bool is_deg = false;
				std::string deg_sym = ConstValue::DEG_SYMBOL;
				if(id.size() > deg_sym.size() && id.substr(id.size() - deg_sym.size()) == deg_sym)
				{
					is_deg = true;
					id = id.substr(0, id.size() - deg_sym.size()); // 提取deg前部分字符串
				}

				// 如字符为常量时
				push_implicit_mul_if_needed(); // 添加隐式乘号
				if (id == ConstValue::PI_SYMBOL) // pi输入
				{
					tokens.push_back(Token::Number(ConstValue::PI_VAL, id, is_deg)); // 将pi输入
				}
				else if (id == ConstValue::EULER_SYMBOL) // euler输入
				{
					tokens.push_back(Token::Number(ConstValue::EULER_VAL, id, is_deg)); // 将euler输入
				}
				else // 函数输入
				{ 
					// 判断函数是否存在
					auto info = Tool::get_function_info(id);

					if (info.id != ConstValue::FunctionID::NONE) // 为已知函数
					{
						tokens.push_back(Token::Function(info.id, id, info.arity, info.is_multi));
					}
					else // 为未知函数
					{
						tokens.push_back(make_token(TokenType::UNKNOWN, id));
					}
				}

				i = j;
				continue;
			}

            // 运算符处理
			if(Judge::is_operator(ch))
            {
                // 判断是否为一元负号
                bool is_unary_minus = (ch == '-')
                    && (tokens.empty() || (tokens.back().type == TokenType::OPERATOR && tokens.back().op_info.id != ConstValue::OperatorID::RIGHT_PAREN));

				// 将运算符推入tokens(右结合符号表示->符号右侧绑定数字)
                if (is_unary_minus) // 若为一元负号
                {
					tokens.push_back(Token::Operator(ConstValue::get_operator_map().at("u-").id, "u-", ConstValue::get_operator_map().at("u-").is_unary, ConstValue::get_operator_map().at("u-").is_right_combinative));
                }
                else // 其他符号
                {
					std::string ch_str = std::string(1, ch);
					tokens.push_back(Token::Operator(ConstValue::get_operator_map().at(ch_str).id, ch_str, ConstValue::get_operator_map().at(ch_str).is_unary, ConstValue::get_operator_map().at(ch_str).is_right_combinative));
                }

                i++;
                continue;
            }

			// 未知输入处理
			tokens.push_back(make_token(TokenType::UNKNOWN, std::string(1,ch)));
			i++;
		}

		// 结尾token填入
		tokens.push_back(make_token(TokenType::EOf, ""));

		// 返回结果
		return tokens;
	}
};