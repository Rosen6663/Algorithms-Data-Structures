#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//定义二叉树结点结构体
typedef struct node {
    char data; 
    struct node *left;
    struct node *right; 
} node;

//定义栈结构体
typedef struct stack {
    node *data; 
    struct stack *next; 
} stack;

//判断一个字符是否是运算符
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

//判断一个字符是否是数字
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

//比较两个运算符的优先级
int compare_priority(char a, char b) {
    if (a == '(') return 0; 
    if (b == '(') return 0; 
    if (a == '*' || a == '/') return 1;
    if (b == '*' || b == '/') return 0; 
    return 1; 
}

//创建一个新的二叉树结点
node *create_node(char data) {
    node *new_node = (node *)malloc(sizeof(node)); 
    new_node->data = data;
    new_node->left = NULL; 
    new_node->right = NULL;
    return new_node; 
}

//创建一个新的栈元素
stack *create_stack(node *data) {
    stack *new_stack = (stack *)malloc(sizeof(stack)); //分配内存空间
    new_stack->data = data; //赋值数据域
    new_stack->next = NULL; //初始化指针域为空
    return new_stack; //返回新栈元素的指针
}

//判断栈是否为空
int is_empty(stack *s) {
    return s == NULL; 
}

//入栈操作
void push(stack **s, node *data) {
    stack *new_stack = create_stack(data); 
    new_stack->next = *s; 
    *s = new_stack; 
}

//出栈操作
node *pop(stack **s) {
    if (is_empty(*s)) return NULL;
    stack *temp = *s; 
    node *data = temp->data; 
    *s = temp->next; 
    free(temp); 
    return data; 
}

//获取栈顶数据，不改变栈的状态
node *peek(stack *s) {
    if (is_empty(s)) return NULL; 
    return s->data; 
}

//将中缀表达式转换为后缀表达式，并构造二叉树
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

//中序遍历二叉树，输出表达式
void inorder_traverse(node *root) {
    if (root == NULL) return; 
    if (is_operator(root->data)) printf("("); 
    inorder_traverse(root->left); 
    printf("%c", root->data); 
}
//后序遍历二叉树，输出表达式
void postorder_traverse(node *root) {
    if (root == NULL) return; 
    postorder_traverse(root->left); 
    postorder_traverse(root->right); 
    printf("%c", root->data);
}

//计算表达式的值
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

//主函数
int main() {
    char infix[100]; 
    printf("请输入一个算术表达式：\n"); 
    scanf("%s", infix); 
    node *root = convert(infix); 
    printf("中序遍历二叉树，输出表达式：\n");
    inorder_traverse(root); 
    printf("\n");
    printf("后序遍历二叉树，输出表达式：\n");
    postorder_traverse(root); 
    printf("\n");
    printf("表达式的值为：\n"); 
    printf("%d\n", evaluate(root)); 
    return 0; 
}

