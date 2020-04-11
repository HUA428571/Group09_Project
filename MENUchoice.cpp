#include"MENUchoice.h"

int AdminMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
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
int AdminMENU_SearchMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
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
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//鼠标按在按降落地搜索区域
				return 13;
		}
	}
}
int AdminMENU_SearchMENU_MultiFlight_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
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
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 1070 && m.y > 165 && m.x < 1100 && m.y < 195)//鼠标按在上一页区域
				return 15;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在下一页区域
				return 16;
			if (m.x > 460 && m.y > 200 && m.x < 540 && m.y < 230)//鼠标按在起飞时间区域（排序）
				return 19;
			for (int i = 0; i < 15; i++)//i用来计算行数
			{
				if (m.x > 380 && m.y > 230 + 30 * i && m.x <1220 && m.y < 260 + 30 * i)//鼠标按在具体哦航班区域
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
			if (m.x > 140 && m.y > 270 && m.x < 320 && m.y < 310)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 140 && m.y > 320 && m.x < 320 && m.y < 360)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 140 && m.y > 370 && m.x < 320 && m.y < 410)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在返回区域
				return 18;
		}
	}
}

