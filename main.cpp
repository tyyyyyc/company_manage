#include <stdlib.h>
#include <getch.h>
#include "serviceview_console_impl.h"
#include "managerview_console_impl.h"
#include "tools.h"
#include "sql.h"
#include "emis.h"

//定义为全局变量
SQL Dept;
SQL Mana;
SQL Emp;

int main()
{

	//连接数据库并创建相应的数据库
	Dept.insert_date("create table Dept(Dept_Id int,Dept_Name char(20));");//部门
	Mana.insert_date("create table Mana(Mana_Id int,Mana_Name char(20),Mana_pass char(20));");//经理
	Emp.insert_date("create table Emp(Emp_Id int,Dept_Id int,Emp_Name char(20),Emp_Gender char(5),Emp_Age int);");//员工
	
	MaganagerViewConsoleImpl mag;
	ServiceViewConsoleImpl ser;
	while(1)
	{
		cin.clear();
		system("clear");
		cout << "企业管理系统" << endl;
		cout << "1.管理子系统界面" << endl;
		cout << "2.业务子系统界面" << endl;
		cout << "q.退出" << endl;
		switch(getch())
		{
			case'1':mag.menu();break;
			case'2':ser.menu();break;
			case'q':return QUIT;
			case'Q':return QUIT;
			default :cout << "输入的指令不正确!" << endl;anyone_key();break;
		}
		
	}
	return 0;
}
