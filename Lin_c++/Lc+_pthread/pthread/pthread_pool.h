/*************************************************************************
	> File Name: pthread_pool.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 03:24:26 PM CST
 ************************************************************************/
#ifndef _PTHREAD_POOL_H
#define _PTHREAD_POOL_H

#include<stdio.h>
#include<pthread.h>
#include<iostream>
#include<string>
#include<unistd.h>
#include"Noncopyable.h"
//#include"mutex.h"


class Thread : private Noncopyable
{
	pthread_t m_pthid;
	bool m_isRunning;
protected:
	static void *runInThread(void *arg);
public:
	Thread() : m_pthid(0), m_isRunning(false){}
	virtual ~Thread();
	void start();
	void join();
	virtual void run()= 0;

	pthread_t thread_id() const;
};





class MyThread :public Thread
{
public:
	void run()
	{
		while(1)
		{
			std::cout << " OK " << std::endl;
			sleep(3);
		}
	}
};

#endif
