#include"notes.h"
using namespace std;
//使用蔡勒公式转换日期与星期
int WeekDayTransfer(int year, int month, int day)//使用蔡勒公式转换日期与星期
{
	int week = 0;
	int century = year / 100;				//注意这边实际上是年份的前两位，不是世纪数
	year = year % 100;						//年份的后两位
	if (month == 1 || month == 2)			//月份的范围为3-14，所以1月2月变成了13月14月
	{
		month += 12;
		year--;
	}
	week = year + year / 4 + century / 4 - 2 * century + (26 * (month + 1)) / 10 + day - 1;
	week = week % 7;
	return (week >= 0) ? week : (7 + week);
}
//返回日期对应天数
int DateTransfer(int year, int month, int day)//返回日期对应天数
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
//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
int JudgeAircraftSize(FlightID* ID, int n)//判断飞机是小飞机还是大飞机，小飞机返回1，大飞机返回2
{
	if (strcmp(ID[n].AircraftType, "319") && strcmp(ID[n].AircraftType, "320") && strcmp(ID[n].AircraftType, "321") && strcmp(ID[n].AircraftType, "737") && strcmp(ID[n].AircraftType, "738"))
		return 2;
	else
		return 1;
}
//导入导出数据库
int ImportFlightDatabase(FlightID* ID, char* Location)//用于在开头询问是否要引入现有航线数据库,函数返回读取航班个数
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
		while ((c = fgetc(fp)) != ',')//读取班期
		{
			ID[FlightIDcount].FlyDay[i] = c;
			i++;
		}
		i = 0;
		while ((c = fgetc(fp)) != ',')//读取出发机场
		{
			ID[FlightIDcount].DepartureAirport[i] = c;
			i++;
		}
		ID[FlightIDcount].DepartureAirport[i] = '\0';//字符串结尾
		fscanf_s(fp, "%d", &ID[FlightIDcount].DepartureTime);//读取出发时间
		fgetc(fp);
		fscanf_s(fp, "%d", &ID[FlightIDcount].ArrivalTime);//读取到达时间
		i = 0;
		fgetc(fp);
		while ((c = fgetc(fp)) != ',')//读取到达机场
		{
			ID[FlightIDcount].ArrivalAirport[i] = c;
			i++;
		}
		ID[FlightIDcount].ArrivalAirport[i] = '\0';//字符串结尾
		i = 0;
		while (i < 2)//读取航空公司
		{
			c = fgetc(fp);
			ID[FlightIDcount].Carrier[i] = c;
			i++;
		}
		ID[FlightIDcount].Carrier[i] = '\0';//字符串结尾
		i = 0;
		while ((c = fgetc(fp)) != ',')//读取航班号
		{
			ID[FlightIDcount].ID[i] = c;
			i++;
		}
		ID[FlightIDcount].ID[i] = '\0';//字符串结尾
		i = 0;
		while ((c = fgetc(fp)) != ',')//读取机型
		{
			ID[FlightIDcount].AircraftType[i] = c;
			i++;
		}
		ID[FlightIDcount].AircraftType[i] = '\0';//字符串结尾
		i = 0;
		while (((c = fgetc(fp)) != ','))//读取舱位
		{
			ID[FlightIDcount].Class[i] = c;
			i++;
		}
		ID[FlightIDcount].Class[i] = '\0';//字符串结尾
		fscanf_s(fp, "%d", &ID[FlightIDcount].TravelTimeHour);//读取飞行时间
		c = fgetc(fp);//读取冒号
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
//查找航班号，返回查找到航班个数
int SearchFlightID(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//查找航班号，返回查找到航班个数
{
	//查询航班号分两种情况，第一种纯数字，即没有航空公司代码，这种情况下可能重名；第二种字母加数字，即有航空公司代码，这种情况下航班号唯一。
	SearchCount = 0; //记录搜索到的航班个数,先置零
	if (strcmp(search, "AAAA") < 0)//纯数字
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
			char a[12];//存储航空公司+航班号的合体
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
//查找航起飞地，返回查找到航班个数
int SearchFlightDepartureAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//查找航起飞地，返回查找到航班个数
{
	SearchCount = 0; //记录搜索到的航班个数,先置零
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
//查找航降落地，返回查找到航班个数
int SearchFlightArrivalAirport(FlightID* ID, char* search, int IDcount, int* SearchReasult, int& SearchCount)//查找航起飞地，返回查找到航班个数
{
	SearchCount = 0; //记录搜索到的航班个数,先置零
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
//查找航起飞降落地，返回查找到航班个数
int SearchFlightDepartureAndArrivalAirport(FlightID* ID, char* Departure, char* Arrival, int IDcount, int* SearchReasult, int& SearchCount)//查找航起飞地，返回查找到航班个数
{
	SearchCount = 0; //记录搜索到的航班个数,先置零
	int TempSearchCount = 0;			//临时搜索结果个数统计，用于存储符合起飞机场要求的航班
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
//按照起飞时间排序
//重载，全数据库排序/搜索结果数据库排序
int SortByDepartureTime(FlightID* ID, int IDcount, int* SortReasult)//冒泡排序法按照时间排序所有航班；注意此函数有重载
{

	int i;
	//首先要初始化一下存储排序结果的数组
	for (i = 0; i < IDcount; i++)

	{
		SortReasult[i] = i;
	}
	int i1, i2;
	//先写一个时间由早到晚的
	//谁会时间由晚到早查呢，就不写了。
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
int SortByDepartureTime(FlightID* ID, int* SearchReasult, int SearchCount, int* SortReasult)//冒泡排序法按照时间排序搜索航班结果；注意此函数有重载
{
	int i;
	//首先要初始化一下存储排序结果的数组
	for (i = 0; i < SearchCount; i++)
	{
		SortReasult[i] = SearchReasult[i];
	}
	int i1, i2;
	//先写一个时间由早到晚的
	//谁会时间由晚到早查呢，就不写了。
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

//删除
//重载，当添加航班取消时使用第二个

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
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default)
{
	clearrectangle(x, y, x + 160, y + 40);
	fflush(stdin);//先清空输入缓存
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
	outtextxy(x + 10, y + 4, Default);
	settextcolor(BLACK);
	while (true)
	{
		c = _getch();
		if (c != 13)//如果输入的不是回车
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
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	settextstyle(Hsize, 0, FONT);
	setlinecolor(BLACK);
	for (int i = x; i < x + Lsize; i++)
	{
		line(i, y + Hsize + 2, i + 1, y + Hsize + 2);
		Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x, y, Default);
	settextcolor(BLACK);
	while (true)
	{
		c = _getch();
		if (c != 13)//如果输入的不是回车
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
				if (Length == Limit)
				{
					;
				}
				else
				{
					if (Length == 0)//第一个字符
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
//计算飞行数据
int CountFlyingDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int wday, int yday,
	int* FlyingID, int& FlyCount, int& OnTimeCount, int& DelayCount, int& CancelCount)
{
	int Arrival;
	if (wday == 0)
		wday = 7;
	FlyCount = 0;
	OnTimeCount = 0;
	DelayCount = 0;
	CancelCount = 0;
	for (int i = 0; i < IDcount; i++)
	{
		if (ID[i].FlyDay[wday] != '0')
		{
			FlyingID[FlyCount] = i;
			FlyCount++;
			if (DATA[yday][i].ActuralDepartureTime == 2500)
			{
				CancelCount++;
				continue;
			}
			if ((ID[i].ArrivalTime % 100) >= 45)
				Arrival = ID[i].ArrivalTime + 65;
			else
				Arrival = ID[i].ArrivalTime + 15;
			if (DATA[yday][i].ActuralArrivalTime > Arrival)
			{
				DelayCount++;
				continue;
			}
			OnTimeCount ++;
		}
	}
	return FlyCount;
}