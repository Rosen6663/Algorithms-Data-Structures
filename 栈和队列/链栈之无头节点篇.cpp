#include<stdio.h>
#include<stdlib.h>
typedef struct Linknode{
	int data;
	struct Linknode *next;
}*LiStack;
//初始化栈
void initStack(LiStack &L)
{

	L=NULL;
}
//判断栈是否为空 
bool StackEmpty(LiStack L)
{
	if(L==NULL)
		return true;
	return false;
}
//入栈
bool Push(LiStack &L,int x)
{
	LiStack p=(LiStack)malloc(sizeof(Linknode));
	p->data=x;
	p->next=L;
	L=p;
	printf("数值：%d入栈成功\n",x);
	return true;
}
//出栈
bool Pop(LiStack &L,int &x)
{
	if(StackEmpty(L))
	{
		printf("栈为空\n");
	}
	x=L->data;
	L=L->next;
	printf("出栈成功,数值为：%d\n",x);
}
//查栈顶
bool GetTop(LiStack &L,int &x)
{
	if(StackEmpty(L))
	{
		printf("栈为空\n");
	}
	x=L->data;
	printf("栈顶数值为：%d\n",x);
}
void screen()
{
	printf("---------------------------------\n");
	printf("1.入栈\n");
	printf("2.出栈\n");
	printf("3.读栈\n");
	printf("4.栈是否为空\n");
	printf("---------------------------------\n");
	printf("请选择想要执行的命令\n");
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
				printf("\n请输入想要入栈的数字：\n");
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
					printf("栈为空"); 
				}else
				printf("栈不为空");
				break;
		}
		system("pause");
	
	}
}
