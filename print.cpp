#include"print.h"
void PrintFlightDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i)
{
	cleardevice();
	IMAGE BG;
	IMAGE plane;
	IMAGE FlightDetail;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\Search2.png"), 1280, 720);
	loadimage(&FlightDetail, _T(".\\IMAGES\\FlightDetail.png"), 680, 40);
	putimage(0, 0, &BG);						// 更新背景
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	settextstyle(20, 0, "黑体");
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
	putimage(1280 - 60 - 240, 200, &plane);						//飞机图片
	char IntChange[8];
	//信息输出以25px为行距
	outtextxy(380, 200, "航班号：");
	outtextxy(520, 200, ID[i].Carrier);
	outtextxy(540, 200, ID[i].ID);
	outtextxy(380, 225, "执飞航司：");
	outtextxy(520, 225, carrier);
	//显示开航日期的底色（浅灰色）
	settextcolor(RGB(220, 220, 220));
	outtextxy(520, 250, "一  二  三  四  五  六  日");
	//恢复原有颜色
	settextcolor(BLACK);
	outtextxy(380, 250, "开航日期：");
	outtextxy(520, 250, Flyday);
	outtextxy(380, 275, "基准票价：");
	outtextxy(520, 275, _itoa(ID[i].Price, IntChange, 10));
	outtextxy(380, 300, "舱位：");
	outtextxy(520, 300, ID[i].Class);
	outtextxy(380, 325, "机型：");
	outtextxy(520, 325, AircraftType);		//飞机型号
	//飞行信息展示
	outtextxy(380, 400, "起降机场：");
	outtextxy(380, 425, "IATA代码：");
	outtextxy(380, 450, "起降时间：");
	outtextxy(520, 400, DepartureAirport);
	outtextxy(520, 425, ID[i].DepartureAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);
	outtextxy(520, 450, IntChange);
	outtextxy(580, 450, "预计");
	//航线飞机飞行小动画
	setlinecolor(RGB(255, 255, 253));
	setfillcolor(RGB(255, 255, 253));
	for (int i = 540; i < 1280; i += 2)
	{
		putimage(500, 360, &FlightDetail);							//航线示意图
		fillrectangle(i, 360, 1280, 400);
		Sleep(1);
	}
	putimage(500, 360, &FlightDetail);								//航线示意图
	//小动画到此结束
	outtextxy(1020, 400, ArrivalAirport);
	outtextxy(1020, 425, ID[i].ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].ArrivalTime);
	outtextxy(1020, 450, IntChange);
	outtextxy(1080, 450, "预计");
	Sleep(50);
	//飞行时间
	outtextxy(790, 420, "飞行时长");
	_stprintf(IntChange, _T("%2d"), ID[i].TravelTimeHour);
	outtextxy(770, 440, IntChange);
	outtextxy(790, 440, "小时");
	_stprintf(IntChange, _T("%2d"), ID[i].TravelTimeMinute);
	outtextxy(835, 440, IntChange);
	outtextxy(860, 440, "分钟");
	return;
}
void PrintSingleFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i)
{
	outtextxy(380, 170, "共找到一个航班");
	PrintFlightDetail(ID, DATA, IDcount,i);
	PrintTimeAccuracyBar(ID, DATA, i);
	return;
}

int PrintMultiFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount)//返回菜单选择
{
	clearrectangle(380, 170, 1220, 680);//开始前把显示区域清空
	IMAGE PageChoiceImage;
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//上下页图片
	char IntChange[8];
	int Page = (SearchCount - 1) / 15 + 1;
	int CurrentPage = 1;
	outtextxy(380, 170, "共找到");
	_stprintf(IntChange, _T("%d"), SearchCount);
	outtextxy(450, 170, IntChange);
	outtextxy(485, 170, "个航班");
	PrintFlightTitle();
	PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
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
		case 14:
			return MENUchoice;
		case 15:					//上一页
			if (CurrentPage == 1)
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage--;
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 16:					//下一页
			if (CurrentPage == Page)
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage++;
				PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 18:					//按下了返回键，也就是还显示上一次的界面
			clearrectangle(1070, 165, 1220, 200);//开始前把返回区域清空
			clearrectangle(380, 200, 1220, 680);//开始前把显示区域清空
			PrintFlightTitle();
			PrintMultiFlightPage(ID, DATA, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 19:					//按起飞时间排序
			int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。
			SortByDepartureTime(ID, SearchReasult, SearchCount, SortReasult);//冒泡排序法按照时间排序搜索航班结果；注意此函数有重载
			return PrintMultiFlight(ID, DATA, IDcount, SortReasult, SearchCount);
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
		case 115:									//跳转到详情页面
			//首先判断该页的航班数量
			int Count = (CurrentPage - 1) * 15;//count表示之前页数总计的航班数，即本页航班应该从count+1的下标开始
			if ((MENUchoice % 100 + Count) <= SearchCount)
			{
				clearrectangle(1070, 165, 1220, 200);//开始前把返回区域清空
				IMAGE PageChoiceImage;
				loadimage(&PageChoiceImage, _T(".\\IMAGES\\Back.png"), 30, 30);
				putimage(1280 - 60 - 30, 165, &PageChoiceImage);						//返回键图片
				PrintFlightDetail(ID, DATA, IDcount, SearchReasult[MENUchoice % 100 + Count - 1]);
				PrintTimeAccuracyBar(ID, DATA, SearchReasult[MENUchoice % 100 + Count - 1]);
				MENUchoice = AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose();
			}
			else
				MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		}
	}
}
void PrintFlightTitle()
{
	outtextxy(380, 200, "航班号");
	outtextxy(460, 200, "起飞时间");
	outtextxy(620, 200, "起飞机场");
	outtextxy(820, 200, "降落机场");
	outtextxy(980, 200, "降落时间");
	outtextxy(1080, 200, "机型");
	outtextxy(1140, 200, "飞行时间");
	return;
}
void PrintMultiFlightPage(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int SearchCount, int CurrentPage, int Page)//page表示当前显示第几页
{
	char IntChange[8];
	clearrectangle(380, 230, 1220, 680);//开始前把显示区域清空
	IMAGE PageChoiceImage;
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//上下页图片
	_stprintf(IntChange, _T("%d"), CurrentPage);
	outtextxy(1280 - 60 - 120, 170, IntChange);
	outtextxy(1280 - 60 - 95, 170, "/");
	_stprintf(IntChange, _T("%d"), Page);
	outtextxy(1280 - 60 - 80, 170, IntChange);
	outtextxy(1280 - 60 - 55, 170, "页");
	int Count = (CurrentPage - 1) * 15;//count表示之前页数总计的航班数，即本页航班应该从count+1的下标开始
	for (int i = 0; i < 15; i++)//i用来计算行数
	{
		if ((i + Count) >= SearchCount)
			break;
		PrintSingleLineFlight(ID, DATA, IDcount, SearchReasult[Count + i], 230 + 30 * i);
	}
	return;
}
void PrintSingleLineFlight(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i, int roll)
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


