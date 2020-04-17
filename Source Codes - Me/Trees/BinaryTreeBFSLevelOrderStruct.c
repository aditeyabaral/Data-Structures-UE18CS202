#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
struct tree
{
    NODE *head;
};
typedef struct tree TREE;
NODE *q[100];
int top = -1;
NODE *create();
void init(TREE*);
void bfs(NODE*);
void push(NODE*);
NODE* pop();
int empty();
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    t->head = create();
    bfs(t->head);
}
void init(TREE *t)
{
    t->head = create();
}
NODE *create()
{
    int x;
    printf("Enter element : ");
    scanf("%d", &x);
    if(x==-1)
        return NULL;
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = x;
    printf("Enter left sub tree of %d: ",x);
    node->left = create();
    printf("Enter right sub tree %d: ",x);
    node->right = create();
    return node;
}
void bfs(NODE *node)
{
    push(node);
    NODE *x;
    while (!empty())
    {
        x = pop(q);
        printf("%d->", x->data);
        if(x->left!=NULL)
            push(x->left);
        if(x->right!=NULL)
            push(x->right);
    }
}
void push(NODE *node)
{
    top++;
    q[top] = node;
}
NODE* pop()
{
    NODE *temp = q[0];
    for(int i=0;i<top;i++)
        q[i]=q[i+1];
    top--;
    return temp;
}
int empty()
{
    return (top==-1?1:0);
}