#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
    char sign;
    struct Stack* next;
} Stack, *Stacks;

void Push(Stacks& L, char c) {
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->sign = c;
    p->next = L;
    L = p;
}

char Pop(Stacks& L) {
    char c = L->sign;
    L = L->next;
    return c;
}

int main() {
	while(true){
		system("cls");
	
	//��׺���ʽתΪ��׺���ʽ 
    Stacks head = NULL;
    printf("���������������������ʽ��\n");
    char str[100];
    char str1[100];
    gets(str);
    int j = 0;

    for (int i = 0; i < strlen(str); i++) {
    	//���������� 
        if (str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='('&&str[i]!=')') {
            str1[j] = str[i];
            j++;
            //���������� 
        } else if (str[i] == '(' ) {
            Push(head, str[i]);
            //���� 
        } else if (str[i] == ')' || str[i] == '��') {
            while (head != NULL && (head->sign != '(' )) {
            	if(head->sign=='(')
				{
					break;
				}
                str1[j] = Pop(head);
                j++;
            }
            if (head != NULL && (head->sign == '(' )) {
                Pop(head); 
            }
        } else if (str[i] == '+' || str[i] == '-') {
            while (head != NULL ) {
                if(head->sign=='(')
				{
					break;
				}
				str1[j] = Pop(head);
                j++;
            }
            Push(head, str[i]);
        } else if (str[i] == '*' || str[i] == '/') {
            while (head != NULL ) {
                if(head->sign == '*' || head->sign == '/'){
                	str1[j] = Pop(head);
                	j++;
				}else{
					break;
				}
				
            }
            Push(head, str[i]);
        }
    }

    while (head != NULL) {
        str1[j] = Pop(head);
        j++;
    }

    printf("��׺���ʽ: ");
    for (int i = 0; i < j; i++) {
        printf("%c ", str1[i]);
    }
	//2.�����׺���ʽ 
	Stacks head1 = NULL;
	 for (int i = 0; i < strlen(str1); i++) {
        if (str1[i]!='+'&&str1[i]!='-'&&str1[i]!='*'&&str1[i]!='/')
        {
        	Push(head1,str1[i]);
		}else
		{
			char a1=Pop(head1);
			char b1=Pop(head1);
			int a=a1-48;
			int b=b1-48;
			switch(str1[i])
			{
				case'+':
					Push(head1,b+a+48);break;
				case'-':
					Push(head1,b-a+48);break;
				case'*':
					Push(head1,b*a+48);break;
				case'/':
					Push(head1,b/a+48);break;
			}	
		}
    }
	printf("�����Ϊ��%d\n",Pop(head1)-48);
	system("pause");
	}
	
    return 0;
}
