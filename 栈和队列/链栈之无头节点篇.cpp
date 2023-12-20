#include<stdio.h>
#include<stdlib.h>
typedef struct Linknode{
	int data;
	struct Linknode *next;
}*LiStack;
//��ʼ��ջ
void initStack(LiStack &L)
{

	L=NULL;
}
//�ж�ջ�Ƿ�Ϊ�� 
bool StackEmpty(LiStack L)
{
	if(L==NULL)
		return true;
	return false;
}
//��ջ
bool Push(LiStack &L,int x)
{
	LiStack p=(LiStack)malloc(sizeof(Linknode));
	p->data=x;
	p->next=L;
	L=p;
	printf("��ֵ��%d��ջ�ɹ�\n",x);
	return true;
}
//��ջ
bool Pop(LiStack &L,int &x)
{
	if(StackEmpty(L))
	{
		printf("ջΪ��\n");
	}
	x=L->data;
	L=L->next;
	printf("��ջ�ɹ�,��ֵΪ��%d\n",x);
}
//��ջ��
bool GetTop(LiStack &L,int &x)
{
	if(StackEmpty(L))
	{
		printf("ջΪ��\n");
	}
	x=L->data;
	printf("ջ����ֵΪ��%d\n",x);
}
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
	LiStack L; 
	initStack(L);
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
				Push(L,x);
				break;
			case 2:
				Pop(L,x);
				break;
			case 3:
				GetTop(L,x);
				break;
			case 4:
				if(StackEmpty(L))
				{
					printf("ջΪ��"); 
				}else
				printf("ջ��Ϊ��");
				break;
		}
		system("pause");
	
	}
}
