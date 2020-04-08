#include"notes.h"
#include<iostream>
#include<graphics.h>
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include<string>
using namespace std;
int AdminMENU(FlightID*, FlightTicket[][999], int&);
int AdminMENU_MainMENU(FlightID* ID, int IDcount);
int AdminMENU_SearchMENU(FlightID* ID, int IDcount);
int AdminMENU_AddMENU(FlightID* ID, int IDcount);
int AdminMENU_DeleteMENU(FlightID* ID, int IDcount);
int AdminMENU_ChangeMENU(FlightID* ID, int IDcount);

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
	// 设置背景色为蓝色
	setbkcolor(RGB(255, 255, 253));
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	//settextstyle(20, 0, _T("等线"));
	//char s2[] = "欢迎访问管理员后台";
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
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
	loadimage(&BG, _T(".\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	int MENUchoice;
	MENUchoice=AdminMENU_MainMENU(ID, IDcount);
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
			MENUchoice=AdminMENU_MainMENU(ID, IDcount);
			break;
		case 1:
			MENUchoice = AdminMENU_SearchMENU(ID, IDcount);
			break;
		case 2:
			MENUchoice = AdminMENU_AddMENU(ID,IDcount);
			break;
		case 3:
			MENUchoice = AdminMENU_DeleteMENU(ID,IDcount);
				break;
		case 4:
			MENUchoice = AdminMENU_ChangeMENU(ID,IDcount);
				break;


		}
	}

	//LOGFONT f;
	//gettextstyle(&f);						// 获取当前字体设置
	//f.lfHeight = 48;						// 设置字体高度为 48
	//_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	//f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	//settextstyle(&f);						// 设置字体样式
	//outtextxy(0, 50, _T("抗锯齿效果"));

	//clearroundrect

	//char s[10];
	//InputBox(s, 10, "请输入半径");	// 将用户输入转换为数字
	//int r;
	//sscanf(s, "%d", &r);
	//settextstyle(16, 0, _T("Consolas"));
	//char s2[] = "Hello World";
	//outtextxy(10, 20, s2);
	//setfillcolor(BLUE);
	//fillcircle(320, 240, r);// 画圆
	_getch();
	closegraph();			// 关闭绘图窗口
	return 0;
}

int AdminMENU_MainMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	char count[4];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(240, 200, "当前数据库中有");
	outtextxy(240, 230, count);
	outtextxy(292, 230, "个航线数据");
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
		//switch (m.uMsg)
		//{
		//case WM_LBUTTONDOWN://左键被按下
		//	// 鼠标移动的时候画红色的小点
		//	putpixel(m.x, m.y, RED);
		//	break;

		//case WM_LBUTTONDOWN:
		//	// 如果点左键的同时按下了 Ctrl 键
		//	if (m.mkCtrl)
		//		// 画一个大方块
		//		rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
		//	else
		//		// 画一个小方块
		//		rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
		//	break;

		//case WM_RBUTTONUP:
		//	return 0;	// 按鼠标右键退出程序
	}
	_getch();
}
int AdminMENU_SearchMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	char count[4];
	_stprintf(count, _T("%d"), IDcount);
	for (int i = 0; i < 100; i++)
	{
		outtextxy(240-i, 200, "当前数据库中有");
		outtextxy(240-i, 230, count);
		outtextxy(292-i, 230, "个航线数据");
		Sleep(5);
	}
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
int AdminMENU_AddMENU(FlightID* ID, int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
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
	loadimage(&BG, _T(".\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
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
	loadimage(&BG, _T(".\\BlackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
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
