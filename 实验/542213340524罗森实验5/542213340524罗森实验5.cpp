#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//疫苗系统中的最大人数 
#define MaxSize 100
const int s[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
//日期 
typedef struct Date{
	int year;
	int month; 
	int day; 
}Date; 
//用户的信息 
typedef struct Data{
	//身份证 
	char ID[19];
	//姓名 
	char name[19];
	//接种次数 
	int num;
	//第一针接种是时间 
	Date time[2];

	
}Data;
 //顺序表的创建 
typedef struct People{
	Data data[MaxSize];
	int length;
}People; 

//比较日期
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

//计算这年过了多少天
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
	printf("欢迎使用新冠疫苗接种信息管理系统\n");
	printf("------------------------------------\n");
	printf("1.新增接种者信息\n");
	printf("2.删除接种者信息\n");
	printf("3.输出疫苗接种信息\n");
	printf("4.排序疫苗接种信息\n");
	printf("5.二分查找疫苗接种信息\n");
	printf("------------------------------------\n");
	printf("请输入你想执行的指令:\n");
	
	
}


//顺序插入 
void insert(People &p)
{
	//清空缓存区 
	getchar();
	system("cls");
	//如果已经达到最大人数了，那么就不能再添加人了 
	if(p.length==MaxSize){
		printf("对不起，用户已经满了\n");
		system("pause");
	}else{
	
	
	printf("请输入你想插入的接种者信息\n");
	//输入用户身份证号，必须是18位 
	while(true)
	{
		printf("接种者身份证号：");
		gets(p.data[p.length].ID);
	
		if(strlen(p.data[p.length].ID)!=18)
		{
			printf("对不起，请输入正确的身份证号\n");
	 	}else{
	 		break;
		 }
	}
		//输入姓名 
		printf("接种者姓名:");
		gets(p.data[p.length].name);
		//输入接种次数 
		while(true)
		{
			printf("接种者接种次数:");
			scanf("%d",&p.data[p.length].num);
			if(p.data[p.length].num==0||p.data[p.length].num==1||p.data[p.length].num==2)
			{
				break;
				
			}else{
				printf("请输入正确接种次数\n"); 
			}
		} 
		
			//输入接种时间
			for(int i=0;i<p.data[p.length].num;i++)
			{
				printf("第%d针接种年份:",i+1);
				scanf("%d",&p.data[p.length].time[i].year);
				printf("第%d针接种月份:",i+1);
				scanf("%d",&p.data[p.length].time[i].month);
				printf("第%d针接种日:",i+1);
				scanf("%d",&p.data[p.length].time[i].day);
			}	
		
	 printf("\n新接种者信息加入成功\n信息:\n");
	 printf("身份证：%s\n",p.data[p.length].ID);
	 printf("姓名：%s\n",p.data[p.length].name);
	 printf("接种次数：%d\n",p.data[p.length].num);
	 //输出接种时间
	for(int i=0;i<p.data[p.length].num;i++)
	{
		printf("第%d次接种时间%d-%d-%d\n",i+1,p.data[p.length].time[i].year,p.data[p.length].time[i].month,p.data[p.length].time[i].day);
	}
	p.length++;
	system("pause");
	}
	
}

