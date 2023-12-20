#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//一.不带头节点的单链表 
//1.初始化单链表,
//L是引用，不然修改不了 
bool InitList(LinkList &L)
{
	//空表,放在这个地方原来有遗留的脏数据 
	L = NULL; 
	return true ;
}

//2.初始化单链表,不带头节点的单链表 
bool Empty(LinkList L)
{
	if(L==NULL)
		return true;
	else 
		return false;
}

 //二.带头节点的单链表 
bool InitListHead(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->next=NULL;
	return true;	
}

//插入1
//把头节点当作0节点 
bool ListInsertHead(LinkList &L,int i,int e)
{
	if(i<1)
		return false;
	LNode *p;
	int j=0;
	p=L;
	//先判断0节点不为NULL才 继续 
	//最开始j=0，j等于几代表在第几个节点，直到在插入节点的前一个,还没到那么就为空 
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	//不可以颠倒，先连接后面，在连接前面 
	s->next=p->next;
	p->next=s;
}

//插入2
//不带头节点 
bool ListInsert(LinkList &L,int i,int e)
{
	if(i<1)
		return false;
	//修改1，没有头节点，则第一个插入会不同 
	if(i==1)
	{
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		return true;
	} 
	LNode *p;
	//修改2，是从1开始了 
	int j=1;
	p=L;
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
 
	s->next=p->next;
	p->next=s;
}

//后插操作，在节点p后插入数据e
bool InsertNextNode(LNode*p,int e)
{
	if(p==NULL)
		return false;
	//有可能内存分配失败 
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
 
//前插操作，在节点p前插入数据e 
//因为前插本来就看不到前面的，但是你发现如果把插入节点和p节点数值交换，就相当于插入了 
//O(1)
bool InsertPriorNode(LNode*p,int e)
{
	if(p==NULL)
		return false;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data=e;
	return true;
}
//查找1（都是带头节点） 
// 按位查找
LNode* GeetElem(LinkList L, int i){
	if(i<0)
		return NULL;
	LNode*p;
	int j=0;
	p=L;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	return p;

}


//查找2
//按值查找 
LNode* LocateElem(LinkList L,int e){
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;
	
	
}

//求一个表的长度
int Length(LinkList L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
	
	
	
	
} 






int main()
{
	//创建单链表
	LinkList L;
	InitListHead(L);
	int input,where;
	scanf("%d %d",&where,&input); 
	ListInsertHead(L,where,input);	
}
