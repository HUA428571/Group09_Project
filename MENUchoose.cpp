#include"MENUchoose.h"

int AdminMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
		}
	}
}
int AdminMENU_SearchMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڰ��������������
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڰ���ɵ���������
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڰ��������������
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴�ڰ��𽵵���������
				return 14;
		}
	}
}
int AdminMENU_SearchMENU_MultiFlight_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڰ��������������
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڰ���ɵ���������
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڰ��������������
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴�ڰ��𽵵���������
				return 14;
			if (m.x > 1070 && m.y > 165 && m.x < 1100 && m.y < 195)//��갴����һҳ����
				return 15;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//��갴����һҳ����
				return 16;
			if (m.x > 460 && m.y > 200 && m.x < 540 && m.y < 230)//��갴�����ʱ����������
				return 19;
			for (int i = 0; i < 15; i++)//i������������
			{
				if (m.x > 380 && m.y > 230 + 30 * i && m.x <1220 && m.y < 260 + 30 * i)//��갴�ھ���Ŷ��������
					return i+101;
			}
		}
	}

}
int AdminMENU_SearchMENU_MultiFlight_FlightDetail_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڰ��������������
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڰ���ɵ���������
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڰ��������������
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴�ڰ��𽵵���������
				return 14;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//��갴�ڷ�������
				return 18;
		}
	}
}

int AdminMENU_DeleteMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴��ɾ������
				return 31;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴��ȡ������
				return 32;
		}
	}
}

int AdminMENU_AddMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴���������
				return 21;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴��ȡ������
				return 22;
		}
	}
}


int AdminMENU_MainMENU_Import_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڵ��뺽�����ݿ�����
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڵ����Ʊ���ݿ�����
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڵ����������ݿ�����
				return 53;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴�ڵ�����Ʊ���ݿ�����
				return 54;
			if (m.x > 400 && m.y > 300 && m.x < 550 && m.y < 390)//��갴��ȷ�ϵ�������
				return 57;
			if (m.x > 550 && m.y > 300 && m.x < 700 && m.y < 390)//��갴��ȡ����������
				return 58;
			if (m.x > 700 && m.y > 300 && m.x < 850 && m.y < 390)//��갴���޸�·������
				return 59;

		}
	}
}

int AdminMENU_MainMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//��갴�ڸ�������
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//��갴�ڵ��뺽�����ݿ�����
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//��갴�ڵ����Ʊ���ݿ�����
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//��갴�ڵ����������ݿ�����
				return 53;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//��갴�ڵ�����Ʊ���ݿ�����
				return 54;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//��갴���˳�����
				return 5;
		}
	}
}
