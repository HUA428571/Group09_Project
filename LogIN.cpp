#include"LogIN.h"
int StartMENU(users u[999], Passenger p[999])
{
	initgraph(1280, 720);	// ������ͼ���ڣ���СΪ 1280x720 ����
	// ���ñ���ɫΪ����ɫ
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// �ñ���ɫ�����Ļ
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 30;						// ��������߶�Ϊ30
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// ��������ΪFONT
	settextstyle(&format);						// ����������ʽ
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\SignIN.png"), 1280, 720);
	putimage(0, 0, &BG);	// ��ʾ����
	//���϶��ǳ������
	char UserName[50];
	char UserNameCheck=0;
	char PassWord[50];
	int MENUchoice;
	MENUchoice = Log_MENUChoose();		//�Ƚ�����ҳ
	while (true)											//ѭ��
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