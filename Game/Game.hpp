#pragma once

#include <string>
#include <vector>
#include <ctime>

// 游戏类，提供趣味回答以及反馈
class Game
{
public:
	// 展示游戏模式
	enum class mode
	{
		NONE = 0,
		RANDOM,EMOJI,NORMAL
	};

	// 获取提示
	std::string get_tip()
	{
		// 设置种子
		static bool is_init = false;
		if (!is_init)
		{
			srand((unsigned int)time(nullptr));
			is_init = true;
		}

		std::string tip = tips[level][rand() % tips[level].size()];

		// 经验加1
		cur_exe++;
		check_level_up();

		return tip;
	}

	// 判断并升级等级
	bool check_level_up()
	{
		// 最高级不再升级
		if (level >= static_cast<int>(exe_thresholds.size()))
		{
			return false;
		}

		if (cur_exe >= exe_thresholds[level] && level < exe_thresholds.size()) // 升级
		{
			level++;
			cur_exe = 0;
			return true;
		}

		return false;
	}

	// 修改游戏开关
	void game_mode(bool game_on)
	{
		is_on = game_on;
	}

	// 对特殊数字输入进行反馈
	std::string special_num_feedback(double num)
	{
		if(!is_on) // 游戏模式未开启
		{
			return "";
		}

		cur_exe++; // 经验加1
		if (fabs(num - 114514.0) <= 1e-9)
		{
			return R"(
---------▃▆█▇▄
-------▅◤　 　 ▉◥█▎
----◢▅◤　 ▉　 　 ▉
---▅◤　　▅▂　 ▅▅　▕█▎
--▅◤　  ▅◥▄　 ▅◣　　█▊
--▅　▕▎◥ ◣◤　　　　◢██
--█◣　◥▅█▅▅　　　 ██◤
--█　　　    ◢██◤
---◥██◣　　◢▄◤
------██▅▇
				     )";
		}
		else if (fabs(num - 520.0) <= 1e-9)
		{
			return R"(
----***  ***
---** **** **
--**        **
----**    **
-----**  **
------****
-------**
					 )";
		}
		else if (fabs(num - 9331.0) <= 1e-9)
		{
			return R"(
_____________________
|YYRR|YYRr|YyRR|YyRr|
|____|____|____|____|
|YYRr|YYrr|YyRr|Yyrr|
|____|____|____|____|
|YyRR|YyRr|yyRR|yyRr|
|____|____|____|____|
|YyRr|Yyrr|yyRr|yyrr|
|____|____|____|____|
				     )";
		}
		else if (fabs(num - 12321.0) <= 1e-9)
		{
			return R"(
----------------
--3---3---3---3-
-2-2-2-2-2-2-2-2
1---1---1---1---
----------------
					  )";
		}
		else if (fabs(num - 153.0) <= 1e-9)
		{
			return R"(
----O
---/|\
--/ | \
-/  |  \
----|
----|
					 )";
		}

		cur_exe--; // 经验减1(未触发特殊数字)
		return "";
	}

	// 当输入特殊指令时,提供的特殊结果输出
	std::string special_output(std::string print_in,std::string print_out)
	{
		// 若非游戏模式
		if(!is_on)
		{
			return "";
		}

		if(special_output_mode == mode::NONE || special_output_mode == mode::NORMAL) // 若为正常模式
		{
			return "";
		}
		else if(special_output_mode == mode::RANDOM) // random混乱输出
		{
			// 设置种子
			static bool is_init = false;
			if (!is_init)
			{
				srand((unsigned int)time(nullptr));
				is_init = true;
			}

			std::string to_return = print_in + " = " + print_out;

			// 遍历字符,在字符数内随机替换为一个字符
			for(size_t i = 0; i < to_return.size(); i++)
			{
				if(to_return[i] == ' ') // 空格跳过
				{ 
					continue;
				}

				if(rand() % 10 < 2) // 20%概率替换
				{
					to_return[i] = static_cast<char>(32 + rand() % 95); // 替换为可打印字符
				}
			}
			return to_return;
		}
		else if(special_output_mode == mode::EMOJI) // emoji输出
		{
			return print_in + " =( ^_^ )-> " + print_out;
		}

		return "";
	}

	// 设置特殊输出模式
	void set_special_output_mode(mode mode_)
	{
		special_output_mode = mode_;
	}

	// 对外接口
	int get_level() const { return level; }
	int get_max_level() const { return static_cast<int>(tips.size()) - 1; }
	bool is_game_on() const { return is_on; }
	int get_cur_exe() const { return cur_exe; }
	int get_cur_exe_threshold() const
	{
		// 最高级时不再有下一阈值
		if (level >= static_cast<int>(exe_thresholds.size()))
		{
			return 0;
		}
		return exe_thresholds[level];
	}

