#pragma once
#include"MENUchoose.h"
#include"struct.h"
#include"match.h"
#include"notes.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include<conio.h>
#include<string>
#include<stdlib.h>
//��ӡ�������ߵ���ϸ��Ϣ:��ҳ�������������飬��Ҫ��ӡ����������±꣩
void PrintFlightDetail(FlightID* ID,  int i);
//��ӡ�������ߣ������������飬��Ҫ��ӡ����������±꣩
void PrintSingleFlight(FlightID* ID, int i);
//��ҳ��ӡ������ߣ������������飬�������ݼ���������������飬�������������
int PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount);
//��ҳ��ӡʱ�ı���ͷ����
void PrintFlightTitle();
//��ҳ��ӡʱ�Ĵ�ӡһҳ�������ݣ������������飬�������ݼ���������������飬���������������ǰҳ������ҳ����
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page);
//��ӡ�������ߵ���ϸ��Ϣ:һ�У������������飬�������ݼ�������Ҫ��ӡ����������±꣬����:xλ�ã�
void PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll);
//����
void PrintSearchDetail(FlightID* ID, int IDcount, int i);
//��ӡ������

