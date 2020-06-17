#pragma once
#include<iostream>
#include<string>
#include"notes.h"
#include"struct.h"
#include"match.h"
#include"print.h"
#include"MENUchoose.h"
using namespace std;
int HOMEpage(Passenger* P, The_users* users, int id);
int OrderMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, int id);
int BookingMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, bookiinginformation* custom, int id);
int Refunding_ChngeMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, int id);
void SignOutMENU();
void CustomMenu(FlightID * ID, FlightTicket DATA[366][999], int IDcount, Passenger * P, The_users * users, FlyhistoryAndOrder * FO, bookiinginformation* custom, int id);