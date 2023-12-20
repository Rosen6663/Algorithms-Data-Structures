#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//һ.����ͷ�ڵ�ĵ����� 
//1.��ʼ��������,
//L�����ã���Ȼ�޸Ĳ��� 
bool InitList(LinkList &L)
{
	//�ձ�,��������ط�ԭ���������������� 
	L = NULL; 
	return true ;
}

//2.��ʼ��������,����ͷ�ڵ�ĵ����� 
bool Empty(LinkList L)
{
	if(L==NULL)
		return true;
	else 
		return false;
}

 //��.��ͷ�ڵ�ĵ����� 
bool InitListHead(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->next=NULL;
	return true;	
}

//����1
//��ͷ�ڵ㵱��0�ڵ� 
bool ListInsertHead(LinkList &L,int i,int e)
{
	if(i<1)
		return false;
	LNode *p;
	int j=0;
	p=L;
	//���ж�0�ڵ㲻ΪNULL�� ���� 
	//�ʼj=0��j���ڼ������ڵڼ����ڵ㣬ֱ���ڲ���ڵ��ǰһ��,��û����ô��Ϊ�� 
	while(p!=NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	//�����Եߵ��������Ӻ��棬������ǰ�� 
	s->next=p->next;
	p->next=s;
}

//����2
//����ͷ�ڵ� 
bool ListInsert(LinkList &L,int i,int e)
{
	if(i<1)
		return false;
	//�޸�1��û��ͷ�ڵ㣬���һ������᲻ͬ 
	if(i==1)
	{
		LNode *s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		s->next=L;
		L=s;
		return true;
	} 
	LNode *p;
	//�޸�2���Ǵ�1��ʼ�� 
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

//���������ڽڵ�p���������e
bool InsertNextNode(LNode*p,int e)
{
	if(p==NULL)
		return false;
	//�п����ڴ����ʧ�� 
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL)
		return false;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
 
//ǰ��������ڽڵ�pǰ��������e 
//��Ϊǰ�屾���Ϳ�����ǰ��ģ������㷢������Ѳ���ڵ��p�ڵ���ֵ���������൱�ڲ����� 
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
//����1�����Ǵ�ͷ�ڵ㣩 
// ��λ����
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


//����2
//��ֵ���� 
LNode* LocateElem(LinkList L,int e){
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e)
		p=p->next;
	return p;
	
	
}

//��һ����ĳ���
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
	//����������
	LinkList L;
	InitListHead(L);
	int input,where;
	scanf("%d %d",&where,&input); 
	ListInsertHead(L,where,input);	
}
