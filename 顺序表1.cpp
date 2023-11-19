#include<stdio.h>
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L)
{
L.length=0;

}

bool ListInsert(SqList &L,int i,int e)
{
	if(i<=0||i>L.length+1)
		return false;
	if(L.length>=MaxSize)
		return false;
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
}


int main()
{
    SqList L;
    InitList(L);
    ListInsert(L,1,666);
    for(int i=0;i<MaxSize;i++){
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    return 0;
}
