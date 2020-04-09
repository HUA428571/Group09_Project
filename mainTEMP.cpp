#pragma once
#include"notes.h"
#include"print.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// 引用图形库头文件
#include<conio.h>
#include<string>
#include<stdlib.h>

//#include"easyXclass.cpp"
using namespace std;
int AdminMENU(FlightID*, FlightTicket[][999], int&);
int AdminMENU_MainMENU(FlightID* ID, int IDcount);
int AdminMENU_SearchMENU(FlightID* ID, int IDcount);
int AdminMENU_AddMENU(FlightID* ID, int IDcount);
int AdminMENU_DeleteMENU(FlightID* ID, int IDcount);
int AdminMENU_ChangeMENU(FlightID* ID, int IDcount);
int AdminMENU_ChooseMENU();
int AdminMENU_SearchMENU_ChooseMENU();
int AdminMENU_SearchMENU_SearchByID(FlightID*, int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID*, int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID*, int IDcount, int* SearchReasult, int& SearchCount);

char Input();

int main()
{
	//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[999];//默认最多存储999个航线 全局变量所有函数均可访问
	static FlightTicket DATA[366][999];//存储一年的航班数
	int FlightID_Count = 0;//存储当前航班号个数
	FlightID_Count = ImportFlightDatabase(ID);
	//int SearchReasult[999];//用于存储搜索结果
		//int SearchCount = 0;//存储搜索结果数
		//int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。
		//以下都是测试用的临时代码
	AdminMENU(ID, DATA, FlightID_Count);
	return 0;
}

int AdminMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)

{
	int SearchReasult[999];//用于存储搜索结果
	int SearchCount = 0;//存储搜索结果数
	int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。

	initgraph(1280, 720);	// 创建绘图窗口，大小为 1280x720 像素
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	//settextstyle(20, 0, _T("等线"));
	//char s2[] = "欢迎访问管理员后台";
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	outtextxy(20, 20, "你好！");
	Sleep(500);
	cleardevice();
	outtextxy(20, 20, "欢迎访问管理员后台管理系统");
	Sleep(1000);
	cleardevice();
	outtextxy(20, 20, "版权所有 CopyRight 2020 HuaCL");
	Sleep(1000);
	cleardevice();
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	int MENUchoice;
	MENUchoice = AdminMENU_MainMENU(ID, IDcount);			//先进入主页
	while (true)											//循环
	{
		switch (MENUchoice)
		{
		case 0:
			MENUchoice = AdminMENU_MainMENU(ID, IDcount);
			break;
		case 1:
			MENUchoice = AdminMENU_SearchMENU(ID, IDcount);
			break;
		case 2:
			MENUchoice = AdminMENU_AddMENU(ID, IDcount);
			break;
		case 3:
			MENUchoice = AdminMENU_DeleteMENU(ID, IDcount);
			break;
		case 4:
			MENUchoice = AdminMENU_ChangeMENU(ID, IDcount);
			break;
		}
	}
	closegraph();			// 关闭绘图窗口
	return 0;
}

