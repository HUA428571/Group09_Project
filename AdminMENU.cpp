#include"AdminMENU.h"

int AdminMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)

{
	int SearchReasult[999];//���ڴ洢�������
	int SearchCount = 0;//�洢���������
	int SortReasult[999];//���ڴ洢������˳�������Ͳ������ԭ�еĽṹ������˳�򣬲�Ӱ���±���ʡ�
	//Resize();
	initgraph(1280, 720, EW_SHOWCONSOLE | EW_NOCLOSE);	// ������ͼ���ڣ���СΪ 1280x720 ����
	// ���ñ���ɫΪ����ɫ
	setbkcolor(RGB(255, 255, 253));
	// �ñ���ɫ�����Ļ
	cleardevice();
	settextcolor(BLACK);
	//settextstyle(20, 0, _T(FONT));
	//char s2[] = "��ӭ���ʹ���Ա��̨";


	//LOGFONT format;
	//gettextstyle(&format);						// ��ȡ��ǰ��������
	//format.lfHeight = 25;						// ��������߶�Ϊ 25
	//_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	//format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	//settextstyle(&format);							// ����������ʽ
	//outtextxy(20, 20, "��ã�");
	//Sleep(500);
	//cleardevice();
	//outtextxy(20, 20, "��ӭ���ʹ���Ա��̨����ϵͳ");
	//Sleep(1000);
	//cleardevice();
	//outtextxy(20, 20, "��Ȩ���� CopyRight 2020 HuaCL");
	//Sleep(1000);
	//cleardevice();

	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	//format.lfWeight = FW_LIGHT;			// ��������ΪLight 
	//format.lfOutPrecision = OUT_TT_PRECIS;
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// ��������ΪFONT
	settextstyle(&format);						// ����������ʽ
	PrintLoading();

	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Home.png"), 1280, 720);
	putimage(0, 0, &BG);	// ��ʾ����
	int MENUchoice;
	MENUchoice = AdminMENU_MainMENU(ID, DATA, IDcount);			//�Ƚ�����ҳ
	while (true)											//ѭ��
	{
		switch (MENUchoice)
		{
		case 0:
			MENUchoice = AdminMENU_MainMENU(ID, DATA, IDcount);
			break;
		case 1:
			MENUchoice = AdminMENU_SearchMENU(ID, DATA, IDcount);
			break;
		case 2:
			MENUchoice = AdminMENU_AddMENU(ID, DATA, IDcount);
			break;
		case 3:
			MENUchoice = AdminMENU_DeleteMENU(ID, DATA, IDcount);
			break;
		case 4:
			MENUchoice = AdminMENU_ChangeMENU(ID, DATA, IDcount);
			break;
		case 5:
			PrintExit(ID, DATA, IDcount);
			closegraph();			// �رջ�ͼ����
			return 0;
		}
	}
}
int AdminMENU_MainMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	IMAGE BG;
	MOUSEMSG m;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\Home.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	settextcolor(BLACK);
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 20;						// ��������߶�Ϊ 20
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	char count[8];
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "��");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "��");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "��");

	settextstyle(25, 0, FONT);
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	char Location[4][100] = { ".\\Default_FlightID_Database_NEW.txt",".\\Default_Ticket_Database.dat",".\\FlightID.txt",".\\Ticket.dat" };
	int MENUchoice = AdminMENU_MainMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return MENUchoice;
		case 51:
			MENUchoice = AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
			break;
		case 52:
			MENUchoice = AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
			break;
		case 53:
			MENUchoice = AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
			break;
		case 54:
			MENUchoice = AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
			break;
		}
	}
	return AdminMENU_MENUChoose();
}
int AdminMENU_MainMENU_ImportFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int& IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Import.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	settextcolor(RED);
	outtextxy(400, 200, "�ر���ʾ����ע�⺽���뺽�����ݿ��ƥ��");
	settextcolor(BLACK);
	outtextxy(400, 240, "��������Ŀ¼���뺽�����ݿ⣺");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[0]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		//���ڼӵ㶯����
		//�ټ�һ���������ʧ�ָܻ��Ĺ���
		IDcount = ImportFlightDatabase(ID, Location[0]);
		clearrectangle(400, 200, 1220, 400);
		if (IDcount == -1)
		{
			outtextxy(400, 200, "����ʧ��");
			IDcount++;//��idcount���û���
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "������");
			char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "����������");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "��ȡ������");
		Sleep(500);
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "�������µ��ļ�·����");
		if (LocationTEMP[1] == 0)//�������Ϊ�գ��򷵻�ԭ��Ŀ¼
		{
			outtextxy(400, 280, "��Ч��Ŀ¼��");
			Sleep(50);
		}
		else
		{
			strcpy(Location[0], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
}
int AdminMENU_MainMENU_ImportTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Import.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	settextcolor(RED);
	outtextxy(400, 200, "�ر���ʾ����ע�⺽���뺽�����ݿ��ƥ��");
	settextcolor(BLACK);
	outtextxy(400, 240, "��������Ŀ¼�����Ʊ���ݿ⣺");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[1]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		//���ڼӵ㶯����
		//�ټ�һ���������ʧ�ָܻ��Ĺ���
		IDcount = ImportTicketDatabase(DATA, IDcount, Location[1]);
		clearrectangle(400, 200, 1220, 400);
		if (IDcount == -1)
		{
			outtextxy(400, 200, "����ʧ��");
			IDcount++;//��idcount���û���
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "������ȫ����Ʊ���ݿ�");
			/*char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "����������");*/
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "��ȡ������");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "�������µ��ļ�·����");
		if (LocationTEMP[1] == 0)//�������Ϊ�գ��򷵻�ԭ��Ŀ¼
		{
			outtextxy(400, 280, "��Ч��Ŀ¼��");
			Sleep(50);
		}
		else
		{
			strcpy(Location[1], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
}
int AdminMENU_MainMENU_SaveFlightDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Export.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	settextcolor(RED);
	outtextxy(400, 200, "�ر���ʾ����ע�⺽���뺽�����ݿ��ƥ��");
	settextcolor(BLACK);
	outtextxy(400, 240, "��������Ŀ¼�����������ݿ⣺");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[2]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	int success;
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		success = SaveFlightDatabase(ID, IDcount, Location[2]);
		clearrectangle(400, 200, 1220, 400);
		if (success == -1)
		{
			outtextxy(400, 200, "����ʧ��");
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "������");
			char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "����������");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "��ȡ������");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "�������µ��ļ�·����");
		if (LocationTEMP[1] == 0)//�������Ϊ�գ��򷵻�ԭ��Ŀ¼
		{
			outtextxy(400, 280, "��Ч��Ŀ¼��");
			Sleep(50);
		}
		else
		{
			strcpy(Location[2], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
}
int AdminMENU_MainMENU_SaveTicketDatabase(FlightID* ID, FlightTicket DATA[][999], int IDcount, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Export.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	settextcolor(RED);
	outtextxy(400, 200, "�ر���ʾ����ע�⺽���뺽�����ݿ��ƥ��");
	settextcolor(BLACK);
	outtextxy(400, 240, "��������Ŀ¼������Ʊ���ݿ⣺");
	settextstyle(20, 0, FONT);
	outtextxy(400, 280, Location[3]);
	int MENUchoice = AdminMENU_MainMENU_Import_MENUChoose();
	int success;
	switch (MENUchoice)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 51:
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	case 52:
		return AdminMENU_MainMENU_ImportTicketDatabase(ID, DATA, IDcount, Location);
	case 53:
		return AdminMENU_MainMENU_SaveFlightDatabase(ID, DATA, IDcount, Location);
	case 54:
		return AdminMENU_MainMENU_SaveTicketDatabase(ID, DATA, IDcount, Location);
	case 57:
		//���ڼӵ㶯����
		//�ټ�һ���������ʧ�ָܻ��Ĺ���
		success = SaveTicketDatabase(DATA, IDcount, Location[3]);
		clearrectangle(400, 200, 1220, 400);
		if (success == -1)
		{
			outtextxy(400, 200, "����ʧ��");
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "���������л�Ʊ����");
			/*char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "����������");*/
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "��ȡ������");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "�������µ��ļ�·����");
		if (LocationTEMP[1] == 0)//�������Ϊ�գ��򷵻�ԭ��Ŀ¼
		{
			outtextxy(400, 280, "��Ч��Ŀ¼��");
			Sleep(50);
		}
		else
		{
			strcpy(Location[3], LocationTEMP);
		}
		return AdminMENU_MainMENU_ImportFlightDatabase(ID, DATA, IDcount, Location);
	}
}


