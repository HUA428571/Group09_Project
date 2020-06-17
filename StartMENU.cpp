#include"StartMENU.h"
int StartMENU(users u[999], Passenger p[999])
{
	initgraph(1280, 720);	// 创建绘图窗口，大小为 1280x720 像素
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	// 设置背景色为淡白色
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 30;						// 设置字体高度为30
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT2_EN));	// 设置字体为FONT2_EN
	settextstyle(&format);						// 设置字体样式
	IMAGE BG;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1280, 720);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	putimage(0, 0, &BG);
	//以上都是常规代码
	char UserName[50];
	char UserNameCheck=0;
	char PassWord[50];
	int MENUchoice;
	MENUchoice = StartMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 1:
			putimage(0, 0, &BG);
			putimage(470, 280, &UserNameBox);
			C_InputBox(UserName, 40, 530, 290, 270, 40, "");
			UserNameCheck = 1;
			MENUchoice = StartMENU_MENUChoose();
			break;
		case 2:
			putimage(470, 380, &PassWordBox);
			CH_InputBox(PassWord, 40, 530, 390, 270, 40, "");
			if (UserNameCheck == 0)
			{
				MENUchoice = StartMENU_MENUChoose();
			}
			else
			{
				if (!(strcmp(UserName, "Admin") || strcmp(PassWord, "Admin")))
				{
					return 0;
				}
			}
			MENUchoice = StartMENU_MENUChoose();
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