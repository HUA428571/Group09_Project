#include<iostream>
#include<string>
#include<vector>
#include<easyx.h>
#include<graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include<conio.h>
#include"mian.h"
using namespace std;
int HOMEpage(Passenger* P, The_users* users, int id)
{

	return 0;
}
int  OrderMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, int id)
{
	int SearchCount = 0;
	SearchCount = FindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	int* flyday = FO->flyday;
	int* SearchReasult = FO->flight;
	int x = C_PrintMultiFlight(ID, FO, IDcount, SearchReasult, SearchCount, flyday);
	return x;
}
int  BookingMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, bookiinginformation custom, int id)
{
	int SearchCount = 0;
	SearchCount = Searching(ID, DATA, custom, IDcount);
	int* SearchReasult = custom.flynumber;
	int* flyday = &custom.flyday;
	int x = b_printmultiflight(ID, DATA, P, users, IDcount, SearchReasult, SearchCount, flyday, id);
	return x;
}
int  Refunding_ChngeMENU(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, int id)
{
	int SearchCount = 0;
	SearchCount = REFindTheHistoryAndOrder(DATA, ID, P, users, id, FO);
	int* flyday = FO->flyday;
	int* SearchReasult = FO->flight;
	int x = c_printmultiflight(ID, DATA, FO, P, users, IDcount, SearchReasult, SearchCount, flyday, id);
	return x;
}
void SignOutMENU()
{

}
void CustomMenu(FlightID* ID, FlightTicket DATA[366][999], int IDcount, Passenger* P, The_users* users, FlyhistoryAndOrder* FO, bookiinginformation custom, int id)
{
	initgraph(1280, 720);	// ������ͼ���ڣ���СΪ 1280x720 ����
	// ���ñ���ɫΪ����ɫ
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// �ñ���ɫ�����Ļ
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// ��������ΪFONT
	settextstyle(&format);						// ����������ʽ
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Bacgr.png"), 1280, 720);
	putimage(0, 0, &BG);	// ��ʾ����
	int MENUchoice;
	MENUchoice = CustomMENU_MENUChoose();
	while (true)											//ѭ��
	{
		switch (MENUchoice)
		{
		case 0://��ҳ
			MENUchoice = HOMEpage(P, users, id);
			break;
		case 1://��ʷ����
			MENUchoice = OrderMENU(ID, DATA, IDcount, P, users, FO, id);
			break;
		case 2://��Ʊ
			MENUchoice = BookingMENU(ID, DATA, IDcount, P, users, custom, id);
			break;
		case 3://�˸�ǩ
			MENUchoice = Refunding_ChngeMENU(ID, DATA, IDcount, P, users, FO, id);
			break;
		case 4://�˳���¼
			SignOutMENU();
			break;
		}
	}
}