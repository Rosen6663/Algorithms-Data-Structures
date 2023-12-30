#include<stdio.h>
#include<stdlib.h>
#define MaxVerteNum 10
typedef struct 
{
	char Vex[MaxVerteNum];//顶点表 
	int Edge[MaxVerteNum][MaxVerteNum];//邻接矩阵，边表 
	int vexnum,arcnum;	  //图的当前顶点数和边数/弧数 
}MGraph;
int main()
{
	//创建图，设置顶点是A-J代表对应的部门 
	MGraph graph;
	char temp='A';
	for(int i=0;i<10;i++)
	{
		graph.Vex[i]=temp;
		temp++;
		//而且顶点数目要++ 
		graph.vexnum++;
	}
	//连接各个图之间，并且设置权值
	 	//收费室-药房:50(E,D)
	 	graph.Edge[4][3]=50;
	 	graph.Edge[3][4]=50;
	 	//药房和急诊部:120(D,C)
		 graph.Edge[2][3]=120;
		 graph.Edge[3][2]=120;
		//急诊部和行政楼:80(C,J)
		graph.Edge[2][9]=80;
		graph.Edge[9][2]=80;
		//行政楼和放科室:160(J,G)
		graph.Edge[9][6]=160;
		graph.Edge[6][9]=160;
		//放射科和B超室:30(G,I)
		graph.Edge[6][5]=160;
		graph.Edge[5][6]=160;	
		//放射科和住院部:130(G,B)
		graph.Edge[6][1]=130;
		graph.Edge[1][6]=130;
		//放射科和手术室:100(G,H);
		graph.Edge[6][7]=100;
		graph.Edge[7][6]=100;	  
		//手术室和住院部:50（H,B）
		graph.Edge[7][1]=50;
		graph.Edge[1][7]=50;
		//手术室和化验室：100(H,F)
		graph.Edge[7][5]=100;
		graph.Edge[5][7]=100;
		//住院部和化验室:60(B,F)
		graph.Edge[1][5]=60;
		graph.Edge[5][1]=60;
		//化验室和收费室(F,
		graph.Edge[] 
	 

	
} 
