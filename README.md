﻿# 民航票务系统的设计与实现
这里是NJUPT计算机学院2019级学生的程序设计课程小组
Developing outline for group 09

## 确定基本功能及框架
* Basic Function：
	* 主界面（欢迎界面/各功能入口）
	* 用户登入/登出界面（管理员游客认证/旅客信息填写与认证）
	* 机票/航班信息管理[admin]（录入/修改/删除相关数据）
	* 机票/航班信息查找[user]（查询/按照要求排列相关数据/航班信息时间表）
	* 机票/航班预订[user]（预售/改签/退票）
	* 旅客信息管理[admin]（旅客个人信息查询/已定机票/按照航班查询乘客）
* Advanced Functions：
	* 图形界面
	* 更完善的机票/航班信息系统[admin]（机型/航司/登机口/舱位）
	* 更完善的机票/航班预订[user]（价格波动/退票费/改签费/舱位、座位选择）
        
## 小组分工：
* HuaCL[面向管理员的大部分功能]：
	* 航班信息录入、录入时进行查重；
	* 航班信息的查看查找，包括其所搭载的旅客信息；
	* 航班信息的删除、更改、按特定顺序排
	* 航班信息的文件写入；
* Tang[面向用户的大部分功能]：
	* 新用户注册、基本信息填写、密码更改;
	* 管理员验证；
	* 旅客信息录入、录入时进行信息准确度查询；
	* 旅客信息的文件写入
* Lei[面向旅客的大部分功能]：
	* 订票、退票、改签、选座界面及相关限制；
	* 余票查询、航班查询、排序[面向客户]； 
	* 旅客订票信誉；
## Day 4 20200329
* 小组项目进展
	* 所有成员在相关订票软件/网页上进行了实际使用，明确了自己要完成的相关功能
	* 基本分工暂且不变
	* 由于c语言大家都有些生疏，故项目进度稍有推迟。过去几日进行了c语言相关内容的复习与回顾。
	* 已明确主要函数的功能
	* 具体已开工编写代码部分：
		* 用户注册和登录部分代码
		* 航班信息读取、显示、写入文件部分代码
	* 已在github上创建仓库用于组员协同
	* 预计在本周完成基本代码编写并进行代码合体
## Day 5 20200330
* 小组项目进展
	* 下午小组进行的电话讨论，确定了几个具体的问题，比如数据的查找，座位的定义，票价等，并相应的更改的相关结构体  
	具体内容有：
		* 结构体FlightID中增加票价一栏，用于基准票价的计算
		* 结构体FlightTicket中删除了余票信息一栏，而是使用一个数组来代表座位用于标明订座情况
		* 对单通道飞机和双通道飞机设置两种座舱布局
## Day 11 20200405
* 小组项目进展
	* 所有组员已经基本完成自己的代码编写工作，主要内容有：
		* 航班信息的录入，查找，删除，更改，排序，文件读取与写入；
		* 用户注册、基本信息填写、密码更改，找回密码，用户与管理员的区分；
		* 机票的订票、退票、改签、选座；
	* 部分功能仍在完善/调试。
	* 预计本周进行主菜单的编写，代码合并工作。并同期进行联合调试。
## Day 18 20200412
* 小组项目进展
	* 本周二(4.7)小组进行代码合并的相关讨论，确定了菜单界面的样式
		* 菜单分为程序开始的用户注册登录菜单(杨艺林负责）
		* 以及登陆过后根据登录用户性质面对的管理员（华文嘉负责）/普通用户（雷尚远负责）菜单
	* 同时，组员相互之间共享了已编写的功能函数，利于代码重用，并利用这些函数开始了自己菜单的逻辑设计和代码编写  
	至周日，组员已经基本完成了自己的菜单编写（由于GUI菜单界面的编写较为复杂，最终的代码合并稍有推迟）
	* 明天（4.13）小组将进行最后一次电话讨论，将所有的代码合并并进行最后的联合调试。
	
## 已知BUG
* "const char \*" 类型的实参与 "char \*" 类型的形参不兼容 **BUG FIX**  
VS2019中 项目 -> 属性 -> C/C++ -> 语言 -> 符合模式 将“是”改为“否”即可。

