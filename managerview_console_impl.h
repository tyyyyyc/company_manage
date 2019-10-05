#ifndef MANAGERVIEW_CONSOLE_IMPL_H
#define MANAGERVIEW_CONSOLE_IMPL_H
#include "managerview.h"
#include "managerservice_impl.h"

class MaganagerViewConsoleImpl:public MaganagerView
{
	ManagerServiceImpl* m;
public:
	MaganagerViewConsoleImpl(void)
	{
		m = new ManagerServiceImpl;
	}
	~MaganagerViewConsoleImpl(void)
	{
		delete m;
	}
	void menu(void); 
	void add(void);
	void del(void);
	void list(void);
	
};

#endif//MANAGERVIEW_CONSOLE_IMPL_H
