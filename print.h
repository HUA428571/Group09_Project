#pragma once
#include"MENUchoose.h"
#include"struct.h"
#include"match.h"
#include"notes.h"
#include<time.h>
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;
//���ض���800*600
void PrintLoading();
//�˳����ض���
void PrintExit(FlightID* ID, FlightTicket DATA[][999], int IDcount);
//��ӡ�������ߵ���ϸ��Ϣ:��ҳ�������������飬��Ҫ��ӡ����������±꣩
void PrintFlightDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i);
//��ӡ�������ߣ������������飬��Ҫ��ӡ����������±꣩
int PrintSingleFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i);
//��ҳ��ӡ������ߣ������������飬�������ݼ���������������飬�������������
int PrintMultiFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount);
//��ҳ��ӡʱ�ı���ͷ����
void PrintFlightTitle();
//��ҳ��ӡʱ�Ĵ�ӡһҳ�������ݣ������������飬�������ݼ���������������飬���������������ǰҳ������ҳ����
void PrintMultiFlightPage(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page);
//��ӡ�������ߵ���ϸ��Ϣ:һ�У������������飬�������ݼ�������Ҫ��ӡ����������±꣬����:xλ�ã�
void PrintSingleLineFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i, int roll);
//����
void PrintSearchDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i);
//������ҳ�·���ӡ������������
void PrintTimeAccuracyBar(FlightID* ID, FlightTicket DATA[][999], int i);
//��ӡ��Ʊҳ������
void PrintTicketTitle();
//
int PrintTicket(FlightID* ID, FlightTicket DATA[][999], int n);
//
void PrintTicketPage(FlightID* ID, FlightTicket DATA[][999], int* Fly,int n, int Page, int CurrentPage, int FlyDayCountAll);
//��ӡ������

