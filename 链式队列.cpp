#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinNode;
typedef struct Queue
{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;
//带头节点的初始化 
void IintQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}
//判断是否为空 
bool IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	return false;
}
//入队 
void EnQueue(LinkQueue &Q,int x)
{
	LinkNode*s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=x;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	printf("%d入队成功\n",x);
}
//出队
bool DeQueue(LinkQueue &Q,int &x)
{
	if(IsEmpty(Q))
	{
		printf("队列为空\n");
		return false;
	}
	x=Q.front->next->data;
	Q.front->next=Q.front->next->next;
	if(Q.front->next==NULL)
		Q.rear=Q.front;	
	printf("%d出队成功\n",x);	
	return true;
}
void screen()
{
	printf("---------------------------------\n");
	printf("1.入队\n");
	printf("2.出队\n");
	printf("3.队列是否为空\n");
	printf("---------------------------------\n");
	printf("请选择想要执行的命令\n");
} 
int main()
{
	int x;
	LinkQueue Q;
	IintQueue(Q);
	int order;
	while(true)
	{
		system ("cls");
		screen();
		scanf("%d",&order);
		switch(order)
		{
			case 1:
				printf("\n请输入想要入队的数字：\n");
				scanf("%d",&x);
				EnQueue(Q,x);
				break;
			case 2:
				DeQueue(Q,x);
				break;
			case 3:
				if(IsEmpty(Q))
				{
					printf("队列为空"); 
				}else
				printf("队列不为空");
				break;
		}
		system("pause");
	
	}
}
