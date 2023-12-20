#include<stdio.h>
#include<stdlib.h>
//������ 
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
	int ltag,rtag;
}BiTNode,*BiTree;
BiTNode *pre=NULL;

void visit(BiTNode *q)
{
	//������ǰ��
	if(q->lchild==NULL)
	{
		q->lchild=pre;
		q->ltag=1;
	}
	//���ú��
	if(pre!=NULL&&pre->rchild==NULL)
	{
		pre->rchild=q;
		pre->rtag=1;
	}
	pre=q;
}
void InThread(BiTree T)
{
	if(T!=NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}
void preorder(BiTree T)
{
    if(T!=NULL){

    
        //printf("%d\n",T->data);
        preorder(T->lchild);
        printf("%c ",T->data);
        preorder(T->rchild);
        //printf("%d\n",T->data);
    }
}

//�������ڵ� 
void InitBiTree(BiTree &root)
{
	
	root->data='A';
	root->ltag=root->rtag=0;
	root->lchild=NULL;
	root->rchild=NULL;
}




int main()
{
	//���������� 
	BiTree root=(BiTree)malloc(sizeof(BiTNode));

	InitBiTree(root);

	BiTNode*b1=(BiTNode*)malloc(sizeof(BiTNode));
	b1->data='B';
	b1->rchild=NULL;
	b1->lchild=NULL;
	b1->ltag=root->rtag=0;
	root->lchild=b1;

	
	BiTNode*b2=(BiTNode*)malloc(sizeof(BiTNode));
	b2->data='C';
	b2->rchild=NULL;
	b2->lchild=NULL;
	b2->ltag=root->rtag=0;
	root->rchild=b2;

	BiTNode*b3=(BiTNode*)malloc(sizeof(BiTNode));
	b3->data='D';
	b3->rchild=NULL;
	b3->lchild=NULL;
	b3->ltag=root->rtag=0;
	root->lchild->rchild=b3;
	
	BiTNode*b4=(BiTNode*)malloc(sizeof(BiTNode));
	b4->data='E';
	b4->rchild=NULL;
	b4->lchild=NULL;
	b4->ltag=root->rtag=0;
	root->rchild->lchild=b4;
	
	printf("%c\n",root->data);
	printf("%c\n",root->lchild->data);
	printf("%c\n",root->rchild->data);
	printf("%c\n",root->lchild->rchild->data);
	printf("%c\n",root->rchild->lchild->data);
	
	//�������������� 
	preorder(root);

	InThread(root);
	preorder(root);
} 
