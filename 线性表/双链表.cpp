#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{
	int data;
	struct DNode *prior,*next;
}DNode,*DLinklist;
//��ʼ�� 
bool InitDlinkList(DLinklist &L){
	L=(DNode*)malloc(sizeof(DNode));
	if(L=NULL)
		return false;
	L->prior=NULL;
	L->next=NULL;
	return true;
	
}
//�ж��Ƿ�Ϊ��
 bool Empty(DLinklist L){
 	if(L->next)
 		return true;
	else
		return false;
 }
//˫����Ĳ���
//��p�ڵ�����s�ڵ�
bool InsertNextDNode(DNode *p,DNode*s){
	s->next=p->next;
	p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}
//��Ϊ��p->nextΪNULLʱ��ڶ��е�prior�Ǵ����
/*
//��p�ڵ�����s�ڵ�
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
