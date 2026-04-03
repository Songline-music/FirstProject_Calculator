#pragma once

#include "Core/Equation.hpp"
#include "Helper/StrProcess.hpp"
#include "Core/Parser.hpp"
#include "Input/Tokenizer.hpp"
#include "Game/Game.hpp"
#include "Helper/ConstValue.hpp"
#include "Output/Menu.hpp"

// 计算器类(处理用户交互)
class Calculator
{
public:
	// 输出类型
	enum class output_type
	{
		EQUATION, // 算式输出
		ERROR,    // 错误输出
		POP_UP,   // 弹窗输出
		NONE      // 无输出
	};

	// 输出结果结构体
	struct result
	{
		output_type type;    // 输出类型
		std::string content; // 输出内容
		std::string egg;     // 彩蛋内容
	};

	// 计算器处理
	result process(const std::string& input)
	{
		// 收集输出内容
		result output_res;
		std::stringstream out;

		try
		{
			// 解析输入
			std::vector<Tokenizer::Token> tokens = tnz.tokenize(input);
			auto parsed_result = parser.parse(tokens);

			if (parsed_result.is_cmd) // 指令处理
			{
				output_res.type = output_type::NONE;

				if (parsed_result.command.empty())
				{
					throw(Exception::Error("指令输入不能为空"));
				}

				if (parsed_result.command[0].cmd_info.id == ConstValue::CommandID::QUIT) // 退出程序
				{
					throw(Exception::Quit());
				}
				else // 未知指令
				{
					throw(Exception::Error("未知指令输入"));
				}
			}
			else // 算式处理
			{
				output_res.type = output_type::EQUATION;

				double res;
				double last_res = eq.get_last_result();
				std::string print_in;
				std::string print_out;

				if (tokens.front().type == Tokenizer::TokenType::OPERATOR && Judge::is_continuous(tokens.front().op_info)) // 若为续算
				{
					// 上次计算结果token化
					Tokenizer::Token last_res_tokens = Tokenizer::Token::Number(last_res, StrProcess::num_to_string(last_res), false);

					// 拼贴续算输入
					std::vector<Tokenizer::Token> new_tokens = { last_res_tokens };
					new_tokens.insert(new_tokens.end(), tokens.begin(), tokens.end());

					// 重新解析
					parsed_result = parser.parse(new_tokens);

					res = eq.cal(parsed_result.equation);
					print_in = StrProcess::num_to_string(last_res, eq.get_cur_decimal()) + input;
					print_out = StrProcess::num_to_string(res, eq.get_cur_decimal());
				}
				else // 非续算
				{
					// 清零从头开始
					eq.clear();

					res = eq.cal(parsed_result.equation);
					print_in = input;
					print_out = StrProcess::num_to_string(res, eq.get_cur_decimal());
				}
				std::string show_str = print_in + " = " + print_out;

				// 历史记录存储
				history.push_back(show_str);

				// 游戏模式输出
				std::string game_str = game.special_output(print_in, print_out); // 处理游戏模式下输出

				// 结果输出
				// 先输出标准格式
				out << show_str << std::endl;
				if (!game_str.empty()) // 若有游戏展示
				{
					out << game_str << std::endl;
				}

				// 彩蛋输出
				std::string feedback = game.special_num_feedback(res);
				if (!feedback.empty()) // 若有彩蛋反馈
				{
					output_res.egg = feedback;
				}
			}
		}
		catch (const Exception::Error& expt) // 捕获异常
		{
			out << expt.what();
			output_res.type = output_type::ERROR;
		}
		catch (const Exception::Quit&) // 登出
		{
			exit(0);
		}

		// 完整一轮输出内容
		output_res.content = out.str();
		return output_res;
	}

	// 接口
	void remove_history() { history.clear(); }
	void game_mode(bool mode) { game.game_mode(mode); }
	void set_deg() { eq.set_deg_mode(true); }
	void set_rad() { eq.set_deg_mode(false); }
	void set_precision(int digit) { eq.set_decimal(digit); }
	void set_game_mode(ConstValue::CommandID cur)
	{
		if(cur == ConstValue::CommandID::EMOJI)
		{
			game.set_special_output_mode(Game::mode::EMOJI);
		}
		else if(cur == ConstValue::CommandID::NORMAL)
		{
			game.set_special_output_mode(Game::mode::NORMAL);
		}
		else if(cur == ConstValue::CommandID::RANDOM)
		{
			game.set_special_output_mode(Game::mode::RANDOM);
		}
	}
	std::string get_tip() { return game.get_tip(); }
	int get_level() const { return game.get_level(); }
	int get_cur_exe() const { return game.get_cur_exe(); }
	int get_max_level() const { return game.get_max_level(); }
	int get_cur_exe_threshold() const { return game.get_cur_exe_threshold(); }
	const std::vector<std::string>& get_history() { return history; }
private:

	std::vector<std::string> history; // 输入历史记录

	Equation eq;   // 计算引擎
	Tokenizer tnz; // 拆分引擎
	Parser parser; // 解析引擎
	Game game;     // 游戏引擎
};