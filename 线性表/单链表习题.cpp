#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}LNode,*LinkList;

bool bianli(LinkList L);
bool paixu(LinkList &L);
bool diguidetele(LinkList &p,LinkList &L,int x);
int main()
{
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	
	int a[10]={1,2,3,1,1,4,6,23,44,66};
	L->data=a[0];
	LNode *p=L;
	for(int i=1;i<10;i++)
	{
		 p->next=(LNode*)malloc(sizeof(LNode));
		 p=p->next;
		 p->data=a[i];
	}
	
	diguidetele(p,L,1);
	bianli(L);
}
bool bianli(LinkList L)
{
	if(L->next==NULL)
	{
		return false;
	}
	for(int i=0;i<10;i++)
	{
		L=L->next;
		printf("��%d���ڵ㣬dataΪ%d\n",i+1,L->data);
		
	}
	return true;
}

bool paixu(LinkList &L)
{
	LNode *p=L;
for(int j=0;j<10;j++){

	p=L;
	for(int i=0;i<10-1;i++)
	{
		p=p->next;
		if((p->data)>(p->next->data))
		{
			int temp=p->data;
			p->data=p->next->data;
			p->next->data=temp;
		}
		
	}
}
	return true;
	
}
bool diguidetele(LinkList p,LinkList &L,int x)
{
	//������ 
	if(p==NULL)
		return false;
	//���� 
	if(p->data==x)
	{
		if(p==L)
		{
			L=L->next;
			p=L;
			return diguidetele(p,L,x);
		}
		else{
			p->data=p->next->data;
			p->next=p->next->next;	
		
		}
		
	}
	//�������� 
	if(p->next==NULL)
		return true;
	//ѭ���������� 
	p=p->next;
	return diguidetele(p,L,x);
}
