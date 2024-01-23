#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//����ϵͳ�е�������� 
#define MaxSize 100
const int s[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
//���� 
typedef struct Date{
	int year;
	int month; 
	int day; 
}Date; 
//�û�����Ϣ 
typedef struct Data{
	//���֤ 
	char ID[19];
	//���� 
	char name[19];
	//���ִ��� 
	int num;
	//��һ�������ʱ�� 
	Date time[2];

	
}Data;
 //˳���Ĵ��� 
typedef struct People{
	Data data[MaxSize];
	int length;
}People; 

//�Ƚ�����
int Datecmp(Date date1,Date date2)
{
	if (date1.year > date2.year)
    	return 1;
	else if (date1.year < date2.year)
   	 return -1;
	else
	{
   	 if (date1.month > date2.month)
       	 return 1;
    	else if (date1.month < date2.month)
        	return -1;
    	else
    	{
        if (date1.day > date2.day)
            return 1;
        else if (date1.day < date2.day)
            return -1;
        else
            return 0;
   		 }
	}

}

//����������˶�����
int count(const struct Date *p) 
{
	int i,t = 0;
	if(p->year%100 != 0 && p->year%4 == 0 || p->year%400 == 0)
		for(i = 1;i < p->month;i++)	t += s[1][i];
	else	for(i = 1;i < p->month;i++)	t += s[0][i];
	return t + p->day;
}



void screen()
{
	printf("��ӭʹ���¹����������Ϣ����ϵͳ\n");
	printf("------------------------------------\n");
	printf("1.������������Ϣ\n");
	printf("2.ɾ����������Ϣ\n");
	printf("3.������������Ϣ\n");
	printf("4.�������������Ϣ\n");
	printf("5.���ֲ������������Ϣ\n");
	printf("------------------------------------\n");
	printf("����������ִ�е�ָ��:\n");
	
	
}


//˳����� 
void insert(People &p)
{
	//��ջ����� 
	getchar();
	system("cls");
	//����Ѿ��ﵽ��������ˣ���ô�Ͳ������������ 
	if(p.length==MaxSize){
		printf("�Բ����û��Ѿ�����\n");
		system("pause");
	}else{
	
	
	printf("�������������Ľ�������Ϣ\n");
	//�����û����֤�ţ�������18λ 
	while(true)
	{
		printf("���������֤�ţ�");
		gets(p.data[p.length].ID);
	
		if(strlen(p.data[p.length].ID)!=18)
		{
			printf("�Բ�����������ȷ�����֤��\n");
	 	}else{
	 		break;
		 }
	}
		//�������� 
		printf("����������:");
		gets(p.data[p.length].name);
		//������ִ��� 
		while(true)
		{
			printf("�����߽��ִ���:");
			scanf("%d",&p.data[p.length].num);
			if(p.data[p.length].num==0||p.data[p.length].num==1||p.data[p.length].num==2)
			{
				break;
				
			}else{
				printf("��������ȷ���ִ���\n"); 
			}
		} 
		
			//�������ʱ��
			for(int i=0;i<p.data[p.length].num;i++)
			{
				printf("��%d��������:",i+1);
				scanf("%d",&p.data[p.length].time[i].year);
				printf("��%d������·�:",i+1);
				scanf("%d",&p.data[p.length].time[i].month);
				printf("��%d�������:",i+1);
				scanf("%d",&p.data[p.length].time[i].day);
			}	
		
	 printf("\n�½�������Ϣ����ɹ�\n��Ϣ:\n");
	 printf("���֤��%s\n",p.data[p.length].ID);
	 printf("������%s\n",p.data[p.length].name);
	 printf("���ִ�����%d\n",p.data[p.length].num);
	 //�������ʱ��
	for(int i=0;i<p.data[p.length].num;i++)
	{
		printf("��%d�ν���ʱ��%d-%d-%d\n",i+1,p.data[p.length].time[i].year,p.data[p.length].time[i].month,p.data[p.length].time[i].day);
	}
	p.length++;
	system("pause");
	}
	
}

//ѡ��λ�ò���
void insertpro(People &p,int locate)
{	
	//�����β������ 
	if(locate==p.length)
	{
		insert(p);
		//�����β��֮����� 
	}else if(locate>p.length)
	{
		system("cls");
		printf("�Բ��𣬲���λ�ò�����\n");
		system("pause"); 
	}else if(locate<p.length){
		system("cls");
	//���������data 
	Data t;
	printf("�������������Ľ�������Ϣ\n");
	//�����û����֤�ţ�������18λ 
	while(true)
	{
		getchar();
		printf("���������֤�ţ�");
		gets(t.ID);
	
		if(strlen(t.ID)!=18)
		{
			printf("�Բ�����������ȷ�����֤��\n");
	 	}
		 else
		{
	 		break;
		}
	}
		//�������� 
		printf("����������:");
		gets(t.name);
		//������ִ��� 
		while(true)
		{
			printf("�����߽��ִ���:");
			scanf("%d",&t.num);
			if(t.num==0||t.num==1||t.num==2)
			{
				break;
				
			}else{
				printf("��������ȷ���ִ���\n"); 
			}
		} 
		
			//�������ʱ��
			for(int i=0;i<t.num;i++)
			{
				printf("��%d��������:",i+1);
				scanf("%d",&t.time[i].year);
				printf("��%d������·�:",i+1);
				scanf("%d",&t.time[i].month);
				printf("��%d�������:",i+1);
				scanf("%d",&t.time[i].day);
			}	
		
	
		 
		for(int i=locate;i<p.length+1;i++)
		{
			//��������λ�õ������ó��� 
			Data temp=p.data[i];
			//����������ݲ��� 
			p.data[i]=t;
			//Ȼ���ٽ��� 
			t=temp;
			
		}
			 printf("\n�½�������Ϣ����ɹ�\n��Ϣ:\n");
	 printf("���֤��%s\n",p.data[locate].ID);
	 printf("������%s\n",p.data[locate].name);
	 printf("���ִ�����%d\n",p.data[locate].num);
	 //�������ʱ��
	for(int i=0;i<p.data[locate].num;i++)
	{
	
		printf("��%d�ν���ʱ��%d-%d-%d\n",i+1,p.data[locate].time[i].year,p.data[locate].time[i].month,p.data[locate].time[i].day);
		
		
		
	}
		p.length++;
		
		system("pause");
	}	
} 
//������� 
void insertScreen(People &p)
{
		system("cls");
		
		printf("1.˳����ӽ�������Ϣ\n");
		printf("2.ָ��λ����ӽ�������Ϣ\n");
		printf("��ѡ��������ӵķ�ʽ:");
		int num;
		scanf("%d",&num);
		switch(num)
		{
			case 1:insert(p);break;
			case 2:printf("������������ӵ�λ��:");
			int a;scanf("%d",&a);insertpro(p,a);break;
		}
}
//��ӡ�����û���Ϣ 
void print(People p)
{
	system("cls");
	if(p.length==0)
	{
		printf("�Բ��𣬻�û���û�����\n");
	}else{
	for(int j=0;j<p.length;j++){
		
	 printf("��%dλ�û�\n",j+1);
	 printf("���֤��%s\n",p.data[j].ID);
	 printf("������%s\n",p.data[j].name);
	 printf("���ִ�����%d\n",p.data[j].num);
	 //�������ʱ��
	for(int i=0;i<p.data[i].num;i++)
	{
		printf("��%d�ν���ʱ��%d-%d-%d\n",i+1,p.data[j].time[i].year,p.data[j].time[i].month,p.data[j].time[i].day);	
	}
	printf("\n");
								}
	}

	system("pause");
}
//��ӡ���ּ��14-28����û��û���Ϣ
 void printMore(People p)
{
	system("cls");
	if(p.length==0)
	{
		printf("�Բ��𣬻�û���û�����\n");
		system("pause");
	}else{
		time_t curTime =time(NULL);
		puts(ctime(&curTime));
		struct tm *ptm=localtime(&curTime);
		Date b;
		b.year=ptm->tm_year+1900;
		b.month=ptm->tm_mon+1;
		b.day=ptm->tm_mday;
		printf("��������Ϊ��%d %d %d\n\n",b.year,b.month,b.day);
		
	for(int j=0;j<p.length;j++){
		if(p.data[j].num==1)
		{
			
			
					int ans = 0,i;
				for(i = p.data[j].time[0].year;i <b.year ;i++)
				{
					if(i%100 != 0 && i%4 == 0 || i%400 == 0)	ans += 366;
					else	ans += 365;
				}
				ans += count(&b) - count(&p.data[j].time[0]);
				if(ans>=14&&ans<=28)
				{
					printf("���֤��%s\n",p.data[j].ID);
	 				printf("������%s\n",p.data[j].name);
	 				printf("���ִ�����%d\n",p.data[j].num);
	 				//�������ʱ��
					for(int i=0;i<p.data[i].num;i++)
					{
						printf("��%d�ν���ʱ��%d-%d-%d\n",i+1,p.data[j].time[i].year,p.data[j].time[i].month,p.data[j].time[i].day);	
					}
					printf("\n");
				}
}
	}
	system("pause");
}
	
}
void printscreen(People p)
{
	system("cls");
	printf("1.���ȫ����Ա��Ϣ\n");
	printf("2.���������ֵڶ���������Ա��Ϣ\n");
	printf("����������ִ�еĹ���:");
	int a;
	scanf("%d",&a);
	if(a==1)
	{
		print(p);
	}else if(a==2)
	{
		printMore(p);
	}
	
	
	
}
void deletelocate(People &p,int locate)
{
	if(locate>p.length){
		printf("�Բ��������û�п���ɾ���ĳ�Ա\n");
		system("pause");
	}else if(locate==p.length){
		p.length--;
		printf("ɾ���ɹ�\n");
		system("pause");
	}else if(locate<p.length)
	{
		
		for(int i=locate;i<p.length-1;i++)
		{
			p.data[i]=p.data[i+1];
		}
		p.length--;
		printf("ɾ���ɹ�\n");
		system("pause");
	}
}
void deleteById(People &p)
{
	getchar();
	system("cls");
	char ID[19];


	while(true)
	{
		
		printf("����������ɾ��������Ա��ID:");
		gets(ID);
	
		if(strlen(ID)!=18)
		{
			printf("�Բ�����������ȷ�����֤��\n");
	 	}
		 else
		{
	 		break;
		}
	}
	int qq=0;
	for(int i=0;i<p.length;i++)
	{
		if(strcmp(ID,p.data[i].ID)==0)
		{
			deletelocate(p,i);
			qq=2;
		}
	}
	if(qq==2)
	{
	
	}else if(qq==0){
		printf("û���ҵ���Ӧ��Ա\n");
		system("pause");
	}
	
}

void deleteScreen(People &p)
{
	
	system("cls");
		if(p.length==0)
		{
			printf("�Բ������ڻ�û�н�����Ա\n");
			system("pause");
		}
else{
		
			printf("1.ɾ��ָ��λ�õĽ�����\n");
			printf("2.ɾ����Ӧ���֤�ŵĽ�����\n");
			printf("��ѡ������ɾ���ķ�ʽ:");
			int num;
			scanf("%d",&num);
			switch(num)
			{
				case 1:printf("����������ɾ����λ��:");
				int a;scanf("%d",&a);deletelocate(p,a);break;
				case 2:deleteById(p);break;
			
			}
		
	}
	
}


//���֤��ֱ�Ӳ������� 
void InsertSort(People &p)
{
	int i,j;
	char temp[19];

	for(i=1;i<p.length;i++)
		if(strcmp(p.data[i].ID,p.data[i-1].ID)<0)
		{
			strcpy(temp,p.data[i].ID);
			
			for(j=i-1;j>=0&&strcmp(p.data[j].ID,temp)>0;--j)
				strcpy(p.data[j+1].ID,p.data[j].ID);
			strcpy(p.data[j+1].ID,temp);
		}
	printf("�Ѿ��������֤�Ž�������\n");
}

int Partition(People &p, int low, int high)
{
    Date pivot = p.data[low].time[0];
    int i = low;
    int j = high + 1;

    while (1)
    {
        do
        {
            ++i;
        } while (Datecmp(p.data[i].time[0], pivot) < 0);

        do
        {
            --j;
        } while (Datecmp(p.data[j].time[0], pivot) > 0);

        if (i >= j)
            break;

        // ���� data[i] �� data[j]
        Data temp = p.data[i];
        p.data[i] = p.data[j];
        p.data[j] = temp;
    }

    // ���� data[low] �� data[j]
    Data temp = p.data[low];
    p.data[low] = p.data[j];
    p.data[j] = temp;

    return j;
}
void sortQuick(People &p, int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(p, low, high);
        sortQuick(p, low, pivotpos - 1);
        sortQuick(p, pivotpos + 1, high);
    }
}



 
 
