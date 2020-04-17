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
int checksum(NODE*,int,int);
int sum;
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    init(t);
    preorder(t->head);
    printf("\nEnter sum : ");
    int count;
    scanf("%d",&count);
    sum = 0;
    printf("Found = %d\n",checksum(t->head,sum,count));
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

int checksum(NODE* node, int sum, int count)
{
    if (node==NULL) return 0;
    sum+= node->data;
    if(node->left==NULL && node->right==NULL)
    {
        if(sum==count) 
        {
            sum-=node->data;
            return 1;
        }
        else
        {
            sum-=node->data;
            return 0;
        }
    }
    else
    {
        sum-=node->data;
        return (checksum(node->left,sum,count)||checksum(node->right,sum,count));
    }
}