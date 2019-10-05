#ifndef SERVICEVIEW_CONSOLE_IMPL_H
#define SERVICEVIEW_CONSOLE_IMPL_H
#include"emis.h"
#include"serviceview.h"
#include"service_impl.h"

class ServiceViewConsoleImpl:public ServiceView
{
	ServiceImpl* m_pService;
public:
	ServiceViewConsoleImpl(void)
	{
		m_pService = new ServiceImpl;
	}
	~ServiceViewConsoleImpl(void)
	{
		delete m_pService;
	}
	void menu(void); 
	void add_Dept(void);
	void delete_Dept(void);
	void list_Dept(void);
	void add_Emp(void);
	void delete_Emp(void);
	void update_Emp(void);
	void list_Emp(void);
	void listAll_Emp(void);
	int load(int id,string password);//登入界面
};

#endif//SERVICEVIEW_CONSOLE_IMPL_H
