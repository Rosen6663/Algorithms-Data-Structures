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
//��ͷ�ڵ�ĳ�ʼ�� 
void IintQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}
//�ж��Ƿ�Ϊ�� 
bool IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	return false;
}
//��� 
void EnQueue(LinkQueue &Q,int x)
{
	LinkNode*s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=x;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	printf("%d��ӳɹ�\n",x);
}
//����
bool DeQueue(LinkQueue &Q,int &x)
{
	if(IsEmpty(Q))
	{
		printf("����Ϊ��\n");
		return false;
	}
	x=Q.front->next->data;
	Q.front->next=Q.front->next->next;
	if(Q.front->next==NULL)
		Q.rear=Q.front;	
	printf("%d���ӳɹ�\n",x);	
	return true;
}
void screen()
{
	printf("---------------------------------\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.�����Ƿ�Ϊ��\n");
	printf("---------------------------------\n");
	printf("��ѡ����Ҫִ�е�����\n");
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
				printf("\n��������Ҫ��ӵ����֣�\n");
				scanf("%d",&x);
				EnQueue(Q,x);
				break;
			case 2:
				DeQueue(Q,x);
				break;
			case 3:
				if(IsEmpty(Q))
				{
					printf("����Ϊ��"); 
				}else
				printf("���в�Ϊ��");
				break;
		}
		system("pause");
	
	}
}
