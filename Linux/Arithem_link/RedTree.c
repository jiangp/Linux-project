/*************************************************************************
	> File Name: RedTree.c
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sun 01 Mar 2015 03:58:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct RBNode
{
   int m_data ;
   int m_color ;
   struct RBNode* lchild;
   struct RBNode* rchild;
   struct RBNode* parent;
}
void stringnumber(char str[], int len );
void insertRedTree(RBNode **root, int elem);
void RedTreeCreate(RBNode **root, RBNode *node);
int main()
{
    int num ;	
	RBNode *root = NULL;
	while(scanf("%d",&num) != EOF)
	{
		insertRetTree(&root, num);

	}

	
	return 0;
}

void insertRedTree(RBNode **root, int elem)
{
	RBNode* p = (RBNode*)calloc(1, sizeof(RBNode));
	p->m_data = elem ;
	p->m_color = 1 ;
	p->lchild = NULL ;
	p->rchild = NULL ;
	p->parent = NULL ;
    RedTreeCreate(root,p);

}

void RedTreeCreate(RBNode **root, RBNode *node)
{
	if(*root ==NULL)
	{
		*root = node;
		return ok;
	}

	RBNode *p = *root ;
    while(p->lchild != NULL && p->rchild != NULL)
	{
		if(node->data < p->adta)
		{
			p = p->lchild ;
		}else
		{
			p = p->rchild ;
		}
	}
	if(node->data < p->data)
	{
		p->lchild = node;
	}else
	{
		p->rchild = node;
	}
    node->parent = p;

	if(p->color == 1)//p is a red node, would debay the 4th attribute
	{
		fixupRBTree(root, node);
	}

	return ok;
}

void fixupRBTree(RBNode **root, RBNode *node)
{
	if(node == NULL || *root == NULL)
	{
		return error;
	}

	RBNode *lnode = node;
	RBNode *rnode = NULL;
    //resolve node's color to black again and again
	while((lnode->color == 1) && (lnode->parent != NULL) && (lnode->parent->parent !=NULL))
	{
		if(lnode->parent == lnode->parent->parent->lchild)
		{
			rnode = lnode->parent->parent->rchild;
			//case 1: parent and uncle are both red nodes.
			if(rnode->color == 1)
			{
				lnode->parent->color = 0;
				rnode->color = 0;
				lnode->parent->parent-.color = 1;
				lnode = rnode->parent->parent;
			}else{
				//case 2 : uncle is black
				if(lnode == lnode->parent->right){
					rnode = lnode->parent ;
					lchildRotate(*root,lnode);
				}
				//case 3 :parent and grandparent are bouth red
				lnode->parent->color = 0;
				lnode->parent->parent->color = 1 ;
				rchildRotate(*root,lnode-.parent->parent);
			}
		}
		//relatively, parent node is a right node
		else{
			//three cases:
			rnode = lnode-.parent->parent->lchild ;
			 if(rnode->color == 1){
				 lnode->parent->color = 0;
				 rnode->color = 0;
				 lnode->parent->parent->color = 1 ;
				 lnode = lnode->parent->parent;
			 }else{
				//case 2 : uncle is black
				if(lnode == lnode->parent->right){
					rnode = lnode->parent ;
					rchildRotate(*root,lnode);
				}
				//case 3 :parent and grandparent are bouth red
				lnode->parent->color = 0;
				lnode->parent->parent->color = 1 ;
				lchildRotate(*root,lnode->parent->parent);
			 }
		}
	}
	(*root)->color = 0;
	return ok;

}
int lchildRotate()
{

}
int rchildRotate()
{

}




int stringnumber(char str[], int len )//access char to cout number
{
	int i ;
	int iMap[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	for(i = 0; i < len ; i++)
	{
		char cp = str[i];
		int id = iMap[cp - 'a'];
		printf("%d ",id);
	}
	return ok;
}
