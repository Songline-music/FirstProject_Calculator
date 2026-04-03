#pragma once

#define _USE_MATH_DEFINES
#include "Helper/ConstValue.hpp"
#include <sstream>
#include <string>
#include <iomanip>

// 存储对于用户输入字符串的处理方法
namespace StrProcess
{
	// 数字转字符串(小数精度限制)
	inline std::string num_to_string(double res, int decimal = ConstValue::default_decimal)
	{
		// 局部输出流限制小数位数
		std::stringstream ss;

		// 若能被π整除
		if (fabs(res) >= 1e-9 && fabs(res / ConstValue::PI_VAL - round(res / ConstValue::PI_VAL)) < 1e-9)
		{
			return std::to_string((long long)round(res / ConstValue::PI_VAL)) + ConstValue::PI_SHOW_SYMBOL;
		}

		// 若能被e整除
		if (fabs(res) >= 1e-9 && fabs(res / ConstValue::EULER_VAL - round(res / ConstValue::EULER_VAL)) < 1e-9)
		{
			return std::to_string((long long)round(res / ConstValue::EULER_VAL)) + ConstValue::EULER_SYMBOL;
		}

		// 提前四舍五入
		double rounded_res = res;
		if (decimal > 0)
		{
			double pow10 = std::pow(10, decimal);
			rounded_res = std::round(res * pow10) / pow10;
		}
		else // 保留0位时直接取整
		{
			rounded_res = std::round(res);
		}

		// 按小数位数取舍
		ss << std::fixed << std::setprecision(decimal) << rounded_res;
		std::string ans = ss.str();

		// 去除末尾零(从后找到第一个零的索引)
		ans.erase(ans.find_last_not_of('0') + 1, std::string::npos);

		// 若无小数部分删去多余零
		if (!ans.empty() && ans.back() == '.')
		{
			ans.pop_back();
		}

		return ans;
	}
};