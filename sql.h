#ifndef SQL_H
#define SQL_H
 
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdint.h>
#include <mysql/mysql.h>
#include "emis.h"

class SQL
{
	MYSQL* conn;
	bool isAutoCommit;
public:
	SQL(const char* ip="127.0.0.1",const char* user="test",const char* passwd="123456",const char* database="testDB",uint16_t port=3306);
	
	~SQL(void);
	
	bool connect(const char* ip,const char* user,const char* passwd,const char* database,uint16_t port);
	
	int insert_date(const char* cmd);
	int delete_date(const char* cmd);
	int update_date(const char* cmd);
	//select重载
	int select_date(const char* cmd,vector<vector<string> >& result);
	int select_date(const char* cmd);
	
	void show_Result(vector<vector<string> >& result);
	
	bool off_Auto_Commit(void);
	bool on_Auto_Commit(void);
	bool get_Auto_Commit(void);
};

#endif//SQL_H