//选择位置插入
void insertpro(People &p,int locate)
{	
	//如果在尾部插入 
	if(locate==p.length)
	{
		insert(p);
		//如果在尾部之后插入 
	}else if(locate>p.length)
	{
		system("cls");
		printf("对不起，插入位置不存在\n");
		system("pause"); 
	}else if(locate<p.length){
		system("cls");
	//创建插入的data 
	Data t;
	printf("请输入你想插入的接种者信息\n");
	//输入用户身份证号，必须是18位 
	while(true)
	{
		getchar();
		printf("接种者身份证号：");
		gets(t.ID);
	
		if(strlen(t.ID)!=18)
		{
			printf("对不起，请输入正确的身份证号\n");
	 	}
		 else
		{
	 		break;
		}
	}
		//输入姓名 
		printf("接种者姓名:");
		gets(t.name);
		//输入接种次数 
		while(true)
		{
			printf("接种者接种次数:");
			scanf("%d",&t.num);
			if(t.num==0||t.num==1||t.num==2)
			{
				break;
				
			}else{
				printf("请输入正确接种次数\n"); 
			}
		} 
		
			//输入接种时间
			for(int i=0;i<t.num;i++)
			{
				printf("第%d针接种年份:",i+1);
				scanf("%d",&t.time[i].year);
				printf("第%d针接种月份:",i+1);
				scanf("%d",&t.time[i].month);
				printf("第%d针接种日:",i+1);
				scanf("%d",&t.time[i].day);
			}	
		
	
		 
		for(int i=locate;i<p.length+1;i++)
		{
			//将本来的位置的数据拿出来 
			Data temp=p.data[i];
			//将插入的数据插入 
			p.data[i]=t;
			//然后再交换 
			t=temp;
			
		}
			 printf("\n新接种者信息加入成功\n信息:\n");
	 printf("身份证：%s\n",p.data[locate].ID);
	 printf("姓名：%s\n",p.data[locate].name);
	 printf("接种次数：%d\n",p.data[locate].num);
	 //输出接种时间
	for(int i=0;i<p.data[locate].num;i++)
	{
	
		printf("第%d次接种时间%d-%d-%d\n",i+1,p.data[locate].time[i].year,p.data[locate].time[i].month,p.data[locate].time[i].day);
		
		
		
	}
		p.length++;
		
		system("pause");
	}	
} 
//插入入口 
void insertScreen(People &p)
{
		system("cls");
		
		printf("1.顺序添加接种者信息\n");
		printf("2.指定位置添加接种者信息\n");
		printf("请选择你想添加的方式:");
		int num;
		scanf("%d",&num);
		switch(num)
		{
			case 1:insert(p);break;
			case 2:printf("请输入你想添加的位置:");
			int a;scanf("%d",&a);insertpro(p,a);break;
		}
}
//打印所有用户信息 
void print(People p)
{
	system("cls");
	if(p.length==0)
	{
		printf("对不起，还没有用户存在\n");
	}else{
	for(int j=0;j<p.length;j++){
		
	 printf("第%d位用户\n",j+1);
	 printf("身份证：%s\n",p.data[j].ID);
	 printf("姓名：%s\n",p.data[j].name);
	 printf("接种次数：%d\n",p.data[j].num);
	 //输出接种时间
	for(int i=0;i<p.data[i].num;i++)
	{
		printf("第%d次接种时间%d-%d-%d\n",i+1,p.data[j].time[i].year,p.data[j].time[i].month,p.data[j].time[i].day);	
	}
	printf("\n");
								}
	}

	system("pause");
}
//打印接种间隔14-28天的用户用户信息
 void printMore(People p)
{
	system("cls");
	if(p.length==0)
	{
		printf("对不起，还没有用户存在\n");
		system("pause");
	}else{
		time_t curTime =time(NULL);
		puts(ctime(&curTime));
		struct tm *ptm=localtime(&curTime);
		Date b;
		b.year=ptm->tm_year+1900;
		b.month=ptm->tm_mon+1;
		b.day=ptm->tm_mday;
		printf("今日日期为：%d %d %d\n\n",b.year,b.month,b.day);
		
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
					printf("身份证：%s\n",p.data[j].ID);
	 				printf("姓名：%s\n",p.data[j].name);
	 				printf("接种次数：%d\n",p.data[j].num);
	 				//输出接种时间
					for(int i=0;i<p.data[i].num;i++)
					{
						printf("第%d次接种时间%d-%d-%d\n",i+1,p.data[j].time[i].year,p.data[j].time[i].month,p.data[j].time[i].day);	
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
	printf("1.输出全部人员信息\n");
	printf("2.输出满足接种第二针疫苗人员信息\n");
	printf("请输入你想执行的功能:");
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
		printf("对不起，这后面没有可以删除的成员\n");
		system("pause");
	}else if(locate==p.length){
		p.length--;
		printf("删除成功\n");
		system("pause");
	}else if(locate<p.length)
	{
		
		for(int i=locate;i<p.length-1;i++)
		{
			p.data[i]=p.data[i+1];
		}
		p.length--;
		printf("删除成功\n");
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
		
		printf("请输入你想删除接种人员的ID:");
		gets(ID);
	
		if(strlen(ID)!=18)
		{
			printf("对不起，请输入正确的身份证号\n");
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
		printf("没有找到对应人员\n");
		system("pause");
	}
	
}

void deleteScreen(People &p)
{
	
	system("cls");
		if(p.length==0)
		{
			printf("对不起，现在还没有接种人员\n");
			system("pause");
		}
else{
		
			printf("1.删除指定位置的接种者\n");
			printf("2.删除对应身份证号的接种者\n");
			printf("请选择你想删除的方式:");
			int num;
			scanf("%d",&num);
			switch(num)
			{
				case 1:printf("请输入你想删除的位置:");
				int a;scanf("%d",&a);deletelocate(p,a);break;
				case 2:deleteById(p);break;
			
			}
		
	}
	
}


//身份证号直接插入排序 
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
	printf("已经按照身份证号进行排序\n");
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

        // 交换 data[i] 和 data[j]
        Data temp = p.data[i];
        p.data[i] = p.data[j];
        p.data[j] = temp;
    }

    // 交换 data[low] 和 data[j]
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



 
 
//排序页面
void sortscreen(People &p)
{
	system("cls");
	printf("1.身份证号进行排序\n");
	printf("2.第一剂接种时间排序\n");
	int a;
	printf("请输入你想按照哪种方式排序");
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
		printf("排序完毕\n");
		system("pause");
	}	
}

//折半查找

Data  binarySearch(People &p)
{
	getchar();
	//先进行排序才能进行二分查找 
	system("cls");
	InsertSort(p);
	
	system("cls");
	char ID[19];


	while(true)
	{
		
		printf("请输入你想查找接种人员的ID:");
		gets(ID);
	
		if(strlen(ID)!=18)
		{
			printf("对不起，请输入正确的身份证号\n");
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
				 
	 		printf("身份证：%s\n",p.data[mid].ID);
			printf("姓名：%s\n",p.data[mid].name);
	 		printf("接种次数：%d\n",p.data[mid].num);
	 			//输出接种时间
			for(int i=0;i<p.data[i].num;i++)
			{
					printf("第%d次接种时间%d-%d-%d\n",i+1,p.data[mid].time[i].year,p.data[mid].time[i].month,p.data[mid].time[i].day);	
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
	printf("没有找到\n");
	system("pause");
}

int main()
{
	//初始化表 
	People p;
	p.length=0;
	int which;
	while(true)
	{
		system("cls");
		//主界面进行选择功能 
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