int AdminMENU_SearchMENU(FlightID* ID, FlightTicket DATA[][999], int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	loadimage(&BG, _T(".\\IMAGES\\Search.png"), 1280, 720);
	putimage(0, 0, &BG);						// ���±���
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 20;						// ��������߶�Ϊ 20
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	int SearchReasult[999];//���ڴ洢�������
	int SearchCount = 0;
	int MENUchoice = AdminMENU_SearchMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 11:
			MENUchoice = AdminMENU_SearchMENU_SearchByID(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		case 12:
			MENUchoice = AdminMENU_SearchMENU_SearchByDepartureAirport(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		case 13:
			MENUchoice = AdminMENU_SearchMENU_SearchByArrivalAirport(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		case 14:
			MENUchoice = AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(ID, DATA, IDcount, SearchReasult, SearchCount);
			break;
		}
	}
	//�洢���������
	//TextBox textbox(140,260,340,290,50);
	//char UserInput;
	//char search[12];
	//while (true)
	//{
	//	UserInput = Input();
	//	int i = 0;
	//	if (UserInput != 0)
	//	{
	//		textbox.Append(UserInput);
		//		if (UserInput != 8)
	//		{
	//			search[i] = UserInput;
	//			i++;
	//		}
		//		//// �ж�������ַ����Ƿ��������ַ������
	//		//for (int i = 0; i < 3; i++)
	//		//	if (wcscmp(textbox.Text(), words[i].p) == 0)
	//		//	{
	//		//		InitTarget(words, i);
	//		//		textbox.Empty();
	//		//	}
	//	}
	//	textbox.Draw();
	//}
}
int AdminMENU_SearchMENU_SearchByID(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char search[12];
	InputBox(search, 12, "�����������ѯ�ĺ����");
	SearchFlightID(ID, search, IDcount, SearchReasult, SearchCount);//���Һ���ţ����ز��ҵ��������
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "û���ҵ�����Ҫ��ĺ��࣡");
		break;
	case 1:
		return PrintSingleFlight(ID, DATA, IDcount,SearchReasult[0]);
	default:
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char search[12];
	InputBox(search, 12, "�����������ѯ�������ɵ�");
	SearchFlightDepartureAirport(ID, search, IDcount, SearchReasult, SearchCount);//���Һ���ţ����ز��ҵ��������
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "û���ҵ�����Ҫ��ĺ��࣡");
		break;
	case 1:
		return PrintSingleFlight(ID, DATA,IDcount, SearchReasult[0]);
	default:
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char search[12];
	InputBox(search, 12, "�����������ѯ����Ľ����");
	SearchFlightArrivalAirport(ID, search, IDcount, SearchReasult, SearchCount);//���Һ���ţ����ز��ҵ��������
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "û���ҵ�����Ҫ��ĺ��࣡");
		break;
	case 1:
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	clearrectangle(380, 170, 1220, 680);
	char Departure[12];
	InputBox(Departure, 12, "�����������ѯ�������ɵ�");
	char Arrival[12];
	InputBox(Arrival, 12, "�����������ѯ����Ľ����");
	SearchFlightDepartureAndArrivalAirport(ID, Departure, Arrival, IDcount, SearchReasult, SearchCount);//���Һ���ɵأ����ز��ҵ��������
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "û���ҵ�����Ҫ��ĺ��࣡");
		break;
	case 1:
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}


