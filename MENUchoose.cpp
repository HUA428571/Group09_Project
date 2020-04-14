#include"MENUchoose.h"

int AdminMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
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
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
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
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
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
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在按航班号搜索区域
				return 11;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在按起飞地搜索区域
				return 12;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在按降落地搜索区域
				return 13;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在按起降地搜索区域
				return 14;
			if (m.x > 1190 && m.y > 165 && m.x < 1220 && m.y < 195)//鼠标按在返回区域
				return 18;
		}
	}
}

int AdminMENU_DeleteMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在删除区域
				return 31;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在取消区域
				return 32;
		}
	}
}

int AdminMENU_AddMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在添加区域
				return 21;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在取消区域
				return 22;
		}
	}
}


int AdminMENU_MainMENU_Import_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在导入航线数据库区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在导入机票数据库区域
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在导出航线数据库区域
				return 53;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在导出机票数据库区域
				return 54;
			if (m.x > 400 && m.y > 300 && m.x < 550 && m.y < 390)//鼠标按在确认导入区域
				return 57;
			if (m.x > 550 && m.y > 300 && m.x < 700 && m.y < 390)//鼠标按在取消导入区域
				return 58;
			if (m.x > 700 && m.y > 300 && m.x < 850 && m.y < 390)//鼠标按在修改路径区域
				return 59;

		}
	}
}

int AdminMENU_MainMENU_MENUChoose()
{
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在导入航线数据库区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在导入机票数据库区域
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在导出航线数据库区域
				return 53;
			if (m.x > 100 && m.y > 450 && m.x < 300 && m.y < 490)//鼠标按在导出机票数据库区域
				return 54;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//鼠标按在退出区域
				return 5;
		}
	}
}
