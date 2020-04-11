#pragma once
#include<iostream>
#include<graphics.h>
#include <easyx.h>			// 引用图形库头文件

void MatchPlaneImage(IMAGE&, char*);//和数据库匹配飞机图片
void MatchPlaneType(char*, char*);//和数据库匹配机型中文全称
void MatchCarrier(char*, char*);//和数据库匹配航空公司中文全称
void MatchAirport(char*, char*);//和数据库匹配机场中文全称
void MatchFlyDay(char*, char*);//匹配飞行日期
