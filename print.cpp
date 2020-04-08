#include"print.h"
void PrintSingleFlight(FlightID* ID, int IDcount, int i) 
{
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 22;						// ��������߶�Ϊ 20
	_tcscpy_s(format.lfFaceName, _T("����"));	// ��������Ϊ�����塱
	format.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&format);							// ����������ʽ
	IMAGE plane;
	char carrier[20];
	MatchCarrier(ID[i].Carrier, carrier);
	MatchPlaneImage(plane, ID[i].AircraftType);
	putimage(1280-60-240, 200, &plane);
	outtextxy(380, 200, "���ҵ�һ������");
	outtextxy(380, 230, "����ţ�");
	outtextxy(550, 230, ID[i].Carrier);
	outtextxy(570, 230, ID[i].ID);
	outtextxy(650, 230, carrier);
	outtextxy(380, 260, "��ɻ�����");
	outtextxy(550, 260, ID[i].DepartureAirport);
	outtextxy(380, 290, "���������");
	outtextxy(550, 290, ID[i].ArrivalAirport);
	char Time[5];
	outtextxy(380, 320, "���ʱ�䣺");
	outtextxy(550, 320, _itoa(ID[i].DepartureTime, Time, 10));
	outtextxy(380, 350, "����ʱ�䣺");
	outtextxy(550, 350, _itoa(ID[i].ArrivalTime, Time, 10));
	outtextxy(380, 380, "���ͣ�");
	outtextxy(550, 380, ID[i].AircraftType);
	return;
}

void MatchPlaneImage(IMAGE &plane, char* AircraftType)
{
	int type;
	sscanf(AircraftType, "%d", &type);
	switch (type)
	{
	case 737:
	case 738:
		loadimage(&plane, _T(".\\IMAGES\\plane\\737.jpg"), 240, 160);
		return;
	case 74:
	case 744:
	case 747:
		loadimage(&plane, _T(".\\IMAGES\\plane\\747.jpg"), 240, 160);
		return;
	case 76:
		loadimage(&plane, _T(".\\IMAGES\\plane\\767.jpg"), 240, 160);
		return;
	case 77:
	case 772:
	case 773:
	case 777:
		loadimage(&plane, _T(".\\IMAGES\\plane\\777.jpg"), 240, 160);
		return;
	case 788:
	case 789:
		loadimage(&plane, _T(".\\IMAGES\\plane\\787.jpg"), 240, 160);
				return;
	case 319:
	case 320:
	case 321:
		loadimage(&plane, _T(".\\IMAGES\\plane\\320.jpg"), 240, 160);
				return;
	case 330:
	case 333:
		loadimage(&plane, _T(".\\IMAGES\\plane\\330.jpg"), 240, 160);
				return;
	case 343:
		loadimage(&plane, _T(".\\IMAGES\\plane\\340.jpg"), 240, 160);
				return;
	default:
		loadimage(&plane, _T(".\\IMAGES\\plane\\default.png"), 240, 160);
				return;
	}
}

void MatchCarrier(char* carrier, char* CARRIER)
{
	if (carrier == "CA")
	{
		strcpy(CARRIER,"�й����ʺ��չ�˾");
	}
	return;
}

