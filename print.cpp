#include"print.h"
void PrintFlightDetail(FlightID* ID, int IDcount, int i)
{
	clearrectangle(380, 200, 1220, 680);//��ʼǰ����ʾ�������
	IMAGE plane;
	IMAGE FlightDetail;
	LOGFONT format;
	loadimage(&FlightDetail, _T(".\\IMAGES\\FlightDetail.png"), 840, 55);
	char carrier[20];
	char AircraftType[50];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char Flyday[50];
	MatchCarrier(ID[i].Carrier, carrier);
	MatchPlaneImage(plane, ID[i].AircraftType);
	MatchPlaneType(ID[i].AircraftType, AircraftType);
	MatchAirport(ID[i].DepartureAirport, DepartureAirport);
	MatchAirport(ID[i].ArrivalAirport, ArrivalAirport);
	MatchFlyDay(ID[i].FlyDay, Flyday);
	putimage(1280 - 60 - 240, 200, &plane);						//�ɻ�ͼƬ
	putimage(380, 400, &FlightDetail);							//����ʾ��ͼ
	outtextxy(1280 - 60 - 240, 200 + 160 + 5, AircraftType);	//�ɻ��ͺ�
	char IntChange[8];
	//��Ϣ�����30pxΪ�о�
	outtextxy(380, 200, "����ţ�");
	outtextxy(550, 200, ID[i].Carrier);
	outtextxy(570, 200, ID[i].ID);
	outtextxy(380, 230, "ִ�ɺ��չ�˾��");
	outtextxy(550, 230, carrier);
	//��ʾ�������ڵĵ�ɫ��ǳ��ɫ��
	settextcolor(RGB(220, 220, 220));
	outtextxy(550, 260, "һ  ��  ��  ��  ��  ��  ��");
	//�ָ�ԭ����ɫ
	settextcolor(BLACK);
	outtextxy(380, 260, "�������ڣ�");
	outtextxy(550, 260, Flyday);
	outtextxy(380, 290, "��׼Ʊ�ۣ�");
	outtextxy(550, 290, _itoa(ID[i].Price, IntChange, 10));
	outtextxy(380, 320, "��λ��");
	outtextxy(550, 320, ID[i].Class);
	outtextxy(380, 460, DepartureAirport);
	outtextxy(380, 490, ID[i].DepartureAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);
	outtextxy(380, 520, IntChange);
	//���߷ɻ�����С����
	setlinecolor(RGB(255, 255, 253));
	setfillcolor(RGB(255, 255, 253));
	for (int i = 480; i < 1000; i += 2)
	{
		putimage(380, 400, &FlightDetail);							//����ʾ��ͼ
		fillrectangle(i, 400, 1280, 440);
		Sleep(1);
	}
	putimage(380, 400, &FlightDetail);								//����ʾ��ͼ
	//С�������˽���
	outtextxy(980, 460, ArrivalAirport);
	outtextxy(980, 490, ID[i].ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].ArrivalTime);
	outtextxy(980, 520, IntChange);
	Sleep(50);
	outtextxy(680, 480, "����ʱ��");
	outtextxy(660, 500, _itoa(ID[i].TravelTimeHour, IntChange, 10));
	outtextxy(680, 500, "Сʱ");
	outtextxy(730, 500, _itoa(ID[i].TravelTimeMinute, IntChange, 10));
	outtextxy(750, 500, "����");
	return;

}
void PrintSingleFlight(FlightID* ID, int IDcount, int i)
{
	outtextxy(380, 170, "���ҵ�һ������");
	PrintFlightDetail(ID, IDcount, i);
	return;
}

int PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount)//���ز˵�ѡ��
{
	clearrectangle(380, 170, 1220, 680);//��ʼǰ����ʾ�������
	IMAGE PageChoiceImage;
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//����ҳͼƬ
	char IntChange[8];
	int Page = (SearchCount - 1) / 15 + 1;
	int CurrentPage=1;
	outtextxy(380, 170, "���ҵ�");
	_stprintf(IntChange, _T("%d"), SearchCount);
	outtextxy(450, 170, IntChange);
	outtextxy(485, 170, "������");
	PrintFlightTitle();
	PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
	int MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 11:
		case 12:
		case 13:
			return MENUchoice;
		case 15:					//��һҳ
			if(CurrentPage==1)
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage--;
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 16:					//��һҳ
			if(CurrentPage==Page)
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage++;
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 18:					//�����˷��ؼ���Ҳ���ǻ���ʾ��һ�εĽ���
			clearrectangle(1070, 165, 1220, 200);//��ʼǰ�ѷ����������
			clearrectangle(380, 200, 1220, 680);//��ʼǰ����ʾ�������
			PrintFlightTitle();
			PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 19:					//�����ʱ������
			int SortReasult[999];//���ڴ洢������˳�������Ͳ������ԭ�еĽṹ������˳�򣬲�Ӱ���±���ʡ�
			SortByDepartureTime(ID, SearchReasult, SearchCount, SortReasult);//ð�����򷨰���ʱ������������������ע��˺���������
			return PrintMultiFlight(ID,IDcount,SortReasult,SearchCount);
		case 101:
		case 102:
		case 103:
		case 104:
		case 105:
		case 106:
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
		case 114:
		case 115:									//��ת������ҳ��
			//�����жϸ�ҳ�ĺ�������
			int FlightReamin=SearchCount- (CurrentPage - 1) * 15;//��ҳ��ʣ�ຽ�����
			if (MENUchoice % 100 <= FlightReamin)
			{
				clearrectangle(1070, 165, 1220, 200);//��ʼǰ�ѷ����������
				IMAGE PageChoiceImage;
				loadimage(&PageChoiceImage, _T(".\\IMAGES\\Back.png"), 30, 30);
				putimage(1280 - 60 - 30, 165, &PageChoiceImage);						//���ؼ�ͼƬ
				PrintFlightDetail(ID, IDcount, SearchReasult[MENUchoice % 100 + (CurrentPage - 1) * 15]-1);
				MENUchoice = AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose();
			}
			else
				break;
		}
	}
}
void PrintFlightTitle()
{
	outtextxy(380, 200, "�����");
	outtextxy(460, 200, "���ʱ��");
	outtextxy(620, 200, "��ɻ���");
	outtextxy(820, 200, "�������");
	outtextxy(980, 200, "����ʱ��");
	outtextxy(1080, 200, "����");
	outtextxy(1140, 200, "����ʱ��");
	return;
}
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount,int CurrentPage, int Page)//page��ʾ��ǰ��ʾ�ڼ�ҳ
{
	char IntChange[8];
	clearrectangle(380, 230, 1220, 680);//��ʼǰ����ʾ�������
	IMAGE PageChoiceImage;
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//����ҳͼƬ
	_stprintf(IntChange, _T("%d"), CurrentPage);
	outtextxy(1280 - 60 - 120, 170, IntChange);
	outtextxy(1280 - 60 - 95, 170, "/");
	_stprintf(IntChange, _T("%d"), Page);
	outtextxy(1280 - 60 - 80, 170, IntChange);
	outtextxy(1280 - 60 - 55, 170, "ҳ");
	int Count = (CurrentPage - 1) * 15;//count��ʾ֮ǰҳ���ܼƵĺ�����������ҳ����Ӧ�ô�count+1���±꿪ʼ
	for (int i = 0; i < 15; i++)//i������������
	{
		if ((i + Count) >= SearchCount)
			break;
		PrintSingleLineFlight(ID, IDcount, SearchReasult[Count + i], 230 + 30 * i);
	}
	return;
}
void PrintSingleLineFlight(FlightID* ID, int IDcount, int i, int roll)
{
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char IntChange[5];
	MatchAirport(ID[i].DepartureAirport, DepartureAirport);
	MatchAirport(ID[i].ArrivalAirport, ArrivalAirport);
	outtextxy(390, roll, ID[i].Carrier);
	outtextxy(410, roll, ID[i].ID);
	_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);
	outtextxy(480, roll, IntChange);
	outtextxy(570, roll, DepartureAirport);
	outtextxy(780, roll, ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].ArrivalTime);
	outtextxy(1000, roll, IntChange);
	outtextxy(1090, roll, ID[i].AircraftType);
	_stprintf(IntChange, _T("%2d"), ID[i].TravelTimeHour);
	outtextxy(1150, roll, IntChange);
	outtextxy(1170, roll, "h");
	_stprintf(IntChange, _T("%02d"), ID[i].TravelTimeMinute);
	outtextxy(1180, roll, IntChange);
	outtextxy(1200, roll, "m");
	return;
}
void PrintSearchDetail(FlightID* ID, int IDcount, int i)
{

}