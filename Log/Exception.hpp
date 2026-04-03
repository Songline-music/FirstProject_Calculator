#pragma once

#include <string>
#include <exception>

namespace Exception 
{
	// 处理提交报错信息
	class Error : public std::exception
	{
	public:
		explicit Error(std::string msg) : _msg(std::move(msg)) {} // 存储报错信息

		const char* what() const noexcept override // C形式字符串重载
		{
			return _msg.c_str();
		}

	private:
		std::string _msg;
	};

	// 处理提交登出信息
	class Quit : public std::exception
	{
	public:
		const char* what() const noexcept override // C形式字符串重载
		{
			return "quit";
		}
	};
}