#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
	
}BiTNode,*BiTree;
int main()
{
	//����һ������ 
	BiTree root = NULL;
	
	//������ڵ�
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data=1;
	root->lchild=NULL;
	root->rchild=NULL;
	
	BiTNode * p=(BiTNode*)malloc(sizeof(BiTNode));
	p->data=2;
	p->lchild=NULL;
	p->rchild = NULL;
	root->lchild=p;
	
}
