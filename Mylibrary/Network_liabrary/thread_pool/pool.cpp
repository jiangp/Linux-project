/*************************************************************************
	> File Name: pool.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 26 Mar 2015 11:53:04 AM CST
 ************************************************************************/

#include"pool.h"


/*init pool_t*/
Pool_t::Pool_t(size_t queueSize, size_t threadsNum)
	:m_empty(m_mutex),
	m_full(m_mutex),
	m_queueSize(queueSize),
	m_threadsNum(threadsNum),
	m_isStarted(false)
{

}


/*Create m_threadNum pthread */
void Pool_t::start()
{
	m_isStarted = true;
	for(size_t ix = 0; ix != m_threadsNum; ++ix){
		m_threads.push_back(std::unique_ptr<Thread>(new Thread(std::bind(&Pool_t::runInThread, this))));
	}

	for(size_t ix = 0; ix != m_threadsNum; ++ix){
		m_threads[ix] ->start();
	}
}


/*add event if the size is more than m_queuesize 
 * the add change to wait 
 * lock the m_mutex befor push*/
void Pool_t::addTask(Task task)
{
	MutexLockGuard lock(m_mutex);
	while(m_queue.size() >= m_queueSize){
		m_empty.wait();
	}
	m_queue.push(task);
	m_full.signal();
}

/*handle event if the queue is empty wait
 *the getTask is wait 
 * lock the m_nutex befor pop 
 * of is empty senf a signal to m_empty*/
Task Pool_t::getTask()
{
	MutexLockGuard lock(m_mutex);
	while(m_queue.empty()){
		m_full.wait();
	}
	Task task = m_queue.front(); 
	m_queue.pop();          
	m_empty.signal();        
	return task;
}



/*execution the function getTask  */
void Pool_t::runInThread()
{
	while(1){
		Task task(getTask()); 
		task.execute();	
	}
}
