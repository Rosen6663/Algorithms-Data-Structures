#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
//定义哈夫曼树结点结构体
typedef struct node {
    int weight; 
    int parent; 
    int left; 
    int right; 
} node;

//定义哈夫曼编码结构体
typedef struct code {
    char *bits; 
    int len; 
} code;

//选择 
void select(node *tree, int n, int *s1, int *s2) {
    int min1 = 0, min2 = 0; 
    int i = 1; 

    while (tree[i].parent != 0 && i <= n) {
        i++;
    }
    min1 = tree[i].weight;
    *s1 = i; 
    i++; 
    
    while (tree[i].parent != 0 && i <= n) {
        i++;
    }
    
    if (tree[i].weight < min1) {
        min2 = min1;
        *s2 = *s1;
        min1 = tree[i].weight;
        *s1 = i;
    } else {
        min2 = tree[i].weight;
        *s2 = i;
    }
    i++; 
   
    for (; i <= n; i++) {
        
        if (tree[i].parent != 0) {
            continue;
        }
      
        if (tree[i].weight < min1) {
            min2 = min1;
            *s2 = *s1;
            min1 = tree[i].weight;
            *s1 = i;
        }
        else if (tree[i].weight >= min1 && tree[i].weight < min2) {
            min2 = tree[i].weight;
            *s2 = i;
        }
    }
}

//构造哈夫曼树
node *create_huffman_tree(int *freq, int n) {
    if (n <= 0) return NULL; 
    int m = 2 * n - 1; 
    node *tree = (node *)malloc((m + 1) * sizeof(node)); 
    
    for (int i = 1; i <= n; i++) {
        tree[i].weight = freq[i - 1];
        tree[i].parent = 0; 
        tree[i].left = 0; 
        tree[i].right = 0; 
    }
    
    for (int i = n + 1; i <= m; i++) {
        tree[i].weight = 0;
        tree[i].parent = 0;
        tree[i].left = 0;
        tree[i].right = 0;
    }

    for (int i = n + 1; i <= m; i++) {
        int s1, s2; 
        select(tree, i - 1, &s1, &s2); 
        tree[s1].parent = i; 
        tree[s2].parent = i; 
        tree[i].left = s1; 
        tree[i].right = s2; 
        tree[i].weight = tree[s1].weight + tree[s2].weight; 
    }
    return tree;
}

//根据哈夫曼编码
code *create_huffman_code(node *tree, int n) {
    if (tree == NULL || n <= 0) return NULL; 
    code *codes = (code *)malloc(n * sizeof(code)); 
    char *temp = (char *)malloc(n * sizeof(char)); 
    temp[n - 1] = '\0'; 

    for (int i = 1; i <= n; i++) {
        int start = n - 1; 
        int current = i; 
        int parent = tree[i].parent; 
        
        while (parent != 0) {
           
            if (tree[parent].left == current) {
                temp[--start] = '0';
            } else {
                temp[--start] = '1';
            }
          
            current = parent;
            parent = tree[parent].parent;
        }
      
        codes[i - 1].bits = (char *)malloc((n - start) * sizeof(char));
       
        strcpy(codes[i - 1].bits, &temp[start]);
       
        codes[i - 1].len = n - start;
    }
   
    free(temp);
    //返回编码数组的指针
    return codes;
}

//打印各部门的内线电话号码
void print_huffman_code(code *codes, int n) {
    if (codes == NULL || n <= 0) return; 
    printf("各部门的内线电话号码如下：\n");
 
    for (int i = 0; i < n; i++) {
        printf("部门%d的号码是：%s\n", i + 1, codes[i].bits);
    }
}


//主函数
int main() {
    int freq[] = {5, 20, 10, 12, 8, 43, 5, 6, 9, 15, 19, 32}; 
    int n = 12; 
    node *tree = create_huffman_tree(freq, n); 
    code *codes = create_huffman_code(tree, n); 
    print_huffman_code(codes, n);
    return 0; 
}

