#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}Sqlist;

void bianli(Sqlist &L);
bool first(Sqlist &L,int &x);
bool third(Sqlist &L,int value);
bool easythird(Sqlist &L,int a);
int main()
{
	//��ʼ�� 
	Sqlist L;
	L.length=0;
	srand(1);
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<10;i++)
	{
		L.data[L.length++]=a[i];
	}
	bianli(L);
//	int x;
//	first(L,x);
//	bianli(L);

	printf("--------------------------\n");
	easythird(L,1);
	bianli(L);
}

void bianli(Sqlist &L){
	for(int i=0;i<L.length;i++)
	{
		printf("%d\n",L.data[i]);
	}
}
//ɾ����Сֵ������ɾ��ֵ�������һ��Ԫ�����ɾ��λ�� 
bool first(Sqlist &L,int &x)
{
	if(L.length==0)
		return false;
	x=L.data[0];
	int index=0;
	for(int i=1;i<L.length;i++)	
		if(L.data[i]<x)
		{
			x=L.data[i];
			index=i;
		}
	
	L.data[index]=L.data[--L.length];
	printf("��С����Ϊ%d,����Ϊ%d\n",x,index);
}
//ɾ��˳�����ֵΪx��Ԫ�� 
bool third(Sqlist &L,int value)
{
	if(L.length==0)
		return false;
	int p=0;
	while(p==0)
	{
		p=-1;
		for(int i=0;i<L.length;i++)
		{
			if(L.data[i]==value)
			{
				p=0;
				for(int j=i;i<L.length-1;i++)
				{
					L.data[i]=L.data[i+1];
				}
				L.length--;
			}
		}
	}
	return true;
}
bool easythird(Sqlist &L,int a)
{
	int k=0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]!=a)
		{
			L.data[k]=L.data[i];
			k++;
		}
			
	}
	L.length=k;
	
 } 
bool fourth(Sqlist &L,int s,int t)
{
	if(L.length==0)
		return false;
	if(s>=t)
		return false;
	int prior,last;	
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]<=t)
		{
			last=i;
			if(L.data[i]<s)
			{
				prior=i;
			}
		}
	}
	prior++;
	for(int i=last;i<=0;i++)
	{
	
	}
} 
 
