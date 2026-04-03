#pragma once

#include <string>
#include <vector>
#include <unordered_map>

// 常量命名空间
namespace ConstValue
{
	// ======================================默认数部分=================================================
	// 小数常量
	inline int max_decimal = 10;    // 默认最大输出小数位数
	inline int default_decimal = 8; // 默认小数位数

	// 阶乘常量
	inline int max_factorial = 20; // 最大阶乘数

	// 符号常量
	inline double PI_VAL = std::acos(-1.0);
	inline std::string PI_SHOW_SYMBOL = "π";
	inline std::string PI_SYMBOL = "pi";
	inline double EULER_VAL = std::exp(1.0);
	inline std::string EULER_SYMBOL = "e";

	// 角度常量
	inline double RAD_PER_DEG = M_PI / 180.0; // 一度的具体数值
	inline std::string DEG_SYMBOL = "deg";

	// ======================================函数部分=================================================
	// 函数id
	enum class FunctionID
	{
		NONE = 0,
		SEC,CSC,COT,SIN,COS,TAN,ASIN,ACOS,ATAN,SQRT,LOG,LOG10,POW,MAX,MIN,GCD,LCM,ABS,EXP,LN,ROUND,FLOOR,CEIL,SQUARE,RECIPROCAL
	};

	// 每个函数元的结构信息
	struct FunctionInfo
	{
		FunctionID id;         // 函数的id
		int arity = 0;         // 函数的接纳参数个数
		bool is_multi = false; // 是否为多级函数
	};

	// 函数名及信息映射注册表(统一小写格式输入)
	inline const std::unordered_map<std::string, FunctionInfo>& get_function_map()
	{
		static const std::unordered_map<std::string, FunctionInfo> functions_map =
		{
			{ "sec",       {FunctionID::SEC,       1 , false} },
			{ "csc",       {FunctionID::CSC,       1 , false} },
			{ "cot",       {FunctionID::COT,       1 , false} },
			{ "sin",       {FunctionID::SIN,       1 , false} },
			{ "cos",       {FunctionID::COS,       1 , false} },
			{ "tan",       {FunctionID::TAN,       1 , false} },
			{ "asin",      {FunctionID::ASIN,      1 , false} },
			{ "acos",      {FunctionID::ACOS,      1 , false} },
			{ "atan",      {FunctionID::ATAN,      1 , false} },
			{ "sqrt",      {FunctionID::SQRT,      1 , false} },
			{ "abs",       {FunctionID::ABS,       1 , false} },
			{ "floor",     {FunctionID::FLOOR,     1 , false} },
			{ "ceil",      {FunctionID::CEIL,      1 , false} },
			{ "round",     {FunctionID::ROUND,     1 , false} },
			{ "exp",       {FunctionID::EXP,       1 , false} },
			{ "ln",        {FunctionID::LN,        1 , false} },
			{ "log10",     {FunctionID::LOG10,     1 , false} },
			{ "pow",       {FunctionID::POW,       2 , false} },
			{ "log",       {FunctionID::LOG,       2 , false} },
			{ "max",       {FunctionID::MAX,      -1 , true } },
			{ "min",       {FunctionID::MIN,      -1 , true } },
			{ "gcd",       {FunctionID::GCD,       2 , false} },
			{ "lcm",       {FunctionID::LCM,       2 , false} },
			{ "square",    {FunctionID::SQUARE,    1 , false} },
			{ "reciprocal",{FunctionID::RECIPROCAL,1 , false} }
		};

		return functions_map;
	}

	// ======================================指令部分===================================================
	// 指令id
	enum class CommandID
	{
		NONE = 0,
		QUIT,EMOJI,RANDOM,NORMAL
	};

	// 每个指令元的结构信息
	struct CommandInfo
	{
		CommandID id; // 指令的id
	};

	// 指令注册表(统一小写格式输入)
	inline const std::unordered_map<std::string, CommandInfo>& get_command_map()
	{
		static const std::unordered_map<std::string, CommandInfo> command_map =
		{
			{ "quit",           {CommandID::QUIT}          },
			{ "emoji",          {CommandID::EMOJI}         },
			{ "random",         {CommandID::RANDOM}        },
			{ "normal",         {CommandID::NORMAL}        }
		};

		return command_map;
	}

	// ======================================数字部分====================================================
	// 每个数字元的结构信息
	struct NumberInfo
	{
		double value;        // 数字的数值
		bool is_deg = false; // 是否为角度制
	};

	// ======================================运算符部分===================================================
	// 运算符id
	enum class OperatorID
	{
		NONE = 0,
		ADD,SUB,MUL,DIV,MOD,FACTORIAL,POWER,AND,OR,XOR,UNARY_MINUS, LEFT_PAREN,RIGHT_PAREN,COMMA
	};

	// 每个运算符元的结构信息
	struct OperatorInfo
	{
		OperatorID id;                     // 运算符的id
		bool is_unary = false;             // 是否为一元运算符
		bool is_right_combinative = false; // 结合性：true为右结合，false为左结合
	};

	// 运算符注册表(统一小写格式输入)(右结合符号表示->符号右侧绑定数字)
	inline const std::unordered_map<std::string, OperatorInfo>& get_operator_map()
	{
		static const std::unordered_map<std::string, OperatorInfo> operator_map =
		{
			{ "+",  {OperatorID::ADD,         false ,false} },
			{ "-",  {OperatorID::SUB,         false ,false} },
			{ "*",  {OperatorID::MUL,         false ,false} },
			{ "/",  {OperatorID::DIV,         false ,false} },
			{ "%",  {OperatorID::MOD,         false ,false} },
			{ "!",  {OperatorID::FACTORIAL,   true  ,false} },
			{ "^",  {OperatorID::POWER,       false ,false} },
			{ "&",  {OperatorID::AND,         false ,false} },
			{ "|",  {OperatorID::OR,          false ,false} },
			{ "~",  {OperatorID::XOR,         false ,false} },
			{ "u-", {OperatorID::UNARY_MINUS, true  ,true}  },
			{ "(",  {OperatorID::LEFT_PAREN,  false ,false} },
			{ ")",  {OperatorID::RIGHT_PAREN, false ,false} },
			{ ",",  {OperatorID::COMMA,       false ,false} }
		};

		return operator_map;
	}

	// ======================================预处理部分===================================================
	// 获取最大阶数前的阶乘列表
	inline const std::vector<double> factorial_table = []()
	{
			std::vector<double> table(max_factorial + 1);
			table[0] = 1.0;

			for(int i = 1; i <= max_factorial; i++)
			{
				table[i] = table[i - 1] * i;
			}

			return table;
	}();
}