#pragma once
#include"MENUchoose.h"
#include"struct.h"
#include"match.h"
#include"notes.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// 引用图形库头文件
#include<conio.h>
#include<string>
#include<stdlib.h>
//打印单个航线的详细信息:整页（航线数据数组，需要打印航班的数组下标）
void PrintFlightDetail(FlightID* ID,  int i);
//打印单个航线（航线数据数组，需要打印航班的数组下标）
void PrintSingleFlight(FlightID* ID, int i);
//按页打印多个航线（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数）
int PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount);
//按页打印时的表格表头（）
void PrintFlightTitle();
//按页打印时的打印一页航线数据（航线数据数组，航线数据计数，搜索结果数组，搜索结果计数，当前页数，总页数）
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page);
//打印单个航线的详细信息:一行（航线数据数组，航线数据计数，需要打印航班的数组下标，行数:x位置）
void PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll);
//作废
void PrintSearchDetail(FlightID* ID, int IDcount, int i);
//打印标题栏

