#include <fstream>
#include "sql.h"
#include "emis.h"
#include "managerservice_impl.h"

extern SQL Mana;
//增加管理员
bool ManagerServiceImpl::add_Manage(char* Mana_Name,char* Mana_Password)
{
	init_Mana_Id(123);	//初始化管理员ID
	int Mana_Id = generator_Mana_Id();
	char buf[1024] = {};
	sprintf(buf,"insert into Mana values(%d,'%s','%s');",Mana_Id,Mana_Name,Mana_Password);
	if(NONE >= Mana.insert_date(buf))	//插入数据库
	{
		return false;
	}
	return true;
}

//删除管理员
bool ManagerServiceImpl::delete_Manager(int Mana_Id)
{
	char buf[1024] = {};
	sprintf(buf,"delete from Mana where Mana_Id=%d;",Mana_Id);
	if(NONE >= Mana.delete_date(buf))
	{
		return false;	
	}
	return true;
}
//显示管理员
bool ManagerServiceImpl::list_Manager(void)
{
	char buf[1024] = {};
	sprintf(buf,"select * from Mana;");
	vector<vector<string> > result;
	if(NONE >= Mana.select_date(buf,result))
	{
		return false;
	}
	Mana.show_Result(result);
	return true;
}


//设置管理员初始id
void ManagerServiceImpl::init_Mana_Id(int Mana_Id)
{
	if(SUCCESS == access("./department/Mgr_Id.dat",F_OK))
	{
		return;
	}
	fstream fs("./department/Mgr_Id.dat",ios::out|ios::binary);
	fs << Mana_Id;
	fs.close();
}

//生成唯一的管理员ID号
int ManagerServiceImpl::generator_Mana_Id(void)
{
	int Mana_Id = 0;
	fstream fs("./department/Mgr_Id.dat",ios::in|ios::binary);
	if(!fs.good())
	{
		cout << "./department/Mgr_Id.dat exit" << endl;
		return ERROR;
	}
	fs >> Mana_Id;
	Mana_Id++;
	fstream fs1("./department/Mgr_Id.dat",ios::out|ios::binary);
	fs1 << Mana_Id;
	fs.close();
	fs1.close();
	return Mana_Id-1;
}



