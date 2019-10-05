#include "sql.h"
	
SQL::SQL(const char* ip,const char* user,const char* passwd,const char* database,uint16_t port)
{
	conn = mysql_init(NULL);
    if(NULL == conn)
    {
        printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
        return;
    }
    printf("数据库连接初始化成功...\n");
	connect(ip,user,passwd,database,port);
	mysql_query(conn,"SET NAMES 'utf8'");
}
	
SQL::~SQL(void)
{

}
	
bool SQL::connect(const char* ip,const char* user,const char* passwd,const char* database,uint16_t port)
{
	if(NULL == mysql_real_connect(conn,ip,user,passwd,database,port,NULL,0))
    {
        printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
        return false;
    }
    printf("数据库连接成功...\n");
    on_Auto_Commit();
    printf("数据库默认设置为自动commit...\n");
    return true;
}

void SQL::show_Result(vector<vector<string> >& result)
{
	for(vector<vector<string> >::iterator i = result.begin(); i!=result.end(); i++)
	{
		for(vector<string>::iterator j=i->begin(); j!=i->end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}

int SQL::insert_date(const char* cmd)
{
	
	if(mysql_query(conn,cmd) != NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;
	}
	printf("插入数据成功：%s\n",cmd);
	
	return mysql_affected_rows(conn);
}

int SQL::delete_date(const char* cmd)
{
	if(mysql_query(conn,cmd) != NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;
	}
	printf("删除数据成功：%s\n",cmd);
	
	return mysql_affected_rows(conn);
}
//修改数据
int SQL::update_date(const char* cmd)
{
	if(mysql_query(conn,cmd) != NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;
	}
	printf("修改数据成功：%s\n",cmd);
	
	return mysql_affected_rows(conn);
}

int SQL::select_date(const char* cmd,vector<vector<string> >& result)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	if(mysql_query(conn,cmd) != NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return -1;
	}
	int num_fields = mysql_field_count(conn);
	if(num_fields == NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;	
	}
	res = mysql_store_result(conn);
	if(NULL == res)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;
	}
	int count = 0;
	while((row = mysql_fetch_row(res)))
	{
		vector<string> arr;
		for(int i=0; i<num_fields; i++)
		{
			string str(row[i]);
			arr.push_back(str);
		}
		result.push_back(arr);	
		count++;
	}	
	mysql_free_result(res);
	return count;
}
//直接显示
int SQL::select_date(const char* cmd)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL_FIELD * field;
	if(mysql_query(conn,cmd) != NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;
	}
	int num_fields = mysql_field_count(conn);
	if(num_fields == NONE)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;	
	}
	res = mysql_store_result(conn);
	if(NULL == res)
	{
		printf("errno:%d error:%s\n",mysql_errno(conn),mysql_error(conn));
		return ERROR;
	}
	int count = 0;
	printf("+---------------------+\n");
	while((field = mysql_fetch_field(res)))
	{
		printf("|%-15s",field->name);
	}
	printf("|\n+---------------------+\n");
	while(row = mysql_fetch_row(res))
	{
		for(int i = 0 ; i < num_fields ; i++)
		{
			printf("|%-15s",row[i]);	
		}
		printf("|\n");
	}
	printf("+---------------------+\n");
	mysql_free_result(res);
	return count;
}

bool SQL::off_Auto_Commit(void)
{
	isAutoCommit = false;
	return mysql_autocommit(conn,isAutoCommit);
}

bool SQL::on_Auto_Commit(void)
{
	isAutoCommit = true;
	return mysql_autocommit(conn,isAutoCommit);
}

bool SQL::get_Auto_Commit(void)
{
	return isAutoCommit;
}
