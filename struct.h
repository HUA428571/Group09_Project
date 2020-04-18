#pragma once
#include<iostream>
//#define FONT "OPPOSans M"
//#define FONT "����ϸ��"
#define FONT "����"
//#define FONT "Source Han Sans"

using namespace std;

typedef struct FlightID //���ڱ�ʾ����ţ������ֻ�����������Ϣ��
{
	char Carrier[4] = { 'X','X','X','\0' };						//���չ�˾����������д��ĸ��ʾ
	char ID[8] = { 'X','X' ,'X' ,'X','X','X' ,'X' ,'\0' };								//�����
	char FlyDay[9] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'X','\0' };							//�������ڣ�������Ϊ���ڣ����ڼ��������±��Ӧ������Ϊ���֣�������Ϊ0
	char DepartureAirport[8] = { 'X','X','X' ,'X' ,'X' ,'X' ,'X' ,'\0' };				//���������������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
	char ArrivalAirport[8] = { 'X','X' ,'X' ,'X' ,'X' ,'X' ,'X' ,'\0' };					//�ִ�����������룬Ϊ������վ¥�ȣ����ַ�����ʽ�洢��ע���β��\0
	int DepartureTime = 2500;					//����ʱ�̣�������
	int ArrivalTime = 2500;					//����ʱ�̣������롣eg 1230��12ʱ30�֣�
	int TravelTimeHour = 0;//����ʱ��(ʱ)
	int TravelTimeMinute = 0;//����ʱ��(��)
	int Price = 0;
	char AircraftType[4] = { 'X','X' ,'X','\0' };					//�ɻ��ͺţ������롣eg 787��350
	char Class[4] = { 'X','X' ,'X' ,'\0' };							//��λ�����ջ����գ�ע���β��\0��
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