#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef struct{
	int data[MaxSize];
	int top;
}SqStack;
//初始化栈——声明一个顺序栈（分配空间） 
void InitStack(SqStack &S)
{
	S.top=-1;
}
//判断栈是否为空或 
bool StackEmpty(SqStack S)
{
	if(S.top==-1)
	{
		return true;
	}
	printf("栈不为为空\n");	
	return false;	
} 
//入栈
bool Push(SqStack &S,int x)
{
	if(S.top==MaxSize-1)
	{
		printf("栈已满，入栈失败\n");
		return false;
	}
	S.top++;
	S.data[S.top]=x;
	printf("入栈成功，数值为%d\n",x);
	return true;
	
	
	
}
//出栈 
bool Pop(SqStack &S,int &x)
{
	if(StackEmpty(S))
	{
		printf("出栈失败\n");
		return false;
	}
	x=S.data[S.top];
	printf("出栈成功，%d已被出栈\n",x);
	S.top--;
	return true;
}
//读取栈顶元素 
bool GetTop(SqStack S,int &x)
{
		if(StackEmpty(S))
	{
		printf("读取栈顶失败\n");
		return false;
	}
	x=S.data[S.top];
	printf("读取成功，栈顶为%d\n",x);
	return true;
}
//主界面 
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
				printf("\n请输入想要入栈的数字：\n");
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
					printf("栈为空"); 
				}else
				printf("栈不为空");
				break;
		}
		system("pause");
	
	}
} 
