/*************************************************************************
	> File Name: pthread_pool.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 04:19:22 PM CST
 ************************************************************************/

#include"pthread_pool.h"
#include<assert.h>

Thread::~Thread()
{
	assert(m_isRunning);
	pthread_detach(m_pthid);
}

void Thread::start()
{
	assert(!m_isRunning);
	pthread_create(&m_pthid, NULL, runInThread, this);
	m_isRunning = true;
}


void Thread::join()
{
	assert(m_isRunning);
	pthread_join(m_pthid, NULL);
	m_isRunning = false;
}



void *Thread::runInThread(void *arg) 
{
	Thread *pt = static_cast<Thread *>(arg);
	pt->run();
	return NULL;
}

