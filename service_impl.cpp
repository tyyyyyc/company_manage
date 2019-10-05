#include <string.h>
#include <fstream>
#include <vector>
#include "sql.h"
#include "emis.h"
#include "service_impl.h"


extern SQL Dept;
extern SQL Mana;
extern SQL Emp;

//增加部门
bool ServiceImpl::add_Dept(char* Dept_Name)
{
	ServiceImpl::init_Dept_Id(1);	//初始化部门ID
	int Dept_Id = generator_Dept_Id();	//设置唯一ID
	char buf[1024] = {};
	sprintf(buf,"insert into Dept values(%d,'%s');",Dept_Id,Dept_Name);
	if(NONE >= Dept.insert_date(buf))	//插入数据库
	{
		return false;	
	}
	return true;
}

//删除部门
bool ServiceImpl::delete_Dept(int Dept_Id)
{
	char buf[1024] = {};
	sprintf(buf,"delete from Dept where Dept_Id=%d;",Dept_Id);
	if(0 >= Dept.delete_date(buf))
	{
		return false;
	}
	return true;
}
//列出部门
bool ServiceImpl::list_Dept(void)
{
	char buf[1024] = {};
	sprintf(buf,"select * from Dept;");
	vector<vector<string> > result;
	if(NONE >= Dept.select_date(buf,result))
	{
		return false;
	}
	Dept.show_Result(result);
	return true;
}

//增加员工，部门id
bool ServiceImpl::add_Emp(int Dept_Id,char* Emp_Name,int Emp_Gender,int Emp_Age)
{
	char buf[1024] = {};
	vector<vector<string> > result;
	sprintf(buf,"select * from Dept where Dept_Id=%d;",Dept_Id);
	if(NONE >= Dept.select_date(buf,result))
	{
		return false;
	}
	bzero(buf,sizeof(buf));
	init_Emp_Id(1000);
	int id = generator_Emp_Id();
	const char* sex = Emp_Gender > 0 ? "男":"女";
	sprintf(buf,"insert into Emp values(%d,%d,'%s','%s',%d);",id,Dept_Id,Emp_Name,sex,Emp_Age);
	if(NONE >= Emp.insert_date(buf))
	{
		return false;
	}
	return true;
}

//删除员工,员工id
bool ServiceImpl::delete_Emp(int Emp_Id)
{
	char buf[1024] = {};
	sprintf(buf,"delete from Emp where Emp_Id=%d;",Emp_Id);
	if(0 >= Dept.delete_date(buf))
	{
		return false;
	}
	return true;
}

//修改员工信息
bool ServiceImpl::update_Emp(int Emp_Id)
{
	char buf[1024] = {};
	sprintf(buf,"select * from Emp where Emp_Id=%d;",Emp_Id);
	vector<vector<string> > result;
	if(NONE >= Emp.select_date(buf,result))
	{
		return false;
	}
	char Emp_name[20];
	cout << "请输入姓名:";
	cin >> Emp_name;
	int sex;
	cout << "请输入性别(0女／1男):";
	cin >> sex;
	int Emp_age;
	cout << "请输入年龄:";
	cin >> Emp_age;			
	const char* Emp_sex = sex > 0 ? "男":"女";
	bzero(buf,sizeof(buf));
	sprintf(buf,"update Emp set Emp_Name='%s',Emp_Gender='%s',Emp_Age=%d where Emp_Id=%d;",Emp_name,Emp_sex,Emp_age,Emp_Id);
	Emp.update_date(buf);
	return true;
}

//列出部门员工,部门id
bool ServiceImpl::list_Emp(int Dept_Id)
{
	char buf[1024] = {};
	sprintf(buf,"select * from Emp where Dept_Id=%d;",Dept_Id);
	vector<vector<string> > result;
	if(NONE >= Emp.select_date(buf,result))
	{
		return false;
	}
	Emp.show_Result(result);
	return true;
}

//列出所有员工
bool ServiceImpl::listAll_Emp(void)
{
	char buf[1024] = {};
	sprintf(buf,"select * from Emp;");
	vector<vector<string> > result;
	if(NONE >= Emp.select_date(buf,result))
	{
		return false;
	}
	Emp.show_Result(result);
	return true;
}

//设置部门初始id
void ServiceImpl::init_Dept_Id(int Dept_id)
{
	if(SUCCESS == access("./department/Dept_Id.dat",F_OK))
	{
		return;
	}
	fstream fs("./department/Dept_Id.dat",ios::out|ios::binary);
	fs << Dept_id;
	fs.close();
}

//生成唯一的部门ID号
int ServiceImpl::generator_Dept_Id(void)
{
	int id = 0;
	fstream fs("./department/Dept_Id.dat",ios::in|ios::binary);
	if(!fs.good())
	{
		cout << "./department/Dept_Id.dat exit" << endl;
		return ERROR;
	}
	fs >> id;
	id++;
	fstream fs1("./department/Dept_Id.dat",ios::out|ios::binary);
	fs1 << id;
	fs.close();
	fs1.close();
	return id-1;
}

//设置员工初始id
void ServiceImpl::init_Emp_Id(int Emp_id)
{
	if(SUCCESS == access("./department/Emp_Id.dat",F_OK))
	{
		return;
	}
	fstream fs("./department/Emp_Id.dat",ios::out|ios::binary);
	fs << Emp_id;
	fs.close();
}

//生成唯一的员工ID号
int ServiceImpl::generator_Emp_Id(void)
{
	int id = 0;
	fstream fs("./department/Emp_Id.dat",ios::in|ios::binary);
	if(!fs.good())
	{
		cout << "./department/Emp_Id.dat exit" << endl;
		return ERROR;
	}
	fs >> id;
	id++;
	fstream fs1("./department/Emp_Id.dat",ios::out|ios::binary);
	fs1 << id;
	fs.close();
	fs1.close();
	return id-1;
}






