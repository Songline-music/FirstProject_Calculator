#pragma once

#define _USE_MATH_DEFINES
#include "Helper/ConstValue.hpp"
#include <string>
#include <cmath>

// 存放判断函数
namespace Judge 
{
	// 判断数字是否为整数
	inline bool is_int(double cur)
	{
		if (fabs(cur - round(cur)) < 1e-9)
		{
			return true;
		}
		return false;
	}

	// 判断是否为函数
	inline bool is_function(const std::string& name)
	{
		return ConstValue::get_function_map().find(name) != ConstValue::get_function_map().end();
	}

	// 判断是否为指令
	inline bool is_command(const std::string& name)
	{
		return ConstValue::get_command_map().find(name) != ConstValue::get_command_map().end();
	}

	// 判断是否为续算(为标准二元运算符)
	inline bool is_continuous(const ConstValue::OperatorInfo& op_info)
	{
		bool is_continue = (op_info.is_unary == false && op_info.id != ConstValue::OperatorID::LEFT_PAREN && op_info.id != ConstValue::OperatorID::RIGHT_PAREN && op_info.id != ConstValue::OperatorID::COMMA);
		return is_continue;
	}

	// 判断首字符是否为运算符
	inline bool is_operator(char cur)
	{
		return (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^' || cur == '%' || cur == '|' || cur == '&' || cur == '!' || cur == '~' || cur == ',' || cur == '(' || cur == ')');
	}
};