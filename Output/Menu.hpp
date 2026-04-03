#pragma once

#define _USE_MATH_DEFINES
#include <Helper/ConstValue.hpp>
#include <iostream>

// 用来统一存放默认输出内容
namespace Menu
{
	inline const std::string help = 
R"(
指令:(可在算式输入栏中输入,按"="执行)
	quit(退出程序)

游戏:(软件内置趣味小互动,可自行探索)

计算器:(具备科学计算器的所有功能)
运算符: 
	+,-,*,/
	%,^,!(最高不超过20)
	&,|,~
一级函数:
	abs(),square()
	sqrt(),floor(),ceil(),round()
	sin(),cos(),tan(),sec(),csc(),cot() <-弧度输入下(输入数字自动转换)
	asin(),acos(),atan()
	exp()
	ln(),log10()
二级函数: 
	gcd(),lcm()
	pow(),log()
多级函数: 
	max(),min()
特殊:
	续算
	自动补零
	e/π(pi替代)识别
	负号
	科学计数法
	"无主."
	回车输入
	弧度/角度制(默认弧度制) <-弧度输入下三角函数内输入默认为弧度单位
	不同模式下继承输入
模式:
	标准
	科学
	程序员 <-只具备简单逻辑运算符
version: 1.0.6
)";
};