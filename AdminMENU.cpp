#include"AdminMENU.h"

int AdminMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	//Resize();
	initgraph(1280, 720, EW_SHOWCONSOLE | EW_NOCLOSE);	// 创建绘图窗口，大小为 1280x720 像素
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	//format.lfWeight = FW_LIGHT;				// 设置字重为Light 
	//format.lfOutPrecision = OUT_TT_PRECIS;
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	PrintLoading();

	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\Home.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	int MENUchoice;
	MENUchoice = AdminMENU_MainMENU(ID, DATA, IDcount);			//先进入主页
	while (true)											//循环
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
		case 61:
			PrintExit_AutoSAVE(ID, DATA, IDcount);
			closegraph();			// 关闭绘图窗口
			return 0;
		case 62:
			PrintExit();
			closegraph();			// 关闭绘图窗口
			return 0;
		}
	}
}
int AdminMENU_MainMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	PrintHomeBG(IDcount);
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
		case 61:
		case 62:
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
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将从以下目录导入航线数据库：");
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
		//后期加点动画吧
		//再加一个如果导入失败恢复的功能
		IDcount = ImportFlightDatabase(ID, Location[0]);
		clearrectangle(400, 200, 1220, 400);
		if (IDcount == -1)
		{
			outtextxy(400, 200, "导入失败");
			IDcount++;//将idcount重置回零
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导入了");
			char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个航线数据");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导入");
		Sleep(500);
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
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
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将从以下目录导入机票数据库：");
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
		//后期加点动画吧
		//再加一个如果导入失败恢复的功能
		IDcount = ImportTicketDatabase(DATA, IDcount, Location[1]);
		clearrectangle(400, 200, 1220, 400);
		if (IDcount == -1)
		{
			outtextxy(400, 200, "导入失败");
			IDcount++;//将idcount重置回零
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导入了全部机票数据库");
			/*char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个航线数据");*/
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导入");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
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
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将在以下目录导出航线数据库：");
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
			outtextxy(400, 200, "导出失败");
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导出了");
			char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个航线数据");
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导出");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
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
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	MOUSEMSG m;
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	settextcolor(RED);
	outtextxy(400, 200, "特别提示：请注意航线与航班数据库的匹配");
	settextcolor(BLACK);
	outtextxy(400, 240, "将在以下目录导出机票数据库：");
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
		//后期加点动画吧
		//再加一个如果导入失败恢复的功能
		success = SaveTicketDatabase(DATA, IDcount, Location[3]);
		clearrectangle(400, 200, 1220, 400);
		if (success == -1)
		{
			outtextxy(400, 200, "导出失败");
		}
		else
		{
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导出了所有机票数据");
			/*char count[8];
			_stprintf(count, _T("%d"), IDcount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个航线数据");*/
		}
		Sleep(500);
		return 0;
	case 58:
		clearrectangle(400, 200, 1220, 400);
		outtextxy(420, 200, "已取消导出");
		return 0;
	case 59:
		clearrectangle(400, 200, 1220, 400);
		char LocationTEMP[100] = "\0";
		InputBox(LocationTEMP, 100, "请输入新的文件路径：");
		if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
		{
			outtextxy(400, 280, "无效的目录！");
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
	PrintSearchBG(IDcount);
	int SearchReasult[999];//用于存储搜索结果
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
	//存储搜索结果数
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
		//		//// 判断输入的字符串是否与掉落的字符串相等
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
	PrintSearchBG(IDcount);
	char search[12];
	//InputBox(search, 12, "请输入你想查询的航班号");
	C_InputBox(search, 11, 135, 300, "CA101");
	SearchFlightID(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		settextstyle(25, 0, FONT);
		PrintSearchBG(IDcount);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByDepartureAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char search[12];
	//InputBox(search, 12, "请输入你想查询航班的起飞地");
	C_InputBox(search, 11, 135, 350, "PEK");
	SearchFlightDepartureAirport(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		PrintSearchBG(IDcount);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char search[12];
	//InputBox(search, 12, "请输入你想查询航班的降落地");
	C_InputBox(search, 11, 135, 400, "PEK");
	SearchFlightArrivalAirport(ID, search, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		PrintSearchBG(IDcount);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchByDepartureAndArrivalAirport(FlightID* ID, FlightTicket DATA[][999], int IDcount, int* SearchReasult, int& SearchCount)
{
	PrintSearchBG(IDcount);
	char Departure[12];
	//InputBox(Departure, 12, "请输入你想查询航班的起飞地");
	settextstyle(28, 0, FONT2_EN);
	outtextxy(105, 506, "TO:");
	setlinecolor(RGB(220, 220, 220));
	line(140, 535, 290, 535);
	setlinecolor(BLACK);
	C_InputBox(Departure, 11, 135, 450, "PEK");
	char Arrival[12];
	//InputBox(Arrival, 12, "请输入你想查询航班的降落地");
	C_InputBox(Arrival, 11, 135, 500, "PVG");
	SearchFlightDepartureAndArrivalAirport(ID, Departure, Arrival, IDcount, SearchReasult, SearchCount);//查找航起飞地，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		PrintSearchBG(IDcount);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		PrintProcess();
		return PrintSingleFlight(ID, DATA, IDcount, SearchReasult[0]);
	default:
		PrintProcess();
		return PrintMultiFlight(ID, DATA, IDcount, SearchReasult, SearchCount);
	}
	return AdminMENU_SearchMENU_MENUChoose();
}


int AdminMENU_AddMENU_OLD(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	MOUSEMSG m;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	InputBox(Input, 12, "请输新航班的航班号\n完整航班号，eg CA101");
	int SearchReasult[999];
	int SearchCount;
	if (SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
	{
		outtextxy(380, 200, "航班号不能重复！\n已取消本次录入。");
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
	InputBox(ID[IDcount].FlyDay, 9, "请输新航班的开航日期\n首位为0,然后1:开航,2:不开航");
	InputBox(ID[IDcount].DepartureAirport, 8, "请输新航班的起飞机场\n三字代码，eg PEK");
	InputBox(ID[IDcount].ArrivalAirport, 8, "请输新航班的降落机场\n三字代码，eg PEK");
	InputBox(Input, 8, "请输新航班的起飞时间\n四字码，eg 1230");
	sscanf(Input, "%d", &ID[IDcount].DepartureTime);
	InputBox(Input, 8, "请输新航班的到达时间\n四字码，eg 1230");
	sscanf(Input, "%d", &ID[IDcount].ArrivalTime);
	InputBox(Input, 8, "请输新航班的飞行时间\n小时");
	sscanf(Input, "%d", &ID[IDcount].TravelTimeHour);
	InputBox(Input, 8, "请输新航班的飞行时间\n分钟");
	sscanf(Input, "%d", &ID[IDcount].TravelTimeMinute);
	InputBox(ID[IDcount].AircraftType, 4, "请输新航班的执飞机型\n三字码，eg 747");
	InputBox(ID[IDcount].Class, 4, "请输新航班的舱位\neg CY");
	ID[IDcount].Price = ID[IDcount].TravelTimeHour * 675 + ID[IDcount].TravelTimeMinute * 11.25;
	loadimage(&BG, _T(".\\IMAGES\\Add.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	PrintFlightDetail(ID, DATA, IDcount, IDcount);
	int MENUchoice = AdminMENU_AddMENU_Confirm_MENUChoose();
	switch (MENUchoice)
	{
	case 22:
		DeleteFlight(ID, IDcount, IDcount);
		outtextxy(380, 170, "已取消添加");
		MENUchoice = AdminMENU_MENUChoose();
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return MENUchoice;
	case 21:
		loadimage(&BG, _T(".\\IMAGES\\BackGround.png"), 1280, 720);
		putimage(0, 0, &BG);	// 在另一个位置再次显示背景
		outtextxy(380, 170, "已成功添加");
		PrintFlightDetail(ID, DATA, IDcount, IDcount);
		IDcount++;
		gettextstyle(&format);						// 获取当前字体设置
		format.lfHeight = 25;						// 设置字体高度为 25
		_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
		format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
		settextstyle(&format);						// 设置字体样式
		char count[8];
		_stprintf(count, _T("%d"), IDcount);
		outtextxy(110, 200, "当前数据库中有");
		outtextxy(110, 230, count);
		outtextxy(162, 230, "个航线数据");
		return AdminMENU_MENUChoose();
	}
}
int AdminMENU_AddMENU_FullScreen(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	PrintBG(IDcount);
	IMAGE Right;
	IMAGE Wrong;
	IMAGE Plane;
	MOUSEMSG m;
	FlightID NEW;
	loadimage(&Right, _T(".\\IMAGES\\Right.png"), 25, 25);
	loadimage(&Wrong, _T(".\\IMAGES\\Wrong.png"), 25, 25);
	settextstyle(25, 0, FONT);
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	setlinecolor(RGB(220, 220, 220));
	outtextxy(380, 200, "航班号：");
	line(500, 227,650,227);
	outtextxy(380, 230, "执飞航司：");
	outtextxy(380, 260, "开航日期：");
	line(500, 287, 650, 287);
	outtextxy(380, 290, "执飞机型：");
	line(500, 317, 650, 317);
	outtextxy(380, 320, "起飞机场：");
	line(500, 347, 650, 347);
	outtextxy(380, 350, "起飞时间：");
	line(500, 377, 650, 377);
	outtextxy(380, 380, "降落机场：");
	line(500, 407, 650, 407);
	outtextxy(380, 410, "降落时间：");
	line(500, 437, 650, 437);
	outtextxy(380, 440, "飞行时间：");
	line(500, 467, 650, 467);
	outtextxy(380, 470, "基准票价：");
	outtextxy(380, 500, "基本舱位：");
	line(500, 527, 650, 527);
	int SearchReasult[999];
	int SearchCount;
	char carrier[20];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char Flyday[50];
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
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
		case 201:
			clearrectangle(650, 200, 680, 230);
			C_InputBox(Input, 11, 500, 200, 150, 25, "CA101");
			if (SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
			{
				putimage(655, 200, &Wrong);						//正确
				NEW.Carrier[0] = Input[0];
				NEW.Carrier[1] = Input[1];
				NEW.Carrier[2] = '\0';
				NEW.ID[0] = Input[2];
				NEW.ID[1] = Input[3];
				NEW.ID[2] = Input[4];
				NEW.ID[3] = Input[5];
				NEW.ID[4] = Input[6];
				NEW.ID[5] = Input[7];
				NEW.ID[6] = Input[8];
				NEW.ID[7] = Input[9];
				MatchCarrier(NEW.Carrier, carrier);
				outtextxy(500, 230, carrier);
			}
			else
			{
				putimage(655, 200, &Right);						//错误
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 203:
			//开航日期，点击方式读入，不急写
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 204:
			C_InputBox(NEW.AircraftType, 3, 500, 290, 150, 25, "747");
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 205:
			C_InputBox(NEW.DepartureAirport, 7, 500, 320, 150, 25, "PEK");
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 206:
			C_InputBox(Input, 4, 500, 350, 150, 25, "1000");
			sscanf(Input, "%d", &NEW.DepartureTime);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 207:
			C_InputBox(NEW.ArrivalAirport, 7, 500, 380, 150, 25, "PVG");
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 208:
			C_InputBox(Input, 4, 500, 410, 150, 25, "1200");
			sscanf(Input, "%d", &NEW.ArrivalTime);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 209:
			//这个要分小时写，也先不急
			C_InputBox(Input, 11, 500, 200, 150, 25, "2");
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 211:
			C_InputBox(NEW.Class, 3, 500, 500, 150, 25, "CY");
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 21:
			PrintBG(IDcount);
			return AdminMENU_MENUChoose();
		case 22:
			DeleteFlight(ID, IDcount, IDcount);
			outtextxy(380, 170, "已取消添加");
			MENUchoice = AdminMENU_MENUChoose();
		}
	}
}

int AdminMENU_AddMENU(FlightID* ID, FlightTicket DATA[][999], int& IDcount)
{
	Resize(NULL, 480, 500);
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE Right;
	IMAGE Wrong;
	IMAGE Confirm;
	IMAGE Plane;
	MOUSEMSG m;
	FlightID NEW;
	strcpy(NEW.FlyDay, "00000000");
	loadimage(&Right, _T(".\\IMAGES\\Right.png"), 25, 25);
	loadimage(&Wrong, _T(".\\IMAGES\\Wrong.png"), 25, 25);
	loadimage(&Confirm, _T(".\\IMAGES\\AddConfirm.png"), 380, 60);
	putimage(50, 390, &Confirm);
	settextstyle(24, 0, FONT);
	outtextxy(A_LEFT_MARGIN, 50, "添加航线");
	settextstyle(20, 0, FONT);
	char Input[12] = { 'X','X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' };
	setlinecolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_MARGIN, 100, "航班号：");
	line(A_LEFT_LINE_START, 122, A_LEFT_LINE_END, 122);
	outtextxy(A_LEFT_MARGIN, 125, "开航日期：");
	//显示开航日期的底色（浅灰色）
	settextcolor(RGB(220, 220, 220));
	outtextxy(A_LEFT_LINE_START, 125, "  一  二  三  四  五  六  日");
	//恢复原有颜色
	settextcolor(BLACK);
	outtextxy(A_LEFT_MARGIN, 150, "执飞机型：");
	line(A_LEFT_LINE_START, 172, A_LEFT_LINE_END, 172);
	outtextxy(A_LEFT_MARGIN, 175, "起飞机场：");
	line(A_LEFT_LINE_START, 197, A_LEFT_LINE_END, 197);
	outtextxy(A_LEFT_MARGIN, 200, "起飞时间：");
	line(A_LEFT_LINE_START, 222, A_LEFT_LINE_END, 222);
	outtextxy(A_LEFT_MARGIN, 225, "降落机场：");
	line(A_LEFT_LINE_START, 247, A_LEFT_LINE_END, 247);
	outtextxy(A_LEFT_MARGIN, 250, "降落时间：");
	line(A_LEFT_LINE_START, 272, A_LEFT_LINE_END, 272);
	outtextxy(A_LEFT_MARGIN, 275, "飞行时间：");
	line(A_LEFT_LINE_START, 297, A_LEFT_LINE_START+50, 297);
	outtextxy(A_LEFT_LINE_START + 60, 275, "小时");
	line(A_RIGHT_TEXT_START, 297, A_RIGHT_TEXT_START+50, 297);
	outtextxy(A_RIGHT_TEXT_START + 60, 275, "分钟");
	outtextxy(A_LEFT_MARGIN, 300, "基准票价：");
	outtextxy(A_LEFT_MARGIN, 325, "基本舱位：");
	line(A_LEFT_LINE_START, 347, A_LEFT_LINE_END, 347);
	int SearchReasult[999];
	int SearchCount;
	char carrier[50];
	char AircraftType[50];
	char DepartureAirport[50];
	char ArrivalAirport[50];
	char Flyday[50];
	char IntChange[12];
	char Check[10] = { 0 };
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
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
		case 201:
			clearrectangle(A_RIGHT_TEXT_START, 100, 480, 125);
			C_InputBox(Input, 9, A_LEFT_LINE_START, 100, 90, 20, "CA101");
			line(A_LEFT_LINE_START, 122, A_LEFT_LINE_END, 122);
			if (!SearchFlightID(ID, Input, IDcount, SearchReasult, SearchCount))
			{
				NEW.Carrier[0] = Input[0];
				NEW.Carrier[1] = Input[1];
				NEW.Carrier[2] = '\0';
				NEW.ID[0] = Input[2];
				NEW.ID[1] = Input[3];
				NEW.ID[2] = Input[4];
				NEW.ID[3] = Input[5];
				NEW.ID[4] = Input[6];
				NEW.ID[5] = Input[7];
				NEW.ID[6] = Input[8];
				NEW.ID[7] = 0;
				MatchCarrier(NEW.Carrier, carrier);
				outtextxy(A_RIGHT_TEXT_START, 100, carrier);
				Check[0] = 1;
			}
			else
			{
				clearrectangle(A_RIGHT_TEXT_START, 100, 480, 125);
				putimage(A_RIGHT_TEXT_START, 100, &Wrong);						//错误
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2031:
			if (NEW.FlyDay[1] == '0')
			{
				NEW.FlyDay[1] = '1';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 20, 125, "一");
			}
			else
			{
				NEW.FlyDay[1] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 20, 125, "一");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2032:
			if (NEW.FlyDay[2] == '0')
			{
				NEW.FlyDay[2] = '2';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 60, 125, "二");
			}
			else
			{
				NEW.FlyDay[2] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 60, 125, "二");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2033:
			if (NEW.FlyDay[3] == '0')
			{
				NEW.FlyDay[3] = '3';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 100, 125, "三");
			}
			else
			{
				NEW.FlyDay[3] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 100, 125, "三");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2034:
			if (NEW.FlyDay[4] == '0')
			{
				NEW.FlyDay[4] = '4';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 140, 125, "四");
			}
			else
			{
				NEW.FlyDay[4] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 140, 125, "四");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2035:
			if (NEW.FlyDay[5] == '0')
			{
				NEW.FlyDay[5] = '5';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 180, 125, "五");
			}
			else
			{
				NEW.FlyDay[5] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 180, 125, "五");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2036:
			if (NEW.FlyDay[6] == '0')
			{
				NEW.FlyDay[6] = '6';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 220, 125, "六");
			}
			else
			{
				NEW.FlyDay[6] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 220, 125, "六");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2037:
			if (NEW.FlyDay[7] == '0')
			{
				NEW.FlyDay[7] = '7';
				settextcolor(BLACK);
				outtextxy(A_LEFT_LINE_START + 260, 125, "日");
			}
			else
			{
				NEW.FlyDay[7] = '0';
				settextcolor(RGB(220, 220, 220));
				outtextxy(A_LEFT_LINE_START + 260, 125, "日");
				settextcolor(BLACK);
			}
			Check[1] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 204:
			clearrectangle(A_RIGHT_TEXT_START, 150, 480, 175);
			C_InputBox(NEW.AircraftType, 3, A_LEFT_LINE_START, 150, 90, 20, "747");
			line(A_LEFT_LINE_START, 172, A_LEFT_LINE_END, 172);
			Check[2] = 1;
			MatchPlaneType(NEW.AircraftType, AircraftType);
			outtextxy(A_RIGHT_TEXT_START, 150, AircraftType);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 205:
			clearrectangle(A_RIGHT_TEXT_START, 175, 480, 200);
			C_InputBox(NEW.DepartureAirport, 3, A_LEFT_LINE_START, 175, 90, 20, "PEK");
			line(A_LEFT_LINE_START, 197, A_LEFT_LINE_END, 197);
			Check[3] = 1;
			MatchAirport(NEW.DepartureAirport, DepartureAirport);
			outtextxy(A_RIGHT_TEXT_START, 175, DepartureAirport);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 206:
			C_InputBox(Input, 4, A_LEFT_LINE_START, 200, 90, 20, "1000");
			sscanf(Input, "%d", &NEW.DepartureTime);
			line(A_LEFT_LINE_START, 222, A_LEFT_LINE_END, 222);
			Check[4] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 207:
			clearrectangle(A_RIGHT_TEXT_START, 225, 480, 250);
			C_InputBox(NEW.ArrivalAirport, 3, A_LEFT_LINE_START, 225, 90, 20, "PVG");
			line(A_LEFT_LINE_START, 247, A_LEFT_LINE_END, 247);
			Check[5] = 1;
			MatchAirport(NEW.ArrivalAirport, ArrivalAirport);
			outtextxy(A_RIGHT_TEXT_START, 225, ArrivalAirport);
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 208:
			C_InputBox(Input, 4, A_LEFT_LINE_START, 250, 90, 20, "1200");
			sscanf(Input, "%d", &NEW.ArrivalTime);
			line(A_LEFT_LINE_START, 272, A_LEFT_LINE_END, 272);
			Check[6] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2091:
			C_InputBox(Input, 2, A_LEFT_LINE_START, 275, 50, 20, "2");
			line(A_LEFT_LINE_START, 297, A_LEFT_LINE_START + 50, 297);
			sscanf(Input, "%d", &NEW.TravelTimeHour);
			Check[7] = 1;
			if (Check[8])
			{
				NEW.Price = NEW.TravelTimeHour * 675 + NEW.TravelTimeMinute * 11.25;
				clearrectangle(A_LEFT_LINE_START, 300, A_LEFT_LINE_END, 325);
				outtextxy(A_LEFT_LINE_START, 300, _itoa(NEW.Price, IntChange, 10));
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 2092:
			C_InputBox(Input, 2, A_RIGHT_TEXT_START, 275, 50, 20, "0");
			line(A_RIGHT_TEXT_START, 297, A_RIGHT_TEXT_START + 50, 297);
			sscanf(Input, "%d", &NEW.TravelTimeMinute);
			Check[8] = 1;
			if (Check[7])
			{
				NEW.Price = NEW.TravelTimeHour * 675 + NEW.TravelTimeMinute * 11.25;
				clearrectangle(A_LEFT_LINE_START, 300, A_LEFT_LINE_END, 325);
				outtextxy(A_LEFT_LINE_START,300, _itoa(NEW.Price, IntChange, 10));
			}
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 211:
			C_InputBox(NEW.Class, 3, A_LEFT_LINE_START, 325, 90, 20, "CY");
			line(A_LEFT_LINE_START, 347, A_LEFT_LINE_END, 347);
			Check[9] = 1;
			MENUchoice = AdminMENU_AddMENU_MENUChoose();
			break;
		case 21:
			if (Check[0] && Check[1] && Check[2] && Check[3] && Check[4] && Check[5] && Check[6] && Check[7] && Check[8] && Check[9])
			{
				ID[IDcount] = NEW;
				Resize(NULL, 1280, 720);
				PrintBG(IDcount+1);
				outtextxy(380, 170, "已成功添加");
				PrintFlightDetail(ID, DATA, IDcount, IDcount);
				IDcount++;
				return AdminMENU_MENUChoose();
			}
			else
			{
				MENUchoice = AdminMENU_AddMENU_MENUChoose();
			}
		case 22:
			Resize(NULL, 1280, 720);
			PrintBG(IDcount);
			outtextxy(380, 170, "已取消添加");
			MENUchoice = AdminMENU_MENUChoose();
		}
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
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	char Delete[12];
	int SearchReasult[999];
	int SearchCount;
	InputBox(Delete, 12, "请输入你想删除的航班号\n完整航班号，eg CA101");
	SearchFlightID(ID, Delete, IDcount, SearchReasult, SearchCount);//查找航班号，返回查找到航班个数
	switch (SearchCount)
	{
	case 0:
		outtextxy(380, 200, "没有找到符合要求的航班！");
		break;
	case 1:
		loadimage(&BG, _T(".\\IMAGES\\Delete.png"), 1280, 720);
		putimage(0, 0, &BG);	// 显示删除界面背景
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
			clearrectangle(100, 200, 1220, 680);//把显示区域清空
			DeleteFlight(ID, DATA, IDcount, SearchReasult[0]);
			outtextxy(380, 200, "已成功删除");
			break;
		case 32:
			clearrectangle(100, 200, 1220, 680);//把显示区域清空
			outtextxy(380, 200, "已取消删除");
			break;
		}
		break;
	}
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
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
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	char count[8];
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);							// 设置字体样式
	_stprintf(count, _T("%d"), IDcount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个航线数据");
	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//鼠标按在更改区域
				return 4;
		}
	}
}
