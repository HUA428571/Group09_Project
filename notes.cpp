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

int ImportFlightDatabase(FlightID* ID)//�����ڿ�ͷѯ���Ƿ�Ҫ�������к������ݿ�,�������ض�ȡ�������
{
	char choice;
	do {
		cout << "����Ĭ�Ϻ�������(1)/�ϴα���ĺ�������(2)/������(N)��" << endl;
		cin >> choice;
	} while (choice != '1' && choice != '2' && choice != 'n' && choice != 'N');
	if (choice == '1' || choice == '2')
	{
		FILE* fp;
		if (choice == '1')
		{
			if ((fp = fopen(".\\Default_FlightID_Database_NEW.txt", "r")) == NULL)
			{
				printf("Fail to open file!\n");
				return 0;
			}
		}
		else
		{
			if ((fp = fopen(".\\FlightID_Database.txt", "r")) == NULL)
			{
				printf("Fail to open file!\n");
				return 0;
			}
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
		cout << "�ɹ�����" << FlightIDcount << "���������ݣ�" << endl;
		return FlightIDcount;
	}
	if (choice == 'n' || choice == 'N')
	{
		return 0;
	}
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
int SaveFlightDatabase(FlightID* ID, int IDcount)
{
	char choice;
	FILE* fp;
	do {
		cout << "���������ݿ�(A)/���������ݿ�������(B)" << endl;
		cin >> choice;
	} while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b');
	if (choice == 'A' || choice == 'a')
	{
		if ((fp = fopen(".\\FlightID_Database.txt", "w")) == NULL)
		{
			printf("Fail to establish new file!\n");
			return 0;
		}
	}
	else
	{
		if ((fp = fopen(".\\FlightID_Database.txt", "a")) == NULL)
		{
			printf("Fail to open file!\n");
			return 0;
		}
	}
	for (int i = 0; i < IDcount; i++)
	{
		//printf("%c%c%c%c%c%c%c,%s,%04d,%04d,%s,%s%s,%s,%s,%d:%02d\n", ID[i].FlyDay[1], ID[i].FlyDay[2], ID[i].FlyDay[3], ID[i].FlyDay[4], ID[i].FlyDay[5], ID[i].FlyDay[6], ID[i].FlyDay[7], ID[i].DepartureAirport, ID[i].DepartureTime, ID[i].ArrivalTime, ID[i].ArrivalAirport, ID[i].Carrier, ID[i].ID, ID[i].AircraftType, ID[i].Class, ID[i].TravelTimeHour, ID[i].TravelTimeMinute);
		fprintf(fp, "%c%c%c%c%c%c%c,%s,%04d,%04d,%s,%s%s,%s,%s,%d:%02d\n", ID[i].FlyDay[1], ID[i].FlyDay[2], ID[i].FlyDay[3], ID[i].FlyDay[4], ID[i].FlyDay[5], ID[i].FlyDay[6], ID[i].FlyDay[7], ID[i].DepartureAirport, ID[i].DepartureTime, ID[i].ArrivalTime, ID[i].ArrivalAirport, ID[i].Carrier, ID[i].ID, ID[i].AircraftType, ID[i].Class, ID[i].TravelTimeHour, ID[i].TravelTimeMinute);
	}
	cout << "�ѳɹ�����" << IDcount << "����������" << endl;
	fclose(fp);
	return IDcount;
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


void PrintFlight(FlightID* ID, int n, int i)//�������飬�����±꣬���
{
	printf("%d\t%s%s\t\t%04d\t\t%s\t\t%s\t\t%04d\t\t%dСʱ%02d����\t%s\n", i, ID[n].Carrier, ID[n].ID, ID[n].DepartureTime, ID[n].DepartureAirport, ID[n].ArrivalAirport, ID[n].ArrivalTime, ID[n].TravelTimeHour, ID[n].TravelTimeMinute, ID[n].AircraftType);
	return;
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


int PrintSearch(FlightID* ID, int IDcount, int* SearchReasult, int& SearchCount)//չʾ��ѯ�Ľ��
{
	int SearchReasultChoice;
	if (SearchCount)
	{
		if (SearchCount == 1)
		{
			cout << "�ɹ��ҵ�һ�����࣡" << endl;
			return SearchReasult[0];
		}
		else
		{
			cout << "��Ϊ���ҵ�" << SearchCount << "������\n" << "��ѡ������Ҫ��ѯ�ĺ�����ţ�" << endl;
			for (int i = 0; i <= SearchCount; i++)
			{
				PrintFlight(ID, i, i + 1);
			}
			cin >> SearchReasultChoice;
			return SearchReasult[SearchReasultChoice - 1];
		}
	}
	else
	{
		cout << "û���ҵ����������ĺ��࣡" << endl;
		return 999;
	}
}

//����Ѿ��ò�����
int NewFlight(FlightID* ID, int& IDcount)
{
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	int SearchReasult[2];
	int SearchCount = 0;
	cout << "��������������ţ�";
	cin >> Input;
	if (SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
	{
		cout << "�ظ��ĺ���ţ�����������\n";
		return IDcount;
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
	cout << "�����뿪�����ڣ�";
	cin >> ID[IDcount].FlyDay;
	cout << "��������ɻ�����";
	cin >> ID[IDcount].DepartureAirport;
	cout << "�����뽵�������";
	cin >> ID[IDcount].ArrivalAirport;
	cout << "���������ʱ�䣺";
	cin >> ID[IDcount].DepartureTime;
	cout << "�����뽵��ʱ�䣺";
	cin >> ID[IDcount].ArrivalTime;
	cout << "���������ʱ�䣨Сʱ����";
	cin >> ID[IDcount].TravelTimeHour;
	cout << "���������ʱ�䣨���ӣ���";
	cin >> ID[IDcount].TravelTimeMinute;
	cout << "������ִ�ɻ��ͣ�";
	cin >> ID[IDcount].AircraftType;
	cout << "�������λ��";
	cin >> ID[IDcount].Class;
	ID[IDcount].Price = ID[IDcount].TravelTimeHour * 675 + ID[IDcount].TravelTimeMinute * 11.25;
	IDcount++;
	cout << "�ѳɹ���ӵ�" << IDcount << "����������" << endl;//��仰���ܺ���Ҫ�ӵ��ϼ��˵�������ͷ
	return IDcount;
}//��ѡ���ܣ������������ݵ���ȷ�ԣ��������̫�����ˣ��Ȳ�����


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

int C_InputBox(char* Input, int Limit, int x, int y)
{
	clearrectangle(x, y, x + 160, y + 40);
	fflush(stdin);
	char c;
	int Length=0;
	char InputBuf[100] = { '\0' };
	settextstyle(25, 0, "Consolas");
	while (true)
	{
		c = _getch();
		if (c != 13)//�������Ĳ��ǻس�
		{
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
					outtextxy(x + 10 + 10 * Length, y + 8, c);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + 10 + 10 * Length, y, x + 20 + 10 * Length, y + 40);
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