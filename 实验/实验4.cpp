#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MaxVerteNum 10
typedef struct 
{
	char Vex[MaxVerteNum];//����� 
	int Edge[MaxVerteNum][MaxVerteNum];//�ڽӾ��󣬱߱� 
	int vexnum,arcnum;	  //ͼ�ĵ�ǰ�������ͱ���/���� 
}MGraph;

//չʾ������Ϣ
//������ͼ+Ҫ���ҵĲ�������
void showMessage(MGraph graph,char str[])
{
	if(strcmp(str,"���ﲿ")==0)
	{
		
	}else if(strcmp(str,"סԺ��")==0)
	{
		
	}else if(strcmp(str,"���ﲿ")==0){
		
	}else if(strcmp(str,"ҩ��")==0){
	
		
	}else if(strcmp(str,"�շ���")==0){
		
		
	} else if(strcmp(str,"������")==0){
		
		
	}else if(strcmp(str,"�����")==0){
		
		
	}else if(strcmp(str,"������")==0){
		
		
	}else if(strcmp(str,"B����")==0){
		
	
	}else if(strcmp(str,"����¥")==0){
		
	}
}


int main()
{
	//1.����ͼ�����ö�����A-J�����Ӧ�Ĳ��� 
	MGraph graph;
	char temp='A';
	for(int i=0;i<10;i++)
	{
		graph.Vex[i]=temp;
		temp++;
		//���Ҷ�����ĿҪ++ 
		graph.vexnum++;
	}
	//2.���Ӹ���ͼ֮�䣬��������Ȩֵ
	 	//�շ���-ҩ��:50(E,D)
	 	graph.Edge[4][3]=50;
	 	graph.Edge[3][4]=50;
	 	graph.arcnum++;
	 	//ҩ���ͼ��ﲿ:120(D,C)
		 graph.Edge[2][3]=120;
		 graph.Edge[3][2]=120;
		 graph.arcnum++;
		//���ﲿ������¥:80(C,J)
		graph.Edge[2][9]=80;
		graph.Edge[9][2]=80;
		graph.arcnum++;
		//����¥�ͷſ���:160(J,G)
		graph.Edge[9][6]=160;
		graph.Edge[6][9]=160;
		graph.arcnum++;
		//����ƺ�B����:30(G,I)
		graph.Edge[6][5]=160;
		graph.Edge[5][6]=160;
		graph.arcnum++;	
		//����ƺ�סԺ��:130(G,B)
		graph.Edge[6][1]=130;
		graph.Edge[1][6]=130;
		graph.arcnum++;
		//����ƺ�������:100(G,H);
		graph.Edge[6][7]=100;
		graph.Edge[7][6]=100;
		graph.arcnum++;	  
		//�����Һ�סԺ��:50��H,B��
		graph.Edge[7][1]=50;
		graph.Edge[1][7]=50;
		graph.arcnum++;
		//�����Һͻ����ң�100(H,F)
		graph.Edge[7][5]=100;
		graph.Edge[5][7]=100;
		graph.arcnum++;
		//סԺ���ͻ�����:60(B,F)
		graph.Edge[1][5]=60;
		graph.Edge[5][1]=60;
		graph.arcnum++;
		//�����Һ��շ���:150(F,E)
		graph.Edge[5][4]=150;
		graph.Edge[4][5]=150;
		graph.arcnum++;
		//�����Һ�����:150(F,A)
		graph.Edge[5][0]=150;
		graph.Edge[0][5]=150;
		graph.arcnum++;
	 	//�շ��Һ�����:190(E,A)
	 	graph.Edge[4][0]=190;
	 	graph.Edge[0][4]=190;
	 	graph.arcnum++;
		//���ﲿ������:100(C,A)
		graph.Edge[2][0]=100;
		graph.Edge[0][2]=100;
		graph.arcnum++;
		//����¥������:90(J,A)
		graph.Edge[9][0]=90;
		graph.Edge[0][9]=90;
		graph.arcnum++;
		//���ò���չʾ��Ӧ��Ϣ 
		char str[4];
		printf("����������Ҫ���ҵĲ�����Ϣ��");
		gets(str);
		showMessage(graph,str);
			
} 