int AdminMENU_AddMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	MOUSEMSG m;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 20;						// ��������߶�Ϊ 20
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	InputBox(Input, 12, "�����º���ĺ����\n��������ţ�eg CA101");
	int SearchReasult[999];
	int SearchCount;
	if (SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
	{
		outtextxy(380, 200, "����Ų����ظ���\n��ȡ������¼�롣");
		return AdminMENU_MENUChoose();
	}
	ID[IDcount].Carrier[0] = Input[0];
	ID[IDcount].Carrier[1] = Input[1];
	ID[IDcount].Carrier[2] = '\0';
	ID[IDcount].ID[0] = Input[2];
	ID[IDcount].ID[1] = Input[3];
	ID[IDcount].ID[2] = Input[4];
	ID[IDcount].ID[3] = Input[5];
	ID[IDcount].ID[4] = Input[6];
	ID[IDcount].ID[5] = Input[7];
	ID[IDcount].ID[6] = Input[8];
	ID[IDcount].ID[7] = Input[9];
	InputBox(ID[IDcount].FlyDay, 9, "�����º���Ŀ�������\n��λΪ0,Ȼ��1:����,2:������");
	InputBox(ID[IDcount].DepartureAirport, 8, "�����º������ɻ���\n���ִ��룬eg PEK");
	InputBox(ID[IDcount].ArrivalAirport, 8, "�����º���Ľ������\n���ִ��룬eg PEK");
	InputBox(Input, 8, "�����º�������ʱ��\n�����룬eg 1230");
	sscanf(Input, "%d", &ID[IDcount].DepartureTime);
	InputBox(Input, 8, "�����º���ĵ���ʱ��\n�����룬eg 1230");
	sscanf(Input, "%d", &ID[IDcount].ArrivalTime);
	InputBox(Input, 8, "�����º���ķ���ʱ��\nСʱ");
	sscanf(Input, "%d", &ID[IDcount].TravelTimeHour);
	InputBox(Input, 8, "�����º���ķ���ʱ��\n����");
	sscanf(Input, "%d", &ID[IDcount].TravelTimeMinute);
	InputBox(ID[IDcount].AircraftType, 4, "�����º����ִ�ɻ���\n�����룬eg 747");
	InputBox(ID[IDcount].Class, 4, "�����º���Ĳ�λ\neg CY");
	ID[IDcount].Price = ID[IDcount].TravelTimeHour * 675 + ID[IDcount].TravelTimeMinute * 11.25;
	loadimage(&BG, _T(".\\IMAGES\\Add.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	PrintFlightDetail(ID, DATA, IDcount, IDcount);
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
	switch (MENUchoice)
	{
	case 22:
		DeleteFlight(ID, IDcount, IDcount);
		outtextxy(380, 170, "��ȡ�����");
		MENUchoice = AdminMENU_MENUChoose();
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 21:
		loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
		putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
		outtextxy(380, 170, "�ѳɹ����");
		PrintFlightDetail(ID, DATA, IDcount, IDcount);
		IDcount++;
		gettextstyle(&format);						// ��ȡ��ǰ��������
		format.lfHeight = 25;						// ��������߶�Ϊ 25
		_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
		format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
		settextstyle(&format);						// ����������ʽ
		char count[8];
		_stprintf(count, _T("%d"), IDcount);
		outtextxy(110, 200, "��ǰ���ݿ�����");
		outtextxy(110, 230, count);
		outtextxy(162, 230, "����������");
		return AdminMENU_MENUChoose();
	}
}


int AdminMENU_DeleteMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	MOUSEMSG m;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	settextcolor(BLACK);
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);							// ����������ʽ
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	char Delete[12];
	int SearchReasult[999];
	int SearchCount;
	InputBox(Delete, 12, "����������ɾ���ĺ����\n��������ţ�eg CA101");
	SearchFlightID(ID, Delete, IDcount, SearchReasult, SearchCount);//���Һ���ţ����ز��ҵ��������
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "û���ҵ�����Ҫ��ĺ��࣡");
		break;
	case 1:
		loadimage(&BG, _T(".\\IMAGES\\Delete.png"), 1280, 720);
		putimage(0, 0, &BG);	// ��ʾɾ�����汳��
		PrintFlightDetail(ID, DATA, IDcount, SearchReasult[0]);
		int MENUchoice = AdminMENU_DeleteMENU_MENUChoose();
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 31:
			clearrectangle(100, 200, 1220, 680);//����ʾ�������
			DeleteFlight(ID, DATA, IDcount, SearchReasult[0]);
			outtextxy(380, 200, "�ѳɹ�ɾ��");
			break;
		case 32:
			clearrectangle(100, 200, 1220, 680);//����ʾ�������
			outtextxy(380, 200, "��ȡ��ɾ��");
			break;
		}
		break;
	}
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);						// ����������ʽ
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	return AdminMENU_MENUChoose();
}


int AdminMENU_ChangeMENU(FlightID* ID, FlightTicket DATA[][999], int IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	MOUSEMSG m;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// ����һ��λ���ٴ���ʾ����
	char count[8];
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// ��������ΪFONT
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	settextstyle(&format);							// ����������ʽ
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	while (true)
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//��갴�ڸ�������
				return 4;
		}
	}
}
