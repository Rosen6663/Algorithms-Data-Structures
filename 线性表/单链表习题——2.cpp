#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
int main()
{

	//创建表头 
	LinkList L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	//链表初始化 
	int a[10]={1,2,3,4,5,6,7,2,3,7};
	LNode* p,*s=L;
	p=L;
	for(int i=0;i<10;i++)
	{
		p=(LNode*)malloc(sizeof(LNode));
		p->data=a[i];
		s->next=p;
		s=p;
	}
	s->next=NULL;
	//遍历
	s=L->next;
	while(s!=NULL)
	{
		printf("%d\n",s->data);
		
		s=s->next;
	}
	//删除模式
	s=L; 
	while(s!=NULL&&s->next!=NULL)
	{
		printf("new\n",s->data);
		if(s->next->data==4)
		{
			printf("aaanew\n",s->data);
			s->next=s->next->next;	
		}
		s=s->next;
	}
	//遍历
	s=L->next;
	while(s!=NULL)
	{
		printf("%d\n",s->data);
		
		s=s->next;
	}
	
}
