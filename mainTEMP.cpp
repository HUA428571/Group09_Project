#pragma once
#define BUFF_LEN 11 // 12 may fix the Run-Time Check Failure #2 
#include"notes.h"
#include"print.h"
#include"AdminMENU.h"
//#include"easyXclass.cpp"
using namespace std;
//管理员菜单界面

//char Input();

int main()
{

	//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[699];//默认最多存储999个航线
	static FlightTicket DATA[366][699];//存储一年的航班数
	int FlightID_Count = 0;//存储当前航班号个数
	int fail = 0;
	char choice;
	do {
		cout << "导入默认数据(1)/上次保存数据(2)/不导入(N)？" << endl;
		cin >> choice;
	} while (choice != '1' && choice != '2' && choice != 'n' && choice != 'N');
	if (choice == '1' || choice == '2')
	{
		char FlightLocation[50];
		char TicketLication[50];
		if (choice == '1')
		{
			strcpy(FlightLocation, ".\\Default_FlightID_Database_NEW.txt");
			strcpy(TicketLication, ".\\Default_Ticket_Database.dat");
		}
		else
		{
			strcpy(FlightLocation, ".\\FlightID.txt");
			strcpy(TicketLication, ".\\Ticket.dat");
		}
		FlightID_Count = ImportFlightDatabase(ID, FlightLocation);
		fail=ImportTicketDatabase(DATA, FlightID_Count, TicketLication);
	}
	if (FlightID_Count == -1||fail==-1)
	{
		cout << "无法打开默认数据库文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	cout << "成功导入" << FlightID_Count << "个航线数据！" << endl;
	//int SearchReasult[999];//用于存储搜索结果
		//int SearchCount = 0;//存储搜索结果数
		//int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。

	//cout << sizeof(DATA) << endl;

	AdminMENU(ID, DATA, FlightID_Count);

	//for (int i1 = 0; i1 < FlightID_Count; i1++)
	//{
	//	for (int i2 = 0; i2 < 366; i2++)
	//	{
	//		DATA[i2][i1].ActuralArrivalTime = ID[i1].ArrivalTime;
	//		DATA[i2][i1].ActuralDepartureTime = ID[i1].DepartureTime;
	//		if (JudgeAircraftSize(ID, i1) == 2)
	//		{
	//			DATA[i2][i1].BusinessClassTicketRemain = 36;
	//			DATA[i2][i1].EconomyClassTicketRemain = 400;
	//			DATA[i2][i1].FirstClassTicketRemain = 8;
	//		}
	//		else
	//		{
	//			DATA[i2][i1].BusinessClassTicketRemain = 8;
	//			DATA[i2][i1].EconomyClassTicketRemain = 180;
	//			DATA[i2][i1].FirstClassTicketRemain = 0;
	//		}
	//	}
	//}
	//char Location[50];
	//strcpy(Location, ".\\Default_Ticket_Database.dat");
	//SaveTicketDatabase(DATA, FlightID_Count, Location);


	return 0;
}

//char Input()
//{
//	char c = 0;
//
//	if (_kbhit())
//	{
//		c = _getwch();
//		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) && c != 8)
//			c = 0;
//	}
//	return c;
//}
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
