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
	printf("���ǵ�%d���ڵ㣬����ڵ����ֵΪ%d\n",j,p->data);	j++;
	while(p->next!=NULL)
	{
		p=p->next;
		j++;
		printf("���ǵ�%d���ڵ㣬����ڵ����ֵΪ%d\n",j,p->data);
			
	}
}
bool digui(LinkList &L,int x)
{
	//��������ֱ�ӽ��� 
	if(L==NULL)
		return false;
	//��һ���ڵ�Ϊx�����ڶ���û�е�ʱ��ֱ�ӱ�ɿ�������֮�õڶ����ڵ��ɵ�һ���ڵ㣬�ٴεݹ� 
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
	//�м������1�Ļ��������δ�ҵ� 
	int p=1;
	//�ҵ���һ��Ϊx�� 
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
