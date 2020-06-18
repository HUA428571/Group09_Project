#pragma once
#include"notes.h"
#include"print.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<time.h>

int StartMENU(users u[999], Passenger p[999]);
int Identify_ID(char* n, char* m, users u[999]);
int SetMenu_Register(users u[999]);
int SetMenu_Manager_Register(users u[999]);