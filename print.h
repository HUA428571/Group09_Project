#pragma once
#include"MENUchoice.h"
#include"struct.h"
#include"match.h"
#include"notes.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include<conio.h>
#include<string>
#include<stdlib.h>

void PrintFlightDetail(FlightID* ID, int IDcount, int i);

void PrintSingleFlight(FlightID* ID, int IDcount, int i);
int PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount);
void PrintFlightTitle();
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page);
void PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll);
void PrintSearchDetail(FlightID* ID, int IDcount, int i);
//��ӡ������

