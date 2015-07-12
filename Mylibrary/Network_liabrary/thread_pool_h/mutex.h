/*************************************************************************
	> File Name: mutex.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 24 Mar 2015 05:37:13 PM CST
 ************************************************************************/
#ifndef _MUTEX_H
#define _MUTEX_H
#include<iostream>
#include<pthread.h>
#include"noncopyable.h"

//use to testing pthread function return value
#define TINY_CHECK(exp) \
	if(!(exp)) \
	{ \
		fprintf(stderr, "File:%s, Line:%d Exp:[" #exp "] is true, abort.\n", __FILE__, __LINE__); abort(); \
	}



class Mutex : private Noncopyable
{
	pthread_mutex_t m_mutex;
	bool m_isLock;
public:
	Mutex();
	~Mutex();
	void lock();
	void unlock();
	pthread_mutex_t *getMutexptr(){return &m_mutex; }
	bool isLock() const {return m_isLock; }
private:
	friend class Condition;
	void restoreMutexStatus() {m_isLock = true; }
};

class MutexLockGuard : Noncopyable
{
public:
	MutexLockGuard(Mutex &mutex) :m_mutex(mutex)
	{ m_mutex.lock(); }
	~MutexLockGuard(){ m_mutex.unlock(); }
private:
	Mutex &m_mutex;
};

class Condition : private Noncopyable
{
	pthread_cond_t cond_pro;
	Mutex &m_mutex;
public:
	Condition(Mutex &m_mutex);
	 ~Condition();
	void signal();
	void wait();

	void broadcast();
};

#define MutexLockGuard(m) "Error MutexLockGuard"

#endif
