/*************************************************************************
	> File Name: mutex.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 08:26:53 PM CST
 ************************************************************************/

#include"mutex.h"
#include<assert.h>



Mutex::~Mutex()
{
	assert(!isLock());// make sure unlock
	TINY_CHECK(!pthread_mutex_destroy(&m_mutex));
}



Mutex::Mutex() : m_isLock(false)
{
	TINY_CHECK(!pthread_mutex_init(&m_mutex, NULL));
}



void Mutex::lock()
{
	TINY_CHECK(!pthread_mutex_lock(&m_mutex));
	m_isLock = true;
}
void Mutex::unlock()
{
	m_isLock = false;
	TINY_CHECK(!pthread_mutex_unlock(&m_mutex));
}






Condition::~Condition()
{
	TINY_CHECK(!pthread_cond_destroy(&cond_pro));
}


Condition::Condition(Mutex &mutex): m_mutex(mutex)
{
	TINY_CHECK(!pthread_cond_init(&cond_pro, NULL));
}



void Condition::signal()
{
	TINY_CHECK(!pthread_cond_signal(&cond_pro));
}




void Condition::wait()
{
	assert(m_mutex.isLock());// wait  pro must lock
	TINY_CHECK(!pthread_cond_wait(&cond_pro, m_mutex.getMutexptr()));
	m_mutex.restoreMutexStatus(); //
}


void Condition::broadcast()
{
	TINY_CHECK(!pthread_cond_broadcast(&cond_pro));
}

