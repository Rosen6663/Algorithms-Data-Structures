#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef struct
{
	//��̬����ָ�� ,ָ��˳����һ��Ԫ�� 
	int *data;
	//˳����������� 
	int MaxSize;
	//��ǰ���� 
	int length;
}SeList;
//��ʼ�� 
void InitList(SeList &L)
{
L.data=(int *)malloc(sizeof(int)*InitSize);
L.length=0;
L.MaxSize=InitSize;
}
//���Ӷ�̬����ĳ��� 
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
//����˳��� 
SeList L;
//malloc����ָ�������Ҫǿת 
InitList(L);
IncreaseSize(L,5);
return 0;
}

