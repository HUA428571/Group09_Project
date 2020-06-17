#pragma once
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// 引用图形库头文件
#include"struct.h"
using namespace std;
//获取鼠标位置进行选择的函数
int AdminMENU_MENUChoose();
int AdminMENU_MainMENU_MENUChoose();
int AdminMENU_MainMENU_Import_MENUChoose();

int AdminMENU_SearchMENU_MENUChoose();
int AdminMENU_SearchMENU_SingleFlight_MENUChoose();
int AdminMENU_SearchMENU_MultiFlight_MENUChoose();
int AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose();

int AdminMENU_DeleteMENU_MENUChoose();

int AdminMENU_AddMENU_MENUChoose();

int AdminMENU_ChangeMENU_MENUChoose();

int AdminMENU_Ticket_MENUChoose();

int StartMENU_MENUChoose();

//乘客部分
int CustomMENU_MENUChoose();
int CAdminMENU_SearchMENU_MultiFlight_MENUChoose();
int CAdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose();
int CAdminMENU_ReMENU_MultiFlight_MENUChoose();
int CAdminMENU_ReMENU_MultiFlight_FlightDetail_MENUChoose();
int CAdminMENU_BOOKINGMENU_MultiFlight_MENUChoose();
int CAdminMENU_BookingMENU_MultiFlight_FlightDetail_MENUChoose();
int CAdminMENU_BOOKINGMENU_MultiFlight_Passenger_MENUChoose();
