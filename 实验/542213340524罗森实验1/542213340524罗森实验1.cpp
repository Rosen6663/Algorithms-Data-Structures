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
	printf("1.增加学生信息\n");
	printf("2.删除学生信息\n");
	printf("3.修改学生信息\n");
	printf("4.查询学生信息\n");
	printf("5.输出学生信息\n");
	printf("6.退出\n");
	printf("--------------------------\n");
}
//学生信息的创建
struct sdata createStu()
{
	sdata p; 
	printf("请输入要添加的学生信息\n");
	printf("学号:");
	scanf("%s",p.sno);
	printf("姓名:");
	scanf("%s",p.sname);
	while(true)
	{
		printf("性别:");
		scanf("%s",p.sex);
		if(strcmp(p.sex,"男")==0||strcmp(p.sex,"女")==0)
			break;
		printf("输入非法，请输入男或女\n");
	}
	
	printf("年龄:");
	scanf("%d",&(p.age));
	printf("电话:");
	scanf("%s",p.tel);
	printf("专业:");
	scanf("%s",p.pro);
	printf("班级:");
	scanf("%d",&p.myclass);
	
	
	return p;
	
} 
//增加学生信息 
void addStu(Students &head)
{		
	sdata data1=createStu();	
 	Student* p=(Student*)malloc(sizeof(Student));
 	
 	
 	p->data=data1;
 	
 	p->next=head->next;
 	head->next=p;
 	printf("学生信息添加成功\n");
	
}
//输出学生信息
bool printStu(Students head)
{
	
	if(head->next==NULL)
	{
		printf("没有学生信息，请您添加\n");
		return false;
	}
	Student* p=head;
	int count=1;
	while(p->next!=NULL)
	{
		printf("%d.%s\n",count,p->next->data.sno);
		printf("姓名：%s,性别：%s,年龄:%d,电话号码：%s,专业：%s，班级：%d\n",p->next->data.sname,p->next->data.sex,p->next->data.age,p->next->data.tel,p->next->data.pro,p->next->data.myclass);
		p=p->next;
		count++; 
	}
	
 }
 //删除学生信息
void deleteStu(Students &head)
{	
	char str[20];
	printf("请输入你想删除的学生学号:");
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
		printf("删除成功\n");
	}else{
		printf("未找到该学生\n");	
	}
	
}
//修改学生信息 
void changeStu(Students &head)
{
		char str[20];
		char change[20];
	printf("请输入你想修改学生的学号:\n");
	scanf("%s",str);
	Student* p=head;
	int temp=0;
	while(p->next!=NULL)
	{
		if(strcmp(str,p->next->data.sno)==0)
		{
			temp=1;
			int how;
			printf("1.姓名\n");
			printf("2.性别\n");
			printf("3.年龄\n");
			printf("4.电话号码\n");
			printf("5.专业\n");
			printf("6.班级\n");
			printf("请输入你想修改的学生的哪项信息:");
			scanf("%d",&how);
		
			if(how==2){
					
				if(strcmp(p->next->data.sex,"男")==0){
					
					 char sex[] = "女";  
					strcpy(p->next->data.sex, sex);
				}else{
						 char sex[] = "男";  
					strcpy(p->next->data.sex, sex);
				}
				break;
			}else{
				printf("修改成什么:");
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
		printf("修改成功\n");
	}else{
		printf("未找到该学生\n");	
	}
	
}
void selectStu(Students head)
{
		char str[20];
	printf("请输入你想查询的学生学号:");
	scanf("%s",str);
	Student* p=head;
	int temp=0;
	while(p->next!=NULL)
	{
		if(strcmp(str,p->next->data.sno)==0)
		{
			printf("学号：%s,姓名：%s,性别：%s,年龄:%d,电话号码：%s,专业：%s，班级：%d\n",p->next->data.sno,p->next->data.sname,p->next->data.sex,p->next->data.age,p->next->data.tel,p->next->data.pro,p->next->data.myclass);

			temp=1;
			break;
		}
		p=p->next;
	}
	if(temp!=1)
	{
		printf("未找到该学生\n");
	}
}
int main()
{
	Students head=(Student*)malloc(sizeof(Student));
	head->next=NULL;
	int bre=0;
	while(true){
		system("cls");
		printf("请输入你想执行的功能\n");
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
