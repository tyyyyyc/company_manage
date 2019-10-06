#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string.h>
#include"employee.h"
#include"emis.h"

class Department
{
	int Dept_Id;//ID号
	char Dept_Name[20];//名称
public:
	Department(int Dept_Id,char* Dept_Name)
	{
		this->Dept_Id = Dept_Id;
		strcpy(this->Dept_Name,Dept_Name);
	}
	//获得
	int get_Dept_Id(void);
	char* get_Dept_Name(void);
};

#endif//DEPARTMENT_H
