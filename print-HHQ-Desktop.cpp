#include"print.h"
void PrintSingleFlight(FlightID* ID, int IDcount, int i)
{
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 20;						// ��������߶�Ϊ 20
	_tcscpy_s(format.lfFaceName, _T("����"));	// ��������Ϊ�����塱
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	IMAGE plane;
	IMAGE FlightDetail;
	loadimage(&FlightDetail, _T(".\\IMAGES\\FlightDetail.png"),840,55);
	char carrier[20];
	char AircraftType[50];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	MatchCarrier(ID[i].Carrier, carrier);
	MatchPlaneImage(plane, ID[i].AircraftType);
	MatchPlaneType(ID[i].AircraftType, AircraftType);
	MatchAirport(ID[i].DepartureAirport, DepartureAirport);
	MatchAirport(ID[i].ArrivalAirport, ArrivalAirport);
	putimage(1280 - 60 - 240, 200, &plane);						//�ɻ�ͼƬ
	putimage(380, 400, &FlightDetail);							//����ʾ��ͼ
	outtextxy(1280 - 60 - 240, 200 + 160 + 5, AircraftType);	//�ɻ��ͺ�
	//��Ϣ�����30pxΪ�о�
	outtextxy(380, 200, "���ҵ�һ������");
	outtextxy(380, 230, "����ţ�");
	outtextxy(550, 230, ID[i].Carrier);
	outtextxy(570, 230, ID[i].ID);
	//outtextxy(700, 230, carrier);
	outtextxy(380, 260, "ִ�ɺ��չ�˾��");
	outtextxy(550, 260, carrier);
	//outtextxy(380, 260, "��ɻ�����");
	//outtextxy(550, 260, ID[i].DepartureAirport);
	//outtextxy(700, 260, DepartureAirport);
	//outtextxy(380, 290, "���������");
	//outtextxy(550, 290, ID[i].ArrivalAirport);
	//outtextxy(700, 290, ArrivalAirport);
	//char Time[5];
	//outtextxy(380, 320, "���ʱ�䣺");
	//outtextxy(550, 320, _itoa(ID[i].DepartureTime, Time, 10));
	//outtextxy(380, 350, "����ʱ�䣺");
	//outtextxy(550, 350, _itoa(ID[i].ArrivalTime, Time, 10));
	//outtextxy(380, 380, "ִ�ɻ��ͣ�");
	//outtextxy(550, 380, ID[i].AircraftType);
	setlinecolor(RGB(255, 255, 253));
	setfillcolor(RGB(255, 255, 253));
	outtextxy(380, 460, DepartureAirport);
	outtextxy(380, 490, ID[i].DepartureAirport);
	char Time[5];
	outtextxy(380, 520, _itoa(ID[i].DepartureTime, Time, 10));
	for (int i = 480; i < 1000; i+=2)
	{
		putimage(380, 400, &FlightDetail);							//����ʾ��ͼ
		fillrectangle(i, 400, 1280, 440);
		Sleep(1);
	}
	putimage(380, 400, &FlightDetail);							//����ʾ��ͼ
	outtextxy(980, 460, ArrivalAirport);
	outtextxy(980, 490, ID[i].ArrivalAirport);
	outtextxy(980, 520, _itoa(ID[i].ArrivalTime, Time, 10));


	return;
}

