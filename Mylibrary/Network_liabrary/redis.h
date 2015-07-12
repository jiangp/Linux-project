/*************************************************************************
  > File Name: redis.h
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Sun 05 Apr 2015 11:25:40 PM CST
 ************************************************************************/

#ifndef _REDIS_H_
#define _REDIS_H_

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <hiredis/hiredis.h>

class Redis
{
	public:

		Redis(){}

		~Redis()
		{
			this->m_connect = NULL;
			this->m_reply = NULL;	    	    
		}
	// connect the redis
		bool connect(std::string host, int port)
		{
			this->m_connect = redisConnect(host.c_str(), port);
			if(this->m_connect != NULL && this->m_connect->err)
			{
				printf("connect error: %s\n", this->m_connect->errstr);
				return 0;
			}
			return 1;
		}
		//get the data
		std::string get(std::string key)
		{
			this->m_reply = (redisReply*)redisCommand(this->m_connect, "GET %s", key.c_str());

			if (NULL == (this->m_reply->str)){

				freeReplyObject(this->m_reply);
				return "NO";
			}else{

				std::string str = this->m_reply->str;
				freeReplyObject(this->m_reply);

				return str;
			}
		}
		//save the data
		void set(std::string key, std::string value)
		{
			redisCommand(this->m_connect, "SET %s %s", key.c_str(), value.c_str());
		}

	private:

		redisContext* m_connect;
		redisReply* m_reply;

};

#endif

