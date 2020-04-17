#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int rthread;
    int lthread;
};
typedef struct node NODE;
struct tree
{
    NODE* root;
};
typedef struct tree TREE;
void insert(TREE*,int);
void preorder(NODE*);
void postorder(NODE*);
void inorder(TREE*);
NODE* inordersuccessor(NODE*);
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    t->root = NULL;
    int x;
    while(1)
    {
        printf("Enter node : ");
        scanf("%d",&x);
        if(x==-1) break;
        insert(t,x);
    }
    preorder(t->root);
    printf("\n");
    inorder(t);
    printf("\n");
    postorder(t->root);
}
void insert(TREE *t, int x)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    node->lthread = 1;
    node->rthread = 1;
    if(t->root==NULL)
        t->root = node;
    else
    {
        NODE *pres = t->root;
        while(pres!=NULL)
        {
            if(x>pres->data)
            {
                if(pres->rthread==0)
                    pres = pres->right;
                else
                    break;
            }
            else
            {
                if(pres->lthread==0)
                    pres = pres->left;
                else
                    break;
            }
        }
        if(x<pres->data)
        {
            node->left = pres->left;
            node->right = pres;
            pres->lthread = 0;
            pres->left = node;
        }
        else
        {
            node->right = pres->right;
            node->left = pres;
            pres->right = node;
            pres->rthread = 0;
        }
    }
}
void inorder(TREE *t)
{
    NODE *pres = t->root;
    if(pres==NULL) return;
    while(pres->lthread==0)
        pres = pres->left;
    while(pres!=NULL)
    {
        printf("%d ",pres->data);
        pres = inordersuccessor(pres);
    }
}
NODE* inordersuccessor(NODE* node)
{
    if(node->rthread) return node->right;
    node = node->right;
    while(node->lthread==0)
        node = node->left;
    return node;
}
