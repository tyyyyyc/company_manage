#ifndef SERVICE_IMPL_H
#define SERVICE_IMPL_H
#include"service.h"

class ServiceImpl:public Service
{
public:
	void init_Dept_Id(int Dept_id);//初始化部门文本文件
	void init_Emp_Id(int Emp_id);//初始化员工文本文件
	int generator_Dept_Id(void);//生成唯一的部门ID号
	int generator_Emp_Id(void);//生成唯一的员工ID号
	
	bool add_Dept(char* Dept_Name);//增加部门
	bool delete_Dept(int Dept_Id);//删除部门
	bool list_Dept(void);//列出部门
	bool add_Emp(int Dept_Id,char* Emp_Name,int Emp_Gender,int Emp_Age);//增加员工，部门id
	bool delete_Emp(int Emp_Id);//删除员工,员工id
	bool update_Emp(int Emp_Id);//修改员工信息
	bool list_Emp(int Emp_Id);//列出部门员工,部门id
	bool listAll_Emp(void);//列出所有员工

};

#endif//SERVICE_IMPL_H
