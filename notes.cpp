#include"notes.h"
using namespace std;

int WeekDayTransfer(int year, int month, int day)//ʹ�ò��չ�ʽת������������
{
	int week = 0;
	int century = year / 100;//ע�����ʵ��������ݵ�ǰ��λ������������
	year = year % 100;//��ݵĺ���λ
	if (month == 1 || month == 2)//�·ݵķ�ΧΪ3-14������1��2�±����13��14��
	{
		month += 12;
		year--;
	}
	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
	week = week % 7;
	return (week >= 0) ? week : (7 + week);
}

int DateTransfer(int year, int month, int day)//�������ڶ�Ӧ����
{
	int daycount = 0;
	if (year % 4 == 0 && year % 100 != 0)
		daycount++;
	switch (month)
	{
	case 12:
		daycount += 30;
	case 11:
		daycount += 31;
	case 10:
		daycount += 30;
	case 9:
		daycount += 31;
	case 8:
		daycount += 31;
	case 7:
		daycount += 30;
	case 6:
		daycount += 31;
	case 5:
		daycount += 30;
	case 4:
		daycount += 31;
	case 3:
		daycount += 28;
	case 2:
		daycount += 31;
		daycount += day;
		break;
	}
	return daycount;
}

int JudgeAircraftSize(FlightID* ID, int n)//�жϷɻ���С�ɻ����Ǵ�ɻ���С�ɻ�����1����ɻ�����2
{
	if (strcmp(ID[n].AircraftType, "319") && strcmp(ID[n].AircraftType, "320") && strcmp(ID[n].AircraftType, "321") && strcmp(ID[n].AircraftType, "737") && strcmp(ID[n].AircraftType, "738"))
		return 2;
	else
		return 1;
}

int ImportFlightDatabase(FlightID* ID, char* Location)//�����ڿ�ͷѯ���Ƿ�Ҫ�������к������ݿ�,�������ض�ȡ�������
{
	FILE* fp;
	if ((fp = fopen(Location, "r")) == NULL)
	{
		return -1;
	}
	int FlightIDcount = 0;
	char c;
	while (!feof(fp))
	{
		int i = 1;
		while ((c = fgetc(fp)) != ',')//��ȡ����
		{
			ID[FlightIDcount].FlyDay[i] = c;
			i++;
		}
		i = 0;
		while ((c = fgetc(fp)) != ',')//��ȡ��������
		{
			ID[FlightIDcount].DepartureAirport[i] = c;
			i++;
		}
		ID[FlightIDcount].DepartureAirport[i] = '\0';//�ַ�����β
		fscanf_s(fp, "%d", &ID[FlightIDcount].DepartureTime);//��ȡ����ʱ��
		fgetc(fp);
		fscanf_s(fp, "%d", &ID[FlightIDcount].ArrivalTime);//��ȡ����ʱ��
		i = 0;
		fgetc(fp);
		while ((c = fgetc(fp)) != ',')//��ȡ�������
		{
			ID[FlightIDcount].ArrivalAirport[i] = c;
			i++;
		}
		ID[FlightIDcount].ArrivalAirport[i] = '\0';//�ַ�����β
		i = 0;
		while (i < 2)//��ȡ���չ�˾
		{
			c = fgetc(fp);
			ID[FlightIDcount].Carrier[i] = c;
			i++;
		}
		ID[FlightIDcount].Carrier[i] = '\0';//�ַ�����β
		i = 0;
		while ((c = fgetc(fp)) != ',')//��ȡ�����
		{
			ID[FlightIDcount].ID[i] = c;
			i++;
		}
		ID[FlightIDcount].ID[i] = '\0';//�ַ�����β
		i = 0;
		while ((c = fgetc(fp)) != ',')//��ȡ����
		{
			ID[FlightIDcount].AircraftType[i] = c;
			i++;
		}
		ID[FlightIDcount].AircraftType[i] = '\0';//�ַ�����β
		i = 0;
		while (((c = fgetc(fp)) != ','))//��ȡ��λ
		{
			ID[FlightIDcount].Class[i] = c;
			i++;
		}
		ID[FlightIDcount].Class[i] = '\0';//�ַ�����β
		fscanf_s(fp, "%d", &ID[FlightIDcount].TravelTimeHour);//��ȡ����ʱ��
		c = fgetc(fp);//��ȡð��
		fscanf_s(fp, "%2d", &ID[FlightIDcount].TravelTimeMinute);
		ID[FlightIDcount].Price = ID[FlightIDcount].TravelTimeHour * 675 + ID[FlightIDcount].TravelTimeMinute * 11.25;
		FlightIDcount++;
		if ((c = fgetc(fp)) == EOF)break;
	}
	fclose(fp);
	return FlightIDcount;
}
int SaveFlightDatabase(FlightID* ID, int IDcount, char* Location)
{
	FILE* fp;
	if ((fp = fopen(Location, "w")) == NULL)
	{
		return -1;
	}
	for (int i = 0; i < IDcount; i++)
	{
		fprintf(fp, "%c%c%c%c%c%c%c,%s,%04d,%04d,%s,%s%s,%s,%s,%d:%02d\n", ID[i].FlyDay[1], ID[i].FlyDay[2], ID[i].FlyDay[3], ID[i].FlyDay[4], ID[i].FlyDay[5], ID[i].FlyDay[6], ID[i].FlyDay[7], ID[i].DepartureAirport, ID[i].DepartureTime, ID[i].ArrivalTime, ID[i].ArrivalAirport, ID[i].Carrier, ID[i].ID, ID[i].AircraftType, ID[i].Class, ID[i].TravelTimeHour, ID[i].TravelTimeMinute);
	}
	fclose(fp);
	return IDcount;
}
int ImportTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location)
{
	FILE* fp;
	if ((fp = fopen(Location, "rb")) == NULL)
	{
		return -1;
	}
	fread(DATA, sizeof(FlightTicket), 366 * 999, fp);
	fclose(fp);
	return IDcount;
}
int SaveTicketDatabase(FlightTicket DATA[][999], int IDcount, char* Location)
{
	FILE* fp;
	if ((fp = fopen(Location, "wb")) == NULL)
	{
		return -1;
	}
	fwrite(DATA, sizeof(FlightTicket), 366 * 999, fp);
	fclose(fp);
	return IDcount;
}

