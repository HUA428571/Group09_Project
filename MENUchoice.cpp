#include"MENUchoice.h"

int AdminMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//������������
		{
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//��갴�ڸ�������
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
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//��갴�ڸ�������
				return 4;
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//��갴�ڰ��������������
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//��갴�ڰ���ɵ���������
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//��갴�ڰ��������������
				return 13;
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
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//��갴�ڸ�������
				return 4;
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//��갴�ڰ��������������
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//��갴�ڰ���ɵ���������
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//��갴�ڰ��������������
				return 13;
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
			if (m.y > 90 && m.y < 136 && m.x>220 && m.x < 325)//��갴����ҳ����
				return 0;
			if (m.y > 90 && m.y < 136 && m.x>410 && m.x < 515)//��갴�ڲ�������
				return 1;
			if (m.y > 90 && m.y < 136 && m.x>600 && m.x < 705)//��갴���������
				return 2;
			if (m.y > 90 && m.y < 136 && m.x>790 && m.x < 895)//��갴��ɾ������
				return 3;
			if (m.y > 90 && m.y < 136 && m.x>980 && m.x < 1085)//��갴�ڸ�������
				return 4;
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//��갴�ڰ��������������
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//��갴�ڰ���ɵ���������
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//��갴�ڰ��������������
				return 13;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//��갴�ڷ�������
				return 18;
		}
	}
}

