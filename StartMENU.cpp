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
				int temp;
				temp = Identify_ID(UserName, PassWord, u);
				if (temp >= 0)
					return temp;
				else
				{
					setlinecolor(RED);
					line(530, 430, 800, 430);
					settextcolor(RED);
					settextstyle(30, 0, "����");
					outtextxy(470, 250, "�û������������");
					MENUchoice = StartMENU_MENUChoose();
				}
			}
			break;
		case 3:
		{
			int tmp = SetMenu_Register(u);
			if (tmp < 0)
			{
				putimage(0, 0, &BG);
				MENUchoice = StartMENU_MENUChoose();
				break;
			}
		}
		case 4:
			SetMenu_Manager_Register(u);
			if (SetMenu_Manager_Register < 0)
			{
				putimage(0, 0, &BG);
				break;
			}
		}
	}	
}
int Identify_ID(char* n, char* m, users u[999])
{
	users temp;
	int count = 0;
	while (count < 999)
	{
		temp = u[count];
		if (strcmp(temp.id, n) == 0)
		{
			if (strcmp(temp.pwd, m) == 0)
			{
				if (temp.Identity == '1')
					return 0;
				if (temp.Identity == '0')
					return count;
			}
			else
				return -1;
		}
		else
			count++;

	}
	return -1;
}
int SetMenu_Register(users u[999])
{
	users temp;
	int count = 0;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE TELBox;
	IMAGE BG_Register;
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	loadimage(&TELBox, _T(".\\IMAGES\\TELBox.png"), 340, 60);
	loadimage(&BG_Register, _T(".\\IMAGES\\Register.png"), 1280, 720);
	char UserName[50] = "\0";
	char PassWord[50] = "\0";
	char PassWord0[50] = "\0";
	char Telephone[50] = "\0";
	putimage(0, 0, &BG_Register);
	int MENUchoice_Register = StartMENU_Register_MENUChoose();
	while (1)
	{
		switch (MENUchoice_Register)
		{
		case 1:
			putimage(470, 230, &UserNameBox);
			C_InputBox(UserName, 40, 530, 240, 270, 40, "");
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 2:
			putimage(470, 300, &PassWordBox);
			CH_InputBox(PassWord, 40, 530, 310, 270, 40, "");
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 3:
			putimage(470, 370, &PassWordBox);
			CH_InputBox(PassWord0, 40, 530, 380, 270, 40, "");
			if (strcmp(PassWord, PassWord0) == 0)
			{
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			else
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 220, "�������벻��ͬ");
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
		case 4:
			putimage(470, 440, &TELBox);
			C_InputBox(Telephone, 40, 530, 450, 270, 40, "");
			if (strlen(Telephone) == 11)
			{
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			else
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 220, "��������ȷ�ĵ绰����");
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
		case 5:
		{
			if (strlen(UserName) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 240, "�������û���");
			}
			if (strlen(PassWord) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 310, "����������");
			}
			if (strlen(PassWord0) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 380, "��������֤����");
			}
			if (strlen(Telephone) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 450, "������绰����");
			}
			if (strlen(UserName) != 0 && strlen(PassWord) != 0 && strlen(PassWord0) != 0 && strlen(Telephone) != 0)
			{
				strcpy(temp.id, UserName);
				strcpy(temp.pwd, PassWord);
				strcpy(temp.phone, Telephone);
				temp.Identity = 0;
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 250, "ע��ɹ���");
				return 0;
			}
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		}
		case 6:
			return -1;
		}
	}
}
int SetMenu_Manager_Register(users u[999])
{
	users temp;
	int count = 0;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE InvitationBox;
	IMAGE BG_AdminRegister;
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	loadimage(&InvitationBox, _T(".\\IMAGES\\InvitationBox.png"), 340, 60);
	loadimage(&BG_AdminRegister, _T(".\\IMAGES\\AdminRegister.png"), 1280, 720);
	char UserName[50];
	char PassWord[50];
	char PassWord0[50];
	char Invitation[50];
	putimage(0, 0, &BG_AdminRegister);
	int MENUchoice_Register = StartMENU_AdminRegister_MENUChoose();
	while (1)
	{
		switch (MENUchoice_Register)
		{
		case 1:
			putimage(470, 230, &UserNameBox);
			C_InputBox(UserName, 40, 530, 240, 270, 40, "");
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 2:
			putimage(470, 300, &PassWordBox);
			CH_InputBox(PassWord, 40, 530, 310, 270, 40, "");
			MENUchoice_Register = StartMENU_Register_MENUChoose();
			break;
		case 3:
			putimage(470, 370, &PassWordBox);
			CH_InputBox(PassWord0, 40, 530, 380, 270, 40, "");
			if (strcmp(PassWord, PassWord0) == 0)
			{
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			else
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 220, "�������벻��ͬ");
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
		case 4:
			putimage(470, 440, &InvitationBox);
			C_InputBox(UserName, 40, 530, 450, 270, 40, "");
			if (strcmp(Invitation, "B190303") == 0)
			{
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
			else
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 220, "��������ȷ��������");
				MENUchoice_Register = StartMENU_Register_MENUChoose();
				break;
			}
		case 5:
		{
			if (strlen(UserName) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 240, "�������û���");
			}
			if (strlen(PassWord) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 310, "����������");
			}
			if (strlen(PassWord0) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 380, "��������֤����");
			}
			if (strlen(Invitation) == 0)
			{
				setlinecolor(RED);
				line(530, 430, 800, 430);
				settextcolor(RED);
				settextstyle(30, 0, "����");
				outtextxy(470, 450, "������������");
			}
			if (strlen(UserName) != 0 && strlen(PassWord) != 0 && strlen(PassWord0) != 0 && strlen(Invitation) != 0)
			{
				strcpy(temp.id, UserName);
				strcpy(temp.pwd, PassWord);
				temp.Identity = 1;
			}
		}
		case 6:
		{
			return -1;
		}
		}
	}
}
