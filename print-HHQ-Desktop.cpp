#include"print.h"
void PrintSingleFlight(FlightID* ID, int IDcount, int i)
{
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 20;						// 设置字体高度为 20
	_tcscpy_s(format.lfFaceName, _T("黑体"));	// 设置字体为“黑体”
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
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
	putimage(1280 - 60 - 240, 200, &plane);						//飞机图片
	putimage(380, 400, &FlightDetail);							//航线示意图
	outtextxy(1280 - 60 - 240, 200 + 160 + 5, AircraftType);	//飞机型号
	//信息输出以30px为行距
	outtextxy(380, 200, "共找到一个航班");
	outtextxy(380, 230, "航班号：");
	outtextxy(550, 230, ID[i].Carrier);
	outtextxy(570, 230, ID[i].ID);
	//outtextxy(700, 230, carrier);
	outtextxy(380, 260, "执飞航空公司：");
	outtextxy(550, 260, carrier);
	//outtextxy(380, 260, "起飞机场：");
	//outtextxy(550, 260, ID[i].DepartureAirport);
	//outtextxy(700, 260, DepartureAirport);
	//outtextxy(380, 290, "到达机场：");
	//outtextxy(550, 290, ID[i].ArrivalAirport);
	//outtextxy(700, 290, ArrivalAirport);
	//char Time[5];
	//outtextxy(380, 320, "起飞时间：");
	//outtextxy(550, 320, _itoa(ID[i].DepartureTime, Time, 10));
	//outtextxy(380, 350, "到达时间：");
	//outtextxy(550, 350, _itoa(ID[i].ArrivalTime, Time, 10));
	//outtextxy(380, 380, "执飞机型：");
	//outtextxy(550, 380, ID[i].AircraftType);
	setlinecolor(RGB(255, 255, 253));
	setfillcolor(RGB(255, 255, 253));
	outtextxy(380, 460, DepartureAirport);
	outtextxy(380, 490, ID[i].DepartureAirport);
	char Time[5];
	outtextxy(380, 520, _itoa(ID[i].DepartureTime, Time, 10));
	for (int i = 480; i < 1000; i+=2)
	{
		putimage(380, 400, &FlightDetail);							//航线示意图
		fillrectangle(i, 400, 1280, 440);
		Sleep(1);
	}
	putimage(380, 400, &FlightDetail);							//航线示意图
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
		strcpy(AIRCRAFTTYPE, "波音B737系列飞机");
		return;
	case 74:
	case 744:
	case 747:
		strcpy(AIRCRAFTTYPE, "波音B747系列飞机");
		return;
	case 76:
		strcpy(AIRCRAFTTYPE, "波音B767系列飞机");
		return;
	case 77:
	case 772:
	case 773:
	case 777:
		strcpy(AIRCRAFTTYPE, "波音B777系列飞机");
		return;
	case 788:
	case 789:
		strcpy(AIRCRAFTTYPE, "波音B787系列飞机");
		return;
	case 319:
	case 320:
	case 321:
		strcpy(AIRCRAFTTYPE, "空中客车A320系列飞机");
		return;
	case 330:
	case 333:
		strcpy(AIRCRAFTTYPE, "空中客车A330系列飞机");
		return;
	case 343:
		strcpy(AIRCRAFTTYPE, "空中客车A340系列飞机");
		return;
	case 350:
		strcpy(AIRCRAFTTYPE, "空中客车A350系列飞机");
		return;
	case 380:
		strcpy(AIRCRAFTTYPE, "空中客车A380系列飞机");
		return;
	default:
		strcpy(AIRCRAFTTYPE, "没有找到机型数据");
		return;
	}

}
void MatchCarrier(char* carrier, char* CARRIER)
{
	if (!strcmp(carrier, "CA"))
	{
		strcpy(CARRIER, "中国国际航空公司");
		return;
	}
}
void MatchAirport(char* airport, char* AIRPORT)
{
	strncpy(airport, airport, 3);
	airport[3] = '\0';
	if (!strcmp(airport, "PEK")) { strcpy(AIRPORT, "北京首都国际机场"); return; }
	if (!strcmp(airport, "CAN")) { strcpy(AIRPORT, "广州白云国际机场"); return; }
	if (!strcmp(airport, "SHA")) { strcpy(AIRPORT, "上海虹桥国际机场"); return; }
	if (!strcmp(airport, "PVG")) { strcpy(AIRPORT, "上海浦东国际机场"); return; }
	if (!strcmp(airport, "CTU")) { strcpy(AIRPORT, "成都双流国际机场"); return; }
	if (!strcmp(airport, "SZX")) { strcpy(AIRPORT, "深圳宝安国际机场"); return; }
	if (!strcmp(airport, "KMG")) { strcpy(AIRPORT, "昆明长水国际机场"); return; }
	if (!strcmp(airport, "XIY")) { strcpy(AIRPORT, "西安咸阳国际机场"); return; }
	if (!strcmp(airport, "CKG")) { strcpy(AIRPORT, "重庆江北国际机场"); return; }
	if (!strcmp(airport, "HGH")) { strcpy(AIRPORT, "杭州萧山国际机场"); return; }
	if (!strcmp(airport, "XMN")) { strcpy(AIRPORT, "厦门高崎国际机场"); return; }
	if (!strcmp(airport, "CSX")) { strcpy(AIRPORT, "长沙黄花国际机场"); return; }
	if (!strcmp(airport, "NKG")) { strcpy(AIRPORT, "南京禄口国际机场"); return; }
	if (!strcmp(airport, "WUH")) { strcpy(AIRPORT, "武汉天河国际机场"); return; }
	if (!strcmp(airport, "DLC")) { strcpy(AIRPORT, "大连国际机场"); return; }
	if (!strcmp(airport, "TAO")) { strcpy(AIRPORT, "青岛流亭国际机场"); return; }
	if (!strcmp(airport, "SYX")) { strcpy(AIRPORT, "三亚凤凰国际机场"); return; }
	if (!strcmp(airport, "HAK")) { strcpy(AIRPORT, "海口美兰国际机场"); return; }
	if (!strcmp(airport, "TSN")) { strcpy(AIRPORT, "天津滨海国际机场"); return; }
	if (!strcmp(airport, "HKG")) { strcpy(AIRPORT, "香港国际机场"); return; }
	if (!strcmp(airport, "MFM")) { strcpy(AIRPORT, "澳门国际机场"); return; }
	if (!strcmp(airport, "URC")) { strcpy(AIRPORT, "乌鲁木齐机场"); return; }
	if (!strcmp(airport, "TPE")) { strcpy(AIRPORT, "台北桃园国际机场"); return; }
	if (!strcmp(airport, "NRT")) { strcpy(AIRPORT, "东京成田国际机场"); return; }
	if (!strcmp(airport, "HND")) { strcpy(AIRPORT, "东京羽田国际机场"); return; }
	if (!strcmp(airport, "KIX")) { strcpy(AIRPORT, "大阪关西国际机场"); return; }
	if (!strcmp(airport, "FUK")) { strcpy(AIRPORT, "福冈国际机场"); return; }
	if (!strcmp(airport, "OKA")) { strcpy(AIRPORT, "冲绳那霸国际机场"); return; }
	if (!strcmp(airport, "ITM")) { strcpy(AIRPORT, "大阪国际机场"); return; }
	if (!strcmp(airport, "NGO")) { strcpy(AIRPORT, "名古屋国际机场"); return; }
	if (!strcmp(airport, "ICN")) { strcpy(AIRPORT, "首尔仁川国际机场"); return; }
	if (!strcmp(airport, "GMP")) { strcpy(AIRPORT, "首尔金浦国际机场"); return; }
	if (!strcmp(airport, "PUS")) { strcpy(AIRPORT, "釜山金海国际机场"); return; }
	if (!strcmp(airport, "CJU")) { strcpy(AIRPORT, "济州岛国际机场"); return; }
	if (!strcmp(airport, "BKK")) { strcpy(AIRPORT, "曼谷素万那普国际机场"); return; }
	if (!strcmp(airport, "DMK")) { strcpy(AIRPORT, "曼谷廊曼国际机场"); return; }
	if (!strcmp(airport, "CNX")) { strcpy(AIRPORT, "清迈国际机场"); return; }
	if (!strcmp(airport, "HKT")) { strcpy(AIRPORT, "普吉国际机场"); return; }
	if (!strcmp(airport, "KUL")) { strcpy(AIRPORT, "吉隆坡国际机场"); return; }
	if (!strcmp(airport, "PEN")) { strcpy(AIRPORT, "槟城国际机场"); return; }
	if (!strcmp(airport, "BKI")) { strcpy(AIRPORT, "亚庇国际机场"); return; }
	if (!strcmp(airport, "MNL")) { strcpy(AIRPORT, "马尼拉国际机场"); return; }
	if (!strcmp(airport, "CRK")) { strcpy(AIRPORT, "克拉克国际机场"); return; }
	if (!strcmp(airport, "CGK")) { strcpy(AIRPORT, "雅加达国际机场"); return; }
	if (!strcmp(airport, "BDO")) { strcpy(AIRPORT, "万隆国际机场"); return; }
	if (!strcmp(airport, "DPS")) { strcpy(AIRPORT, "巴厘岛登巴萨机场"); return; }
	if (!strcmp(airport, "DEL")) { strcpy(AIRPORT, "新德里国际机场"); return; }
	if (!strcmp(airport, "BLR")) { strcpy(AIRPORT, "班加罗尔国际机场"); return; }
	if (!strcmp(airport, "CMB")) { strcpy(AIRPORT, "科伦坡国际机场"); return; }
	if (!strcmp(airport, "SIN")) { strcpy(AIRPORT, "新加坡樟宜机场"); return; }
	if (!strcmp(airport, "SGN")) { strcpy(AIRPORT, "胡志明国际机场"); return; }
	if (!strcmp(airport, "HAN")) { strcpy(AIRPORT, "河内国际机场"); return; }
	if (!strcmp(airport, "DEL")) { strcpy(AIRPORT, "印度新德里甘地机场"); return; }
	if (!strcmp(airport, "KHI")) { strcpy(AIRPORT, "卡拉奇国际机场"); return; }
	if (!strcmp(airport, "BOM")) { strcpy(AIRPORT, "印度孟买机场"); return; }
	if (!strcmp(airport, "BLR")) { strcpy(AIRPORT, "印度班加罗尔机场"); return; }
	if (!strcmp(airport, "KTM")) { strcpy(AIRPORT, "尼珀尔加德满都机场"); return; }
	if (!strcmp(airport, "DXB")) { strcpy(AIRPORT, "阿联酋迪拜国际机场"); return; }
	if (!strcmp(airport, "DOH")) { strcpy(AIRPORT, "卡塔尔多哈国际机场"); return; }
	if (!strcmp(airport, "AUH")) { strcpy(AIRPORT, "阿联酋阿布扎比机场"); return; }
	if (!strcmp(airport, "DAC")) { strcpy(AIRPORT, "孟加拉达卡机场"); return; }
	if (!strcmp(airport, "JED")) { strcpy(AIRPORT, "沙特阿拉伯吉达国王机场"); return; }
	if (!strcmp(airport, "CCU")) { strcpy(AIRPORT, "印度加尔各答机场"); return; }
	if (!strcmp(airport, "THR")) { strcpy(AIRPORT, "伊朗德黑兰机场"); return; }
	if (!strcmp(airport, "BAK")) { strcpy(AIRPORT, "阿塞拜疆巴库机场"); return; }
	if (!strcmp(airport, "ISB")) { strcpy(AIRPORT, "巴基斯坦伊斯兰堡机场"); return; }
	if (!strcmp(airport, "ASB")) { strcpy(AIRPORT, "土库曼阿什哈巴德机场"); return; }
	if (!strcmp(airport, "DYU")) { strcpy(AIRPORT, "塔吉克斯坦杜尚别机场"); return; }
	if (!strcmp(airport, "LBD")) { strcpy(AIRPORT, "塔吉克斯坦库德贾德机场"); return; }
	if (!strcmp(airport, "OSS")) { strcpy(AIRPORT, "吉尔吉斯斯坦奥什机场"); return; }
	if (!strcmp(airport, "TBS")) { strcpy(AIRPORT, "格鲁吉亚第比利斯机场"); return; }
	if (!strcmp(airport, "MDL")) { strcpy(AIRPORT, "缅甸曼德勒机场"); return; }
	if (!strcmp(airport, "MEL")) { strcpy(AIRPORT, "墨尔本国际机场"); return; }
	if (!strcmp(airport, "SYD")) { strcpy(AIRPORT, "悉尼史密斯国际机场"); return; }
	if (!strcmp(airport, "BNE")) { strcpy(AIRPORT, "布里斯班国际机场"); return; }
	if (!strcmp(airport, "PER")) { strcpy(AIRPORT, "珀斯国际机场"); return; }
	if (!strcmp(airport, "AKL")) { strcpy(AIRPORT, "奥克兰国际机场"); return; }
	if (!strcmp(airport, "LHR")) { strcpy(AIRPORT, "伦敦希罗斯国际机场"); return; }
	if (!strcmp(airport, "LGW")) { strcpy(AIRPORT, "伦敦盖威克国际机场"); return; }
	if (!strcmp(airport, "STN")) { strcpy(AIRPORT, "伦敦斯坦斯特德机场"); return; }
	if (!strcmp(airport, "LTN")) { strcpy(AIRPORT, "伦敦卢顿机场"); return; }
	if (!strcmp(airport, "LCY")) { strcpy(AIRPORT, "伦敦城市机场"); return; }
	if (!strcmp(airport, "LPL")) { strcpy(AIRPORT, "利物浦国际机场"); return; }
	if (!strcmp(airport, "MAN")) { strcpy(AIRPORT, "曼彻斯特国际机场"); return; }
	if (!strcmp(airport, "CDG")) { strcpy(AIRPORT, "巴黎戴高乐机场"); return; }
	if (!strcmp(airport, "ORY")) { strcpy(AIRPORT, "巴黎奥利机场"); return; }
	if (!strcmp(airport, "MRS")) { strcpy(AIRPORT, "马赛国际机场"); return; }
	if (!strcmp(airport, "LYS")) { strcpy(AIRPORT, "里昂国际机场"); return; }
	if (!strcmp(airport, "TXL")) { strcpy(AIRPORT, "柏林泰戈尔机场"); return; }
	if (!strcmp(airport, "BER")) { strcpy(AIRPORT, "柏林勃兰登堡机场"); return; }
	if (!strcmp(airport, "MUC")) { strcpy(AIRPORT, "慕尼黑国际机场"); return; }
	if (!strcmp(airport, "BRE")) { strcpy(AIRPORT, "不莱梅机场BRE"); return; }
	if (!strcmp(airport, "FRA")) { strcpy(AIRPORT, "法兰克福机场"); return; }
	if (!strcmp(airport, "STR")) { strcpy(AIRPORT, "斯图加特机场"); return; }
	if (!strcmp(airport, "HAM")) { strcpy(AIRPORT, "汉堡国际机场"); return; }
	if (!strcmp(airport, "NUE")) { strcpy(AIRPORT, "纽伦堡机场"); return; }
	if (!strcmp(airport, "ZRH")) { strcpy(AIRPORT, "苏黎世国际机场"); return; }
	if (!strcmp(airport, "BRN")) { strcpy(AIRPORT, "伯尔尼贝尔普机场"); return; }
	if (!strcmp(airport, "GVA")) { strcpy(AIRPORT, "日内瓦国际机场"); return; }
	if (!strcmp(airport, "BSL")) { strcpy(AIRPORT, "巴塞尔国际机场"); return; }
	if (!strcmp(airport, "MAD")) { strcpy(AIRPORT, "马德里巴拉哈斯机场"); return; }
	if (!strcmp(airport, "BCN")) { strcpy(AIRPORT, "巴塞罗那安普拉特机场"); return; }
	if (!strcmp(airport, "VLC")) { strcpy(AIRPORT, "巴伦西亚机场"); return; }
	if (!strcmp(airport, "SVQ")) { strcpy(AIRPORT, "塞维利亚机场"); return; }
	if (!strcmp(airport, "AMS")) { strcpy(AIRPORT, "阿姆斯特丹史基浦机场"); return; }
	if (!strcmp(airport, "RTM")) { strcpy(AIRPORT, "鹿特丹机场"); return; }
	if (!strcmp(airport, "FCO")) { strcpy(AIRPORT, "罗马菲乌米奇诺机"); return; }
	if (!strcmp(airport, "MXP")) { strcpy(AIRPORT, "米兰马尔蓬萨机场"); return; }
	if (!strcmp(airport, "VCE")) { strcpy(AIRPORT, "威尼斯机场"); return; }
	if (!strcmp(airport, "FLR")) { strcpy(AIRPORT, "佛罗伦萨机场"); return; }
	if (!strcmp(airport, "TRN")) { strcpy(AIRPORT, "都灵机场"); return; }
	if (!strcmp(airport, "LIS")) { strcpy(AIRPORT, "里斯本国际机场"); return; }
	if (!strcmp(airport, "OPO")) { strcpy(AIRPORT, "奥波多国际机场"); return; }
	if (!strcmp(airport, "CPH")) { strcpy(AIRPORT, "哥本哈根凯斯楚普机场"); return; }
	if (!strcmp(airport, "PRG")) { strcpy(AIRPORT, "布拉格鲁济涅机场"); return; }
	if (!strcmp(airport, "HEL")) { strcpy(AIRPORT, "赫尔辛基万塔机场"); return; }
	if (!strcmp(airport, "ATH")) { strcpy(AIRPORT, "雅典国际机场"); return; }
	if (!strcmp(airport, "ARN")) { strcpy(AIRPORT, "斯德哥尔摩阿兰达机场"); return; }
	if (!strcmp(airport, "OSL")) { strcpy(AIRPORT, "奥斯陆加勒穆恩机场"); return; }
	if (!strcmp(airport, "WAW")) { strcpy(AIRPORT, "华沙奥肯切机场"); return; }
	if (!strcmp(airport, "BUD")) { strcpy(AIRPORT, "布达佩斯费里海吉机场"); return; }
	if (!strcmp(airport, "VIE")) { strcpy(AIRPORT, "维也纳施韦夏特机场"); return; }
	if (!strcmp(airport, "BRU")) { strcpy(AIRPORT, "布鲁塞尔国际机场"); return; }
	if (!strcmp(airport, "LUX")) { strcpy(AIRPORT, "卢森堡国际机场"); return; }
	if (!strcmp(airport, "SVO")) { strcpy(AIRPORT, "莫斯科谢列梅捷沃机场"); return; }
	if (!strcmp(airport, "DME")) { strcpy(AIRPORT, "莫斯科多莫杰多沃机场"); return; }
	if (!strcmp(airport, "KBP")) { strcpy(AIRPORT, "基辅机场"); return; }
	if (!strcmp(airport, "IEV")) { strcpy(AIRPORT, "基辅茹良尼机场"); return; }
	if (!strcmp(airport, "BEG")) { strcpy(AIRPORT, "贝尔格莱德机场"); return; }
	if (!strcmp(airport, "BUH")) { strcpy(AIRPORT, "布加勒斯特机场"); return; }
	if (!strcmp(airport, "ZAG")) { strcpy(AIRPORT, "萨格勒布机场"); return; }
	if (!strcmp(airport, "LAX")) { strcpy(AIRPORT, "洛杉矶国际机场"); return; }
	if (!strcmp(airport, "SAN")) { strcpy(AIRPORT, "圣地亚哥机场"); return; }
	if (!strcmp(airport, "SNA")) { strcpy(AIRPORT, "橘子郡机场"); return; }
	if (!strcmp(airport, "SFO")) { strcpy(AIRPORT, "旧金山国际机场"); return; }
	if (!strcmp(airport, "SJC")) { strcpy(AIRPORT, "圣何塞机场"); return; }
	if (!strcmp(airport, "SEA")) { strcpy(AIRPORT, "西雅图国际机场"); return; }
	if (!strcmp(airport, "PDX")) { strcpy(AIRPORT, "波特兰机场"); return; }
	if (!strcmp(airport, "PHX")) { strcpy(AIRPORT, "菲尼克斯机场"); return; }
	if (!strcmp(airport, "LAS")) { strcpy(AIRPORT, "拉斯维加斯机场"); return; }
	if (!strcmp(airport, "SLC")) { strcpy(AIRPORT, "盐湖城机场"); return; }
	if (!strcmp(airport, "DEN")) { strcpy(AIRPORT, "丹佛机场"); return; }
	if (!strcmp(airport, "AUS")) { strcpy(AIRPORT, "奥斯汀机场"); return; }
	if (!strcmp(airport, "IAH")) { strcpy(AIRPORT, "休斯顿国际机场"); return; }
	if (!strcmp(airport, "HOU")) { strcpy(AIRPORT, "休斯顿哈比机场"); return; }
	if (!strcmp(airport, "DFW")) { strcpy(AIRPORT, "达拉斯机场"); return; }
	if (!strcmp(airport, "MCI")) { strcpy(AIRPORT, "堪萨斯城机场"); return; }
	if (!strcmp(airport, "STL")) { strcpy(AIRPORT, "圣·路易斯机场"); return; }
	if (!strcmp(airport, "MSY")) { strcpy(AIRPORT, "新奥尔良机场"); return; }
	if (!strcmp(airport, "BHM")) { strcpy(AIRPORT, "伯明翰机场"); return; }
	if (!strcmp(airport, "MEM")) { strcpy(AIRPORT, "孟菲斯机场"); return; }
	if (!strcmp(airport, "BNA")) { strcpy(AIRPORT, "纳什维尔机场"); return; }
	if (!strcmp(airport, "ORD")) { strcpy(AIRPORT, "芝加哥机场"); return; }
	if (!strcmp(airport, "DTW")) { strcpy(AIRPORT, "底特律机场"); return; }
	if (!strcmp(airport, "IND")) { strcpy(AIRPORT, "印第安那波利斯"); return; }
	if (!strcmp(airport, "CVG")) { strcpy(AIRPORT, "辛辛那提机场"); return; }
	if (!strcmp(airport, "CMH")) { strcpy(AIRPORT, "哥伦布机场"); return; }
	if (!strcmp(airport, "CLE")) { strcpy(AIRPORT, "克利夫兰机场"); return; }
	if (!strcmp(airport, "PWM")) { strcpy(AIRPORT, "波特兰机场"); return; }
	if (!strcmp(airport, "BOS")) { strcpy(AIRPORT, "波士顿机场"); return; }
	if (!strcmp(airport, "LGA")) { strcpy(AIRPORT, "纽约拉瓜地机场"); return; }
	if (!strcmp(airport, "JFK")) { strcpy(AIRPORT, "纽约肯尼迪机场"); return; }
	if (!strcmp(airport, "EWR")) { strcpy(AIRPORT, "纽约纽华克机场"); return; }
	if (!strcmp(airport, "PIT")) { strcpy(AIRPORT, "匹兹堡机场"); return; }
	if (!strcmp(airport, "PHL")) { strcpy(AIRPORT, "费城机场"); return; }
	if (!strcmp(airport, "DCA")) { strcpy(AIRPORT, "华盛顿国际机场"); return; }
	if (!strcmp(airport, "BWI")) { strcpy(AIRPORT, "巴尔地磨机场"); return; }
	if (!strcmp(airport, "IAD")) { strcpy(AIRPORT, "华盛顿达拉斯机场"); return; }
	if (!strcmp(airport, "CLT")) { strcpy(AIRPORT, "夏洛特机场"); return; }
	if (!strcmp(airport, "ILM")) { strcpy(AIRPORT, "威尔明顿机场"); return; }
	if (!strcmp(airport, "CAE")) { strcpy(AIRPORT, "哥伦比亚机场"); return; }
	if (!strcmp(airport, "CHS")) { strcpy(AIRPORT, "查尔斯顿机场"); return; }
	if (!strcmp(airport, "ATL")) { strcpy(AIRPORT, "亚特兰大机场"); return; }
	if (!strcmp(airport, "MCO")) { strcpy(AIRPORT, "奥兰多机场"); return; }
	if (!strcmp(airport, "TPA")) { strcpy(AIRPORT, "坦帕机场"); return; }
	if (!strcmp(airport, "MIA")) { strcpy(AIRPORT, "迈阿密机场"); return; }
	if (!strcmp(airport, "HNL")) { strcpy(AIRPORT, "火奴鲁鲁机场"); return; }
	if (!strcmp(airport, "YVR")) { strcpy(AIRPORT, "温哥华机场"); return; }
	if (!strcmp(airport, "YYZ")) { strcpy(AIRPORT, "多伦多国际机场"); return; }
	if (!strcmp(airport, "YUL")) { strcpy(AIRPORT, "蒙特利尔特鲁多机场"); return; }
	if (!strcmp(airport, "YOW")) { strcpy(AIRPORT, "渥太华国际机场"); return; }
	if (!strcmp(airport, "YHZ")) { strcpy(AIRPORT, "哈利法克斯国际机场"); return; }
	if (!strcmp(airport, "YYC")) { strcpy(AIRPORT, "卡尔加里国际机场"); return; }
	if (!strcmp(airport, "YEG")) { strcpy(AIRPORT, "埃德蒙顿国际机场"); return; }
	if (!strcmp(airport, "TIJ")) { strcpy(AIRPORT, "蒂华纳国际机场"); return; }
	if (!strcmp(airport, "MEX")) { strcpy(AIRPORT, "墨西哥国际机场"); return; }
	if (!strcmp(airport, "CUN")) { strcpy(AIRPORT, "坎昆国际机场"); return; }
	strcpy(AIRPORT, "没有匹配到机场信息");
	return;
}

