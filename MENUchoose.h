#pragma once
#include<iostream>
#include<graphics.h>
#include<easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include"struct.h"


//��ȡ���λ�ý���ѡ��ĺ���
int AdminMENU_MENUChoose();
int AdminMENU_SearchMENU_MENUChoose();
int AdminMENU_SearchMENU_SingleFlight_MENUChoose();
int AdminMENU_SearchMENU_MultiFlight_MENUChoose();
int AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose();

int AdminMENU_DeleteMENU_MENUChoose();

int AdminMENU_AddMENU_MENUChoose();

int AdminMENU_AddMENU_Confirm_MENUChoose();

int AdminMENU_ChangeMENU_MENUChoose();

int AdminMENU_MainMENU_Import_MENUChoose();

int AdminMENU_MainMENU_MENUChoose();

int AdminMENU_Ticket_MENUChoose();

int AdminMENU_Ticket_Detail_MENUChoose();
