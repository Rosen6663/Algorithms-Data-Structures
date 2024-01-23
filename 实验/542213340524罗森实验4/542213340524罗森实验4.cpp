#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//���ò������� 
#define MaxVerteNum 10
//��������� 
#define INF 9999 

typedef struct 
{
    char Vex[MaxVerteNum]; // �����
    int Edge[MaxVerteNum][MaxVerteNum]; // �ڽӾ��󣬱߱�
    int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͱ���/����
} MGraph;

//ͨ������ͼ������·��
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



//չʾ������Ϣ
//������ͼ+Ҫ���ҵĲ�������
void showMessage(MGraph graph,char str[])
{
	if(strcmp(str,"���ﲿ")==0)
	{
		//�������ﲿ��Ӧһ�еı��� 
		 for(int i=0;i<MaxVerteNum;i++)
		 {
		 	//��Ϊ����Ͳ�Ϊ0���������ӣ��о������չʾ 
			if(graph.Edge[0][i]!=0&&graph.Edge[0][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("���ﲿ�����ﲿ�����ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'B':printf("���ﲿ��סԺ�������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'C':printf("���ﲿ�뼱�ﲿ�����ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'D':printf("���ﲿ��ҩ���������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'E':printf("���ﲿ���շ��������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'F':printf("���ﲿ�뻯���������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'G':printf("���ﲿ�����������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'H':printf("���ﲿ�����������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'I':printf("���ﲿ��B���������ӣ�����%d\n",graph.Edge[0][i]);break;
						case 'J':printf("���ﲿ������¥�����ӣ�����%d\n",graph.Edge[0][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"סԺ��")==0)
	{
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[1][i]!=0&&graph.Edge[1][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("סԺ�������ﲿ�����ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'B':printf("סԺ����סԺ�������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'C':printf("סԺ���뼱�ﲿ�����ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'D':printf("סԺ����ҩ���������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'E':printf("סԺ�����շ��������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'F':printf("סԺ���뻯���������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'G':printf("סԺ�������������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'H':printf("סԺ�������������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'I':printf("סԺ����B���������ӣ�����%d\n",graph.Edge[1][i]);break;
						case 'J':printf("סԺ��������¥�����ӣ�����%d\n",graph.Edge[1][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"���ﲿ")==0){
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[2][i]!=0&&graph.Edge[2][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("���ﲿ�����ﲿ�����ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'B':printf("���ﲿ��סԺ�������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'C':printf("���ﲿ�뼱�ﲿ�����ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'D':printf("���ﲿ��ҩ���������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'E':printf("���ﲿ���շ��������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'F':printf("���ﲿ�뻯���������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'G':printf("���ﲿ�����������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'H':printf("���ﲿ�����������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'I':printf("���ﲿ��B���������ӣ�����%d\n",graph.Edge[2][i]);break;
						case 'J':printf("���ﲿ������¥�����ӣ�����%d\n",graph.Edge[2][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"ҩ��")==0){
	
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[3][i]!=0&&graph.Edge[3][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("ҩ�������ﲿ�����ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'B':printf("ҩ����סԺ�������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'C':printf("ҩ���뼱�ﲿ�����ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'D':printf("ҩ����ҩ���������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'E':printf("ҩ�����շ��������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'F':printf("ҩ���뻯���������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'G':printf("ҩ�������������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'H':printf("ҩ�������������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'I':printf("ҩ����B���������ӣ�����%d\n",graph.Edge[3][i]);break;
						case 'J':printf("ҩ��������¥�����ӣ�����%d\n",graph.Edge[3][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"�շ���")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[4][i]!=0&&graph.Edge[4][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("�շ��������ﲿ�����ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'B':printf("�շ�����סԺ�������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'C':printf("�շ����뼱�ﲿ�����ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'D':printf("�շ�����ҩ���������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'E':printf("�շ������շ��������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'F':printf("�շ����뻯���������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'G':printf("�շ��������������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'H':printf("�շ��������������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'I':printf("�շ�����B���������ӣ�����%d\n",graph.Edge[4][i]);break;
						case 'J':printf("�շ���������¥�����ӣ�����%d\n",graph.Edge[4][i]);break;
					}
			}
		 }
	} else if(strcmp(str,"������")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[5][i]!=0&&graph.Edge[5][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("�����������ﲿ�����ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'B':printf("��������סԺ�������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'C':printf("�������뼱�ﲿ�����ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'D':printf("��������ҩ���������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'E':printf("���������շ��������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'F':printf("�������뻯���������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'G':printf("�����������������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'H':printf("�����������������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'I':printf("��������B���������ӣ�����%d\n",graph.Edge[5][i]);break;
						case 'J':printf("������������¥�����ӣ�����%d\n",graph.Edge[5][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"�����")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[6][i]!=0&&graph.Edge[6][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("����������ﲿ�����ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'B':printf("�������סԺ�������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'C':printf("ס������뼱�ﲿ�����ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'D':printf("�������ҩ���������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'E':printf("��������շ��������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'F':printf("������뻯���������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'G':printf("����������������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'H':printf("����������������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'I':printf("�������B���������ӣ�����%d\n",graph.Edge[6][i]);break;
						case 'J':printf("�����������¥�����ӣ�����%d\n",graph.Edge[6][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"������")==0){
		
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[7][i]!=0&&graph.Edge[7][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("�����������ﲿ�����ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'B':printf("��������סԺ�������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'C':printf("�������뼱�ﲿ�����ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'D':printf("��������ҩ���������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'E':printf("���������շ��������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'F':printf("�������뻯���������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'G':printf("�����������������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'H':printf("�����������������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'I':printf("��������B���������ӣ�����%d\n",graph.Edge[7][i]);break;
						case 'J':printf("������������¥�����ӣ�����%d\n",graph.Edge[7][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"B����")==0){
		
	for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[8][i]!=0&&graph.Edge[8][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("B���������ﲿ�����ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'B':printf("B������סԺ�������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'C':printf("B�����뼱�ﲿ�����ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'D':printf("B������ҩ���������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'E':printf("B�������շ��������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'F':printf("B�����뻯���������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'G':printf("B���������������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'H':printf("B���������������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'I':printf("B������B���������ӣ�����%d\n",graph.Edge[8][i]);break;
						case 'J':printf("B����������¥�����ӣ�����%d\n",graph.Edge[8][i]);break;
					}
			}
		 }
	}else if(strcmp(str,"����¥")==0){
		for(int i=0;i<MaxVerteNum;i++)
		 {
			if(graph.Edge[9][i]!=0&&graph.Edge[9][i]!=INF)
			{
					char str[5];
					switch(graph.Vex[i])
					{
						case 'A':printf("����¥�����ﲿ�����ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'B':printf("����¥��סԺ�������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'C':printf("����¥�뼱�ﲿ�����ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'D':printf("����¥��ҩ���������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'E':printf("����¥���շ��������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'F':printf("����¥�뻯���������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'G':printf("����¥�����������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'H':printf("����¥�����������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'I':printf("����¥��B���������ӣ�����%d\n",graph.Edge[9][i]);break;
						case 'J':printf("����¥������¥�����ӣ�����%d\n",graph.Edge[9][i]);break;
					}
			}
		 }
	}else{
		printf("�Բ������ѯ�Ĳ��Ų�����\n");
	}
}


int main()
{
	//1.����ͼ�����ö�����A-J�����Ӧ�Ĳ��� 
	MGraph graph;
	char temp='A';
for (int i = 0; i < MaxVerteNum; i++) {
    graph.Vex[i] = temp;
    temp++;
    graph.vexnum++;
//��ʼ�����Լ����Լ�֮����Ϊ0������Ĭ����Ϊ����� 
    for (int j = 0; j < MaxVerteNum; j++) {
        if (i != j) {
            graph.Edge[i][j] = INF;
        } else {
            graph.Edge[i][j] = 0;  // ���㵽����ľ���Ϊ0
        }
    }
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
		//�����ͬ����֮��ľ��� 
		floyd(&graph);
		//�����������Ŷ�Ӧ�ı�ţ��������������� 
		char a;
		char b;
		printf("��������������������ŵ���̾���:\n");
		scanf("%c %c",&a,&b);
		int a1=a-'A';
		int b1=b-'A';

		printf("�����ż���̾�����%d",graph.Edge[a1][b1]); 
		
		
		
} 
