#include"notes.h"
#include<iostream>
using namespace std;
int main()
{
	//���е�XXcount���Ǹ��������Ƕ�Ӧ�±꣡�±�Ҫ��һ
	static FlightID ID[999];//Ĭ�����洢999������ ȫ�ֱ������к������ɷ���
	static FlightTicket DATA[366][999];//�洢һ��ĺ�����
	int FlightID_Count = 0;//�洢��ǰ����Ÿ���
	int SearchReasult[999];//���ڴ洢�������
	int SearchCount=0;//�洢���������
	int SortReasult[999];//���ڴ洢������˳�������Ͳ������ԭ�еĽṹ������˳�򣬲�Ӱ���±���ʡ�
	
	//���¶��ǲ����õ���ʱ����
	
	FlightID_Count = ImportFlightDatabase(ID);
	PrintFlightTitle();
	for (int i = 0; i < 10; i++)
	{
		PrintFlight(ID, i, i + 1);
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << JudgeAircraftSize(ID, i) << endl;
	}
	cout << "��������Ҫ��ѯ�ĺ����" << endl;
	char search[10];
	int result;
	cin >> search;
	SearchFlightID(ID, search, FlightID_Count, SearchReasult, SearchCount);//���Һ���ţ����ز��ҵ��������	
	result = PrintSearch(ID, FlightID_Count, SearchReasult, SearchCount);
	PrintFlight(ID, result, 1);
	NewFlight(ID, FlightID_Count);
	NewFlight(ID, FlightID_Count);
	NewFlight(ID, FlightID_Count);
	PrintFlightTitle();
	for (int i = FlightID_Count-1, i2 = 1; i > 200; i--)
	{
		PrintFlight(ID, i, i2);

		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t" << JudgeAircraftSize(ID, i) << endl;
		i2++;
	}

	return 0;
}