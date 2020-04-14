#pragma once
#include"notes.h"
#include"print.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// 引用图形库头文件
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<time.h>


using namespace std;

int AdminMENU(FlightID*, FlightTicket[][999], int&);
int AdminMENU_MainMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount);
int AdminMENU_MainMENU_ImportFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int& IDcount, char Location[][100]);
int AdminMENU_MainMENU_ImportTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100]);
int AdminMENU_MainMENU_SaveFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100]);
int AdminMENU_MainMENU_SaveTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100]);
int AdminMENU_SearchMENU(FlightID* ID, int IDcount);
int AdminMENU_AddMENU(FlightID* ID, int& IDcount);
int AdminMENU_DeleteMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount);
int AdminMENU_ChangeMENU(FlightID* ID, int IDcount);
int AdminMENU_SearchMENU_SearchByID(FlightID*, int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID*, int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID*, int IDcount, int* SearchReasult, int& SearchCount);
int AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount);