void PrintSearchDetail(FlightID* ID, FlightTicket DATA[][999], int IDcount, int i)
{

}


void PrintTimeAccuracyBar(FlightID* ID, FlightTicket DATA[][999], int n) 
{
	clearrectangle(380, 500, 1220, 650);		//开始前把显示区域清空
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char IntChange[8];
	time_t NOW;
	tm* Local;
	/*
	int tm_sec;   // seconds after the minute - [0, 60] including leap second
	int tm_min;   // minutes after the hour - [0, 59]
	int tm_hour;  // hours since midnight - [0, 23]
	int tm_mday;  // day of the month - [1, 31]
	int tm_mon;   // months since January - [0, 11]
	int tm_year;  // years since 1900
	int tm_wday;  // days since Sunday - [0, 6]
	int tm_yday;  // days since January 1 - [0, 365]
	int tm_isdst; // daylight savings time flag
	*/
	NOW = time(NULL);
	Local = localtime(&NOW);
	int yday = Local->tm_yday;
	int wday = Local->tm_wday;
	if (wday == 0)
		wday = 7;
	int Fly[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//获取最近的五次飞行
	for (int i = 0; ; )
	{
		if (yday == -1)//如果到一年的开头，就不在往前找了（本程序只考虑2020年的数据）
			break;
		if (ID[n].FlyDay[wday] != '0')
		{
			Fly[i] = yday;
			i++;
		}
		yday--;
		if (wday == 1)//再往前是星期日不是星期零
			wday = 7;
		else
			wday--;
		if (i > 9)
			break;
	}
	outtextxy(410, 500, "日期");
	outtextxy(520, 500, "起飞");
	outtextxy(580, 500, "到达");
	outtextxy(680, 500, "状态");
	outtextxy(830, 500, "日期");
	outtextxy(940, 500, "起飞");
	outtextxy(1000, 500, "到达");
	outtextxy(1100, 500, "状态");
	char Date[20];
	char Accuracy[20];
	COLORREF TextColor;
	for (int i = 0; i < 5; i++)
	{
		if (Fly[i] == -1)
			break;
		MatchDate(2020, Fly[i], Date);
		outtextxy(380, 525 + 25 * i, Date);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i]][n].ActuralDepartureTime);
		outtextxy(520, 525 + 25 * i, IntChange);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i]][n].ActuralArrivalTime);
		outtextxy(580, 525 + 25 * i, IntChange);
		MatchTimeAccuracy(ID, DATA, n, Fly[i], Accuracy, TextColor);
		settextcolor(TextColor);
		outtextxy(660, 525 + 25 * i, Accuracy);
		settextcolor(BLACK);
	}
	for (int i = 0; i < 5; i++)
	{
		if (Fly[i + 5] == -1)
			break;
		MatchDate(2020, Fly[i + 5], Date);
		outtextxy(800, 525 + 25 * i, Date);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i + 5]][n].ActuralDepartureTime);
		outtextxy(940, 525 + 25 * i, IntChange);
		_stprintf(IntChange, _T("%04d"), DATA[Fly[i + 5]][n].ActuralArrivalTime);
		outtextxy(1000, 525 + 25 * i, IntChange);
		MatchTimeAccuracy(ID, DATA, n, Fly[i + 5], Accuracy, TextColor);
		settextcolor(TextColor);
		outtextxy(1080, 525 + 25 * i, Accuracy);
		settextcolor(BLACK);
	}

}

void PrintTickstTitle()
{
	for (int i = 60; i < 900; i += 400)
	{
		outtextxy(410, 500, "日期");
		outtextxy(520, 500, "起飞");
		outtextxy(580, 500, "到达");
		outtextxy(680, 500, "状态");
	}
}
void PrintTickst(FlightID* ID, FlightTicket DATA[][999], int n)
{
	IMAGE BG;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
}
void PrintTickstPage(FlightID* ID, FlightTicket DATA[][999], int n)
{
	;
}
void PrintTickstdetail(FlightID* ID, FlightTicket DATA[][999], int n)
{
	;
}
