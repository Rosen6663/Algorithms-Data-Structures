#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef struct
{
	//动态分配指针 ,指向顺序表第一个元素 
	int *data;
	//顺序表的最大容量 
	int MaxSize;
	//当前长度 
	int length;
}SeList;
//初始化 
void InitList(SeList &L)
{
L.data=(int *)malloc(sizeof(int)*InitSize);
L.length=0;
L.MaxSize=InitSize;
}
//增加动态数组的长度 
void IncreaseSize(SeList &L,int len)
{
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i];
	}
	L.MaxSize=L.MaxSize+len;
	free(p);
}

int main()
{
//声明顺序表 
SeList L;
//malloc返回指针因此需要强转 
InitList(L);
IncreaseSize(L,5);
return 0;
}

