#include <graphics.h>
#include<easyx.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>

//////////////////////////////////////////////////////
// 定义文本框对象
class TextBox
{
private:
	int		m_x1, m_y1, m_x2, m_y2;		// 文本框位置
	char	m_text[10];					// 用户输入的字符串
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
	void Append(wchar_t c)
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

// 获取用户输入（仅接受英文字母和退格键）
char Input()
{
	char c = 0;

	if (_kbhit())
	{
		c = _getwch();
		if (c >= 'A' && c <= 'Z')
			c = c + 32;
		else if (!(c >= 'a' && c <= 'z') && c != 8)
			c = 0;
	}
	return c;
}