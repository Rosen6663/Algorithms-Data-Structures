#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//设置部门容量 
#define MaxVerteNum 10
//设置无穷大 
#define INF 9999 

typedef struct 
{
    char Vex[MaxVerteNum]; // 顶点表
    int Edge[MaxVerteNum][MaxVerteNum]; // 邻接矩阵，边表
    int vexnum, arcnum; // 图的当前顶点数和边数/弧数
} MGraph;

//通过遍历图求出最短路径
void floyd(MGraph *graph) {
    int i, j, k;

    for (k = 0; k < graph->vexnum; k++) {
        for (i = 0; i < graph->vexnum; i++) {
            for (j = 0; j < graph->vexnum; j++) {
                if (graph->Edge[i][k] + graph->Edge[k][j] < graph->Edge[i][j]) {
                    graph->Edge[i][j] = graph->Edge[i][k] + graph->Edge[k][j];
                }
            }
        }
    }
}



//展示部门信息
//参数：图+要查找的部门名称
void showMessage(MGraph graph,char str[])
{
	if(strcmp(str,"门诊部")==0)
	{
		//进行门诊部对应一行的遍历 
		 for(int i=0;i<MaxVerteNum;i++)
		 {
		 	//不为无穷和不为0代表，有连接，有距离进行展示 
			if(graph.Edge[0][i]!=0&&graph.Edge[0][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("门诊部与门诊部相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'B':printf("门诊部与住院部相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'C':printf("门诊部与急诊部相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'D':printf("门诊部与药房部相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'E':printf("门诊部与收费室相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'F':printf("门诊部与化验室相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'G':printf("门诊部与放射科相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'H':printf("门诊部与手术室连接，距离%d\n",graph.Edge[0][i]);break;
						case 'I':printf("门诊部与B超室相连接，距离%d\n",graph.Edge[0][i]);break;
						case 'J':printf("门诊部与行政楼相连接，距离%d\n",graph.Edge[0][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"住院部")==0)
	{
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[1][i]!=0&&graph.Edge[1][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("住院部与门诊部相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'B':printf("住院部与住院部相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'C':printf("住院部与急诊部相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'D':printf("住院部与药房部相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'E':printf("住院部与收费室相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'F':printf("住院部与化验室相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'G':printf("住院部与放射科相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'H':printf("住院部与手术室连接，距离%d\n",graph.Edge[1][i]);break;
						case 'I':printf("住院部与B超室相连接，距离%d\n",graph.Edge[1][i]);break;
						case 'J':printf("住院部与行政楼相连接，距离%d\n",graph.Edge[1][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"急诊部")==0){
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[2][i]!=0&&graph.Edge[2][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("急诊部与门诊部相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'B':printf("急诊部与住院部相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'C':printf("急诊部与急诊部相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'D':printf("急诊部与药房部相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'E':printf("急诊部与收费室相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'F':printf("急诊部与化验室相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'G':printf("急诊部与放射科相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'H':printf("急诊部与手术室连接，距离%d\n",graph.Edge[2][i]);break;
						case 'I':printf("急诊部与B超室相连接，距离%d\n",graph.Edge[2][i]);break;
						case 'J':printf("急诊部与行政楼相连接，距离%d\n",graph.Edge[2][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"药房")==0){
	
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[3][i]!=0&&graph.Edge[3][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("药房与门诊部相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'B':printf("药房与住院部相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'C':printf("药房与急诊部相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'D':printf("药房与药房部相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'E':printf("药房与收费室相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'F':printf("药房与化验室相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'G':printf("药房与放射科相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'H':printf("药房与手术室连接，距离%d\n",graph.Edge[3][i]);break;
						case 'I':printf("药房与B超室相连接，距离%d\n",graph.Edge[3][i]);break;
						case 'J':printf("药房与行政楼相连接，距离%d\n",graph.Edge[3][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"收费室")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[4][i]!=0&&graph.Edge[4][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("收费室与门诊部相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'B':printf("收费室与住院部相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'C':printf("收费室与急诊部相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'D':printf("收费室与药房部相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'E':printf("收费室与收费室相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'F':printf("收费室与化验室相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'G':printf("收费室与放射科相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'H':printf("收费室与手术室连接，距离%d\n",graph.Edge[4][i]);break;
						case 'I':printf("收费室与B超室相连接，距离%d\n",graph.Edge[4][i]);break;
						case 'J':printf("收费室与行政楼相连接，距离%d\n",graph.Edge[4][i]);break;
					}
			}
		 }
	} else if(strcmp(str,"化验室")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[5][i]!=0&&graph.Edge[5][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("化验室与门诊部相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'B':printf("化验室与住院部相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'C':printf("化验室与急诊部相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'D':printf("化验室与药房部相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'E':printf("化验室与收费室相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'F':printf("化验室与化验室相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'G':printf("化验室与放射科相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'H':printf("化验室与手术室连接，距离%d\n",graph.Edge[5][i]);break;
						case 'I':printf("化验室与B超室相连接，距离%d\n",graph.Edge[5][i]);break;
						case 'J':printf("化验室与行政楼相连接，距离%d\n",graph.Edge[5][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"放射科")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[6][i]!=0&&graph.Edge[6][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("放射科与门诊部相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'B':printf("放射科与住院部相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'C':printf("住放射科与急诊部相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'D':printf("放射科与药房部相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'E':printf("放射科与收费室相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'F':printf("放射科与化验室相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'G':printf("放射科与放射科相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'H':printf("放射科与手术室连接，距离%d\n",graph.Edge[6][i]);break;
						case 'I':printf("放射科与B超室相连接，距离%d\n",graph.Edge[6][i]);break;
						case 'J':printf("放射科与行政楼相连接，距离%d\n",graph.Edge[6][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"手术室")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[7][i]!=0&&graph.Edge[7][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("手术室与门诊部相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'B':printf("手术室与住院部相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'C':printf("手术室与急诊部相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'D':printf("手术室与药房部相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'E':printf("手术室与收费室相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'F':printf("手术室与化验室相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'G':printf("手术室与放射科相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'H':printf("手术室与手术室连接，距离%d\n",graph.Edge[7][i]);break;
						case 'I':printf("手术室与B超室相连接，距离%d\n",graph.Edge[7][i]);break;
						case 'J':printf("手术室与行政楼相连接，距离%d\n",graph.Edge[7][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"B超室")==0){
		
	for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[8][i]!=0&&graph.Edge[8][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("B超室与门诊部相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'B':printf("B超室与住院部相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'C':printf("B超室与急诊部相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'D':printf("B超室与药房部相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'E':printf("B超室与收费室相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'F':printf("B超室与化验室相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'G':printf("B超室与放射科相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'H':printf("B超室与手术室连接，距离%d\n",graph.Edge[8][i]);break;
						case 'I':printf("B超室与B超室相连接，距离%d\n",graph.Edge[8][i]);break;
						case 'J':printf("B超室与行政楼相连接，距离%d\n",graph.Edge[8][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"行政楼")==0){
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[9][i]!=0&&graph.Edge[9][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("行政楼与门诊部相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'B':printf("行政楼与住院部相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'C':printf("行政楼与急诊部相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'D':printf("行政楼与药房部相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'E':printf("行政楼与收费室相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'F':printf("行政楼与化验室相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'G':printf("行政楼与放射科相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'H':printf("行政楼与手术室连接，距离%d\n",graph.Edge[9][i]);break;
						case 'I':printf("行政楼与B超室相连接，距离%d\n",graph.Edge[9][i]);break;
						case 'J':printf("行政楼与行政楼相连接，距离%d\n",graph.Edge[9][i]);break;
					}
			}
		 }
	}else{
		printf("对不起，你查询的部门不存在\n");
	}
}


int main()
{
	//1.创建图，设置顶点是A-J代表对应的部门 
	MGraph graph;
	char temp='A';
for (int i = 0; i < MaxVerteNum; i++) {
    graph.Vex[i] = temp;
    temp++;
    graph.vexnum++;
//初始化，自己和自己之间设为0，其他默认设为无穷大 
    for (int j = 0; j < MaxVerteNum; j++) {
        if (i != j) {
            graph.Edge[i][j] = INF;
        } else {
            graph.Edge[i][j] = 0;  // 顶点到自身的距离为0
        }
    }
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
		//求出不同部门之间的距离 
		floyd(&graph);
		//输入两个部门对应的编号，即可算出最近距离 
		char a;
		char b;
		printf("请输入你想查找两个部门的最短距离:\n");
		scanf("%c %c",&a,&b);
		int a1=a-'A';
		int b1=b-'A';

		printf("两部门间最短距离是%d",graph.Edge[a1][b1]); 
		
		
		
} 
