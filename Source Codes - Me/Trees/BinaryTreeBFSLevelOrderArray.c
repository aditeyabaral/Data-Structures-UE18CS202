#include <stdio.h>
#include <stdlib.h>
void init(int*);
void create(int*,int);
void bfs(int*,int);
void push(int);
int pop();
int empty();
void inorder(int*,int);
int q[1000];
int top = -1;
int main()
{
    int *tree = (int*)malloc(sizeof(int)*1000);
    init(tree);
    create(tree,1);
    //inorder(tree,1);
    bfs(tree,1);
}
void init(int *tree)
{
    for(int i=0;i<1000;i++)
        tree[i]=-1;
}
void create(int *t, int i)
{
    printf("Enter element :");
    int node;
    scanf("%d",&node);
    if(node==-1)
        return;
    t[i]=node;
    printf("Creating left subtree of %d :",node);
    create(t,2*i);
    printf("Creating right subtree of %d :",node);
    create(t,2*i+1);
}
void bfs(int *t, int i)
{
    push(t[i]);
    int x;
    while(top!=-1)
    {
        x = pop();
        printf("%d\n",top);
        printf("%d->",x);
        if(t[2*i]!=-1)
            push(t[2*i]);
        if(t[2*i+1]!=-1)
            push(t[2*i+1]);
    }
}
void push(int x)
{
    top++;
    q[top] = x;
}
int pop()
{
    int x = q[0];
    for(int i=0;i<top;i++)
        q[i] = q[i+1];
    top-=1;
    return x;
}
int empty()
{
    if (top==-1)
        return 1;
    else
        return 0;
}
void inorder(int *t, int i)
{
    if(t[i]!=-1)
    {
        inorder(t,2*i);
        printf("%d->",t[i]);
        inorder(t,2*i+1);
    }
}