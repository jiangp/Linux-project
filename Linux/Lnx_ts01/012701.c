/*************************************************************************
	> File Name: ./012701.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Tue 27 Jan 2015 09:09:18 AM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M    6
#define N    100
typedef struct men
{
	int m_val;
	struct men *m_next;
}MEN ,*pMEN;
int main()
{
	int val;
	int index=0,cnt=0;
	MEN head;
	pMEN pnew,ppre,p;
    head.m_val;
	head.m_next=&head;
	while(index<N)
	{
		pnew=(pMEN)calloc(1,sizeof(MEN));
        pnew->m_val=N-index;
		pnew->m_next=head.m_next;
		head.m_next=pnew;	
		index++;
	}
     index=100;
	ppre=head.m_next;
	while(index>0)
	{
		cnt=0;
		while(cnt<M-1)
		{
			cnt++;
			pnew=ppre;
            ppre=ppre->m_next;
	    	if(ppre==&head)
	    	{

				pnew=ppre;
				ppre=ppre->m_next;}
	 }

		pnew->m_next=ppre->m_next;
		printf("%d  ",ppre->m_val);
		free(ppre);
		ppre=pnew->m_next;
		index--;

	}



/*	ppre=head.m_next;
	index=0;
	while(index<N+10)
	{
		printf("%d ",ppre->m_val);
		ppre=ppre->m_next;
		if(ppre==&head)
			ppre=ppre->m_next;
		index++;
	}*/
	return 0;
}
