#include"notes.h"
#include<iostream>
using namespace std;
int main()
{
	static FlightID ID[999];//Ĭ�����洢999������ ȫ�ֱ������к������ɷ���
	static FlightTicket DATA[366][999];//�洢һ��ĺ�������
	int FlightID_Count = 0;//�洢��ǰ����Ÿ���
	FlightID_Count = ImportFlightDatabase(ID);
	PrintFlightTitle();
	for (int i = 0; i < 10; i++)
	{
		PrintFlight(ID,i,i+1);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t"<<JudgeAircraftSize(ID, i) << endl;
	}
	cout << "��������Ҫ��ѯ�ĺ����" << endl;
	char search[10];
	int result;
	cin >> search;
	result=SearchFlightID(ID, search, FlightID_Count);
	PrintFlight(ID, result, 1);
	return 0;
}