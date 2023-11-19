#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}LNode,*LinkList;
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10]={1,1,1,3,4,5,6,4,2,4};
	
	LinkList L=(Node*)malloc(sizeof(LNode));
	L->data=a[0];
	LNode *p=L;
	for(int i=1;i<=9;i++)
	{
		 p->next=(LNode*)malloc(sizeof(LNode));
		 p=p->next;
		 p->data=a[i];
	}
	p->next=NULL;
	p=L;
	int j=0;
	printf("这是第%d个节点，这个节点的数值为%d\n",j,p->data);	j++;
	while(p->next!=NULL)
	{
		p=p->next;
		j++;
		printf("这是第%d个节点，这个节点的数值为%d\n",j,p->data);
			
	}
}
bool digui(LinkList &L,int x)
{
	//空链表——直接结束 
	if(L==NULL)
		return false;
	//第一个节点为x，当第二个没有的时候，直接变成空链表，反之让第二个节点变成第一个节点，再次递归 
	if(L->data==x)
	{
		if(L->next==NULL)
		{
			L=NULL;
			return =true;	
		}
		L=L->next;
		digui(L,x);
	}
	//中间变量，1的话代表遍历未找到 
	int p=1;
	//找到第一个为x的 
	LNode*p=(LNode*)malloc(sizeof(LNode));
	p=L->next;
	
	while(p->data!=x&&p->next!=NULL)
	{
		p=p->next;	
	}
	if(p->data==x)
	{
		if(p->)		
	}	 
}
