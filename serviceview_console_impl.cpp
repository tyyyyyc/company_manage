#include<stdlib.h>
#include<getch.h>
#include<fstream>
#include "sql.h"
#include"tools.h"

#include"serviceview_console_impl.h"


extern SQL Mana;

//业务主菜单
void ServiceViewConsoleImpl::menu(void)
{
	system("clear");
	int id;
	cin.clear();
	cout << "请输入账号" <<endl;
	cin >> id;
	char password[20];
	cout << "请输入密码" <<endl;
	cin >> password;
	int flag = load(id,password);
	if(NUMBER_ERROR == flag)
	{
		cout << "账号不存在,登入失败" << endl;
		anyone_key();
		return;
	}
	else if(PASSWORD_ERROR == flag)
	{
		cout << "密码错误,登入失败" << endl;
		anyone_key();
		return;
	}
	cout << "登入成功" <<endl;
	anyone_key();

	while(1)
	{
		system("clear");
		cout << "1.添加部门" << endl;
		cout << "2.删除部门" << endl;
		cout << "3.列出部门" << endl;
		cout << "4.添加员工" << endl;
		cout << "5.删除员工" << endl;
		cout << "6.修改员工" << endl;
		cout << "7.列出员工" << endl;
		cout << "8.列出所有员工" << endl;
		cout << "q.退出" << endl;
		switch(getch())
		{
			case'1':ServiceViewConsoleImpl::add_Dept();anyone_key();break;
			case'2':ServiceViewConsoleImpl::delete_Dept();anyone_key();break;
			case'3':ServiceViewConsoleImpl::list_Dept();anyone_key();break;
			case'4':ServiceViewConsoleImpl::add_Emp();anyone_key();break;
			case'5':ServiceViewConsoleImpl::delete_Emp();anyone_key();break;
			case'6':ServiceViewConsoleImpl::update_Emp();anyone_key();break;
			case'7':ServiceViewConsoleImpl::list_Emp();anyone_key();break;
			case'8':ServiceViewConsoleImpl::listAll_Emp();anyone_key();break;
			case'q':return;
			case'Q':return;
			default :cout << "输入的指令不正确!" << endl;anyone_key();break;
		}
	}
}
//1.添加部门菜单
void ServiceViewConsoleImpl::add_Dept(void)
{
	system("clear");
	char Dept_Name[20];
	cout << "请输入新部门的名字:";
	cin >> Dept_Name;
	if(m_pService->add_Dept(Dept_Name))
		cout << "添加成功" <<endl;
	else 
		cout << "添加失败" << endl;
}
//2.删除部门菜单
void ServiceViewConsoleImpl::delete_Dept(void)
{
	system("clear");
	int id;
	cin.clear();
	cout << "请输入要删除部门的编号:";
	cin >> id;
	if(m_pService->delete_Dept(id))
		cout << "删除成功" <<endl;
	else
		cout << "删除失败" <<endl;
}
//3.列出部门菜单
void ServiceViewConsoleImpl::list_Dept(void)
{
	system("clear");
	if(!m_pService->list_Dept())
	{
		cout << "empty" <<endl;
	}
}
//4.添加员工菜单
void ServiceViewConsoleImpl::add_Emp(void)
{
	system("clear");
	char Emp_Name[20];
	cout << "请输入员工姓名：";
	cin >> Emp_Name;
	int Emp_Gender;
	cout << "请输入员工姓别(0女/1男)：";
	cin >> Emp_Gender;
	int Emp_Age = 0;
	cout << "请输入员工年龄：";
	cin >> Emp_Age;
	int Dept_Id = 0;
	cout << "请输入要加入部门的id:";
	cin  >> Dept_Id;
	if(m_pService->add_Emp(Dept_Id,Emp_Name,Emp_Gender,Emp_Age))
	{
		cout << "添加成功" <<endl;
		return;
	}
	else
		cout << "添加失败，部门不存在" <<endl;
}
//删除员工菜单
void ServiceViewConsoleImpl::delete_Emp(void)
{
	system("clear");
	cin.clear();
	int id = 0;
	cout << "请输入要删除员工的id:";
	cin >> id;
	if(m_pService->delete_Emp(id))
		cout << "删除成功" <<endl;
	else
		cout << "删除失败" <<endl;
}
//修改员工菜单
void ServiceViewConsoleImpl::update_Emp(void)
{
	system("clear");
	cin.clear();
	int id = 0;
	cout << "请输入要修改员工的id:";
	cin >> id;
	if(m_pService->update_Emp(id))
		cout << "修改成功" <<endl;
	else
		cout << "修改失败" <<endl;
}
//列出员工菜单
void ServiceViewConsoleImpl::list_Emp(void)
{
	system("clear");
	cin.clear();
	int id = 0;
	cout << "请输入要查找的部门id:";
	cin >> id;
	if(!m_pService->list_Emp(id))
	{
		cout << "empty" <<endl;
	}
}
//列出所有员工菜单
void ServiceViewConsoleImpl::listAll_Emp(void)
{
	system("clear");
	if(!m_pService->listAll_Emp())
	{
		cout << "empty" <<endl;
	}
}

//登入界面
int ServiceViewConsoleImpl::load(int id,string password)
{
	int flag = 0;
	char buf[1024] = {};
	sprintf(buf,"select * from Mana where Mana_ID=%d;",id);
	vector<vector<string> > result;
	if(0 >= Mana.select_date(buf,result))
	{
		return NUMBER_ERROR;	//账号不存在;
	}
	else if(password != result[0][2])
	{
		return PASSWORD_ERROR;	//密码错误
	}
	return SUCCESS;
}

