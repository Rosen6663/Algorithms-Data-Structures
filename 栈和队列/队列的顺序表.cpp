#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct{
	int data[MaxSize];
	int front,rear;
}SqQueue;
//初始化 
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
//是否为空
bool QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	else
		return false;	
}
//入队
bool EnQueue(SqQueue &Q,int x)
{
	//当还有一个空间的时候，就看作满了，因为保证两者相等的时候就判断为空 
	if((Q.rear+1)%MaxSize==Q.front)
	{
		printf("队列满了，无法入队\n");
		return false;
	}
	Q.data[Q.rear]=x;
	//取余，可能会回去，形成了环状 
	Q.rear=(Q.rear+1)%MaxSize;
	printf("%d入成功\n",x);
	return true;
} 
//出队
bool DeQueue(SqQueue &Q,int &x)
{
		if(QueueEmpty(Q))
		{
			printf("队列为空，无法出队\n");	
			return false;
		}
		x=Q.data[Q.front];
		Q.front=(Q.front+1);
		printf("出队成功\n");	
		return true;
}
//获取头队列的数据 
bool GetHead(SqQueue &Q,int &x)
{
		if(QueueEmpty(Q))
		{
			printf("队列为空，无法获取\n");	
			return false;
		}
		x=Q.data[Q.front];
		printf("获取成功，数值为%d\n",x);	
		return true;
}
//查看数量 
bool amount(SqQueue &Q,int &x)
{
	x=(Q.rear+MaxSize-Q.front)%MaxSize;
	printf("队列中有%d个元素\n",x);
}  
//主界面 
void screen()
{
	printf("---------------------------------\n");
	printf("1.入队\n");
	printf("2.出队\n");
	printf("3.读队\n");
	printf("4.队列是否为空\n");
	printf("5.队列元素数量\n");
	printf("---------------------------------\n");
	printf("请选择想要执行的命令\n");
}
int main()
{
	int x;
	SqQueue Q;
	InitQueue(Q);
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
				GetHead(Q,x);
				break;
			case 4:
				if(QueueEmpty(Q))
				{
					printf("队为空"); 
				}else
				printf("队不为空");
				break;
			case 5:
				amount	(Q,x);
				break;
		}
		system("pause");
	
	}
}
