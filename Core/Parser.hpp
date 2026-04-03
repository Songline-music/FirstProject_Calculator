#pragma once

#define _USE_MATH_DEFINES
#include "Input/Tokenizer.hpp"
#include "Helper/ConstValue.hpp"
#include "Log/Exception.hpp"
#include <stack>

// 解析器,用来解析词条,处理为后缀算式,或者解析为指令
class Parser
{
private:
	// 结果结构体
	struct ParseResult
	{
		bool is_cmd = false;                    // 是否为指令
		std::vector<Tokenizer::Token> command;  // 指令词条
		std::vector<Tokenizer::Token> equation; // 表达式(后缀式)
	};

	// 获取运算符优先级
	int get_grade(const Tokenizer::Token& token)
	{
		if (token.op_info.id == ConstValue::OperatorID::LEFT_PAREN || token.op_info.id == ConstValue::OperatorID::RIGHT_PAREN || token.op_info.id == ConstValue::OperatorID::COMMA) return 0;
		if (token.op_info.id == ConstValue::OperatorID::OR) return 1;
		if (token.op_info.id == ConstValue::OperatorID::XOR) return 2;
		if (token.op_info.id == ConstValue::OperatorID::AND) return 3;
		if (token.op_info.id == ConstValue::OperatorID::ADD || token.op_info.id == ConstValue::OperatorID::SUB) return 4;
		if (token.op_info.id == ConstValue::OperatorID::MUL || token.op_info.id == ConstValue::OperatorID::DIV || token.op_info.id == ConstValue::OperatorID::MOD) return 5;
		if (token.op_info.id == ConstValue::OperatorID::POWER) return 6;
		if (token.op_info.id == ConstValue::OperatorID::FACTORIAL) return 7;
		if (token.op_info.id == ConstValue::OperatorID::UNARY_MINUS) return 8;
		if (token.type == Tokenizer::TokenType::FUNCTION) return 9;

		throw(Exception::Error("未知符号输入"));
		return -1;
	}

public:
	// 解析输入或拆分
	ParseResult parse(std::vector<Tokenizer::Token>& tokens)
	{
		// 最终返回结果
		ParseResult res;

		// 若输入为空
		if(tokens.empty())
		{
			throw(Exception::Error("输入不能为空"));
		}

		// 若输入存在未知类型
		for (const auto& it : tokens)
		{
			if (it.type == Tokenizer::TokenType::UNKNOWN)
			{
				throw(Exception::Error("未知符号输入"));
			}
		}

		if(tokens[0].type == Tokenizer::TokenType::COMMAND) // 若输入为指令
		{
			res.is_cmd = true;

			// 检查指令输入后紧跟是否为合法内容(单一数字)
			if(tokens.size() > 3 || (tokens.size() == 3 && tokens[1].type != Tokenizer::TokenType::NUMBER))
			{
				throw(Exception::Error("指令输入格式错误"));
			}

			res.command.assign(tokens.begin(), tokens.end());

			return res;
		}

		// 若输入为表达式
		std::stack<Tokenizer::Token> temp_symbol;    // 符号栈
		std::vector<Tokenizer::Token> temp_equation; // 当前表达式
		std::stack<int> func_arg_count;              // 函数参数计数栈（平行于函数入栈）
		std::stack<bool> func_arg_seen;              // 标记当前函数参数是否已有实际参数

		for(auto& it : tokens)
		{
			if (it.type == Tokenizer::TokenType::EOf) // 跳过结尾标记
			{
				break;
			}
			else if(it.type == Tokenizer::TokenType::FUNCTION) // 若为函数
			{
				// 函数入栈，并为其初始化参数计数
				temp_symbol.push(it);
				func_arg_count.push(0);
				func_arg_seen.push(false);
			}
			else if (it.type == Tokenizer::TokenType::NUMBER) // 若为数字
			{
				temp_equation.push_back(it);

				// 标记当前函数已看到参数
				if (!func_arg_seen.empty())
				{
					func_arg_seen.top() = true;
				}
			}
			else if (it.type == Tokenizer::TokenType::OPERATOR) // 若为运算符
			{
				// 若为括号或者逗号
				if (it.op_info.id == ConstValue::OperatorID::LEFT_PAREN || it.op_info.id == ConstValue::OperatorID::RIGHT_PAREN || it.op_info.id == ConstValue::OperatorID::COMMA)
				{
					if (it.op_info.id == ConstValue::OperatorID::LEFT_PAREN) // 若为左开括号
					{
						temp_symbol.push(it);
					}
					else if (it.op_info.id == ConstValue::OperatorID::RIGHT_PAREN) // 若为右开括号
					{
						// 弹出直到遇见 '('
						while (!temp_symbol.empty() && temp_symbol.top().op_info.id != ConstValue::OperatorID::LEFT_PAREN)
						{
							// 运算符栈顶符号推入最终表达式
							temp_equation.push_back(temp_symbol.top());
							temp_symbol.pop(); // 运算符栈顶符号弹出
						}

						// 若符号异常未遇见 '('
						if (temp_symbol.empty())
						{
							throw(Exception::Error("未找到对应'('"));
						}

						// 弹出 '('
						temp_symbol.pop();

						// 若为函数括号,栈顶的函数名到后缀表达式
						if (!temp_symbol.empty() && temp_symbol.top().type == Tokenizer::TokenType::FUNCTION)
						{
							// 计算并填充该函数的实际参数个数
							Tokenizer::Token f = temp_symbol.top();
							temp_symbol.pop();

							int arity = 0;
							if (!func_arg_count.empty())
							{
								if (func_arg_seen.top()) // 如果当前参数已见到实际表达式，则参数个数为逗号数+1
								{
									arity = func_arg_count.top() + 1;
									func_arg_count.pop();
									func_arg_seen.pop();
								}
								else // 如果当前参数未见到实际表达式，则参数个数为逗号数，但如果逗号数不为0则视为参数为空错误
								{
									if (func_arg_count.top() == 0) // 没有逗号，参数个数为0
									{
										arity = 0;
										func_arg_count.pop();
										func_arg_seen.pop();
									}
									else // 有逗号但没有实际参数，视为参数为空错误
									{
										func_arg_count.pop();
										func_arg_seen.pop();
										throw(Exception::Error("函数参数为空"));
									}
								}
							}

							f.func_info.arity = arity;
							temp_equation.push_back(f);

							// 标记上层函数已见到一个参数
							if (!func_arg_seen.empty())
							{
								func_arg_seen.top() = true;
							}
						}
					}
					else // 若为','
					{
						// 一直弹出符号直到遇见'('
						while (!temp_symbol.empty() && temp_symbol.top().op_info.id != ConstValue::OperatorID::LEFT_PAREN)
						{
							temp_equation.push_back(temp_symbol.top());
							temp_symbol.pop();
						}

						// 若没有识别到'('
						if (temp_symbol.empty())
						{
							throw(Exception::Error("未找到对应'('"));
						}

						// 逗号必须位于函数参数列表中
						if (func_arg_count.empty() || func_arg_seen.empty())
						{
							throw(Exception::Error("逗号不在函数参数列表中"));
						}

						// 当前参数应已有实际表达式
						if (!func_arg_seen.top())
						{
							throw(Exception::Error("函数参数为空"));
						}

						// 增加参数计数并重置 seen 标志以接收下一个参数
						func_arg_count.top()++;
						func_arg_seen.top() = false;
					}

					continue;
				}

				// 一元且左绑定的操作符(直接入栈)
				if (it.op_info.is_unary && !it.op_info.is_right_combinative)
				{
					temp_equation.push_back(it);
					continue;
				}

				// 二元运算符或右绑定一元运算符-优先级排队对比
				while (!temp_symbol.empty())
				{
					int current_grade = get_grade(it);            // 当前符号优先级
					int top_grade = get_grade(temp_symbol.top()); // 栈顶符号优先级

					// 判断出栈条件
					bool should_pop = false;
					if (!it.op_info.is_right_combinative) // 若为左绑定二元运算符(+ - * /)
					{
						should_pop = (current_grade <= top_grade);
					}
					else // 若为右操作数绑定 (^,u-)
					{
						should_pop = (current_grade < top_grade);
					}

					if (should_pop) // 运算符栈顶符号推入最终表达式
					{
						temp_equation.push_back(temp_symbol.top());
						temp_symbol.pop();
					}
					else // 条件不满足，停止出栈
					{
						break; 
					}
				}

				temp_symbol.push(it); // 当前符号推入栈
			}
			else // 异常输入
			{
				throw(Exception::Error("未知符号输入"));
			}
		}

		// 如果运算符栈为非空将其推入
		while (!temp_symbol.empty())
		{
			if (temp_symbol.top().op_info.id == ConstValue::OperatorID::LEFT_PAREN || temp_symbol.top().op_info.id == ConstValue::OperatorID::RIGHT_PAREN)
			{
				throw(Exception::Error("未找到'('"));
			}
			// 运算符栈顶符号推入表达式
			temp_equation.push_back(temp_symbol.top());
			temp_symbol.pop(); // 运算符栈顶符号弹出
		}

		// 将处理结果赋值给返回结果
		res.equation = temp_equation;
		return res;
	}
};