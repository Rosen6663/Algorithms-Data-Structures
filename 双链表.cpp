#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{
	int data;
	struct DNode *prior,*next;
}DNode,*DLinklist;
//初始化 
bool InitDlinkList(DLinklist &L){
	L=(DNode*)malloc(sizeof(DNode));
	if(L=NULL)
		return false;
	L->prior=NULL;
	L->next=NULL;
	return true;
	
}
//判断是否为空
 bool Empty(DLinklist L){
 	if(L->next)
 		return true;
	else
		return false;
 }
//双链表的插入
//在p节点后插入s节点
bool InsertNextDNode(DNode *p,DNode*s){
	s->next=p->next;
	p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}
//因为当p->next为NULL时候第二行的prior是错误的
/*
//在p节点后插入s节点
bool InsertNextDNode(DNode *p,DNode*s){
	if(p==NULL||s==NULL)
		return false;
	s->next=p->next;
	if(p->next!=NULL)
		p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}

*/ 

 
int main(){
	DLinklist L;
	InitDlinkList(L);
	return 0;	
	
}
