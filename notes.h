#pragma once
#include <iostream>
#include<stdio.h>
#include<string.h>
#include"struct.h"

using namespace std;
int WeekDayTransfer(int, int, int);//ʹ�ò��չ�ʽת������������
int DateTransfer(int, int, int);//�������ڶ�Ӧ����
int JudgeAircraftSize(FlightID*, int);//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
int ImportFlightDatabase(FlightID*);
//void PrintFlightTitle();//��ӡ������
void PrintFlight(FlightID*, int, int);
int SearchFlightID(FlightID*, char*, int, int*, int&);//���Һ���ţ����ز��ҵ��������
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);//���Һ���ɵأ����ز��ҵ��������
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount);
//���Һ���ɵأ����ز��ҵ��������
int PrintSearch(FlightID*, int, int*, int&);//չʾ��ѯ�Ľ��
int NewFlight(FlightID*, int&);//�����º���
int SortByDepartureTime(FlightID*, int, int*);
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult);
int DeleteFlight(FlightID* ID, FlightTicket DATA[][999], int& IDcount, int Delete);
int DeleteFlight(FlightID* ID, int& IDcount, int Delete);
//�������ʱ������
int SaveFlightDatabase(FlightID*, int);






