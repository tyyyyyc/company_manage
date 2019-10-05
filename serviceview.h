#ifndef SERVICEVIEW_H
#define SERVICEVIEW_H
/*
	纯虚函数，定义接口
*/
class ServiceView
{
public:
	virtual void menu(void) = 0; 
	virtual void add_Dept(void) = 0;
	virtual void delete_Dept(void) = 0;
	virtual void list_Dept(void) = 0;
	virtual void add_Emp(void) = 0;
	virtual void delete_Emp(void) = 0;
	virtual void update_Emp(void) = 0;
	virtual void list_Emp(void) = 0;
	virtual void listAll_Emp(void) = 0;
};

#endif//SERVICEVIEW_H
