#include <graphics.h>
#include<easyx.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>

//////////////////////////////////////////////////////
// �����ı������
class TextBox
{
private:
	int		m_x1, m_y1, m_x2, m_y2;		// �ı���λ��
	char	m_text[10];					// �û�������ַ���
	int		m_textlen;					// �û������ַ����ĳ���
	int		m_fps;						// ÿ����ö��ٴΣ������˹����˸�ٶȣ�

public:
	// ���캯��
	TextBox(int x1, int  y1, int x2, int y2, int fps)
	{
		m_x1 = x1;	m_y1 = y1;	m_x2 = x2;	m_y2 = y2;
		m_text[0] = '\0';
		m_textlen = 0;
		m_fps = fps;
	}

	// ����һ���ַ������Խ����˸�
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

	// ����������ַ���ָ��
	char* Text()
	{
		return m_text;
	}

	// ���������ַ���
	void Empty()
	{
		m_textlen = 0;
		m_text[0] = '\0';
	}

	// �����ı���
	void Draw()
	{
		static int fps = 0;				// ͳ����ĸ����������λ��

		// �������������ʽ
		settextstyle(20, 0, "Verdana");

		// ���߿�
		setlinecolor(WHITE);
		rectangle(m_x1, m_y1, m_x2, m_y2);

		// ����û�������ַ���
		outtextxy(m_x1 + 30, m_y1 + (m_y2 - m_y1 - 20) / 2, m_text);

		// ���ƹ�� 
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

// ��ȡ�û����루������Ӣ����ĸ���˸����
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