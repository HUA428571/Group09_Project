//#include <graphics.h>
//#include <easyx.h>
//#include <conio.h>
//#include <time.h>
//#include <stdio.h>
//#define GIW_WIDTH 800 // ���ó��򴰿ڳߴ�
//#define GIW_HIGH 480
//using namespace std;
//
//////////////////////////////////////////////////////////
////// �����ı������
////class TextBox
////{
////private:
////	int		m_x1, m_y1, m_x2, m_y2;		// �ı���λ��
////	char	m_text[10];					// �û�������ַ���
////	int		m_textlen;					// �û������ַ����ĳ���
////	int		m_fps;						// ÿ����ö��ٴΣ������˹����˸�ٶȣ�
////
////public:
////	// ���캯��
////	TextBox(int x1, int  y1, int x2, int y2, int fps)
////	{
////		m_x1 = x1;	m_y1 = y1;	m_x2 = x2;	m_y2 = y2;
////		m_text[0] = '\0';
////		m_textlen = 0;
////		m_fps = fps;
////	}
////
////	// ����һ���ַ������Խ����˸�
////	void Append(wchar_t c)
////	{
////		if (c != 8)
////		{
////			if (m_textlen < 9)
////			{
////				m_text[m_textlen] = c;
////				m_text[m_textlen + 1] = '\0';
////				m_textlen++;
////			}
////		}
////		else
////		{
////			if (m_textlen > 0)
////			{
////				m_textlen--;
////				m_text[m_textlen] = '\0';
////			}
////		}
////	}
////
////	// ����������ַ���ָ��
////	char* Text()
////	{
////		return m_text;
////	}
////
////	// ���������ַ���
////	void Empty()
////	{
////		m_textlen = 0;
////		m_text[0] = '\0';
////	}
////
////	// �����ı���
////	void Draw()
////	{
////		static int fps = 0;				// ͳ����ĸ����������λ��
////
////		// �������������ʽ
////		settextstyle(20, 0, "Verdana");
////
////		// ���߿�
////		setlinecolor(WHITE);
////		rectangle(m_x1, m_y1, m_x2, m_y2);
////
////		// ����û�������ַ���
////		outtextxy(m_x1 + 30, m_y1 + (m_y2 - m_y1 - 20) / 2, m_text);
////
////		// ���ƹ�� 
////		fps++;
////		if (fps < (m_fps / 4))
////		{
////			setlinecolor(WHITE);
////			int sx = m_x1 + 31 + textwidth(m_text);
////			line(sx, m_y1 + (m_y2 - m_y1 - 20) / 2, sx, m_y1 + (m_y2 - m_y1 - 20) / 2 + 20);
////		}
////		else if (fps > (m_fps / 2))
////			fps = 0;
////	}
////};
////
////// ��ȡ�û����루������Ӣ����ĸ���˸����
////char Input()
////{
////	char c = 0;
////
////	if (_kbhit())
////	{
////		c = _getwch();
////		if (c >= 'A' && c <= 'Z')
////			c = c + 32;
////		else if (!(c >= 'a' && c <= 'z') && c != 8)
////			c = 0;
////	}
////	return c;
////}
//
//////////////////////////////////////////////////////////
////// ��Ϸ��ѭ��
////void Game()
////{
////	TextBox textbox(10, HEIGHT - 40, WIDTH - 110, HEIGHT - 10, 50);	// �ı������
////	TARGET words[3];												// ����� 3 ������
////	GameClock gameclock(60);										// ��Ϸ��ʱ����
////
////	wchar_t	key;					// �û������Ӣ��
////	int		right = 0, wrong = 0;	// �û��������ȷ���������
////	int		v = 0;					// �����ٶ�
////	double	s;						// ��ȷ��
////
////	// ������ɵ�����ַ���
////	for (int n = 0; n < 3; n++)
////	{
////		InitTarget(words, n);
////		words[n].y = -15 - n * 30;
////	}
////
////	// ��Ϸ��ѭ��
////	while (gameclock.IsStop())
////	{
////		// ��ȡ����/////////////////////////////////////////////////////
////
////		key = Input();
////
////
////		// ����////////////////////////////////////////////////////////
////
////		// ִ��һ����Ϸʱ��
////		gameclock.Tick();
////
////		// �ж��û�����
////		if (key != 0)
////		{
////			textbox.Append(key);
////
////			// �ж��û������Ƿ���ȷ��ͳ����ȷ������
////			if (key != 8)
////			{
////				if (isprefix(textbox.Text(), words))
////					right++;
////				else
////					wrong++;
////			}
////
////			// �ж�������ַ����Ƿ��������ַ������
////			for (int i = 0; i < 3; i++)
////				if (wcscmp(textbox.Text(), words[i].p) == 0)
////				{
////					InitTarget(words, i);
////					textbox.Empty();
////				}
////		}
////
////		// ��������ٶ�
////		v = (gameclock.Elapse() == 0) ? 0 : right * 60 / gameclock.Elapse();
////
////		// ���ʵ��䲢�����ж��Ƿ񳬳���Ļ���䷶Χ
////		for (int n = 0; n < 3; n++)
////		{
////			words[n].y += 2;
////
////			if (words[n].y > HEIGHT - 40)
////				InitTarget(words, n);
////		}
////
////		// ������ȷ��
////		if (wrong + right == 0)
////			s = 0;
////		else
////			s = (double)right / (wrong + right) * 100;
////
////
////		// ����////////////////////////////////////////////////////////
////
////		// �����Ļ
////		cleardevice();
////
////		// ��������ַ�������ʾ��ʽ
////		settextstyle(20, 0, L"Verdana");
////		setbkmode(TRANSPARENT);
////		settextcolor(WHITE);
////
////		// ����ͳ������
////		setfillcolor(RGB(50, 50, 50));
////		solidrectangle(WIDTH - 100, 0, WIDTH - 2, HEIGHT);
////
////		// �������ĵ���
////		for (int n = 0; n < 3; n++)
////			outtextxy(words[n].x, words[n].y, words[n].p);
////
////		// ���� TextBox
////		textbox.Draw();
////
////		// �Ҳ���ȷ����ͳ��
////		outtextxy(WIDTH - 90, 25, L"��ȷ��");
////		outintxy(WIDTH - 80, 50, L"%d", right);
////
////		// �Ҳ��������ͳ��
////		outtextxy(WIDTH - 90, 85, L"������");
////		outintxy(WIDTH - 80, 110, L"%d", wrong);
////
////		// �Ҳ���ȷ�ʵļ���
////		outtextxy(WIDTH - 90, 145, L"��ȷ��");
////		outdoublexy(WIDTH - 80, 170, L"%.1f %%", s);
////
////		// �Ҳ�����ٶȵļ���
////		outtextxy(WIDTH - 90, 205, L"�����ٶ�");
////		outintxy(WIDTH - 80, 230, L"%d kpm", v);
////
////		// �Ҳ�����ĵ���ʱ
////		outtextxy(WIDTH - 90, 265, L"����ʱ");
////		outintxy(WIDTH - 80, 290, L"%d s", gameclock.Now());
////
////		FlushBatchDraw();
////
////		Sleep(20);
////	}
////}
////
//// ������
////int main()
////{
////	srand((unsigned)time(NULL));
////	initgraph(WIDTH, HEIGHT);
////
////	BeginBatchDraw();
////
////	while (true)
////	{
////		Game();
////
////		// ��ʾ��Ϸ����
////		setfillcolor(RGB(200, 200, 200));
////		solidrectangle(150, 200, 450, 300);
////		settextcolor(BLACK);
////		outtextxy(220, 225, L"���¿�ʼ�밴 �ո�");
////		outtextxy(220, 255, L"�˳���Ϸ�밴 Esc");
////		FlushBatchDraw();
////
////		// ʵ�ְ��ո��������� ESC �˳�
////		wchar_t ch = 0;
////		while (ch != 27 && ch != ' ')
////			ch = _getwch();
////
////		if (ch == 27)
////			break;
////	}
////
////	EndBatchDraw();
////
////	closegraph();
////	return 0;
////}
//
//IMAGE img_background; // ���򱳾�ͼƬ
//DWORD cursor_a, cursor_b; // ����ϵͳʱ�����
//char input_text[45]; // �û�������ַ���
//int text_length; // �û������ַ����ĳ���// ���������͹��
//void DrawInputBox(int width_a, int high_a, int width_b, int high_b)
//{
//	setfillcolor(RGB(255, 255, 255)); // �����������ɫ
//	solidrectangle(width_a, high_a, width_b, high_b);
//	LOGFONT f;
//	gettextstyle(&f); // ��ȡ��ǰ��������
//	f.lfHeight = 44; // ��������߶�Ϊ 44
//	_tcscpy_s(f.lfFaceName, _T("����")); // ��������Ϊ����
//	f.lfQuality = ANTIALIASED_QUALITY; // �������Ч�������
//	settextstyle(&f); // ����������ʽ
//	char baidu_text[20] = "Baidu �ٶ�";
//	setbkmode(TRANSPARENT);
//	settextcolor(RGB(255, 255, 255)); // ����������ɫ
//	outtextxy(width_a + (width_b - width_a) / 2 - textwidth(baidu_text) / 2, high_a - 46, baidu_text);
//	settextstyle(30, 0, "����");
//	settextcolor(RGB(0, 0, 0)); // ����������ɫ
//	outtextxy(width_a + 30, high_a + ((high_b - high_a) / 2 - 15), input_text);// ����û�������ַ���
//
//	// ���ƹ��
//	setlinecolor(RGB(0, 0, 0)); // ���ù����ɫ
//	cursor_b = GetTickCount(); // �ڶ��λ�ȡϵͳʱ��
//	int cursor_width = width_a + 30 + textwidth(input_text);// ���ù�������
//	int cursor_frequency = cursor_b - cursor_a; // ������Ƶ��
//	if (cursor_frequency <= 200 || cursor_frequency >= 700) // �ж��Ƿ���ʾ���
//	{
//		line(cursor_width, high_a + 5, cursor_width, high_b - 5);
//	}
//	if (cursor_frequency >= 900) // �ж��Ƿ���»�ȡ��ϵͳʱ��
//	{
//		cursor_a = cursor_b;
//	}
//}
//
//
//// �����ɾ���ַ�
//void AddDeleteCharacter(char c)
//{
//	if (c != 8) // �ж������Ƿ�ΪBACK��
//	{
//		if (c == 27) // �ж������Ƿ�ΪESC��
//		{
//			EndBatchDraw(); // ������ͼ
//			closegraph(); // �رջ�ͼ����
//			exit(0); // �˳�����
//		}
//		if (text_length < 44)
//		{
//			input_text[text_length] = c;
//			input_text[text_length + 1] = '\0';
//			text_length++;
//		}
//	}
//	else
//	{
//		if (text_length > 0)
//		{
//			text_length--;
//			input_text[text_length] = '\0';
//		}
//	}
//}// ��ȡ�û�����
//char GetInput()
//{
//	char c = 0;
//	if (_kbhit())
//	{
//		c = _getwch();
//	}
//	return c;
//}
//int main()
//{
//	initgraph(800, 480);
//	loadimage(&img_background, ".\\IMAGES\\Exit\\Exit000.png", GIW_WIDTH, GIW_HIGH);
//	BeginBatchDraw(); // ��ʼ��ͼ
//	input_text[0] = '\0';
//	text_length = 0;
//	cursor_a = GetTickCount(); // ��һ�λ�ȡϵͳʱ��
//	char key; // �û������Ӣ�� while (true)
//	{
//
//		key = GetInput();
//		if (key != 0)
//		{
//			AddDeleteCharacter(key);
//		}
//		cleardevice(); // �����Ļ
//		putimage(0, 0, &img_background);
//		DrawInputBox(100, 200, 700, 240);
//		FlushBatchDraw();
//	}
//	_getch();
//
//	closegraph();
//	return 0;
//}
//
