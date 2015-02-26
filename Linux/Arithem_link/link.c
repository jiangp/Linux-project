/*************************************************************************
	> File Name: link.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 31 Jan 2015 03:50:39 PM CST
 ************************************************************************/
//merger order link
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define LEN1  8
#define LEN2  5
#define NOD   3
typedef struct node
{
	int m_val;
	struct node *m_next;
}NODE,*PNODE;

void link_init_head(PNODE *phead,int len);
void link_init_tail(PNODE *phead,int len);
void link_delete_node(PNODE phead,int nod);
void link_show(PNODE phead);
int main()
{
	int val;
	PNODE phead1,phead2;
	phead1=NULL;
    phead2=NULL;
	link_init_head(&phead1,LEN1);
//	link_init_tail(&phead2,LEN2);
    link_show(phead1);
  //  link_show(phead2);
    link_delete_node(phead1,NOD);
    link_show(phead1);
	return 0;
}
//set link
void link_init_head(PNODE *phead,int len)
{
	int index=0;
	int val;
	PNODE pnew;
	while(index<len)
	{
        scanf("%d",&val);
        pnew=(PNODE)calloc(1,sizeof(NODE));
    	pnew->m_val=val;
		pnew->m_next=*phead;
		*phead=pnew;
		index++;
	}
	printf("1  is over!\n");
}

void link_init_tail(PNODE *phead,int len)
{
	int index=0;
	int val;
	PNODE pnew,ptail;
	while(index<len)
	{
		scanf("%d",&val);
		pnew=(PNODE)calloc(1,sizeof(NODE));
		pnew->m_val=val;
		if((*phead)==NULL)
		{
			(*phead)=pnew;
			ptail=pnew;
		}else
		{
            ptail->m_next=pnew;
			ptail=pnew;
		}
		index++;
	}
	printf("tow is over!\n");
}

//link show
void link_show(PNODE phead)
{
	PNODE pcur;
	pcur=phead;
	while(pcur!=NULL)
	{
		printf("%d ",pcur->m_val);
		pcur=pcur->m_next;
	}
	printf("\n");
}

//delete the node
void link_delete_node(PNODE phead,int nod)
{
	int index=0;
	PNODE pcur,ppre,ptem;
    pcur=phead;
	ppre=phead;
	while(pcur!=NULL)
	{
		while(index<nod)
		{
			pcur=pcur->m_next;
            index++;
		}
		pcur=pcur->m_next;
		ptem=ppre;
		ppre=ppre->m_next;
	}
    ptem->m_next=ppre->m_next;
	free(ppre);
	printf("allready  delete  the last but nod!");
}


//two link order
void link_order(PNODE *pphead1,PNODE *pphead2)
{
   PNODE pcur,ppre,ptem;











}
