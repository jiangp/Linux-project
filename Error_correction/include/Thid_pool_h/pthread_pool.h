/*************************************************************************
	> File Name: pthread_pool.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 03:24:26 PM CST
 ************************************************************************/
#ifndef _PTHREAD_POOL_H
#define _PTHREAD_POOL_H

#include"Noncopyable.h"
#include<functional>
#include<pthread.h>

class Thread : private Noncopyable
{	
public:
	typedef std::function<void ()> ThreadCallback;
	explicit Thread(ThreadCallback callback);
	~Thread();
	void start();
	void join();
private:
	ThreadCallback m_callback;//callback func

	static void *runInThread(void *);
	pthread_t m_pthid;
	bool m_isRunning;

};


#endif
