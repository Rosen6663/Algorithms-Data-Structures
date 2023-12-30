#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MaxVerteNum 10
typedef struct 
{
	char Vex[MaxVerteNum];//顶点表 
	int Edge[MaxVerteNum][MaxVerteNum];//邻接矩阵，边表 
	int vexnum,arcnum;	  //图的当前顶点数和边数/弧数 
}MGraph;

//展示部门信息
//参数：图+要查找的部门名称
void showMessage(MGraph graph,char str[])
{
	if(strcmp(str,"门诊部")==0)
	{
		
	}else if(strcmp(str,"住院部")==0)
	{
		
	}else if(strcmp(str,"急诊部")==0){
		
	}else if(strcmp(str,"药房")==0){
	
		
	}else if(strcmp(str,"收费室")==0){
		
		
	} else if(strcmp(str,"化验室")==0){
		
		
	}else if(strcmp(str,"放射科")==0){
		
		
	}else if(strcmp(str,"手术室")==0){
		
		
	}else if(strcmp(str,"B超室")==0){
		
	
	}else if(strcmp(str,"行政楼")==0){
		
	}
}


int main()
{
	//1.创建图，设置顶点是A-J代表对应的部门 
	MGraph graph;
	char temp='A';
	for(int i=0;i<10;i++)
	{
		graph.Vex[i]=temp;
		temp++;
		//而且顶点数目要++ 
		graph.vexnum++;
	}
	//2.连接各个图之间，并且设置权值
	 	//收费室-药房:50(E,D)
	 	graph.Edge[4][3]=50;
	 	graph.Edge[3][4]=50;
	 	graph.arcnum++;
	 	//药房和急诊部:120(D,C)
		 graph.Edge[2][3]=120;
		 graph.Edge[3][2]=120;
		 graph.arcnum++;
		//急诊部和行政楼:80(C,J)
		graph.Edge[2][9]=80;
		graph.Edge[9][2]=80;
		graph.arcnum++;
		//行政楼和放科室:160(J,G)
		graph.Edge[9][6]=160;
		graph.Edge[6][9]=160;
		graph.arcnum++;
		//放射科和B超室:30(G,I)
		graph.Edge[6][5]=160;
		graph.Edge[5][6]=160;
		graph.arcnum++;	
		//放射科和住院部:130(G,B)
		graph.Edge[6][1]=130;
		graph.Edge[1][6]=130;
		graph.arcnum++;
		//放射科和手术室:100(G,H);
		graph.Edge[6][7]=100;
		graph.Edge[7][6]=100;
		graph.arcnum++;	  
		//手术室和住院部:50（H,B）
		graph.Edge[7][1]=50;
		graph.Edge[1][7]=50;
		graph.arcnum++;
		//手术室和化验室：100(H,F)
		graph.Edge[7][5]=100;
		graph.Edge[5][7]=100;
		graph.arcnum++;
		//住院部和化验室:60(B,F)
		graph.Edge[1][5]=60;
		graph.Edge[5][1]=60;
		graph.arcnum++;
		//化验室和收费室:150(F,E)
		graph.Edge[5][4]=150;
		graph.Edge[4][5]=150;
		graph.arcnum++;
		//化验室和门诊:150(F,A)
		graph.Edge[5][0]=150;
		graph.Edge[0][5]=150;
		graph.arcnum++;
	 	//收费室和门诊:190(E,A)
	 	graph.Edge[4][0]=190;
	 	graph.Edge[0][4]=190;
	 	graph.arcnum++;
		//急诊部和门诊:100(C,A)
		graph.Edge[2][0]=100;
		graph.Edge[0][2]=100;
		graph.arcnum++;
		//行政楼和门诊:90(J,A)
		graph.Edge[9][0]=90;
		graph.Edge[0][9]=90;
		graph.arcnum++;
		//调用参数展示对应信息 
		char str[4];
		printf("请输入你想要查找的部门信息：");
		gets(str);
		showMessage(graph,str);
			
} 
