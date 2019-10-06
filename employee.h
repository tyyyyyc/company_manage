#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string.h>
#include"emis.h"
class Employee
{
	char Emp_Name[20];//名称
	int Emp_Gender;//性别，true表示男性，false表示女性
	int Emp_Age;//年龄
public:
	Employee(char* Emp_Name,bool Emp_Gender,int Emp_Age)
	{
		strcpy(this->Emp_Name,Emp_Name);
		this->Emp_Gender = Emp_Gender;
		this->Emp_Age = Emp_Age;
	}
	
	//得到信息
	char* get_Emp_Name(void);
	int get_Emp_Gender(void);
	int get_Emp_Age(void);
};

#endif//EMPLOYEE_H
