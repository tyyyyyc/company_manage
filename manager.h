#ifndef MANAGER_H
#define MANAGER_H
#include<string.h>
#include"emis.h"
class Manager
{
	char name[20] ;//名称
	char password[20];//密码
public:
	Manager(void){}
	Manager(char* name,char* password)
	{
		strcpy(this->name,name);
		strcpy(this->password,password);
	}
	const char* get_Mana_Name(void);
	const char* get_Mana_Password(void);
};

#endif//MANAGER_H