private:
	int level = 0;                                      // 交流等级(3级最高)
	bool is_on = false;                                 // 游戏是否开启
	int cur_exe = 0;                                    // 当前经验值(每当获取tip/出发彩蛋时经验+1)
	mode special_output_mode = mode::NONE;              // 特殊输出模式
	const std::vector<int> exe_thresholds = { 3, 5, 8}; // 经验值阈值

	// 提示展示
	const std::vector<std::vector<std::string>> tips=
	{
		// level_0
		{
			"输入格式没问题,我就能正常计算",
			"阶乘最大支持20哦,别输错啦",
			"支持π和e哦,直接输入pi或e就行",
			"续算超方便,直接输运算符就能接着算",
			"角度和弧度模式可以随时切换",
			"max/min函数可装下超级多的参数",
			".5 , 5. 奇怪的输入也是支持的",
			"冷知识: deg模式输入也只是对三角函数有效",
			"90deg 也是角度输入呀",
			"1e+4,1e-5,1e,e和科学计算输入要分清呀",
			"log(a,b)输入a为底数,b为真数",
			"pow(a,b)输入a为底数,b为指数",
			"这是一个level_0的tip"
		},
		// level_1
		{
			"遇到问题可以点击help查看指令说明",
			"小数位数可以在设置调整",
			"game模式也就是我,是可以随时打开以及关闭的",
			"history功能非常好用,你算的奇葩数字都会记录",
			"help内容非常多不妨看看?",
			"clear按钮能让你容光焕发(清零啦)",
			"0+0=0,0×0=0,完美匹配",
			"2是唯一的偶质数,1不是质数",
			"什么数加上它自己,乘以它自己,结果都一样？",
			"什么数的平方加立方,刚好是它的 6 倍呀？",
			"0.99999… 和 1 哪个大呀？",
			"1 到 10 的最小公倍数是 2520",
			"小明今年5岁,哥哥比他大3岁,哥哥明年几岁？别算8岁哦,年份也要记得涨呀",
			"数列0,1,2,3…第100个数是啥？别说是100",
			"这是一个level_1的tip"
		},
		// level_2
		{
			"冷知识,你正在看这个tip",
			"冷知识,这个知识不热",
			"热知识,一点也不冷",
			"以防你不知道,在计算机的世界 1 和 1.0 是不一样的哟",
			"双精度浮点数 double 能精确表示整数到 2^53!",
			"十进制是因为人类有十根手指(什?)",
			"整数溢出会导致结果变成负数",
			"平方根函数只返回非负的结果",
			"模运算就是求除法剩下的余数",
			"让我睡会儿zzzzzz",
			"你知道吗,我其实被翻新过不下10次",
			"你知道吗,我是作者的第一个正式项目",
			"不不不,谁都不能知道我以前只会四则运算!!!!",
			"弹,弹bug都不见qwq",
			"听说level_3的我会有一些神奇小功能哟",
			"想要快速升级?那还不多跟我交流",
			"这是一个level_2的tip"
		},
		// level_3
		{
			"最高级啦,我会给你一些神奇数字的,不妨试着输出下?",
			"以前的我呀还只能在一个黑框里输出呢",
			"计算结果520心形反馈也给你",
			"114514为什么你不试着输出他呢?",
			"9331自由组合还在追我",
			"12321循环位数耶",
			"~(oxo)~",
			"153水仙花数很漂亮",
			"(～￣▽￣)～",
			"到Level3后设置里面会有新东西qaq",
			"要不要试着打开emoji会有新的惊喜~",
			"不妨试一下random?结果是什么我就不知道了)",
			"叮~~~~这是一个极品tip抽到这个很不容易吧",
			"不想要特殊模式?切换normal就行啦"
		}
	};
};