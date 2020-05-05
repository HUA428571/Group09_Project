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
//使用蔡勒公式转换日期与星期
int WeekDayTransfer(int, int, int);
//返回日期对应天数
int DateTransfer(int, int, int);
//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
int JudgeAircraftSize(FlightID*, int);
//导入导出数据库
int ImportFlightDatabase(FlightID* ID, char* Location);
int SaveFlightDatabase(FlightID* ID, int IDcount, char* Location);
int ImportTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location);
int SaveTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location);
//查找航班号，返回查找到航班个数
int SearchFlightID(FlightID*, char*, int, int*, int&);
//查找航起飞地，返回查找到航班个数
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);
//查找航降落地，返回查找到航班个数
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);
//查找航起飞降落地，返回查找到航班个数
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount);
//按照起飞时间排序
//重载，全数据库排序/搜索结果数据库排序
int SortByDepartureTime(FlightID*, int, int*);
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult);
//删除
//重载，当添加航班取消时使用第二个
int DeleteFlight(FlightID* ID, FlightTicket DATA[][999], int& IDcount, int Delete);
int DeleteFlight(FlightID* ID, int& IDcount, int Delete);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);

