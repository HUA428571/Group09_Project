#pragma once
#include<iostream>
#include<graphics.h>
#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<string>
#include<stdlib.h>
#include"struct.h"
void PrintSingleFlight(FlightID* ID, int IDcount, int i);
void PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount);
void MatchPlaneImage(IMAGE &, char*);//�����ݿ�ƥ��ɻ�ͼƬ
void MatchPlaneType(char*, char*);//�����ݿ�ƥ���������ȫ��
void MatchCarrier(char*, char*);//�����ݿ�ƥ�亽�չ�˾����ȫ��
void MatchAirport(char*, char*);//�����ݿ�ƥ���������ȫ��
void MatchFlyDay(char*, char*);//ƥ���������
void PrintFlightTitle();
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int page);
void PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll);
//��ӡ������

