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
void PrintFlightTitle();//��ӡ������
void PrintFlight(FlightID*, int, int);
int SearchFlightID(FlightID*, char*, int, int*, int&);//���Һ���ţ����ز��ҵ��������
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);//���Һ���ɵأ����ز��ҵ��������
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);//���Һ���ɵأ����ز��ҵ��������
int PrintSearch(FlightID*, int, int*, int&);//չʾ��ѯ�Ľ��
int NewFlight(FlightID*, int&);//�����º���
int SortByDepartureTime(FlightID*, int, int*);//�������ʱ������
int SaveFlightDatabase(FlightID*, int);






