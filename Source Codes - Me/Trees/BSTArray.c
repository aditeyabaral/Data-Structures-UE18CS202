#include <stdio.h>
#include <stdlib.h>
void init(int*);
void insert(int*,int);
void inorder(int*,int);
int minimum(int*);
int maximum(int*);
int main()
{
    int *tree = (int*)malloc(sizeof(int)*1000);
    init(tree);
    int x;
    while(1)
    {
        printf("Enter node : ");
        scanf("%d",&x);
        if(x==-1)
            break;
        insert(tree,x);
    }
    inorder(tree,1);
    printf("\nMaximum = %d\n",maximum(tree));
    printf("Minimum = %d\n",minimum(tree));
}
void init(int *tree)
{
    for(int i=0;i<1000;i++)
        tree[i]=-1;
}
void insert(int *t, int x)
{
    int i=1;
    while(t[i]!=-1)
    {
        if(x>t[i])
            i=2*i+1;
        else
            i=2*i;
    }
    t[i]=x;
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
int maximum(int *t)
{
    int i = 1; int k;
    while(t[i]!=-1)
    {
        k = t[i];
        i=2*i+1;
    }
    return k;
}
int minimum(int *t)
{
    int i = 1,k;
    while(t[i]!=-1)
    {
        k = t[i];
        i=2*i;
    }
    return k;
}