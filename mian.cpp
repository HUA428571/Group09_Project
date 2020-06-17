#include<iostream>
#include<string>
#include<vector>
#include<easyx.h>
#include<graphics.h>      // 引用图形库头文件
#include<conio.h>
#include"mian.h"
using namespace std;
int HOMEpage(Passenger* P, The_users* users, int id)
{

	return 0;
}
int  OrderMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, int id)
{
	int SearchCount = 0;
	SearchCount = FindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	int* flyday = FO->flyday;
	int* SearchReasult = FO->flight;
	int x = C_PrintMultiFlight(ID, FO, IDcount, SearchReasult, SearchCount, flyday);
	return x;
}
int  BookingMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, bookiinginformation custom, int id)
{
	int SearchCount = 0;
	SearchCount = Searching(ID, DATA, custom, IDcount);
	int* SearchReasult = custom.flynumber;
	int* flyday = &custom.flyday;
	int x = b_printmultiflight(ID, DATA, P, users, IDcount, SearchReasult, SearchCount, flyday, id);
	return x;
}
int  Refunding_ChngeMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, int id)
{
	int SearchCount = 0;
	SearchCount = REFindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	int* flyday = FO->flyday;
	int* SearchReasult = FO->flight;
	int x = c_printmultiflight(ID, DATA, FO, P, users, IDcount, SearchReasult, SearchCount, flyday, id);
	return x;
}
void SignOutMENU()
{

}
void CustomMenu(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, bookiinginformation custom, int id)
{
	initgraph(1280, 720);	// 创建绘图窗口，大小为 1280x720 像素
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Bacgr.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	int MENUchoice;
	MENUchoice = CustomMENU_MENUChoose();
	while (true)											//循环
	{
		switch (MENUchoice)
		{
		case 0://主页
			MENUchoice = HOMEpage(P, users, id);
			break;
		case 1://历史订单
			MENUchoice = OrderMENU(ID, DATA, IDcount, P, users, FO, id);
			break;
		case 2://订票
			MENUchoice = BookingMENU(ID, DATA, IDcount, P, users, custom, id);
			break;
		case 3://退改签
			MENUchoice = Refunding_ChngeMENU(ID, DATA, IDcount, P, users, FO, id);
			break;
		case 4://退出登录
			SignOutMENU();
			break;
		}
	}
}