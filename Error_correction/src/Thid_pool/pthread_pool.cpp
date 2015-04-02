/*************************************************************************
	> File Name: pthread_pool.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 04:19:22 PM CST
 ************************************************************************/

#include"pthread_pool.h"
#include<assert.h>
#include"mutex.h"

Thread::Thread(ThreadCallback callback)
	: m_callback(std::move(callback)) 
{ 
}

Thread::~Thread()
{
	if(m_isRunning)
	{
		TINY_CHECK(!pthread_detach(m_pthid));
	}
}

void Thread::start()
{
	TINY_CHECK(!pthread_create(&m_pthid, NULL, runInThread, this));
	m_isRunning = true;
}


void Thread::join()
{
	assert(m_isRunning);
	TINY_CHECK(!pthread_join(m_pthid, NULL));
	m_isRunning = false;
}



void *Thread::runInThread(void *arg) 
{
	Thread *pt = static_cast<Thread*>(arg);
	pt->m_callback();//calback
	return NULL;
}
