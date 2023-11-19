#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef struct{
	int data[MaxSize];
	int top;
}SqStack;
//��ʼ��ջ��������һ��˳��ջ������ռ䣩 
void InitStack(SqStack &S)
{
	S.top=-1;
}
//�ж�ջ�Ƿ�Ϊ�ջ� 
bool StackEmpty(SqStack S)
{
	if(S.top==-1)
	{
		return true;
	}
	printf("ջ��ΪΪ��\n");	
	return false;	
} 
//��ջ
bool Push(SqStack &S,int x)
{
	if(S.top==MaxSize-1)
	{
		printf("ջ��������ջʧ��\n");
		return false;
	}
	S.top++;
	S.data[S.top]=x;
	printf("��ջ�ɹ�����ֵΪ%d\n",x);
	return true;
	
	
	
}
//��ջ 
bool Pop(SqStack &S,int &x)
{
	if(StackEmpty(S))
	{
		printf("��ջʧ��\n");
		return false;
	}
	x=S.data[S.top];
	printf("��ջ�ɹ���%d�ѱ���ջ\n",x);
	S.top--;
	return true;
}
//��ȡջ��Ԫ�� 
bool GetTop(SqStack S,int &x)
{
		if(StackEmpty(S))
	{
		printf("��ȡջ��ʧ��\n");
		return false;
	}
	x=S.data[S.top];
	printf("��ȡ�ɹ���ջ��Ϊ%d\n",x);
	return true;
}
//������ 
void screen()
{
	printf("---------------------------------\n");
	printf("1.��ջ\n");
	printf("2.��ջ\n");
	printf("3.��ջ\n");
	printf("4.ջ�Ƿ�Ϊ��\n");
	printf("---------------------------------\n");
	printf("��ѡ����Ҫִ�е�����\n");
}
int main()
{
	int x;
	SqStack S;
	InitStack(S);
	int order;
	while(true)
	{
		system ("cls");
		screen();
		scanf("%d",&order);
		switch(order)
		{
			case 1:
				printf("\n��������Ҫ��ջ�����֣�\n");
				scanf("%d",&x);
				Push(S,x);
				break;
			case 2:
				Pop(S,x);
				break;
			case 3:
				GetTop(S,x);
				break;
			case 4:
				if(StackEmpty(S))
				{
					printf("ջΪ��"); 
				}else
				printf("ջ��Ϊ��");
				break;
		}
		system("pause");
	
	}
} 