int AdminMENU_MainMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	char count[4];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(240, 200, "当前数据库中有");
	outtextxy(240, 230, count);
	outtextxy(292, 230, "个航线数据");
	return AdminMENU_ChooseMENU();
}
int AdminMENU_SearchMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);						// 显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[4];
	_stprintf(count, _T("%d"), IDcount);
	//过渡动画，最后再写
	//for (int i = 0; i < =100; i++)
	//{
	//	outtextxy(240 - i, 200, "当前数据库中有");
	//	outtextxy(240 - i, 230, count);
	//	outtextxy(292 - i, 230, "个航线数据");
	//	Sleep(5);
	//}
	//Sleep(100);
	loadimage(&BG, _T(".\\IMAGES\\Search.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	outtextxy(140, 200, "当前数据库中有");
	outtextxy(140, 230, count);
	outtextxy(192, 230, "个航线数据");

	//setlinecolor(BLACK);
	//fillrectangle(140, 270, 320, 310);
	//fillrectangle(140, 320, 320, 360);
	//fillrectangle(140, 370, 320, 410);
	//fillrectangle(140, 420, 320, 460);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	int SearchReasult[999];//用于存储搜索结果
	int SearchCount = 0;
	int MENUchoice = AdminMENU_SearchMENU_ChooseMENU();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 11:
			MENUchoice = AdminMENU_SearchMENU_SearchByID(ID,IDcount,SearchReasult,SearchCount);
			break;
		case 12:
			MENUchoice = AdminMENU_SearchMENU_SearchByDepartureAirport(ID, IDcount, SearchReasult, SearchCount);
			break;
		case 13:
			MENUchoice = AdminMENU_SearchMENU_SearchByArrivalAirport(ID, IDcount, SearchReasult, SearchCount);
			break;
		}
	}
	//存储搜索结果数
	//TextBox textbox(140,260,340,290,50);
	//char UserInput;
	//char search[12];
	//while (true)
	//{
	//	UserInput = Input();
	//	int i = 0;
	//	if (UserInput != 0)
	//	{
	//		textbox.Append(UserInput);
		//		if (UserInput != 8)
	//		{
	//			search[i] = UserInput;
	//			i++;
	//		}
		//		//// 判断输入的字符串是否与掉落的字符串相等
	//		//for (int i = 0; i < 3; i++)
	//		//	if (wcscmp(textbox.Text(), words[i].p) == 0)
	//		//	{
	//		//		InitTarget(words, i);
	//		//		textbox.Empty();
	//		//	}
	//	}
	//	textbox.Draw();
	//}
}
int AdminMENU_AddMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	outtextxy(240, 200, "添加");
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在更改区域
				return 4;
		}
	}
	_getch();
}
int AdminMENU_DeleteMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	outtextxy(240, 200, "删除");
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在更改区域
				return 4;
		}
	}
	_getch();
}
int AdminMENU_ChangeMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	outtextxy(240, 200, "更改");
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在更改区域
				return 4;
		}
	}
	_getch();
}
int AdminMENU_ChooseMENU()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在更改区域
				return 4;
		}
	}
}
int AdminMENU_SearchMENU_ChooseMENU()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在更改区域
				return 4;
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//鼠标按在按降落地搜索区域
				return 13;
		}
	}
}
int AdminMENU_SearchMENU_SearchByID(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char search[12];
	InputBox(search, 12, "请输入你想查询的航班号");
	SearchFlightID(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintSingleFlight(ID, IDcount, SearchReasult[0]);
		break;
	default:
		PrintMultiFlight(ID, IDcount, SearchReasult, SearchCount);
		break;
	}
	return AdminMENU_SearchMENU_ChooseMENU();
}
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char search[12];
	InputBox(search, 12, "请输入你想查询航班的起飞地");
	SearchFlightDepartureAirport(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintSingleFlight(ID, IDcount, SearchReasult[0]);
		break;
	default:
		PrintMultiFlight(ID, IDcount, SearchReasult, SearchCount);
		break;
	}
	return AdminMENU_SearchMENU_ChooseMENU();
}
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID*ID, int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char search[12];
	InputBox(search, 12, "请输入你想查询航班的降落地");
	SearchFlightArrivalAirport(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintSingleFlight(ID, IDcount, SearchReasult[0]);
		break;
	default:
		PrintMultiFlight(ID, IDcount, SearchReasult, SearchCount);
		break;
	}
	return AdminMENU_SearchMENU_ChooseMENU();
}


char Input()
{
	char c = 0;

	if (_kbhit())
	{
		c = _getwch();
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) && c != 8)
			c = 0;
	}
	return c;
}

//void InputBox()
//{
//
//	static int fps = 0;				// 统计字母个数计算光标位置
//	int		m_x1 = 140, m_y1 = 260, m_x2 = 340, m_y2 = 290;
//	// 设置文字输出样式
//	settextstyle(20, 0, "Verdana");
//
//	// 画边框
//	setlinecolor(WHITE);
//	rectangle(m_x1, m_y1, m_x2, m_y2);
//
//	// 输出用户输入的字符串
//	outtextxy(m_x1 + 30, m_y1 + (m_y2 - m_y1 - 20) / 2, m_text);
//	// 绘制光标 
//	fps++;
//	if (fps < (m_fps / 4))
//	{
//		setlinecolor(WHITE);
//		int sx = m_x1 + 31 + textwidth(m_text);
//		line(sx, m_y1 + (m_y2 - m_y1 - 20) / 2, sx, m_y1 + (m_y2 - m_y1 - 20) / 2 + 20);
//	}
//	else if (fps > (m_fps / 2))
//		fps = 0;
//
//}