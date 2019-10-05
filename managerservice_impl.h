#ifndef MANAGERSERVICE_IMPL_H
#define MANAGERSERVICE_IMPL_H
#include "managerservice.h"

//业务逻辑层接口
class ManagerServiceImpl:public ManagerService
{
public:
	bool add_Manage(char* Mana_Name,char* Mana_Password);//增加管理员
	bool delete_Manager(int Mana_Id);//删除管理员
	bool list_Manager(void);//显示管理员
	void init_Mana_Id(int Mana_Id);//初始化管理员id
	int generator_Mana_Id(void);//设置管理员id
};

#endif//MANAGERSERVICE_IMPL_H
