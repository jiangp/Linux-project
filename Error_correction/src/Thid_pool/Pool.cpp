/*************************************************************************
	> File Name: Pool.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 26 Mar 2015 11:53:04 AM CST
 ************************************************************************/

#include"Pool.h"
//#include"MyConf.h"


Pool_t::Pool_t(size_t queueSize, size_t threadsNum)
	:m_empty(m_mutex),
	m_full(m_mutex),
	m_queueSize(queueSize),
	m_threadsNum(threadsNum),
	m_isStarted(false)
{

}

void Pool_t::start()
{
	m_isStarted = true;
	for(size_t ix = 0; ix != m_threadsNum; ++ix)
	{
		m_threads.push_back(std::unique_ptr<Thread>(new Thread(std::bind(&Pool_t::runInThread, this))));
	}
	for(size_t ix = 0; ix != m_threadsNum; ++ix)
	{
		m_threads[ix] ->start();
	}
}

void Pool_t::addTask(Task task)// add event
{
	MutexLockGuard lock(m_mutex);
	while(m_queue.size() >= m_queueSize)
		m_empty.wait();
	m_queue.push(task); //add
	m_full.signal();    //single -> wait
}

Task Pool_t::getTask() //handle event
{
	MutexLockGuard lock(m_mutex);
	while(m_queue.empty())
		m_full.wait();
	Task task = m_queue.front(); // handle
	m_queue.pop();              //delete
	m_empty.signal();        //single -> wait
	return task;
}

void Pool_t::runInThread()
{
	while(1)
	{
		Task task(getTask()); //取出 任务 
		task.execute();	 //执行
	
	}
}
