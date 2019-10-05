#ifndef SERVICE_H
#define SERVICE_H

//业务逻辑层接口
class Service
{
public:
	virtual void init_Dept_Id(int id) = 0;//初始化部门文本文件
	virtual void init_Emp_Id(int id) = 0;//初始化部门文本文件
	virtual int generator_Dept_Id(void) = 0;//生成唯一的部门ID号
	virtual int generator_Emp_Id(void) = 0;//生成唯一的员工ID号
	
	virtual bool add_Dept(char* m_strName)= 0;//增加部门
	virtual bool delete_Dept(int m_nId)= 0;//删除部门
	virtual bool list_Dept(void)= 0;//列出部门
	virtual bool add_Emp(int Dept_Id,char* Emp_Name,int Emp_Gender,int Emp_Age)= 0;//增加员工，部门id
	virtual bool delete_Emp(int m_nId)= 0;//删除员工,员工id
	virtual bool update_Emp(int m_nId)= 0;//修改员工信息
	virtual bool list_Emp(int m_nId)= 0;//列出部门员工,部门id
	virtual bool listAll_Emp(void)= 0;//列出所有员工
	
};

#endif//SERVICE_H
