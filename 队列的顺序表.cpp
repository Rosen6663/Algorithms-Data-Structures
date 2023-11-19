#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
typedef struct{
	int data[MaxSize];
	int front,rear;
}SqQueue;
//��ʼ�� 
void InitQueue(SqQueue &Q)
{
	Q.rear=Q.front=0;
}
//�Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear)
		return true;
	else
		return false;	
}
//���
bool EnQueue(SqQueue &Q,int x)
{
	//������һ���ռ��ʱ�򣬾Ϳ������ˣ���Ϊ��֤������ȵ�ʱ����ж�Ϊ�� 
	if((Q.rear+1)%MaxSize==Q.front)
	{
		printf("�������ˣ��޷����\n");
		return false;
	}
	Q.data[Q.rear]=x;
	//ȡ�࣬���ܻ��ȥ���γ��˻�״ 
	Q.rear=(Q.rear+1)%MaxSize;
	printf("%d��ɹ�\n",x);
	return true;
} 
//����
bool DeQueue(SqQueue &Q,int &x)
{
		if(QueueEmpty(Q))
		{
			printf("����Ϊ�գ��޷�����\n");	
			return false;
		}
		x=Q.data[Q.front];
		Q.front=(Q.front+1);
		printf("���ӳɹ�\n");	
		return true;
}
//��ȡͷ���е����� 
bool GetHead(SqQueue &Q,int &x)
{
		if(QueueEmpty(Q))
		{
			printf("����Ϊ�գ��޷���ȡ\n");	
			return false;
		}
		x=Q.data[Q.front];
		printf("��ȡ�ɹ�����ֵΪ%d\n",x);	
		return true;
}
//�鿴���� 
bool amount(SqQueue &Q,int &x)
{
	x=(Q.rear+MaxSize-Q.front)%MaxSize;
	printf("��������%d��Ԫ��\n",x);
}  
//������ 
void screen()
{
	printf("---------------------------------\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.����\n");
	printf("4.�����Ƿ�Ϊ��\n");
	printf("5.����Ԫ������\n");
	printf("---------------------------------\n");
	printf("��ѡ����Ҫִ�е�����\n");
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
				printf("\n��������Ҫ��ӵ����֣�\n");
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
					printf("��Ϊ��"); 
				}else
				printf("�Ӳ�Ϊ��");
				break;
			case 5:
				amount	(Q,x);
				break;
		}
		system("pause");
	
	}
}
