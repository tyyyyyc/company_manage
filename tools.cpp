#include<stdlib.h>
#include<getch.h>
#include"emis.h"
#include"tools.h"

//任意键继续
void anyone_key(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
	cout << "请按任意键继续...";
	getch();
}
