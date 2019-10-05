#ifndef MANAGERVIEW_H
#define MANAGERVIEW_H

class MaganagerView
{
public:
	virtual void menu(void) = 0; 
	virtual void add(void) = 0;
	virtual void del(void) = 0;
	virtual void list(void) = 0;
};

#endif//MANAGERVIEW_H
