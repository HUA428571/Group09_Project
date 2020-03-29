#include<iostream>
#include<stdio.h>
#include"struct.h"
using namespace std;

int WeekDayTransfer(int year, int month, int day)//ʹ�ò��չ�ʽת������������
{
	int week = 0;
	int century = year / 100;//ע�����ʵ��������ݵ�ǰ��λ������������
	year = year % 100;//��ݵĺ���λ
	if (month == 1 || month == 2)//�·ݵķ�ΧΪ3-14������1��2�±����13��14��
	{
		month += 12;
		year--;
	}
	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
	week = week % 7;
	return (week >= 0) ? week : (7 + week);
}

int DateTransfer(int year, int month ,int day)//�������ڶ�Ӧ����
{
	int daycount=0;
	if (year % 4 == 0 && year % 100 != 0)
		daycount++;
	switch (month)
	{
	case 12:
		daycount += 30;
	case 11:
		daycount += 31;
	case 10:
		daycount += 30;
	case 9:
		daycount += 31;
	case 8:
		daycount += 31;
	case 7:
		daycount += 30;
	case 6:
		daycount += 31;
	case 5:
		daycount += 30;
	case 4:
		daycount += 31;
	case 3:
		daycount += 28;
	case 2:
		daycount += 31;
		daycount += day;
	break;
	}
	return daycount;
}

int ImportFlightDatabase(FlightID* ID)//�����ڿ�ͷѯ���Ƿ�Ҫ�������к������ݿ�,�������ض�ȡ�������
{
	char choice;
	do {
		cout << "����Ĭ�Ϻ�������ݣ�" << endl;
		cin >> choice;
	} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	if (choice == 'y' || choice == 'Y')
	{
		FILE* fp;
		if ((fp = fopen(".\\Default_FlightID_Database_2.txt", "r")) == NULL)
		{
			printf("Fail to open file!\n");
			return 0;
		}
		int FlightIDcount = 0;
		char c;
		while (!feof(fp))
		{
			int i = 1;
			while ((c = fgetc(fp)) != ',')//��ȡ����
			{
				ID[FlightIDcount].FlyDay[i] = c;
				i++;
			}
			i = 0;
			while ((c = fgetc(fp)) != ',')//��ȡ��������
			{
				ID[FlightIDcount].DepartureAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].DepartureAirport[i] = '\0';//�ַ�����β
			fscanf_s(fp, "%d", &ID[FlightIDcount].DepartureTime);//��ȡ����ʱ��
			fgetc(fp);
			fscanf_s(fp, "%d", &ID[FlightIDcount].ArrivalTime);//��ȡ����ʱ��
			i = 0;
			fgetc(fp);
			while ((c = fgetc(fp)) != ',')//��ȡ�������
			{
				ID[FlightIDcount].ArrivalAirport[i] = c;
				i++;
			}
			ID[FlightIDcount].ArrivalAirport[i] = '\0';//�ַ�����β
			i = 0;
			while (i < 2)//��ȡ���չ�˾
			{
				c = fgetc(fp);
				ID[FlightIDcount].Carrier[i] = c;
				i++;
			}
			ID[FlightIDcount].Carrier[i] = '\0';//�ַ�����β
			i = 0;
			while ((c = fgetc(fp)) != ',')//��ȡ�����
			{
				ID[FlightIDcount].ID[i] = c;
				i++;
			}
			ID[FlightIDcount].ID[i] = '\0';//�ַ�����β
			i = 0;
			while ((c = fgetc(fp)) != ',')//��ȡ����
			{
				ID[FlightIDcount].AircraftType[i] = c;
				i++;
			}
			ID[FlightIDcount].AircraftType[i] = '\0';//�ַ�����β
			i = 0;
			while (((c = fgetc(fp)) != ','))//��ȡ��λ
			{
				ID[FlightIDcount].Class[i] = c;
				i++;
			}
			ID[FlightIDcount].Class[i] = '\0';//�ַ�����β
			fscanf_s(fp, "%d", &ID[FlightIDcount].TravelTimeHour);//��ȡ����ʱ��
			c=fgetc(fp);//��ȡð��
			fscanf_s(fp, "%2d", &ID[FlightIDcount].TravelTimeMinute);
			FlightIDcount++;
			if ((c = fgetc(fp)) == EOF)break;
		}
		fclose(fp);
		cout << "�ɹ�����" << FlightIDcount << "���������ݣ�" << endl;
		return FlightIDcount;
	}
	if (choice == 'n' || choice == 'N')
	{
		return 0;
	}
}

void PrintFlightTitle()//��ӡ������
{
	printf("���\t�����\t\t���ʱ��\t��ɻ���\t�������\t����ʱ��\t����ʱ��\tִ�ɻ���\n");
	return;
}

void PrintFlight(FlightID* ID, int n,int i)//�������飬���
{
	printf("%d\t%s%s\t\t%04d\t\t%s\t\t%s\t\t%04d\t\t%dСʱ%02d����\t%s\n",i,ID[n].Carrier,ID[n].ID, ID[n].DepartureTime, ID[n].DepartureAirport, ID[n].ArrivalAirport, ID[n].ArrivalTime, ID[n].TravelTimeHour, ID[n].TravelTimeMinute, ID[n].AircraftType);
	return;
}

void PrintFlightTicket()
{
	;
}

int SearchFlightID(int search)//���Һ���ţ����ز�ѯ������
{
	return 0;
}