//����ҳ��
void sortscreen(People &p)
{
	system("cls");
	printf("1.���֤�Ž�������\n");
	printf("2.��һ������ʱ������\n");
	int a;
	printf("���������밴�����ַ�ʽ����");
	scanf("%d",&a);
	getchar();
	if(a==1)
	{
		InsertSort(p);
		system("pause");
	}else if(a==2)
	{
		system("cls");
		sortQuick(p, 0, p.length - 1);
		printf("�������\n");
		system("pause");
	}	
}

//�۰����

Data  binarySearch(People &p)
{
	getchar();
	//�Ƚ���������ܽ��ж��ֲ��� 
	system("cls");
	InsertSort(p);
	
	system("cls");
	char ID[19];


	while(true)
	{
		
		printf("������������ҽ�����Ա��ID:");
		gets(ID);
	
		if(strlen(ID)!=18)
		{
			printf("�Բ�����������ȷ�����֤��\n");
	 	}
		 else
		{
	 		break;
		}
	}
	

	int low=0,high=p.length-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(strcmp(p.data[mid].ID,ID)==0)
		{
				 
	 		printf("���֤��%s\n",p.data[mid].ID);
			printf("������%s\n",p.data[mid].name);
	 		printf("���ִ�����%d\n",p.data[mid].num);
	 			//�������ʱ��
			for(int i=0;i<p.data[i].num;i++)
			{
					printf("��%d�ν���ʱ��%d-%d-%d\n",i+1,p.data[mid].time[i].year,p.data[mid].time[i].month,p.data[mid].time[i].day);	
			}
			printf("\n");
			system("pause");
			return p.data[mid];
		}
		
		 
		else if(strcmp(p.data[mid].ID,ID)>0)
			high=mid-1;
		else 
			low=mid+1;
	}
	printf("û���ҵ�\n");
	system("pause");
}

int main()
{
	//��ʼ���� 
	People p;
	p.length=0;
	int which;
	while(true)
	{
		system("cls");
		//���������ѡ���� 
		screen();
		scanf("%d",&which);
	
		switch(which)
		{
			case 1:insertScreen(p);break;
			case 2:deleteScreen(p);break;
			case 3:printscreen(p);break;
			case 4:sortscreen(p);break;	
			case 5:binarySearch(p);break;
			
		}
	
	}
	
} 
