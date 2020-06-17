#include"LogIN.h"
int StartMENU(users u[999], Passenger p[999])
{
	initgraph(1280, 720);	// 创建绘图窗口，大小为 1280x720 像素
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 30;						// 设置字体高度为30
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\SignIN.png"), 1280, 720);
	putimage(0, 0, &BG);	// 显示背景
	//以上都是常规代码
	char UserName[50];
	char UserNameCheck=0;
	char PassWord[50];
	int MENUchoice;
	MENUchoice = Log_MENUChoose();		//先进入主页
	while (true)											//循环
	{
		switch (MENUchoice)
		{
		case 1:
			C_InputBox(UserName, 40, 490, 290, 300, 40, "UserName");
			UserNameCheck = 1;
			MENUchoice = Log_MENUChoose();
			break;
		case 2:
			CH_InputBox(PassWord, 40, 490, 390, 300, 40, "PassWord");
			if (UserNameCheck == 0)
			{
				MENUchoice = Log_MENUChoose();
			}
			else
			{
				if (!(strcmp(UserName, "Admin") || strcmp(PassWord, "Admin")))
				{
					return 1;
				}
			}
			break;
		case 3:
			//MENUchoice = AdminMENU_DeleteMENU(ID, DATA, IDcount);
			break;
		case 4:
			//MENUchoice = AdminMENU_ChangeMENU(ID, DATA, IDcount);
			break;
		}
	}	
}