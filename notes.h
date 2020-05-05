#pragma once
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<easyx.h>
#include<stdlib.h>
#include<conio.h>
#include"struct.h"

using namespace std;
//ʹ�ò��չ�ʽת������������
int WeekDayTransfer(int, int, int);
//�������ڶ�Ӧ����
int DateTransfer(int, int, int);
//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
int JudgeAircraftSize(FlightID*, int);
//���뵼�����ݿ�
int ImportFlightDatabase(FlightID* ID, char* Location);
int SaveFlightDatabase(FlightID* ID, int IDcount, char* Location);
int ImportTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location);
int SaveTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location);
//���Һ���ţ����ز��ҵ��������
int SearchFlightID(FlightID*, char*, int, int*, int&);
//���Һ���ɵأ����ز��ҵ��������
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);
//���Һ�����أ����ز��ҵ��������
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);
//���Һ���ɽ���أ����ز��ҵ��������
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount);
//�������ʱ������
//���أ�ȫ���ݿ�����/����������ݿ�����
int SortByDepartureTime(FlightID*, int, int*);
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult);
//ɾ��
//���أ�����Ӻ���ȡ��ʱʹ�õڶ���
int DeleteFlight(FlightID* ID, FlightTicket DATA[][999], int& IDcount, int Delete);
int DeleteFlight(FlightID* ID, int& IDcount, int Delete);
//������������ݣ��������ƣ���������λ�ã����������λ�ã�Ĭ����ʾ�����ݣ�
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default);
//������������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);

