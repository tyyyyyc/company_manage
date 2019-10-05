#ifndef MANAGERSERVICE_H
#define MANAGERSERVICE_H
//业务逻辑层接口
class ManagerService
{
public:
	virtual bool add_Manage(char* Mana_Name,char* Mana_Password)= 0;//增加管理员
	virtual bool delete_Manager(int Mana_Id)= 0;//删除管理员
	virtual bool list_Manager(void)= 0;//显示管理员
	virtual void init_Mana_Id(int Mana_Id) = 0;//初始化管理员id
	virtual int generator_Mana_Id(void) = 0;//设置管理员id
};

#endif//MANAGERSERVICE_H
