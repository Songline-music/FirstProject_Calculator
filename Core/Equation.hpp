#pragma once

#define _USE_MATH_DEFINES
#include "Helper/Tool.hpp"
#include "Helper/ConstValue.hpp"
#include "Core/Parser.hpp"
#include "Log/Exception.hpp"
#include <stack>

// 处理法则式的拆分以及计算
class Equation 
{
public:
	// 计算单一运算式
	double cal(const std::vector<Tokenizer::Token> &tokens)
	{
		// 重置状态
		final_equation.clear();

		// 获取计算结果
		double res = cal_equation(tokens);

		// 计算成功，记忆更新结果
		last_res = res;
		return res;
	}

	// 设置小数位数
	void set_decimal(int cur_digit) 
	{
		if (cur_digit >= 0 && cur_digit <= ConstValue::max_decimal) // 正常执行
		{
			cur_decimal = cur_digit;
		}
		else // 超出限制
		{
			throw(Exception::Error("小数设置输入超出指定范围"));
		}
	}

	// 归零
	void clear() 
	{
		final_equation.clear();
		last_res = 0;
	}

	// 设置deg/rad输入模式
	void set_deg_mode(bool state)
	{
		is_deg_mode = state;
	}

	// 对外接口
	int get_cur_decimal() const { return cur_decimal; }
	double get_last_result() const { return last_res; }
	bool get_deg_mode() const { return is_deg_mode; }

private:
	// 类内属性
	Parser parser;                                 // 解析引擎
	Tokenizer tokenizer;                           // 拆分引擎
	std::vector<Tokenizer::Token> final_equation;  // 存储后缀表达式
	double last_res = 0;                           // 上一次计算的结果
	int cur_decimal = ConstValue::default_decimal; // 当前输出小数位数
	bool is_deg_mode = false;                      // 全局角度输入标志

