#pragma once
#include<iostream>
#define PI 3.1415926536
//全局字体格式
#define FONT "黑体"
#define FONT2_ZH "宋体"
#define FONT2_EN "Consolas"

//添加界面格式
#define A_LEFT_MARGIN 60
#define A_LEFT_LINE_START 150
#define A_LEFT_LINE_END 240
#define A_RIGHT_TEXT_START 260

using namespace std;

typedef struct FlightID //用于表示航班号，航班号只代表航班基本信息。
{
	char Carrier[4] = { 'X','X','X','\0' };									//航空公司，用两个大写字母表示
	char ID[8] = { 'X','X','X','X','X','X','X','\0' };					//航班号
	char FlyDay[9] = { 'X','X','X','X','X','X','X','X','\0' };		//开航日期，以星期为周期，星期几与数组下标对应，开航为数字，不开航为0
	char DepartureAirport[4] = { 'X','X','X','\0' };	//出发机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	char ArrivalAirport[4] = { 'X','X','X','\0' };	//抵达机场，三字码，为标明航站楼等，以字符串形式存储，注意结尾的\0
	int DepartureTime = 2500;												//出发时刻，四字码
	int ArrivalTime = 2500;													//到达时刻，四字码。eg 1230（12时30分）
	int TravelTimeHour = 0;													//飞行时间(时)
	int TravelTimeMinute = 0;												//飞行时间(分)
	int Price = 0;															//基准票价，由飞行时间自动计算而得
	char AircraftType[4] = { 'X','X','X','\0' };							//飞机型号，三字码。eg 787，350
	char Class[4] = { 'X','X','X','\0' };									//舱位，两舱或三舱，注意结尾的\0。
}FlightID;

typedef struct FlightTicket //每日机票情况
{
	short Seat[50][10] = { 0 };
	short FirstClassTicketRemain = 0;
	short BusinessClassTicketRemain = 0;
	short EconomyClassTicketRemain = 0;
	short ActuralDepartureTime = 2600;		//2400及以下的是正常时间，2500代表航班取消，2600代表没有相关信息
	short ActuralArrivalTime = 2600;		//2400及以下的是正常时间，2500代表航班取消，2600代表没有相关信息
}FlightTicket;

typedef struct Passenger
{
	char id[21];				//账号
	char name[11];				//姓名
	char IdCard[19];			//身份证号码
	char TelNum[12];			//电话号码

}Passenger;

typedef struct The_users  
{
	char id[21];				//账号 
	char pwd[21];				//密码 
	char Identity;				//身份为单个字符（0为用户，1为管理员）
	char phone[12];				//电话号码
	int Credit = 0;				//用户信用
}users;
