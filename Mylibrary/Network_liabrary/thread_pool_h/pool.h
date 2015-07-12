/*************************************************************************
	> File Name: pool.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 26 Mar 2015 11:53:23 AM CST
 ************************************************************************/
#ifndef POOL_H
#define POOL_H

#include"noncopyable.h"
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<memory>
#include"mutex.h"
#include"task.h"
#include"thread.h"


class Pool_t: private Noncopyable
{
public:
	
	Pool_t(size_t queueSize, size_t threadsNum);
	void start();
	void addTask(Task task);// c++11
	Task getTask();
	void runInThread();
private:


	mutable Mutex m_mutex;
	Condition m_empty;
	Condition m_full;

	size_t m_queueSize;
	std::queue<Task> m_queue;
	const size_t m_threadsNum;
	std::vector<std::unique_ptr<Thread> > m_threads;  //create Thread
	bool m_isStarted;
};


#endif
