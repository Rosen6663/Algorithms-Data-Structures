#include<stdio.h>
#include<stdlib.h>
#define MaxVerteNum 10
typedef struct 
{
	char Vex[MaxVerteNum];//����� 
	int Edge[MaxVerteNum][MaxVerteNum];//�ڽӾ��󣬱߱� 
	int vexnum,arcnum;	  //ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;
int main()
{
	//����ͼ�����ö�����A-J�����Ӧ�Ĳ��� 
	MGraph graph;
	char temp='A';
	for(int i=0;i<10;i++)
	{
		graph.Vex[i]=temp;
		temp++;
		//���Ҷ�����ĿҪ++ 
		graph.vexnum++;
	}
	//���Ӹ���ͼ֮�䣬��������Ȩֵ
	 	//�շ���-ҩ��:50(E,D)
	 	graph.Edge[4][3]=50;
	 	graph.Edge[3][4]=50;
	 	//ҩ���ͼ��ﲿ:120(D,C)
		 graph.Edge[2][3]=120;
		 graph.Edge[3][2]=120;
		//���ﲿ������¥:80(C,J)
		graph.Edge[2][9]=80;
		graph.Edge[9][2]=80;
		//����¥�ͷſ���:160(J,G)
		graph.Edge[9][6]=160;
		graph.Edge[6][9]=160;
		//����ƺ�B����:30(G,I)
		graph.Edge[6][5]=160;
		graph.Edge[5][6]=160;	
		//����ƺ�סԺ��:130(G,B)
		graph.Edge[6][1]=130;
		graph.Edge[1][6]=130;
		//����ƺ�������:100(G,H);
		graph.Edge[6][7]=100;
		graph.Edge[7][6]=100;	  
		//�����Һ�סԺ��:50��H,B��
		graph.Edge[7][1]=50;
		graph.Edge[1][7]=50;
		//�����Һͻ����ң�100(H,F)
		graph.Edge[7][5]=100;
		graph.Edge[5][7]=100;
		//סԺ���ͻ�����:60(B,F)
		graph.Edge[1][5]=60;
		graph.Edge[5][1]=60;
		//�����Һ��շ���(F,
		graph.Edge[] 
	 

	
} 
