
#include <winsock.h>
#include <iostream>
#include <mysql.h>
using namespace std;
int main()
{
	const char user[] = "admin";
	const char pswd[] = "519519519";
	const char host[] = "172.31.73.118";
	const char table[] = "mysql";
	unsigned int port = 3306;
	MYSQL myCont;
	MYSQL_RES *result=NULL;
	MYSQL_ROW sql_row;
	int res;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式
		res = mysql_query(&myCont, "select * from track_detials");//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					cout << "name:" << sql_row[0] << endl;
					cout << "index:" << sql_row[1] << endl;
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&myCont);
	return 0;
}

