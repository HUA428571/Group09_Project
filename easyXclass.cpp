#pragma once
#include<iostream>
#include<graphics.h>
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
using namespace std;

// 定义文本框对象
class TextBox
{
private:
	int		m_x1, m_y1, m_x2, m_y2;		// 文本框位置
	char	m_text[12];					// 用户输入的字符串
	int		m_textlen;					// 用户输入字符串的长度
	int		m_fps;						// 每秒调用多少次（决定了光标闪烁速度）

public:
	// 构造函数
	TextBox(int x1, int  y1, int x2, int y2, int fps)
	{
		m_x1 = x1;	m_y1 = y1;	m_x2 = x2;	m_y2 = y2;
		m_text[0] = '\0';
		m_textlen = 0;
		m_fps = fps;
	}

	// 附加一个字符（可以接受退格）
	void Append(char c)
	{
		if (c != 8)
		{
			if (m_textlen < 9)
			{
				m_text[m_textlen] = c;
				m_text[m_textlen + 1] = '\0';
				m_textlen++;
			}
		}
		else
		{
			if (m_textlen > 0)
			{
				m_textlen--;
				m_text[m_textlen] = '\0';
			}
		}
	}

	// 返回输入的字符串指针
	char* Text()
	{
		return m_text;
	}

	// 清空输入的字符串
	void Empty()
	{
		m_textlen = 0;
		m_text[0] = '\0';
	}

	// 绘制文本框
	void Draw()
	{
		static int fps = 0;				// 统计字母个数计算光标位置

		// 设置文字输出样式
		settextstyle(20, 0, "Verdana");

		// 画边框
		setlinecolor(WHITE);
		rectangle(m_x1, m_y1, m_x2, m_y2);

		// 输出用户输入的字符串
		outtextxy(m_x1 + 30, m_y1 + (m_y2 - m_y1 - 20) / 2, m_text);

		// 绘制光标 
		fps++;
		if (fps < (m_fps / 4))
		{
			setlinecolor(WHITE);
			int sx = m_x1 + 31 + textwidth(m_text);
			line(sx, m_y1 + (m_y2 - m_y1 - 20) / 2, sx, m_y1 + (m_y2 - m_y1 - 20) / 2 + 20);
		}
		else if (fps > (m_fps / 2))
			fps = 0;
	}
};





////////////////////////////////////////////////////////
//// 游戏主循环
//void Game()
//{
//	TextBox textbox(10, HEIGHT - 40, WIDTH - 110, HEIGHT - 10, 50);	// 文本框对象
//	TARGET words[3];												// 掉落的 3 个单词
//	GameClock gameclock(60);										// 游戏计时对象
//
//	wchar_t	key;					// 用户输入的英文
//	int		right = 0, wrong = 0;	// 用户输入的正确、错误计数
//	int		v = 0;					// 打字速度
//	double	s;						// 正确率
//
//	// 随机生成掉落的字符串
//	for (int n = 0; n < 3; n++)
//	{
//		InitTarget(words, n);
//		words[n].y = -15 - n * 30;
//	}
//
//	// 游戏主循环
//	while (gameclock.IsStop())
//	{
//		// 获取控制/////////////////////////////////////////////////////
//
//		key = Input();
//
//
//		// 计算////////////////////////////////////////////////////////
//
//		// 执行一次游戏时钟
//		gameclock.Tick();
//
//		// 判断用户输入
//		if (key != 0)
//		{
//			textbox.Append(key);
//
//			// 判断用户输入是否正确并统计正确错误数
//			if (key != 8)
//			{
//				if (isprefix(textbox.Text(), words))
//					right++;
//				else
//					wrong++;
//			}
//
//			// 判断输入的字符串是否与掉落的字符串相等
//			for (int i = 0; i < 3; i++)
//				if (wcscmp(textbox.Text(), words[i].p) == 0)
//				{
//					InitTarget(words, i);
//					textbox.Empty();
//				}
//		}
//
//		// 计算打字速度
//		v = (gameclock.Elapse() == 0) ? 0 : right * 60 / gameclock.Elapse();
//
//		// 单词掉落并进行判断是否超出屏幕掉落范围
//		for (int n = 0; n < 3; n++)
//		{
//			words[n].y += 2;
//
//			if (words[n].y > HEIGHT - 40)
//				InitTarget(words, n);
//		}
//
//		// 计算正确率
//		if (wrong + right == 0)
//			s = 0;
//		else
//			s = (double)right / (wrong + right) * 100;
//
//
//		// 绘制////////////////////////////////////////////////////////
//
//		// 清除屏幕
//		cleardevice();
//
//		// 设置输出字符串的显示格式
//		settextstyle(20, 0, L"Verdana");
//		setbkmode(TRANSPARENT);
//		settextcolor(WHITE);
//
//		// 绘制统计区域
//		setfillcolor(RGB(50, 50, 50));
//		solidrectangle(WIDTH - 100, 0, WIDTH - 2, HEIGHT);
//
//		// 输出掉落的单词
//		for (int n = 0; n < 3; n++)
//			outtextxy(words[n].x, words[n].y, words[n].p);
//
//		// 绘制 TextBox
//		textbox.Draw();
//
//		// 右侧正确输入统计
//		outtextxy(WIDTH - 90, 25, L"正确数");
//		outintxy(WIDTH - 80, 50, L"%d", right);
//
//		// 右侧错误输入统计
//		outtextxy(WIDTH - 90, 85, L"错误数");
//		outintxy(WIDTH - 80, 110, L"%d", wrong);
//
//		// 右侧正确率的计算
//		outtextxy(WIDTH - 90, 145, L"正确率");
//		outdoublexy(WIDTH - 80, 170, L"%.1f %%", s);
//
//		// 右侧打字速度的计算
//		outtextxy(WIDTH - 90, 205, L"打字速度");
//		outintxy(WIDTH - 80, 230, L"%d kpm", v);
//
//		// 右侧输出的倒计时
//		outtextxy(WIDTH - 90, 265, L"倒计时");
//		outintxy(WIDTH - 80, 290, L"%d s", gameclock.Now());
//
//		FlushBatchDraw();
//
//		Sleep(20);
//	}
//}


// 主函数
//int main()
//{
//	srand((unsigned)time(NULL));
//	initgraph(WIDTH, HEIGHT);
//
//	BeginBatchDraw();
//
//	while (true)
//	{
//		Game();
//
//		// 提示游戏结束
//		setfillcolor(RGB(200, 200, 200));
//		solidrectangle(150, 200, 450, 300);
//		settextcolor(BLACK);
//		outtextxy(220, 225, L"重新开始请按 空格");
//		outtextxy(220, 255, L"退出游戏请按 Esc");
//		FlushBatchDraw();
//
//		// 实现按空格重来、按 ESC 退出
//		wchar_t ch = 0;
//		while (ch != 27 && ch != ' ')
//			ch = _getwch();
//
//		if (ch == 27)
//			break;
//	}
//
//	EndBatchDraw();
//
//	closegraph();
//	return 0;
//}