void MatchPlaneImage(IMAGE& plane, char* AircraftType)
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
void MatchPlaneType(char* AircraftType, char* AIRCRAFTTYPE)
{
	int type;
	sscanf(AircraftType, "%d", &type);
	switch (type)
	{
	case 737:
	case 738:
		strcpy(AIRCRAFTTYPE, "����B737ϵ�зɻ�");
		return;
	case 74:
	case 744:
	case 747:
		strcpy(AIRCRAFTTYPE, "����B747ϵ�зɻ�");
		return;
	case 76:
		strcpy(AIRCRAFTTYPE, "����B767ϵ�зɻ�");
		return;
	case 77:
	case 772:
	case 773:
	case 777:
		strcpy(AIRCRAFTTYPE, "����B777ϵ�зɻ�");
		return;
	case 788:
	case 789:
		strcpy(AIRCRAFTTYPE, "����B787ϵ�зɻ�");
		return;
	case 319:
	case 320:
	case 321:
		strcpy(AIRCRAFTTYPE, "���пͳ�A320ϵ�зɻ�");
		return;
	case 330:
	case 333:
		strcpy(AIRCRAFTTYPE, "���пͳ�A330ϵ�зɻ�");
		return;
	case 343:
		strcpy(AIRCRAFTTYPE, "���пͳ�A340ϵ�зɻ�");
		return;
	case 350:
		strcpy(AIRCRAFTTYPE, "���пͳ�A350ϵ�зɻ�");
		return;
	case 380:
		strcpy(AIRCRAFTTYPE, "���пͳ�A380ϵ�зɻ�");
		return;
	default:
		strcpy(AIRCRAFTTYPE, "û���ҵ���������");
		return;
	}

}
void MatchCarrier(char* carrier, char* CARRIER)
{
	if (!strcmp(carrier, "CA"))
	{
		strcpy(CARRIER, "�й����ʺ��չ�˾");
		return;
	}
}
void MatchAirport(char* airport, char* AIRPORT)
{
	strncpy(airport, airport, 3);
	airport[3] = '\0';
	if (!strcmp(airport, "PEK")) { strcpy(AIRPORT, "�����׶����ʻ���"); return; }
	if (!strcmp(airport, "CAN")) { strcpy(AIRPORT, "���ݰ��ƹ��ʻ���"); return; }
	if (!strcmp(airport, "SHA")) { strcpy(AIRPORT, "�Ϻ����Ź��ʻ���"); return; }
	if (!strcmp(airport, "PVG")) { strcpy(AIRPORT, "�Ϻ��ֶ����ʻ���"); return; }
	if (!strcmp(airport, "CTU")) { strcpy(AIRPORT, "�ɶ�˫�����ʻ���"); return; }
	if (!strcmp(airport, "SZX")) { strcpy(AIRPORT, "���ڱ������ʻ���"); return; }
	if (!strcmp(airport, "KMG")) { strcpy(AIRPORT, "������ˮ���ʻ���"); return; }
	if (!strcmp(airport, "XIY")) { strcpy(AIRPORT, "�����������ʻ���"); return; }
	if (!strcmp(airport, "CKG")) { strcpy(AIRPORT, "���콭�����ʻ���"); return; }
	if (!strcmp(airport, "HGH")) { strcpy(AIRPORT, "������ɽ���ʻ���"); return; }
	if (!strcmp(airport, "XMN")) { strcpy(AIRPORT, "���Ÿ�����ʻ���"); return; }
	if (!strcmp(airport, "CSX")) { strcpy(AIRPORT, "��ɳ�ƻ����ʻ���"); return; }
	if (!strcmp(airport, "NKG")) { strcpy(AIRPORT, "�Ͼ�»�ڹ��ʻ���"); return; }
	if (!strcmp(airport, "WUH")) { strcpy(AIRPORT, "�人��ӹ��ʻ���"); return; }
	if (!strcmp(airport, "DLC")) { strcpy(AIRPORT, "�������ʻ���"); return; }
	if (!strcmp(airport, "TAO")) { strcpy(AIRPORT, "�ൺ��ͤ���ʻ���"); return; }
	if (!strcmp(airport, "SYX")) { strcpy(AIRPORT, "���Ƿ�˹��ʻ���"); return; }
	if (!strcmp(airport, "HAK")) { strcpy(AIRPORT, "�����������ʻ���"); return; }
	if (!strcmp(airport, "TSN")) { strcpy(AIRPORT, "���������ʻ���"); return; }
	if (!strcmp(airport, "HKG")) { strcpy(AIRPORT, "��۹��ʻ���"); return; }
	if (!strcmp(airport, "MFM")) { strcpy(AIRPORT, "���Ź��ʻ���"); return; }
	if (!strcmp(airport, "URC")) { strcpy(AIRPORT, "��³ľ�����"); return; }
	if (!strcmp(airport, "TPE")) { strcpy(AIRPORT, "̨����԰���ʻ���"); return; }
	if (!strcmp(airport, "NRT")) { strcpy(AIRPORT, "����������ʻ���"); return; }
	if (!strcmp(airport, "HND")) { strcpy(AIRPORT, "����������ʻ���"); return; }
	if (!strcmp(airport, "KIX")) { strcpy(AIRPORT, "����������ʻ���"); return; }
	if (!strcmp(airport, "FUK")) { strcpy(AIRPORT, "���Թ��ʻ���"); return; }
	if (!strcmp(airport, "OKA")) { strcpy(AIRPORT, "�����ǰԹ��ʻ���"); return; }
	if (!strcmp(airport, "ITM")) { strcpy(AIRPORT, "������ʻ���"); return; }
	if (!strcmp(airport, "NGO")) { strcpy(AIRPORT, "�����ݹ��ʻ���"); return; }
	if (!strcmp(airport, "ICN")) { strcpy(AIRPORT, "�׶��ʴ����ʻ���"); return; }
	if (!strcmp(airport, "GMP")) { strcpy(AIRPORT, "�׶����ֹ��ʻ���"); return; }
	if (!strcmp(airport, "PUS")) { strcpy(AIRPORT, "��ɽ�𺣹��ʻ���"); return; }
	if (!strcmp(airport, "CJU")) { strcpy(AIRPORT, "���ݵ����ʻ���"); return; }
	if (!strcmp(airport, "BKK")) { strcpy(AIRPORT, "�����������չ��ʻ���"); return; }
	if (!strcmp(airport, "DMK")) { strcpy(AIRPORT, "�����������ʻ���"); return; }
	if (!strcmp(airport, "CNX")) { strcpy(AIRPORT, "�������ʻ���"); return; }
	if (!strcmp(airport, "HKT")) { strcpy(AIRPORT, "�ռ����ʻ���"); return; }
	if (!strcmp(airport, "KUL")) { strcpy(AIRPORT, "��¡�¹��ʻ���"); return; }
	if (!strcmp(airport, "PEN")) { strcpy(AIRPORT, "�ĳǹ��ʻ���"); return; }
	if (!strcmp(airport, "BKI")) { strcpy(AIRPORT, "�Ǳӹ��ʻ���"); return; }
	if (!strcmp(airport, "MNL")) { strcpy(AIRPORT, "���������ʻ���"); return; }
	if (!strcmp(airport, "CRK")) { strcpy(AIRPORT, "�����˹��ʻ���"); return; }
	if (!strcmp(airport, "CGK")) { strcpy(AIRPORT, "�żӴ���ʻ���"); return; }
	if (!strcmp(airport, "BDO")) { strcpy(AIRPORT, "��¡���ʻ���"); return; }
	if (!strcmp(airport, "DPS")) { strcpy(AIRPORT, "���嵺�ǰ�������"); return; }
	if (!strcmp(airport, "DEL")) { strcpy(AIRPORT, "�µ�����ʻ���"); return; }
	if (!strcmp(airport, "BLR")) { strcpy(AIRPORT, "����޶����ʻ���"); return; }
	if (!strcmp(airport, "CMB")) { strcpy(AIRPORT, "�����¹��ʻ���"); return; }
	if (!strcmp(airport, "SIN")) { strcpy(AIRPORT, "�¼������˻���"); return; }
	if (!strcmp(airport, "SGN")) { strcpy(AIRPORT, "��־�����ʻ���"); return; }
	if (!strcmp(airport, "HAN")) { strcpy(AIRPORT, "���ڹ��ʻ���"); return; }
	if (!strcmp(airport, "DEL")) { strcpy(AIRPORT, "ӡ���µ���ʵػ���"); return; }
	if (!strcmp(airport, "KHI")) { strcpy(AIRPORT, "��������ʻ���"); return; }
	if (!strcmp(airport, "BOM")) { strcpy(AIRPORT, "ӡ���������"); return; }
	if (!strcmp(airport, "BLR")) { strcpy(AIRPORT, "ӡ�Ȱ���޶�����"); return; }
	if (!strcmp(airport, "KTM")) { strcpy(AIRPORT, "������ӵ���������"); return; }
	if (!strcmp(airport, "DXB")) { strcpy(AIRPORT, "�������ϰݹ��ʻ���"); return; }
	if (!strcmp(airport, "DOH")) { strcpy(AIRPORT, "������������ʻ���"); return; }
	if (!strcmp(airport, "AUH")) { strcpy(AIRPORT, "�������������Ȼ���"); return; }
	if (!strcmp(airport, "DAC")) { strcpy(AIRPORT, "�ϼ����￨����"); return; }
	if (!strcmp(airport, "JED")) { strcpy(AIRPORT, "ɳ�ذ����������������"); return; }
	if (!strcmp(airport, "CCU")) { strcpy(AIRPORT, "ӡ�ȼӶ��������"); return; }
	if (!strcmp(airport, "THR")) { strcpy(AIRPORT, "���ʵº�������"); return; }
	if (!strcmp(airport, "BAK")) { strcpy(AIRPORT, "�����ݽ��Ϳ����"); return; }
	if (!strcmp(airport, "ISB")) { strcpy(AIRPORT, "�ͻ�˹̹��˹��������"); return; }
	if (!strcmp(airport, "ASB")) { strcpy(AIRPORT, "��������ʲ���͵»���"); return; }
	if (!strcmp(airport, "DYU")) { strcpy(AIRPORT, "������˹̹���б����"); return; }
	if (!strcmp(airport, "LBD")) { strcpy(AIRPORT, "������˹̹��¼ֵ»���"); return; }
	if (!strcmp(airport, "OSS")) { strcpy(AIRPORT, "������˹˹̹��ʲ����"); return; }
	if (!strcmp(airport, "TBS")) { strcpy(AIRPORT, "��³���ǵڱ���˹����"); return; }
	if (!strcmp(airport, "MDL")) { strcpy(AIRPORT, "��������ջ���"); return; }
	if (!strcmp(airport, "MEL")) { strcpy(AIRPORT, "ī�������ʻ���"); return; }
	if (!strcmp(airport, "SYD")) { strcpy(AIRPORT, "Ϥ��ʷ��˹���ʻ���"); return; }
	if (!strcmp(airport, "BNE")) { strcpy(AIRPORT, "����˹����ʻ���"); return; }
	if (!strcmp(airport, "PER")) { strcpy(AIRPORT, "��˹���ʻ���"); return; }
	if (!strcmp(airport, "AKL")) { strcpy(AIRPORT, "�¿������ʻ���"); return; }
	if (!strcmp(airport, "LHR")) { strcpy(AIRPORT, "�׶�ϣ��˹���ʻ���"); return; }
	if (!strcmp(airport, "LGW")) { strcpy(AIRPORT, "�׶ظ����˹��ʻ���"); return; }
	if (!strcmp(airport, "STN")) { strcpy(AIRPORT, "�׶�˹̹˹�ص»���"); return; }
	if (!strcmp(airport, "LTN")) { strcpy(AIRPORT, "�׶�¬�ٻ���"); return; }
	if (!strcmp(airport, "LCY")) { strcpy(AIRPORT, "�׶س��л���"); return; }
	if (!strcmp(airport, "LPL")) { strcpy(AIRPORT, "�����ֹ��ʻ���"); return; }
	if (!strcmp(airport, "MAN")) { strcpy(AIRPORT, "����˹�ع��ʻ���"); return; }
	if (!strcmp(airport, "CDG")) { strcpy(AIRPORT, "��������ֻ���"); return; }
	if (!strcmp(airport, "ORY")) { strcpy(AIRPORT, "�����������"); return; }
	if (!strcmp(airport, "MRS")) { strcpy(AIRPORT, "�������ʻ���"); return; }
	if (!strcmp(airport, "LYS")) { strcpy(AIRPORT, "�ﰺ���ʻ���"); return; }
	if (!strcmp(airport, "TXL")) { strcpy(AIRPORT, "����̩�������"); return; }
	if (!strcmp(airport, "BER")) { strcpy(AIRPORT, "���ֲ����Ǳ�����"); return; }
	if (!strcmp(airport, "MUC")) { strcpy(AIRPORT, "Ľ��ڹ��ʻ���"); return; }
	if (!strcmp(airport, "BRE")) { strcpy(AIRPORT, "����÷����BRE"); return; }
	if (!strcmp(airport, "FRA")) { strcpy(AIRPORT, "�����˸�����"); return; }
	if (!strcmp(airport, "STR")) { strcpy(AIRPORT, "˹ͼ���ػ���"); return; }
	if (!strcmp(airport, "HAM")) { strcpy(AIRPORT, "�������ʻ���"); return; }
	if (!strcmp(airport, "NUE")) { strcpy(AIRPORT, "Ŧ�ױ�����"); return; }
	if (!strcmp(airport, "ZRH")) { strcpy(AIRPORT, "���������ʻ���"); return; }
	if (!strcmp(airport, "BRN")) { strcpy(AIRPORT, "�����ᱴ���ջ���"); return; }
	if (!strcmp(airport, "GVA")) { strcpy(AIRPORT, "�����߹��ʻ���"); return; }
	if (!strcmp(airport, "BSL")) { strcpy(AIRPORT, "���������ʻ���"); return; }
	if (!strcmp(airport, "MAD")) { strcpy(AIRPORT, "����������˹����"); return; }
	if (!strcmp(airport, "BCN")) { strcpy(AIRPORT, "�������ǰ������ػ���"); return; }
	if (!strcmp(airport, "VLC")) { strcpy(AIRPORT, "�������ǻ���"); return; }
	if (!strcmp(airport, "SVQ")) { strcpy(AIRPORT, "��ά���ǻ���"); return; }
	if (!strcmp(airport, "AMS")) { strcpy(AIRPORT, "��ķ˹�ص�ʷ���ֻ���"); return; }
	if (!strcmp(airport, "RTM")) { strcpy(AIRPORT, "¹�ص�����"); return; }
	if (!strcmp(airport, "FCO")) { strcpy(AIRPORT, "�����������ŵ��"); return; }
	if (!strcmp(airport, "MXP")) { strcpy(AIRPORT, "���������������"); return; }
	if (!strcmp(airport, "VCE")) { strcpy(AIRPORT, "����˹����"); return; }
	if (!strcmp(airport, "FLR")) { strcpy(AIRPORT, "������������"); return; }
	if (!strcmp(airport, "TRN")) { strcpy(AIRPORT, "�������"); return; }
	if (!strcmp(airport, "LIS")) { strcpy(AIRPORT, "��˹�����ʻ���"); return; }
	if (!strcmp(airport, "OPO")) { strcpy(AIRPORT, "�²�����ʻ���"); return; }
	if (!strcmp(airport, "CPH")) { strcpy(AIRPORT, "�籾������˹���ջ���"); return; }
	if (!strcmp(airport, "PRG")) { strcpy(AIRPORT, "������³��������"); return; }
	if (!strcmp(airport, "HEL")) { strcpy(AIRPORT, "�ն�������������"); return; }
	if (!strcmp(airport, "ATH")) { strcpy(AIRPORT, "�ŵ���ʻ���"); return; }
	if (!strcmp(airport, "ARN")) { strcpy(AIRPORT, "˹�¸��Ħ���������"); return; }
	if (!strcmp(airport, "OSL")) { strcpy(AIRPORT, "��˹½�����¶�����"); return; }
	if (!strcmp(airport, "WAW")) { strcpy(AIRPORT, "��ɳ�¿��л���"); return; }
	if (!strcmp(airport, "BUD")) { strcpy(AIRPORT, "������˹���ﺣ������"); return; }
	if (!strcmp(airport, "VIE")) { strcpy(AIRPORT, "άҲ��ʩΤ���ػ���"); return; }
	if (!strcmp(airport, "BRU")) { strcpy(AIRPORT, "��³�������ʻ���"); return; }
	if (!strcmp(airport, "LUX")) { strcpy(AIRPORT, "¬ɭ�����ʻ���"); return; }
	if (!strcmp(airport, "SVO")) { strcpy(AIRPORT, "Ī˹��л��÷���ֻ���"); return; }
	if (!strcmp(airport, "DME")) { strcpy(AIRPORT, "Ī˹�ƶ�Ī�ܶ��ֻ���"); return; }
	if (!strcmp(airport, "KBP")) { strcpy(AIRPORT, "��������"); return; }
	if (!strcmp(airport, "IEV")) { strcpy(AIRPORT, "�������������"); return; }
	if (!strcmp(airport, "BEG")) { strcpy(AIRPORT, "���������»���"); return; }
	if (!strcmp(airport, "BUH")) { strcpy(AIRPORT, "������˹�ػ���"); return; }
	if (!strcmp(airport, "ZAG")) { strcpy(AIRPORT, "�����ղ�����"); return; }
	if (!strcmp(airport, "LAX")) { strcpy(AIRPORT, "��ɼ���ʻ���"); return; }
	if (!strcmp(airport, "SAN")) { strcpy(AIRPORT, "ʥ���Ǹ����"); return; }
	if (!strcmp(airport, "SNA")) { strcpy(AIRPORT, "���ӿ�����"); return; }
	if (!strcmp(airport, "SFO")) { strcpy(AIRPORT, "�ɽ�ɽ���ʻ���"); return; }
	if (!strcmp(airport, "SJC")) { strcpy(AIRPORT, "ʥ��������"); return; }
	if (!strcmp(airport, "SEA")) { strcpy(AIRPORT, "����ͼ���ʻ���"); return; }
	if (!strcmp(airport, "PDX")) { strcpy(AIRPORT, "����������"); return; }
	if (!strcmp(airport, "PHX")) { strcpy(AIRPORT, "�����˹����"); return; }
	if (!strcmp(airport, "LAS")) { strcpy(AIRPORT, "��˹ά��˹����"); return; }
	if (!strcmp(airport, "SLC")) { strcpy(AIRPORT, "�κ��ǻ���"); return; }
	if (!strcmp(airport, "DEN")) { strcpy(AIRPORT, "�������"); return; }
	if (!strcmp(airport, "AUS")) { strcpy(AIRPORT, "��˹͡����"); return; }
	if (!strcmp(airport, "IAH")) { strcpy(AIRPORT, "��˹�ٹ��ʻ���"); return; }
	if (!strcmp(airport, "HOU")) { strcpy(AIRPORT, "��˹�ٹ��Ȼ���"); return; }
	if (!strcmp(airport, "DFW")) { strcpy(AIRPORT, "����˹����"); return; }
	if (!strcmp(airport, "MCI")) { strcpy(AIRPORT, "����˹�ǻ���"); return; }
	if (!strcmp(airport, "STL")) { strcpy(AIRPORT, "ʥ��·��˹����"); return; }
	if (!strcmp(airport, "MSY")) { strcpy(AIRPORT, "�°¶�������"); return; }
	if (!strcmp(airport, "BHM")) { strcpy(AIRPORT, "����������"); return; }
	if (!strcmp(airport, "MEM")) { strcpy(AIRPORT, "�Ϸ�˹����"); return; }
	if (!strcmp(airport, "BNA")) { strcpy(AIRPORT, "��ʲά������"); return; }
	if (!strcmp(airport, "ORD")) { strcpy(AIRPORT, "֥�Ӹ����"); return; }
	if (!strcmp(airport, "DTW")) { strcpy(AIRPORT, "�����ɻ���"); return; }
	if (!strcmp(airport, "IND")) { strcpy(AIRPORT, "ӡ�ڰ��ǲ���˹"); return; }
	if (!strcmp(airport, "CVG")) { strcpy(AIRPORT, "�����������"); return; }
	if (!strcmp(airport, "CMH")) { strcpy(AIRPORT, "���ײ�����"); return; }
	if (!strcmp(airport, "CLE")) { strcpy(AIRPORT, "������������"); return; }
	if (!strcmp(airport, "PWM")) { strcpy(AIRPORT, "����������"); return; }
	if (!strcmp(airport, "BOS")) { strcpy(AIRPORT, "��ʿ�ٻ���"); return; }
	if (!strcmp(airport, "LGA")) { strcpy(AIRPORT, "ŦԼ���ϵػ���"); return; }
	if (!strcmp(airport, "JFK")) { strcpy(AIRPORT, "ŦԼ����ϻ���"); return; }
	if (!strcmp(airport, "EWR")) { strcpy(AIRPORT, "ŦԼŦ���˻���"); return; }
	if (!strcmp(airport, "PIT")) { strcpy(AIRPORT, "ƥ�ȱ�����"); return; }
	if (!strcmp(airport, "PHL")) { strcpy(AIRPORT, "�ѳǻ���"); return; }
	if (!strcmp(airport, "DCA")) { strcpy(AIRPORT, "��ʢ�ٹ��ʻ���"); return; }
	if (!strcmp(airport, "BWI")) { strcpy(AIRPORT, "�Ͷ���ĥ����"); return; }
	if (!strcmp(airport, "IAD")) { strcpy(AIRPORT, "��ʢ�ٴ���˹����"); return; }
	if (!strcmp(airport, "CLT")) { strcpy(AIRPORT, "�����ػ���"); return; }
	if (!strcmp(airport, "ILM")) { strcpy(AIRPORT, "�������ٻ���"); return; }
	if (!strcmp(airport, "CAE")) { strcpy(AIRPORT, "���ױ��ǻ���"); return; }
	if (!strcmp(airport, "CHS")) { strcpy(AIRPORT, "���˹�ٻ���"); return; }
	if (!strcmp(airport, "ATL")) { strcpy(AIRPORT, "�����������"); return; }
	if (!strcmp(airport, "MCO")) { strcpy(AIRPORT, "���������"); return; }
	if (!strcmp(airport, "TPA")) { strcpy(AIRPORT, "̹������"); return; }
	if (!strcmp(airport, "MIA")) { strcpy(AIRPORT, "�����ܻ���"); return; }
	if (!strcmp(airport, "HNL")) { strcpy(AIRPORT, "��ū³³����"); return; }
	if (!strcmp(airport, "YVR")) { strcpy(AIRPORT, "�¸绪����"); return; }
	if (!strcmp(airport, "YYZ")) { strcpy(AIRPORT, "���׶���ʻ���"); return; }
	if (!strcmp(airport, "YUL")) { strcpy(AIRPORT, "����������³�����"); return; }
	if (!strcmp(airport, "YOW")) { strcpy(AIRPORT, "��̫�����ʻ���"); return; }
	if (!strcmp(airport, "YHZ")) { strcpy(AIRPORT, "��������˹���ʻ���"); return; }
	if (!strcmp(airport, "YYC")) { strcpy(AIRPORT, "����������ʻ���"); return; }
	if (!strcmp(airport, "YEG")) { strcpy(AIRPORT, "�����ɶٹ��ʻ���"); return; }
	if (!strcmp(airport, "TIJ")) { strcpy(AIRPORT, "�ٻ��ɹ��ʻ���"); return; }
	if (!strcmp(airport, "MEX")) { strcpy(AIRPORT, "ī������ʻ���"); return; }
	if (!strcmp(airport, "CUN")) { strcpy(AIRPORT, "�������ʻ���"); return; }
	strcpy(AIRPORT, "û��ƥ�䵽������Ϣ");
	return;
}

