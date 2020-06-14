锘�#pragma once
#include"notes.h"
#include"print.h"
#include <stdlib.h>
#include"AdminMENU.h"
using namespace std;
//绠＄悊鍛樿彍鍗曠晫闈�

int main()
{

	//鎵�鏈夌殑XXcount閮芥槸涓暟锛屼笉鏄搴斾笅鏍囷紒涓嬫爣瑕佸噺涓�
	static FlightID ID[999];//榛樿鏈�澶氬瓨鍌�999涓埅绾�
	static FlightTicket DATA[366][999];//瀛樺偍涓�骞寸殑鑸彮鏁�
	int FlightID_Count = 0;//瀛樺偍褰撳墠鑸彮鍙蜂釜鏁�
	int fail = 0;
	char choice;
	do {
		cout << "瀵煎叆榛樿鏁版嵁(1)/涓婃淇濆瓨鏁版嵁(2)/涓嶅鍏�(N)锛�" << endl;
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
		cout << "鏃犳硶鎵撳紑榛樿鏁版嵁搴撴枃浠讹紒绋嬪簭姝ｅ湪閫�鍑�" << endl;
		Sleep(1000);
		exit(1);
	}
	cout << "鎴愬姛瀵煎叆" << FlightID_Count << "涓埅绾挎暟鎹紒" << endl;


	//cout << sizeof(DATA) << endl;


	AdminMENU(ID, DATA, FlightID_Count);

	//srand(time(NULL));
	//for (int i1 = 0; i1 < FlightID_Count; i1++)
	//{
	//	for (int i2 = 0; i2 < 366; i2++)
	//	{
	//		int rnd1 = rand() % 30;
	//		int rnd2 = rand() % 30;
	//		if (rnd1 == rnd2)//涓浜嗭紒鍙栨秷浣�
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
	//strcpy(Location, ".\\Default_Ticket_Database.dat");
	//SaveTicketDatabase(DATA, FlightID_Count, Location);
	//return 0;
}