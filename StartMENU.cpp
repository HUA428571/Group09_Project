#include"StartMENU.h"
int StartMENU(users u[999], Passenger p[999])
{
	initgraph(1280, 720);	// ������ͼ���ڣ���СΪ 1280x720 ����
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	// ���ñ���ɫΪ����ɫ
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 30;						// ��������߶�Ϊ30
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT2_EN));	// ��������ΪFONT2_EN
	settextstyle(&format);						// ����������ʽ
	IMAGE BG;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1280, 720);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	putimage(0, 0, &BG);
	//���϶��ǳ������
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