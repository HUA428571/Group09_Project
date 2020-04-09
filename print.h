#pragma once
#include<iostream>
#include<graphics.h>
#include <easyx.h>			// 引用图形库头文件
#include <conio.h>
#include<string>
#include<stdlib.h>
#include"struct.h"
void PrintSingleFlight(FlightID* ID, int IDcount, int i);
void PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount);
void MatchPlaneImage(IMAGE &, char*);//和数据库匹配飞机图片
void MatchPlaneType(char*, char*);//和数据库匹配机型中文全称
void MatchCarrier(char*, char*);//和数据库匹配航空公司中文全称
void MatchAirport(char*, char*);//和数据库匹配机场中文全称
void MatchFlyDay(char*, char*);//匹配飞行日期
void PrintFlightTitle();
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int page);
void PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll);
//打印标题栏

