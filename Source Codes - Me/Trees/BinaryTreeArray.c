#include <stdio.h>
#include <stdlib.h>
void create(int*,int);
void init(int*);
void preorder(int*,int);
void postorder(int*,int);
void inorder(int*,int);
int heighttest(int*,int);
int height(int*,int);
int leaves(int*,int);
int max(int,int);
int count(int*,int);
int compare(int*,int*,int);
int leaf = 0;
int main()
{
    int *tree = (int*)malloc(sizeof(int)*1000);
    init(tree);
    create(tree,1);
    //preorder(tree,1);
    //postorder(tree,1);
    //inorder(tree,1);
    //printf("Height/Levels = %d\n",height(tree,1));
    //printf("Leaf nodes = %d\n",leaves(tree,1));
    //printf("Total nodes = %d\n",count(tree,1));

    #if 0
    int *tree2 = (int*)malloc(sizeof(int)*1000);
    init(tree2);
    create(tree2,1);
    printf("Equal = %d\n", compare(tree,tree2,1));
    #endif
}
void init(int *t)
{
    for (int i =0;i<1000;i++)
        t[i]=-1;
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
void preorder(int *t, int i)
{
    if(t[i]!=-1)
    {
        printf("%d->",t[i]);
        preorder(t,2*i);
        preorder(t,2*i+1);
    }
}
void postorder(int *t, int i)
{
    if(t[i]!=-1)
    {
        postorder(t,2*i);
        postorder(t,2*i+1);
        printf("%d->",t[i]);
    }
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
int height(int *t, int i)
{
    if (t[i]==-1)
        return 0;
    else
    {
        return 1 + max(height(t,2*i),height(t,2*i+1));
    } 
}
int max(int a, int b)
{
    return (a>b?a:b);
}
int leaves(int *t, int i)
{
    if (t[i]==-1);
    else if(t[2*i]==-1 && t[2*i+1]==-1)
        leaf++;
    else
    {
        leaves(t,2*i);
        leaves(t,2*i+1);
        return leaf;
    }
}
int count(int *t, int i)
{
    if(t[i]==-1)
        return 0;
    else
    {
        return (1+count(t,2*i)+count(t,2*i+1));
    }
}
int compare(int *t1, int*t2, int i)
{
    if(t1[i]==-1 && t2[i]==-1)
        return 1;
    else if (t1[i]!=-1 && t2[i]!=-1)
    {
        if (t1[i]==t2[i])
            return (compare(t1,t2,2*i) && compare(t1,t2,2*i));
        else
            return 0;
    }
    else
        return 0; 
}

