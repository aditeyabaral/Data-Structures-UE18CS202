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
int leaf = 0;
int len=0;
NODE *create();
void init(TREE*);
void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);
int height(NODE*);
int max(int,int);
int leafnode(NODE*);
int count(NODE*);
int compare(NODE*,NODE*);
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    init(t);
    preorder(t->head);
    //preorder(t->head);
    //inorder(t->head);
    printf("Levels/Height = %d\n", height(t->head));
    printf("Leaf nodes = %d\n",leafnode(t->head));
    printf("Total nodes = %d\n", count(t->head));

    #if 0
    TREE *t2 = (TREE*)malloc(sizeof(TREE));
    init(t2);
    printf("Equal = %d\n", compare(t->head,t2->head));
    #endif
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
void preorder(NODE *node)
{ 
    if(node!=NULL)
    {
        printf("%d->",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder(NODE *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d->",node->data);
        inorder(node->right);
    }
}
void postorder(NODE *node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d->",node->data);
    }
}
int height(NODE *node)
{
    if(node==NULL)
        return 0;
    else
        return 1+max(height(node->left),height(node->right));
}
int max(int a, int b)
{
    return (a>b ? a: b);
}
int leafnode(NODE *node)
{
    if(node==NULL);
    else if (node->left==NULL && node->right==NULL)
        leaf+=1;
    else
    {
        leafnode(node->left);
        leafnode(node->right);
        return leaf;
    } 
}
int count(NODE* node)
{
    if(node==NULL)
        return 0;
    else
    {
        int l = count(node->left);
        int r = count(node->right);
        return (l+r+1);
    } 
}
int compare(NODE *node1, NODE* node2)
{
    if(node1==NULL && node2==NULL)
        return 1;
    else if(node1!=NULL && node2!=NULL)
    {
        if(node1->data == node2->data)
            return (compare(node1->left,node2->left) && compare(node1->right,node2->right));
        else
            return 0;
    }
    else
        return 0;
}
