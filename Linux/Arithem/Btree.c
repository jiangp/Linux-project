/*************************************************************************
	> File Name: tree.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 01 Mar 2015 10:02:47 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int m_data;
	struct node* lchild;
	struct node* rchild;
} BNode;

int InsertBTree(BNode **root, int elem);//Set Tree Node
void InsertBTreeP(BNode** root, BNode *p);//set tree
void HXBL(BNode *root);// In Order Traversal

int main()
{

	int num ,i=0;
	BNode *root =NULL;
    while( i<6 )
    {
	   scanf("%d",&num);
       InsertBTree(&root, num);
	   i++;
    }
	printf("hello\n");
    HXBL(root);
	return 0;


}

int InsertBTree(BNode **root, int elem)//Set Tree Node
{
	BNode *p = (BNode*)calloc(1, sizeof(BNode));
	p->m_data = elem ;
	p->lchild = NULL;
	p->rchild = NULL;
	InsertBTreeP(root, p);
	return 0;

}

void  InsertBTreeP(BNode **root, BNode *p)//set tree
{
	if(*root == NULL)
	{
		*root = p;
	}
    else if(p->m_data < (*root)->m_data)
	{
		InsertBTreeP(&((*root)->lchild) , p);
	}else
	{
		InsertBTreeP(&((*root)->rchild) , p);
	}
}

void HXBL(BNode* root)// In Order Traversal
{
	if(root ==NULL)
	{
		printf("the tree is null!\n");
	}
//	if(root -> lchild != NULL)
//	{
//		printf("%s ",root -> m_data);
		HXBL(root->lchild );
//	}
//	 if(root -> rchild != NULL)
//	{
		HXBL(root->rchild);
		printf("%s ",root -> m_data);
//	}
}