	// 计算后缀式
	double cal_equation(std::vector<Tokenizer::Token> tokens)
	{
		std::stack<Tokenizer::Token> num_stack;

		// 遍历后缀式
		for (Tokenizer::Token it : tokens)
		{
			if (it.type == Tokenizer::TokenType::NUMBER) // 为数字
			{
				// 若为deg输入
				if (it.num_info.is_deg)
				{
					it.num_info.value = Tool::deg_to_rad(it.num_info.value); // 将角度转换为弧度
				}
				num_stack.push(it);
			}
			else if (it.type == Tokenizer::TokenType::FUNCTION) // 为函数
			{
				if (it.func_info.is_multi) // 为多级函数
				{
					// 当数字栈为空
					if (num_stack.empty())
					{
						throw(Exception::Error("数字输入为空"));
					}

					// 获取函数参数
					std::stack<double> params;
					for (int i = 0; i < it.func_info.arity; i++)
					{
						if (num_stack.empty())
						{
							throw(Exception::Error("多级函数参数不足"));
						}
						params.push(num_stack.top().num_info.value);
						num_stack.pop();
					}

					// 计算
					double cur_res = 0.0;
					if (it.func_info.id == ConstValue::FunctionID::MAX)
					{
						while (params.size() >= 2)
						{
							double param1 = params.top();
							params.pop();

							double param2 = params.top();
							params.pop();

							params.push(std::max(param1, param2));
						}
					}
					else if (it.func_info.id == ConstValue::FunctionID::MIN)
					{
						while (params.size() >= 2)
						{
							double param1 = params.top();
							params.pop();

							double param2 = params.top();
							params.pop();

							params.push(std::min(param1, param2));
						}
					}
					else // 未知函数
					{
						throw(Exception::Error("未知多级函数"));
					}

					cur_res = params.top();
					num_stack.push(Tokenizer::Token::Number(cur_res, "", false));
				}
				else if (it.func_info.arity == 1) // 为一级函数
				{
					// 当数字栈为空
					if (num_stack.empty())
					{
						throw(Exception::Error("一级函数参数不足"));
					}

					double param = num_stack.top().num_info.value;     // 获取函数参数
					bool is_deg_num = num_stack.top().num_info.is_deg; // 获取参数是否为deg数字
					num_stack.pop();

					// 计算
					double cur_res = 0.0;
					if (it.func_info.id == ConstValue::FunctionID::SIN)
					{
						double p;
						if(!is_deg_num) // 不是deg数
						{
							p = is_deg_mode ? Tool::deg_to_rad(param) : param; // 若为deg输入则转换为弧度
						}
						else // 已是deg数,无需转换
						{
							p = param;
						}
						
						cur_res = sin(p);
					}
					else if (it.func_info.id == ConstValue::FunctionID::COS)
					{
						double p;
						if (!is_deg_num) // 不是deg数
						{
							p = is_deg_mode ? Tool::deg_to_rad(param) : param; // 若为deg输入则转换为弧度
						}
						else // 已是deg数,无需转换
						{
							p = param;
						}

						cur_res = sin(p);
					}
					else if (it.func_info.id == ConstValue::FunctionID::TAN)
					{
						double p;
						if (!is_deg_num) // 不是deg数
						{
							p = is_deg_mode ? Tool::deg_to_rad(param) : param; // 若为deg输入则转换为弧度
						}
						else // 已是deg数,无需转换
						{
							p = param;
						}

						if (fabs(fmod(p, ConstValue::PI_VAL) - ConstValue::PI_VAL / 2) < 1e-9) // Pi/2非法
						{
							throw(Exception::Error("tan参数非法"));
						}
						cur_res = tan(p);
					}
					else if (it.func_info.id == ConstValue::FunctionID::SEC)
					{
						double p;
						if (!is_deg_num) // 不是deg数
						{
							p = is_deg_mode ? Tool::deg_to_rad(param) : param; // 若为deg输入则转换为弧度
						}
						else // 已是deg数,无需转换
						{
							p = param;
						}

						if (fabs(fmod(p, ConstValue::PI_VAL) - ConstValue::PI_VAL / 2) < 1e-9) // Pi/2非法
						{
							throw(Exception::Error("sec参数非法"));
						}
						cur_res = 1.0 / cos(p);
					}
					else if (it.func_info.id == ConstValue::FunctionID::CSC)
					{
						double p;
						if (!is_deg_num) // 不是deg数
						{
							p = is_deg_mode ? Tool::deg_to_rad(param) : param; // 若为deg输入则转换为弧度
						}
						else // 已是deg数,无需转换
						{
							p = param;
						}

						if (fabs(fmod(p, ConstValue::PI_VAL) - ConstValue::PI_VAL / 2) < 1e-9 || fabs(fmod(p, ConstValue::PI_VAL)) < 1e-9) // Pi/2和0非法
						{
							throw(Exception::Error("csc参数非法"));
						}
						cur_res = 1.0 / sin(p);
					}
					else if (it.func_info.id == ConstValue::FunctionID::COT)
					{
						double p;
						if (!is_deg_num) // 不是deg数
						{
							p = is_deg_mode ? Tool::deg_to_rad(param) : param; // 若为deg输入则转换为弧度
						}
						else // 已是deg数,无需转换
						{
							p = param;
						}

						if (fabs(fmod(p, ConstValue::PI_VAL)) < 1e-9) // 0非法
						{
							throw(Exception::Error("cot参数非法"));
						}
						cur_res = 1.0 / tan(p);
					}
					else if (it.func_info.id == ConstValue::FunctionID::ASIN)
					{
						if (param < -1.0 || param > 1.0) // 参数超过范围
						{
							throw(Exception::Error("asin参数须在[-1,1]"));
						}

						cur_res = asin(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::ACOS)
					{
						if (param < -1.0 || param > 1.0) // 参数超过范围
						{
							throw(Exception::Error("acos参数须在[-1,1]"));
						}

						cur_res = acos(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::ATAN)
					{
						cur_res = atan(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::SQRT)
					{
						if (param <= 0.0) // 参数超过范围
						{
							throw(Exception::Error("sqrt参数不得<= 0"));
						}
						cur_res = sqrt(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::LN)
					{
						if (param <= 0.0) // 参数超过范围
						{
							throw(Exception::Error("ln参数不得<=0"));
						}
						cur_res = log(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::LOG10)
					{
						if (param <= 0.0) // 参数超过范围
						{
							throw(Exception::Error("log10参数不得<=0"));
						}
						cur_res = log10(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::ABS)
					{
						cur_res = fabs(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::EXP) // 以e为底的指数函数
					{
						cur_res = exp(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::FLOOR)
					{
						cur_res = floor(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::CEIL)
					{
						cur_res = ceil(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::ROUND)
					{
						cur_res = round(param);
					}
					else if (it.func_info.id == ConstValue::FunctionID::SQUARE)
					{
						cur_res = pow(param,2);
					}
					else if (it.func_info.id == ConstValue::FunctionID::RECIPROCAL)
					{
						if (fabs(param) < 1e-9) // 参数不为0
						{
							throw(Exception::Error("reciprocal参数不为0"));
						}
						cur_res = 1.0 / param;
					}
					else // 未知函数
					{
						throw(Exception::Error("未知一级函数"));
					}
					num_stack.push(Tokenizer::Token::Number(cur_res, "", false));
				}
				else if (it.func_info.arity == 2) // 若为二级函数
				{
					// 当数字栈为空
					if (num_stack.size() < 2)
					{
						throw(Exception::Error("二级函数参数不足"));
					}

					double param2 = num_stack.top().num_info.value; // 获取函数参数2
					num_stack.pop();
					double param1 = num_stack.top().num_info.value; // 获取函数参数1
					num_stack.pop();


					// 计算
					double cur_res = 0.0;
					if (it.func_info.id == ConstValue::FunctionID::POW)
					{
						if (param1 < 0 && !Judge::is_int(param2))
						{
							throw(Exception::Error("pow()底数须为正数"));
						}
						if (fabs(param1) <= 1e-9 && param2 < 0)
						{
							throw(Exception::Error("pow()底数须为正数"));
						}

						cur_res = pow(param1, param2);
					}
					else if (it.func_info.id == ConstValue::FunctionID::GCD)
					{
						cur_res = Tool::gcd(param1, param2);
					}
					else if (it.func_info.id == ConstValue::FunctionID::LCM)
					{
						cur_res = Tool::lcm(param1, param2);
					}
					else if (it.func_info.id == ConstValue::FunctionID::LOG) // pa1为底数 pa2为真数
					{
						if (param1 <= 0 || fabs(param1 - 1) <= 1e-9)
						{
							throw(Exception::Error("log底数不为负数且不为1"));
						}
						if (param2 <= 0)
						{
							throw(Exception::Error("log真数为正数"));
						}

						cur_res = log(param2) / log(param1);
					}
					else // 未知函数
					{
						throw(Exception::Error("未知二级函数"));
					}
					num_stack.push(Tokenizer::Token::Number(cur_res, "", false));
				}
			}
			else if (it.type == Tokenizer::TokenType::OPERATOR) // 为符号
			{
				// 处理一元运算符（例如一元负号u-、后缀阶乘!）
				if(it.op_info.is_unary)
				{
					if (num_stack.empty())
					{
						throw(Exception::Error("数字栈大小不足1"));
					}

					// 获取一个数
					double v = num_stack.top().num_info.value;
					num_stack.pop();

					double cur_res = 0.0;
					if (it.op_info.id == ConstValue::OperatorID::UNARY_MINUS)
					{
						cur_res = -v;
					}
					else if (it.op_info.id == ConstValue::OperatorID::FACTORIAL)
					{
						if (fabs(v - round(v)) >= 1e-9) // 阶乘仅自然数
						{
							throw(Exception::Error("阶乘运算仅支持自然数输入"));
						}
						if (v > ConstValue::max_factorial || v < 0) // 超出阶乘限制范围
						{
							throw(Exception::Error("超出阶乘数限制范围"));
						}

						cur_res = ConstValue::factorial_table[(long long)v];
					}

					num_stack.push(Tokenizer::Token::Number(cur_res, "", false));
					continue;
				}

				// 二元运算符处理
				if (num_stack.size() < 2)
				{
					throw(Exception::Error("数字栈大小不足2"));
				}

				// 获取两个数
				double num2 = num_stack.top().num_info.value; // 栈顶为右因数
				num_stack.pop();
				double num1 = num_stack.top().num_info.value;
				num_stack.pop();

				double cur_res = 0.0;
				if (it.op_info.id == ConstValue::OperatorID::ADD)
				{
					cur_res = num1 + num2;
				}
				else if (it.op_info.id == ConstValue::OperatorID::SUB)
				{
					cur_res = num1 - num2;
				}
				else if (it.op_info.id == ConstValue::OperatorID::MUL)
				{
					cur_res = num1 * num2;
				}
				else if (it.op_info.id == ConstValue::OperatorID::DIV)
				{
					if (fabs(num2) < 1e-9) // 除数不为0
					{
						throw(Exception::Error("除数不为0"));
					}
					cur_res = num1 / num2;
				}
				else if (it.op_info.id == ConstValue::OperatorID::POWER)
				{
					if (fabs(num1 - floor(num1)) >= 1e-9 && num2 < 0) // 底数为负数且指数为负数
					{
						throw(Exception::Error("pow()底数须为正数"));
					}
					cur_res = std::pow(num1, num2);
				}
				else if (it.op_info.id == ConstValue::OperatorID::MOD)
				{
					if (fabs(num2) < 1e-9) // 模不为0
					{
						throw(Exception::Error("模不为0"));
					}
					cur_res = num1 - num2 * floor(num1 / num2);
				}
				else if (it.op_info.id == ConstValue::OperatorID::OR)
				{
					if (fabs(num1 - round(num1)) > 1e-9 || fabs(num2 - round(num2)) > 1e-9)
					{
						throw(Exception::Error("位运算仅支持整数"));
					}
					cur_res = static_cast<double>(static_cast<long long>(round(num1)) | static_cast<long long>(round(num2)));
				}
				else if (it.op_info.id == ConstValue::OperatorID::AND)
				{
					if (fabs(num1 - round(num1)) > 1e-9 || fabs(num2 - round(num2)) > 1e-9)
					{
						throw(Exception::Error("位运算仅支持整数"));
					}
					cur_res = static_cast<double>(static_cast<long long>(round(num1)) & static_cast<long long>(round(num2)));
				}
				else if (it.op_info.id == ConstValue::OperatorID::XOR)
				{
					if (fabs(num1 - round(num1)) > 1e-9 || fabs(num2 - round(num2)) > 1e-9)
					{
						throw(Exception::Error("位运算仅支持整数"));
					}
					cur_res = static_cast<double>(static_cast<long long>(round(num1)) ^ static_cast<long long>(round(num2)));
				}
				else // 未知运算符
				{
					throw(Exception::Error("未知符号"));
				}

				// 结果入栈
				num_stack.push(Tokenizer::Token::Number(cur_res, "", false));
			}
			else // 未知token
			{
				throw(Exception::Error("未知token"));
			}
		}

		// 如果最终栈大小不为1
		if (num_stack.size() != 1)
		{
			throw(Exception::Error("结果不为空"));
		}

		// 返回计算结果
		return num_stack.top().num_info.value;
	}
};