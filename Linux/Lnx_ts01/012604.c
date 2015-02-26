/*************************************************************************
	> File Name: 012604.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Mon 26 Jan 2015 09:58:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M    5
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
	pMEN head=NULL;
	pMEN pnew,ppre,p;

	while(index<N)
	{
		pnew=(pMEN)calloc(1,sizeof(MEN));
        pnew->m_val=N-index;
		pnew->m_next=head;
		head=pnew;
        if(index==0)
		{
			p=pnew;
		}		
		index++;
	}
     p->m_next=head;
   index=100;
	ppre=head;
	while(index>0)
	{
		cnt=0;
		while(cnt<M-1)
		{
			cnt++;
			pnew=ppre;
            ppre=ppre->m_next;
		}
		pnew->m_next=ppre->m_next;
		head=ppre->m_next;
		printf("%d  ",ppre->m_val);
		free(ppre);
		ppre=pnew->m_next;
		index--;

	}



/*	ppre=head;
	index=0;
	while(index<N+10)
	{
		printf("%d ",ppre->m_val);
		ppre=ppre->m_next;
		index++;
	}*/
	return 0;
}
