#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<windows.h>
typedef struct sdata{
	char sno[20];
	char sname[20];
	char sex[3];
	int age;
	char tel[12];
	char pro[20];
	int myclass;
	
}sdata;
typedef struct Student{
	struct Student *next;
	struct sdata data;
}Student,*Students;

void screen()
{
	printf("--------------------------\n");
	printf("1.����ѧ����Ϣ\n");
	printf("2.ɾ��ѧ����Ϣ\n");
	printf("3.�޸�ѧ����Ϣ\n");
	printf("4.��ѯѧ����Ϣ\n");
	printf("5.���ѧ����Ϣ\n");
	printf("6.�˳�\n");
	printf("--------------------------\n");
}
//ѧ����Ϣ�Ĵ���
struct sdata createStu()
{
	sdata p; 
	printf("������Ҫ��ӵ�ѧ����Ϣ\n");
	printf("ѧ��:");
	scanf("%s",p.sno);
	printf("����:");
	scanf("%s",p.sname);
	while(true)
	{
		printf("�Ա�:");
		scanf("%s",p.sex);
		if(strcmp(p.sex,"��")==0||strcmp(p.sex,"Ů")==0)
			break;
		printf("����Ƿ����������л�Ů\n");
	}
	
	printf("����:");
	scanf("%d",&(p.age));
	printf("�绰:");
	scanf("%s",p.tel);
	printf("רҵ:");
	scanf("%s",p.pro);
	printf("�༶:");
	scanf("%d",&p.myclass);
	
	
	return p;
	
} 
//����ѧ����Ϣ 
void addStu(Students &head)
{		
	sdata data1=createStu();	
 	Student* p=(Student*)malloc(sizeof(Student));
 	
 	
 	p->data=data1;
 	
 	p->next=head->next;
 	head->next=p;
 	printf("ѧ����Ϣ��ӳɹ�\n");
	
}
//���ѧ����Ϣ
bool printStu(Students head)
{
	
	if(head->next==NULL)
	{
		printf("û��ѧ����Ϣ���������\n");
		return false;
	}
	Student* p=head;
	int count=1;
	while(p->next!=NULL)
	{
		printf("%d.%s\n",count,p->next->data.sno);
		printf("������%s,�Ա�%s,����:%d,�绰���룺%s,רҵ��%s���༶��%d\n",p->next->data.sname,p->next->data.sex,p->next->data.age,p->next->data.tel,p->next->data.pro,p->next->data.myclass);
		p=p->next;
		count++; 
	}
	
 }
 //ɾ��ѧ����Ϣ
void deleteStu(Students &head)
{	
	char str[20];
	printf("����������ɾ����ѧ��ѧ��:");
	scanf("%s",str);
	Student* p=head;
	int temp=0;
	while(p->next!=NULL)
	{
		if(strcmp(str,p->next->data.sno)==0)
		{
			p->next=p->next->next;
			temp=1;
			break;
		}
		p=p->next;
	}
	if(temp==1)
	{
		printf("ɾ���ɹ�\n");
	}else{
		printf("δ�ҵ���ѧ��\n");	
	}
	
}
//�޸�ѧ����Ϣ 
void changeStu(Students &head)
{
		char str[20];
		char change[20];
	printf("�����������޸�ѧ����ѧ��:\n");
	scanf("%s",str);
	Student* p=head;
	int temp=0;
	while(p->next!=NULL)
	{
		if(strcmp(str,p->next->data.sno)==0)
		{
			temp=1;
			int how;
			printf("1.����\n");
			printf("2.�Ա�\n");
			printf("3.����\n");
			printf("4.�绰����\n");
			printf("5.רҵ\n");
			printf("6.�༶\n");
			printf("�����������޸ĵ�ѧ����������Ϣ:");
			scanf("%d",&how);
		
			if(how==2){
					
				if(strcmp(p->next->data.sex,"��")==0){
					
					 char sex[] = "Ů";  
					strcpy(p->next->data.sex, sex);
				}else{
						 char sex[] = "��";  
					strcpy(p->next->data.sex, sex);
				}
				break;
			}else{
				printf("�޸ĳ�ʲô:");
				int mytemp;
			switch(how)
			{
				case 1: scanf("%s",change);strcpy(p->next->data.sname, change);break;
				case 3:	scanf("%d",&mytemp);p->next->data.age=mytemp;break;
				case 4: scanf("%s",change);strcpy(p->next->data.tel, change);break;
				case 5: scanf("%s",change);strcpy(p->next->data.pro, change);break;
				case 6:	scanf("%d",&mytemp);p->next->data.myclass=mytemp;break;		
			}
			break;
			}
		}
		p=p->next;
	}
	if(temp==1)
	{
		printf("�޸ĳɹ�\n");
	}else{
		printf("δ�ҵ���ѧ��\n");	
	}
	
}
void selectStu(Students head)
{
		char str[20];
	printf("�����������ѯ��ѧ��ѧ��:");
	scanf("%s",str);
	Student* p=head;
	int temp=0;
	while(p->next!=NULL)
	{
		if(strcmp(str,p->next->data.sno)==0)
		{
			printf("ѧ�ţ�%s,������%s,�Ա�%s,����:%d,�绰���룺%s,רҵ��%s���༶��%d\n",p->next->data.sno,p->next->data.sname,p->next->data.sex,p->next->data.age,p->next->data.tel,p->next->data.pro,p->next->data.myclass);

			temp=1;
			break;
		}
		p=p->next;
	}
	if(temp!=1)
	{
		printf("δ�ҵ���ѧ��\n");
	}
}
int main()
{
	Students head=(Student*)malloc(sizeof(Student));
	head->next=NULL;
	int bre=0;
	while(true){
		system("cls");
		printf("����������ִ�еĹ���\n");
		screen();
		int click;
		scanf("%d",&click);
		system("cls");
		switch(click)
		{
			case 1:
				addStu(head);break;
			case 2:
				deleteStu(head);break;
			case 3:changeStu(head);break;
			case 4:selectStu(head);break;
			case 5:
			printStu(head);break;
			case 6:bre=1;break;
		}
		if(bre==1)
		{
		break;
		}
		system("pause");
		
	}
} 
