#include"print.h"
void PrintFlightDetail(FlightID* ID, int IDcount, int i)
{
	clearrectangle(380, 200, 1220, 680);//开始前把显示区域清空
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
	putimage(1280 - 60 - 240, 200, &plane);						//飞机图片
	putimage(380, 400, &FlightDetail);							//航线示意图
	outtextxy(1280 - 60 - 240, 200 + 160 + 5, AircraftType);	//飞机型号
	char IntChange[8];
	//信息输出以30px为行距
	outtextxy(380, 200, "航班号：");
	outtextxy(550, 200, ID[i].Carrier);
	outtextxy(570, 200, ID[i].ID);
	outtextxy(380, 230, "执飞航空公司：");
	outtextxy(550, 230, carrier);
	//显示开航日期的底色（浅灰色）
	settextcolor(RGB(220, 220, 220));
	outtextxy(550, 260, "一  二  三  四  五  六  日");
	//恢复原有颜色
	settextcolor(BLACK);
	outtextxy(380, 260, "开航日期：");
	outtextxy(550, 260, Flyday);
	outtextxy(380, 290, "基准票价：");
	outtextxy(550, 290, _itoa(ID[i].Price, IntChange, 10));
	outtextxy(380, 320, "舱位：");
	outtextxy(550, 320, ID[i].Class);
	outtextxy(380, 460, DepartureAirport);
	outtextxy(380, 490, ID[i].DepartureAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].DepartureTime);
	outtextxy(380, 520, IntChange);
	//航线飞机飞行小动画
	setlinecolor(RGB(255, 255, 253));
	setfillcolor(RGB(255, 255, 253));
	for (int i = 480; i < 1000; i += 2)
	{
		putimage(380, 400, &FlightDetail);							//航线示意图
		fillrectangle(i, 400, 1280, 440);
		Sleep(1);
	}
	putimage(380, 400, &FlightDetail);								//航线示意图
	//小动画到此结束
	outtextxy(980, 460, ArrivalAirport);
	outtextxy(980, 490, ID[i].ArrivalAirport);
	_stprintf(IntChange, _T("%04d"), ID[i].ArrivalTime);
	outtextxy(980, 520, IntChange);
	Sleep(50);
	outtextxy(680, 480, "飞行时长");
	outtextxy(660, 500, _itoa(ID[i].TravelTimeHour, IntChange, 10));
	outtextxy(680, 500, "小时");
	outtextxy(730, 500, _itoa(ID[i].TravelTimeMinute, IntChange, 10));
	outtextxy(750, 500, "分钟");
	return;

}
void PrintSingleFlight(FlightID* ID, int IDcount, int i)
{
	outtextxy(380, 170, "共找到一个航班");
	PrintFlightDetail(ID, IDcount, i);
	return;
}

int PrintMultiFlight(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount)//返回菜单选择
{
	clearrectangle(380, 170, 1220, 680);//开始前把显示区域清空
	IMAGE PageChoiceImage;
	loadimage(&PageChoiceImage, _T(".\\IMAGES\\PageChoice.png"), 150, 30);
	putimage(1280 - 60 - 150, 165, &PageChoiceImage);						//上下页图片
	char IntChange[8];
	int Page = (SearchCount - 1) / 15 + 1;
	int CurrentPage=1;
	outtextxy(380, 170, "共找到");
	_stprintf(IntChange, _T("%d"), SearchCount);
	outtextxy(450, 170, IntChange);
	outtextxy(485, 170, "个航班");
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
		case 15:					//上一页
			if(CurrentPage==1)
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage--;
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 16:					//下一页
			if(CurrentPage==Page)
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			else
			{
				CurrentPage++;
				PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			}
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 18:					//按下了返回键，也就是还显示上一次的界面
			clearrectangle(1070, 165, 1220, 200);//开始前把返回区域清空
			clearrectangle(380, 200, 1220, 680);//开始前把显示区域清空
			PrintFlightTitle();
			PrintMultiFlightPage(ID, IDcount, SearchReasult, SearchCount, CurrentPage, Page);
			MENUchoice = AdminMENU_SearchMENU_MultiFlight_MENUChoose();
			break;
		case 19:					//按起飞时间排序
			int SortReasult[999];//用于存储排序后的顺序，这样就不会更改原有的结构体数组顺序，不影响下标访问。
			SortByDepartureTime(ID, SearchReasult, SearchCount, SortReasult);//冒泡排序法按照时间排序搜索航班结果；注意此函数有重载
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
		case 115:									//跳转到详情页面
			//首先判断该页的航班数量
			int FlightReamin=SearchCount- (CurrentPage - 1) * 15;//本页还剩余航班个数
			if (MENUchoice % 100 <= FlightReamin)
			{
				clearrectangle(1070, 165, 1220, 200);//开始前把返回区域清空
				IMAGE PageChoiceImage;
				loadimage(&PageChoiceImage, _T(".\\IMAGES\\Back.png"), 30, 30);
				putimage(1280 - 60 - 30, 165, &PageChoiceImage);						//返回键图片
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
	outtextxy(380, 200, "航班号");
	outtextxy(460, 200, "起飞时间");
	outtextxy(620, 200, "起飞机场");
	outtextxy(820, 200, "降落机场");
	outtextxy(980, 200, "降落时间");
	outtextxy(1080, 200, "机型");
	outtextxy(1140, 200, "飞行时间");
	return;
}
void PrintMultiFlightPage(FlightID* ID, int IDcount, int* SearchReasult, int SearchCount,int CurrentPage, int Page)//page表示当前显示第几页
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