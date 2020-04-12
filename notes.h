#pragma once
#include <iostream>
#include<stdio.h>
#include<string.h>
#include"struct.h"

using namespace std;
int WeekDayTransfer(int, int, int);//使用蔡勒公式转换日期与星期
int DateTransfer(int, int, int);//返回日期对应天数
int JudgeAircraftSize(FlightID*, int);//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
int ImportFlightDatabase(FlightID*);
//void PrintFlightTitle();//打印标题栏
void PrintFlight(FlightID*, int, int);
int SearchFlightID(FlightID*, char*, int, int*, int&);//查找航班号，返回查找到航班个数
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);//查找航起飞地，返回查找到航班个数
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount);
//查找航起飞地，返回查找到航班个数
int PrintSearch(FlightID*, int, int*, int&);//展示查询的结果
int NewFlight(FlightID*, int&);//创建新航线
int SortByDepartureTime(FlightID*, int, int*);
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult);
int DeleteFlight(FlightID* ID, FlightTicket DATA[][999], int& IDcount, int Delete);
int DeleteFlight(FlightID* ID, int& IDcount, int Delete);
//按照起飞时间排序
int SaveFlightDatabase(FlightID*, int);






