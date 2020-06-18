#pragma once
#include"notes.h"
#include"print.h"
#include"AdminMENU.h"
#include"StartMENU.h"
#include <stdlib.h>
#include"mian.h"
using namespace std;
//主函数
int main()
{
	static users u[999];
	static Passenger p[999];
	static FlyhistoryAndOrder FOL[100];
	static bookiinginformation custom;
	//所有的XXcount都是个数，不是对应下标！下标要减一
	static FlightID ID[999];//默认最多存储999个航线
	static FlightTicket DATA[366][999];//存储一年的航班数
	int FlightID_Count = 0;//存储当前航班号个数
	int fail = 0;
	fail = ImportUserDatabase(u, p);
	if (fail == -1)
	{
		cout << "无法打开用户数据文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	else
	{
		cout << "成功导入用户数据！" << endl;
	}
	char choice;
	do {
		cout << "导入默认航线航班数据(1)/上次保存的航线航班数据(2)？" << endl;
		cin >> choice;
	} while (choice != '1' && choice != '2');
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
	if (FlightID_Count == -1)
	{
		cout << "无法打开默认航线数据库文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	else
	{
		cout << "成功导入" << FlightID_Count << "个航线数据！" << endl;
	}
	if (fail == -1)
	{
		cout << "无法打开默认机票数据库文件！程序正在退出" << endl;
		Sleep(1000);
		exit(1);
	}
	else
	{
		cout << "成功导入机票数据！" << endl;
	}
	cout << "正在进入系统..." << endl;
	Sleep(500);

	//cout << sizeof(DATA) << endl;
	//int Choice = StartMENU(u, p);
	//if (Choice == 0)
	//AdminMENU(ID, DATA, FlightID_Count);
	//else
	int id = 1;
	u[1].p[0] =1;
	u[1].p[1] =2;
	u[1].p[2] =3;
	u[1].p[3] =4;
	u[1].p[4] = 5;
	strcpy(u[1].id, "huacl");
	strcpy(u[1].pwd, "huacl");
	strcpy(u[1].phone, "17601551978");
	u[1].identify = 'm';
	u[1].Credibility = 2000;
	strcpy(p[1].id, "Huacl");
	strcpy(p[1].name, "华文嘉");
	strcpy(p[1].IdCard, "xxxxxxxxxxxxxxx");
	strcpy(p[1].TelNum, "17601551978");
	strcpy(p[2].id, "Huacl");
	strcpy(p[2].name, "雷尚远");
	strcpy(p[2].IdCard, "xxxxxxxxxxxxxxx");
	strcpy(p[2].TelNum, "18851986021");
	strcpy(p[3].id, "Huacl");
	strcpy(p[3].name, "汤艺林");
	strcpy(p[3].IdCard, "xxxxxxxxxxxxxxx");
	strcpy(p[3].TelNum, "xxxxxxxxxxx");
	strcpy(p[4].id, "Huacl");
	strcpy(p[4].name, "小明");
	strcpy(p[4].IdCard, "xxxxxxxxxxxxxxx");
	strcpy(p[4].TelNum, "xxxxxxxxxxx");
	strcpy(p[5].id, "Huacl");
	strcpy(p[5].name, "小红");
	strcpy(p[5].IdCard, "xxxxxxxxxxxxxxx");
	strcpy(p[5].TelNum, "xxxxxxxxxxx");
	CustomMenu(ID, DATA, FlightID_Count, p, u, FOL, &custom, id);

		;

	//srand(time(NULL));
	//for (int i1 = 0; i1 < FlightID_Count; i1++)
	//{
	//	for (int i2 = 0; i2 < 366; i2++)
	//	{
	//		int rnd1 = rand() % 30;
	//		int rnd2 = rand() % 30;
	//		if (rnd1 == rnd2)//中奖了！取消你
	//		{
	//			DATA[i2][i1].ActuralArrivalTime = 2500;
	//			DATA[i2][i1].ActuralDepartureTime = 2500;
	//		}
	//		else
	//		{
	//			if (ID[i1].TravelTimeHour < 3)
	//			{
	//				rnd1 = rand() % 61 - 30;
	//				rnd2 = rand() % 21 - 10;
	//				DATA[i2][i1].ActuralDepartureTime = ID[i1].DepartureTime + rnd1;
	//				if (DATA[i2][i1].ActuralDepartureTime % 100 >= 60)
	//					DATA[i2][i1].ActuralDepartureTime += 40;
	//				if (DATA[i2][i1].ActuralDepartureTime < 0)
	//					DATA[i2][i1].ActuralDepartureTime += 2400;
	//				DATA[i2][i1].ActuralArrivalTime = ID[i1].ArrivalTime + rnd1 + rnd2;
	//				if (DATA[i2][i1].ActuralArrivalTime % 100 >= 60)
	//					DATA[i2][i1].ActuralArrivalTime += 40;
	//				if (DATA[i2][i1].ActuralArrivalTime < 0)
	//					DATA[i2][i1].ActuralArrivalTime += 2400;
	//			}
	//			else
	//			{
	//				if (ID[i1].TravelTimeHour < 6)
	//				{
	//					rnd1 = rand() % 121 - 60;
	//					rnd2 = rand() % 41 - 20;
	//					DATA[i2][i1].ActuralDepartureTime = ID[i1].DepartureTime + rnd1 ;
	//					if (DATA[i2][i1].ActuralDepartureTime % 100 >= 60)
	//						DATA[i2][i1].ActuralDepartureTime += 40;
	//					if (DATA[i2][i1].ActuralDepartureTime < 0)
	//						DATA[i2][i1].ActuralDepartureTime += 2400;
	//					DATA[i2][i1].ActuralArrivalTime = ID[i1].ArrivalTime + rnd1 + rnd2;
	//					if (DATA[i2][i1].ActuralArrivalTime % 100 >= 60)
	//						DATA[i2][i1].ActuralArrivalTime += 40;
	//					if (DATA[i2][i1].ActuralArrivalTime < 0)
	//						DATA[i2][i1].ActuralArrivalTime += 2400;
	//				}
	//				else
	//				{
	//					rnd1 = rand() % 241 - 120;
	//					rnd2 = rand() % 81 - 40;
	//					DATA[i2][i1].ActuralDepartureTime = ID[i1].DepartureTime + rnd1;
	//					if (DATA[i2][i1].ActuralDepartureTime % 100 >= 60)
	//						DATA[i2][i1].ActuralDepartureTime += 40;
	//					if (DATA[i2][i1].ActuralDepartureTime < 0)
	//						DATA[i2][i1].ActuralDepartureTime += 2400;
	//					DATA[i2][i1].ActuralArrivalTime = ID[i1].ArrivalTime + rnd1 + rnd2;
	//					if (DATA[i2][i1].ActuralArrivalTime % 100 >= 60)
	//						DATA[i2][i1].ActuralArrivalTime += 40;
	//					if (DATA[i2][i1].ActuralArrivalTime < 0)
	//						DATA[i2][i1].ActuralArrivalTime += 2400;
	//				}
	//			}
	//		}
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
	//strcpy(Location, ".\\Default_Ticket_Database_20.dat");
	//SaveTicketDatabase(DATA, FlightID_Count, Location);
	return 0;
}
