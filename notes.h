#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//ԭ�ṹ�壬�����͵���ʱ���Ϊ�ַ�����
//typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
//{
//    char Carrier[4] = {'X','X','X','X' };						//���չ�˾����������д��ĸ��ʾ
//    char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//�����
//    char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ1��������Ϊ0
//    char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
//    char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
//    char DepartureTime[4] = { 'X' ,'X' ,'X' ,'X' };					//����ʱ�̣�������
//    char ArrivalTime[4] = { 'X' ,'X' ,'X' ,'X' };					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
//    char AircraftType[4] = { 'X','X' ,'X' };					//�ɻ��ͺţ������롣eg 787��350
//    char Class[4] = { 'X','X' ,'X' ,'X' };							//��λ�����ջ����գ�ע���β��\0��
//}FlightID;
//ϵͳ���Ĭ��Ϊ2020��
//
#ifdef NOTE
#define NOTE
typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
{
    char Carrier[4] = { 'X','X','X','X' };						//���չ�˾����������д��ĸ��ʾ
    char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//�����
    char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ1��������Ϊ0
    char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
    char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
    int DepartureTime = 2500;					//����ʱ�̣�������
    int ArrivalTime = 2500;					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
    int TravelTimeHour = 0;//����ʱ��(ʱ)
    int TravelTimeMinute = 0;//����ʱ��(��)
    char AircraftType[4] = { 'X','X' ,'X' };					//�ɻ��ͺţ������롣eg 787��350
    char Class[4] = { 'X','X' ,'X' ,'X' };							//��λ�����ջ����գ�ע���β��\0��
}FlightID;

typedef struct Date
{
    int year;
    int month;
    int day;
}Date;

typedef struct FlightTicket //ÿ�ջ�Ʊ���
{
    int ID;//�������±�(����Ų�Ψһ��
    Date day;
    int FirstClassTicketRemain = 0;
    int BusinessClassTicketRemain = 0;
    int EconomyClassTicketRemain = 0;
    int FirstClassTicketPrice = -100;
    int BusinessClassTicketPrice = -100;
    int EconomyClassTicketPrice = -100;
    int ActuralDepartureTime = 2500;
    int ActuralArrivalTime = 2500;
}FlightTicket;

extern FlightID ID[999];

extern FlightTicket DATA[366][999];

#endif // NOTE

#ifndef StructDefine
#define StructDefine
typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
{
    char Carrier[4] = { 'X','X','X','X' };						//���չ�˾����������д��ĸ��ʾ
    char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'X' };								//�����
    char FlyDay[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ1��������Ϊ0
    char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'X' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
    char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
    int DepartureTime = 2500;					//����ʱ�̣�������
    int ArrivalTime = 2500;					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
    int TravelTimeHour = 0;//����ʱ��(ʱ)
    int TravelTimeMinute = 0;//����ʱ��(��)
    int Price = 0;
    char AircraftType[4] = { 'X','X' ,'X' };					//�ɻ��ͺţ������롣eg 787��350
    char Class[4] = { 'X','X' ,'X' ,'X' };							//��λ�����ջ����գ�ע���β��\0��
}FlightID;

typedef struct FlightTicket //ÿ�ջ�Ʊ���
{
    int Seat[50][10] = { 0 };
    int FirstClassTicketRemain = 0;
    int BusinessClassTicketRemain = 0;
    int EconomyClassTicketRemain = 0;
    int ActuralDepartureTime = 2500;
    int ActuralArrivalTime = 2500;
}FlightTicket; 
#endif // !struct


int WeekDayTransfer(int, int, int);//ʹ�ò��չ�ʽת������������
int DateTransfer(int, int, int);//�������ڶ�Ӧ����
int JudgeAircraftSize(FlightID*, int);//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
int ImportFlightDatabase(FlightID*);
void PrintFlightTitle();//��ӡ������
void PrintFlight(FlightID*, int, int);
int SearchFlightID(FlightID*, char*, int, int*, int&);//���Һ���ţ����ز��ҵ��������
int SearchFlightDepartureAirport(FlightID*, char*, int, int*, int&);//���Һ���ɵأ����ز��ҵ��������
int SearchFlightArrivalAirport(FlightID*, char*, int, int*, int&);//���Һ���ɵأ����ز��ҵ��������
int PrintSearch(FlightID*, int, int*, int&);//չʾ��ѯ�Ľ��
int NewFlight(FlightID*, int&);//�����º���
int SortByDepartureTime(FlightID*, int, int*);//�������ʱ������
int SaveFlightDatabase(FlightID*, int);






