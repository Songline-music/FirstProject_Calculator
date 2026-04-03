#pragma once

#include "Helper/Judge.hpp"
#include "Helper/ConstValue.hpp"
#include "Log/Exception.hpp"

// 存放数值转换以及计算的工具
namespace Tool
{
	// 获取最大公约数
	inline double gcd(double num1, double num2)
	{
		if (!Judge::is_int(num1) || !Judge::is_int(num2))
		{
			throw(Exception::Error("gcd()函数仅接纳整数"));
		}

		long long x = static_cast<long long>(round(num1));
		long long y = static_cast<long long>(round(num2));

		while (y != 0)
		{
			long long temp = x % y;

			x = y;
			y = temp;
		}

		return (double)x;
	}

	// 获取最小公倍数
	inline double lcm(double num1, double num2)
	{

		double gcd_res = gcd(num1, num2);

		double multiply = num1 * num2;
		if (multiply > LLONG_MAX / 1)
		{
			throw(Exception::Error("参数乘积超过LLONG数据范围"));
		}

		return multiply / gcd_res;
	}

	// 角度转弧度
	inline double deg_to_rad(double num)
	{
		return num * ConstValue::RAD_PER_DEG;
	}

	// 查询指定函数信息
	inline const ConstValue::FunctionInfo& get_function_info(const std::string& name)
	{
		// 先检查函数是否存在
		if (!Judge::is_function(name))
		{
			static const ConstValue::FunctionInfo none_info = { ConstValue::FunctionID::NONE, 0 };
			return none_info;
		}

		return ConstValue::get_function_map().at(name);
	}
};