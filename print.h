#pragma once
#include"MENUchoose.h"
#include"struct.h"
#include"match.h"
#include"notes.h"
#include<time.h>
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// 引用图形库头文件
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;
//加载动画800*600
void PrintLoading();
//退出加载动画
void PrintExit(FlightID* ID, FlightTicket DATA[][699], int IDcount);
//打印单个航线的详细信息:整页（航线数据数组，需要打印航班的数组下标）
void PrintFlightDetail(FlightID* ID, FlightTicket DATA[][699], int IDcount, int i);
//打印单个航线（航线数据数组，需要打印航班的数组下标）
int PrintSingleFlight(FlightID* ID, FlightTicket DATA[][699], int IDcount, int i);
//按页打印多个航线（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数）
int PrintMultiFlight(FlightID* ID, FlightTicket DATA[][699], int IDcount, int* SearchReasult, int SearchCount);
//按页打印时的表格表头（）
void PrintFlightTitle();
//按页打印时的打印一页航线数据（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数，当前页数，总页数）
void PrintMultiFlightPage(FlightID* ID, FlightTicket DATA[][699], int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page);
//打印单个航线的详细信息:一行（航线数据数组，航线数据计数，需要打印航班的数组下标，行数:x位置）
void PrintSingleLineFlight(FlightID* ID, FlightTicket DATA[][699], int IDcount, int i, int roll);
//作废
void PrintSearchDetail(FlightID* ID, FlightTicket DATA[][699], int IDcount, int i);
//在详情页下方打印近期正晚点情况
void PrintTimeAccuracyBar(FlightID* ID, FlightTicket DATA[][699], int i);
//打印机票页标题栏
void PrintTicketTitle();
//
int PrintTicket(FlightID* ID, FlightTicket DATA[][699], int n);
//
void PrintTicketPage(FlightID* ID, FlightTicket DATA[][699], int* Fly,int n, int Page, int CurrentPage, int FlyDayCountAll);
//打印标题栏

