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
namespace Tiny
{

class Thread : private Noncopyable
{
protected:
	static void *runInThread(void *);
public:
	typedef std::function<void ()> ThreadCallback;
	explicit Thread(ThreadCallback callback);
	virtual ~Thread();
	void start();
	void join();
private:
	ThreadCallback m_callback;//callback func
	pthread_t m_pthid;
	bool m_isRunning;

};
}

#endif