void PrintFlightTicket()
{
	;
}

int SearchFlightID(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ţ����ز��ҵ��������
{
	//��ѯ����ŷ������������һ�ִ����֣���û�к��չ�˾���룬��������¿����������ڶ�����ĸ�����֣����к��չ�˾���룬��������º����Ψһ��
	SearchCount = 0; //��¼�������ĺ������,������
	if (strcmp(search, "AAAA") < 0)//������
	{
		for (int i = 0; i < IDcount; i++)
		{
			if (!strcmp(search, ID[i].ID))
			{
				SearchReasult[SearchCount] = i;
				SearchCount++;
			}
		}
	}
	else
	{
		for (int i = 0; i < IDcount; i++)
		{
			char a[12];//�洢���չ�˾+����ŵĺ���
			a[0] = ID[i].Carrier[0];
			a[1] = ID[i].Carrier[1];
			a[2] = '\0';
			strcat(a, ID[i].ID);
			if (!_stricmp(search, a))
			{
				SearchReasult[SearchCount] = i;
				SearchCount++;
				return SearchCount;
			}
		}
	}
	return SearchCount;
}
int SearchFlightDepartureAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ɵأ����ز��ҵ��������
{
	SearchCount = 0; //��¼�������ĺ������,������
	for (int i = 0; i < IDcount; i++)
	{
		if (!_strnicmp(search, ID[i].DepartureAirport, 3))
		{
			SearchReasult[SearchCount] = i;
			SearchCount++;
		}
	}
	return SearchCount;
}
int SearchFlightArrivalAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ɵأ����ز��ҵ��������
{
	SearchCount = 0; //��¼�������ĺ������,������
	for (int i = 0; i < IDcount; i++)
	{
		if (!_strnicmp(search, ID[i].ArrivalAirport, 3))
		{
			SearchReasult[SearchCount] = i;
			SearchCount++;
		}
	}
	return SearchCount;
}
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount)//���Һ���ɵأ����ز��ҵ��������
{
	SearchCount = 0; //��¼�������ĺ������,������
	int TempSearchCount = 0;			//��ʱ�����������ͳ�ƣ����ڴ洢������ɻ���Ҫ��ĺ���
	int TempSearchReasult[999];
	for (int i = 0; i < IDcount; i++)
	{
		if (!_strnicmp(Departure, ID[i].DepartureAirport, 3))
		{
			TempSearchReasult[TempSearchCount] = i;
			TempSearchCount++;
		}
	}
	for (int i = 0; i < TempSearchCount; i++)
	{
		if (!_strnicmp(Arrival, ID[TempSearchReasult[i]].ArrivalAirport, 3))
		{
			SearchReasult[SearchCount] = TempSearchReasult[i];
			SearchCount++;
		}
	}
	return SearchCount;
}

