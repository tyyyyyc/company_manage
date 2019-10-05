#include <string.h>
#include <stdlib.h>
#include <getch.h>
#include <fstream>
#include "emis.h"
#include "tools.h"
#include "managerview_console_impl.h"



void MaganagerViewConsoleImpl::menu(void)
{

	system("clear");
	cin.clear();	//清空输入缓冲区
	char id[20];
	cout << "请输入账号" <<endl;
	cin >> id;
	char password[20];
	cout << "请输入密码" <<endl;
	cin >> password;
	if(strcmp(id,SUPER_ID) && strcmp(password,SUPER_PASS))
	{
		cout << "登入失败,请重试" << endl;
		anyone_key();
		return;
	}
	cout << "登入成功" <<endl;
	anyone_key();
	
	while(1)
	{
		system("clear");
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		cout << "1.添加管理员" << endl;
		cout << "2.删除管理员" << endl;
		cout << "3.列出管理员" << endl;
		cout << "q.退出" << endl;
		switch(getch())
		{
			case'1':MaganagerViewConsoleImpl::add();anyone_key();break;
			case'2':MaganagerViewConsoleImpl::del();anyone_key();break;
			case'3':MaganagerViewConsoleImpl::list();anyone_key();break;
			case'q':return;
			case'Q':return;
			default :cout << "输入的指令不正确!" << endl;anyone_key();break;
		}
	}
}
void MaganagerViewConsoleImpl::add(void)
{
	system("clear");
	char name[20] = {};
	cout << "请输入管理员的名字:";
	cin >> name;
	char password[20] = {};
	cout << "请输入密码:";
	cin >> password;
	if(m->add_Manage(name,password))
		cout << "添加成功" <<endl;
	else
		cout << "添加失败" <<endl;
}
void MaganagerViewConsoleImpl::del(void)
{

	system("clear");
	cin.clear();
	int id;
	cout << "请输入管理员的id:";
	cin >> id;
	if(m->delete_Manager(id))
		cout << "删除成功" <<endl;
	else
		cout << "删除失败" <<endl;


}
void MaganagerViewConsoleImpl::list(void)
{
	system("clear");
	if(!m->list_Manager())
	{
		cout << "empty" <<endl;	
	}
}




