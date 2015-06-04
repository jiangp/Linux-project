/*************************************************************************
	> File Name: mysqlh.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 23 Apr 2015 07:41:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include<mysql/mysql.h>
int main()
{
	MYSQL my_connection;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	int res;
	char column[32][32];
	char query[1024];

	/*init sql porint*/
	if(!mysql_init(&my_connection))
	{
		perror("mysql_init fail!\n");
		return 0;
	}
	/*connect mysql*/
	if(!(mysql_real_connect(&my_connection, "localhost", "root", "666", "FTP_SQL", 3306, NULL, CLIENT_MULTI_STATEMENTS)))
	{
		perror("mysql_connect fail!\n");
		mysql_close(&my_connection);
		return 0;
	}
	/*set sql */
	 strcpy(query, "INSERT INTO test( name, passwd, role,value)values('user4', '12345', 2,'good');");
//	 mysql_real_query(&my_connection, query, (unsigned int)strlen(query));
	if(mysql_query(&my_connection, query))
		printf("error\n");
	else
		printf("success input%lu\n",(ulong)mysql_affected_rows(&my_connection));
	 /*get sql */
	res = mysql_query(&my_connection,"SELECT * from test");
	if(!res)
	{
		result = mysql_store_result(&my_connection);
		if(result){
			int i, j;
			printf("the result number is %lu\n", (unsigned long)mysql_num_rows(result));
			for(i = 0; fd = mysql_fetch_field(result); ++i){
				bzero(column[i], sizeof(column[i]));
				strcpy(column[i], fd->name);
			}
			j = mysql_num_fields(result);
			for(i = 0; i < j; ++i)
			{
				printf("%s  ", column[i]);
			}
			printf("\n");
			while(sql_row = mysql_fetch_row(result)){
				printf("[%s]-[%s]-[%s]\n",sql_row[0],sql_row[1],sql_row[2]);
			}
		}
	}

	mysql_free_result(result);
	mysql_close(&my_connection);
	return 0;
}
