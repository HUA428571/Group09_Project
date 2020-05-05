#pragma once
//#define BUFF_LEN 11 // 12 may fix the Run-Time Check Failure #2 
#include"notes.h"
#include"print.h"
#include"AdminMENU.h"
using namespace std;
//管理员菜单界面

int main()
{

	//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[999];//默认最多存储999个航线
	static FlightTicket DATA[366][999];//存储一年的航班数
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
		fail = ImportTicketDatabase(DATA, FlightID_Count, TicketLication);
	}
	if (FlightID_Count == -1 || fail == -1)
	{
		cout << "无法打开默认数据库文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	cout << "成功导入" << FlightID_Count << "个航线数据！" << endl;

	AdminMENU(ID, DATA, FlightID_Count);

	return 0;
}
