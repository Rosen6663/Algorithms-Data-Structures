#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//������������ṹ��
typedef struct node {
    char data; 
    struct node *left;
    struct node *right; 
} node;

//����ջ�ṹ��
typedef struct stack {
    node *data; 
    struct stack *next; 
} stack;

//�ж�һ���ַ��Ƿ��������
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

//�ж�һ���ַ��Ƿ�������
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

//�Ƚ���������������ȼ�
int compare_priority(char a, char b) {
    if (a == '(') return 0; 
    if (b == '(') return 0; 
    if (a == '*' || a == '/') return 1;
    if (b == '*' || b == '/') return 0; 
    return 1; 
}

//����һ���µĶ��������
node *create_node(char data) {
    node *new_node = (node *)malloc(sizeof(node)); 
    new_node->data = data;
    new_node->left = NULL; 
    new_node->right = NULL;
    return new_node; 
}

//����һ���µ�ջԪ��
stack *create_stack(node *data) {
    stack *new_stack = (stack *)malloc(sizeof(stack)); //�����ڴ�ռ�
    new_stack->data = data; //��ֵ������
    new_stack->next = NULL; //��ʼ��ָ����Ϊ��
    return new_stack; //������ջԪ�ص�ָ��
}

//�ж�ջ�Ƿ�Ϊ��
int is_empty(stack *s) {
    return s == NULL; 
}

//��ջ����
void push(stack **s, node *data) {
    stack *new_stack = create_stack(data); 
    new_stack->next = *s; 
    *s = new_stack; 
}

//��ջ����
node *pop(stack **s) {
    if (is_empty(*s)) return NULL;
    stack *temp = *s; 
    node *data = temp->data; 
    *s = temp->next; 
    free(temp); 
    return data; 
}

//��ȡջ�����ݣ����ı�ջ��״̬
node *peek(stack *s) {
    if (is_empty(s)) return NULL; 
    return s->data; 
}

//����׺���ʽת��Ϊ��׺���ʽ�������������
node *convert(char *infix) {
    stack *operator_stack = NULL; 
    stack *tree_stack = NULL; 
    int i = 0; 
    while (infix[i] != '\0') {
        char c = infix[i]; 
        if (is_digit(c)) { 
            node *new_node = create_node(c); 
            push(&tree_stack, new_node);
        } else if (is_operator(c)) { 
            while (!is_empty(operator_stack) && compare_priority(peek(operator_stack)->data, c)) {
                node *op = pop(&operator_stack); 
                node *right = pop(&tree_stack); 
                node *left = pop(&tree_stack); 
                op->left = left; 
                op->right = right; 
                push(&tree_stack, op); 
            }
            node *new_node = create_node(c); 
            push(&operator_stack, new_node); 
        } else if (c == '(') { 
            node *new_node = create_node(c); 
            push(&operator_stack, new_node); 
        } else if (c == ')') { 
            while (!is_empty(operator_stack) && peek(operator_stack)->data != '(') { 
                node *op = pop(&operator_stack); 
                node *right = pop(&tree_stack); 
                node *left = pop(&tree_stack); 
                op->left = left; 
                op->right = right; 
                push(&tree_stack, op); 
            }
            pop(&operator_stack); 
        }
        i++; 
    }
    while (!is_empty(operator_stack)) {
        node *op = pop(&operator_stack);
        node *right = pop(&tree_stack); 
        node *left = pop(&tree_stack);
        op->left = left; 
        op->right = right; 
        push(&tree_stack, op); 
    }
    node *root = pop(&tree_stack); 
    return root; 
}

//���������������������ʽ
void inorder_traverse(node *root) {
    if (root == NULL) return; 
    if (is_operator(root->data)) printf("("); 
    inorder_traverse(root->left); 
    printf("%c", root->data); 
}
//���������������������ʽ
void postorder_traverse(node *root) {
    if (root == NULL) return; 
    postorder_traverse(root->left); 
    postorder_traverse(root->right); 
    printf("%c", root->data);
}

//������ʽ��ֵ
int evaluate(node *root) {
    if (root == NULL) return 0; 
    if (is_digit(root->data)) return root->data - '0'; 
    int left = evaluate(root->left); 
    int right = evaluate(root->right); 
    switch (root->data) { 
        case '+': return left + right; 
        case '-': return left - right; 
        case '*': return left * right; 
        case '/': return left / right; 
        default: return 0; 
    }
}

//������
int main() {
    char infix[100]; 
    printf("������һ���������ʽ��\n"); 
    scanf("%s", infix); 
    node *root = convert(infix); 
    printf("���������������������ʽ��\n");
    inorder_traverse(root); 
    printf("\n");
    printf("���������������������ʽ��\n");
    postorder_traverse(root); 
    printf("\n");
    printf("���ʽ��ֵΪ��\n"); 
    printf("%d\n", evaluate(root)); 
    return 0; 
}

