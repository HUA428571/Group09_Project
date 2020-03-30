#include"notes.h"
#include<iostream>
using namespace std;
int main()
{
	static FlightID ID[999];//默认最多存储999个航线 全局变量所有函数均可访问
	static FlightTicket DATA[366][999];//存储一年的航班数据
	int FlightID_Count = 0;//存储当前航班号个数
	FlightID_Count = ImportFlightDatabase(ID);
	PrintFlightTitle();
	for (int i = 0; i < 10; i++)
	{
		PrintFlight(ID,i,i+1);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<JudgeAircraftSize(ID, i) << endl;
	}
	cout << "请输入你要查询的航班号" << endl;
	char search[10];
	int result;
	cin >> search;
	result=SearchFlightID(ID, search, FlightID_Count);
	PrintFlight(ID, result, 1);
	return 0;
}