//���أ�ȫ���ݿ�����/����������ݿ�����
int SortByDepartureTime(FlightID* ID, int IDcount, int* SortReasult)//ð�����򷨰���ʱ���������к��ࣻע��˺���������
{
	int i;
	//����Ҫ��ʼ��һ�´洢������������
	for (i = 0; i < IDcount; i++)
	{
		SortReasult[i] = i;
	}
	int i1, i2;
	//��дһ��ʱ�����絽���
	//˭��ʱ����������أ��Ͳ�д�ˡ�
	for (i1 = 0; i1 < (IDcount - 1); i1++)
	{
		for (i2 = 0; i2 < (IDcount - i1 - 1); i2++)
		{
			if (ID[SortReasult[i2]].DepartureTime > ID[SortReasult[i2 + 1]].DepartureTime)
			{
				int Switch;
				Switch = SortReasult[i2];
				SortReasult[i2] = SortReasult[i2 + 1];
				SortReasult[i2 + 1] = Switch;
			}
		}
	}
	return 0;
}
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult)//ð�����򷨰���ʱ������������������ע��˺���������
{
	int i;
	//����Ҫ��ʼ��һ�´洢������������
	for (i = 0; i < SearchCount; i++)
	{
		SortReasult[i] = SearchReasult[i];
	}
	int i1, i2;
	//��дһ��ʱ�����絽���
	//˭��ʱ����������أ��Ͳ�д�ˡ�
	for (i1 = 0; i1 < (SearchCount - 1); i1++)
	{
		for (i2 = 0; i2 < (SearchCount - i1 - 1); i2++)
		{
			if (ID[SortReasult[i2]].DepartureTime > ID[SortReasult[i2 + 1]].DepartureTime)
			{
				int Switch;
				Switch = SortReasult[i2];
				SortReasult[i2] = SortReasult[i2 + 1];
				SortReasult[i2 + 1] = Switch;
			}
		}
	}
	return 0;
}

//���أ�����Ӻ���ȡ��ʱʹ�õڶ���
int DeleteFlight(FlightID* ID, FlightTicket DATA[][999], int& IDcount, int Delete)
{
	for (int i = Delete; i < IDcount; i++)
	{
		ID[i] = ID[i + 1];
		for (int i2 = 0; i2 < 366; i2++)
		{
			DATA[i2][i] = DATA[i2][i + 1];
		}
	}
	IDcount--;
	return IDcount;
}
int DeleteFlight(FlightID* ID, int& IDcount, int Delete)
{
	for (int i = Delete; i < IDcount; i++)
	{
		ID[i] = ID[i + 1];
	}
	IDcount--;
	return IDcount;
}

int C_InputBox(char* Input, int Limit, int x, int y, const char * Default)
{
	clearrectangle(x, y, x + 160, y + 40);
	fflush(stdin);//��������뻺��
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	settextstyle(28, 0, FONT2_EN);
	setlinecolor(BLACK);
	for (int i = x + 5; i < x + 155; i++)
	{
		line(i, y + 35, i + 1, y + 35);
		Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x + 10, y + 4,Default);
	settextcolor(BLACK);
	while (true)
	{
		c = _getch();
		if (c != 13)//�������Ĳ��ǻس�
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + 160, y + 34);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			{
				if (Length == Limit - 1)
				{
					;
				}
				else
				{
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + 10 + 14 * Length, y + 6, c);
					setlinecolor(RGB(0, 191, 255));
					line(x + 8 + Length * 14, y + 35, x + 22 + Length * 14, y + 35);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + 10 + 14 * Length, y, x + 24 + 14 * Length, y + 34);
					setlinecolor(BLACK);
					line(x + 8 + Length * 14, y + 35, x + 22 + Length * 14, y + 35);
				}
			}
		}
		else
		{
			strcpy(Input, InputBuf);
			return Length;
		}
	}
}

int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize);
	fflush(stdin);//��������뻺��
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	settextstyle(Hsize, 0, FONT);
	setlinecolor(BLACK);
	for (int i = x; i < x + Lsize; i++)
	{
		line(i, y + Hsize +2, i + 1, y + Hsize +2);
		Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x, y, Default);
	settextcolor(BLACK);
	while (true)
	{
		c = _getch();
		if (c != 13)//�������Ĳ��ǻس�
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + Lsize, y + Hsize);
				settextcolor(RGB(220, 220, 220));
				outtextxy(x, y, Default);
				settextcolor(BLACK);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			{
				if (Length == Limit - 1)
				{
					;
				}
				else
				{
					if (Length == 0)//��һ���ַ�
					{
						clearrectangle(x, y, x + Lsize, y + Hsize);
					}
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + (Hsize / 2) * Length, y, c);
					setlinecolor(RGB(0, 191, 255));
					line(x + Length * (Hsize / 2), y + Hsize + 2, x + (Length + 1) * (Hsize / 2), y + Hsize + 2);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + Length * (Hsize / 2), y, x + (Length + 1) * (Hsize / 2), y + Hsize);
					setlinecolor(BLACK);
					line(x + Length * (Hsize / 2), y + Hsize + 2, x + (Length + 1) * (Hsize / 2), y + Hsize + 2);
				}
			}
		}
		else
		{
			strcpy(Input, InputBuf);
			return Length;
		}
	}
}