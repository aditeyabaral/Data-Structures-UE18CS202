#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;
typedef struct tree
{
    NODE *head;
}TREE;
void inorder(NODE*);
void insert(TREE*,int);
NODE* recursiveInsert(NODE*,int);
int smallest(NODE*);
int largest(NODE*);
int search(TREE*,int);
NODE *delete(TREE*,int);
void deleteVinay(TREE*,int);
void insertVinay(TREE*,NODE*);
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    t->head = NULL;
    int x;
    while(1)
    {
        printf("Enter node :");
        scanf("%d",&x);
        if(x==-1)
            break;
        insert(t,x);
        //recursiveInsert(t->head,x);
    }
    inorder(t->head);
    //printf("\nLargest node = %d", largest(t->head));
    //printf("\nSmallest node = %d",smallest(t->head));
    //printf("\nEnter element to search : ");
    int s;
    //scanf("%d",&s);
    //printf("Found = %d\n",search(t,3));

    printf("\nEnter value to delete : ");
    scanf("%d",&s);
    deleteVinay(t,s);
    printf("%d\n",t->head->right==NULL);
    inorder(t->head);
}
void insert(TREE *t,int n)
{
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    if(t->head==NULL)
        t->head = temp;
    else
    {
        NODE *pres = t->head;
        NODE *prev = NULL;
        while(pres!=NULL)
        {
            prev = pres;
            if(n<pres->data)
                pres = pres->left;
            else
                pres = pres->right;
        }
        if (n<prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }
}
NODE* recursiveInsert(NODE *node, int x)
{
    if(node==NULL)
    {
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        temp->data = x;
        temp->right = NULL;
        temp->left = NULL;
        return temp;
    }
    if (x<node->data)
        node->left = recursiveInsert(node->left,x);
    else
        node->right = recursiveInsert(node->right,x);
    return node;
    
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
int smallest(NODE *node)
{
    if(node==NULL);
    else
    {
        while(node->left!=NULL)
            node = node->left;
        return node->data;
    }
}
int largest(NODE *node)
{
    if(node==NULL);
    else
    {
        while(node->right!=NULL)
            node=node->right;
        return node->data;
    }
}
int search(TREE *t, int x)
{
    NODE *pres = t->head;
    while(pres!=NULL)
    {
        if(pres->data==x)
            return 1;
        else if(x<pres->data)
            pres = pres->left;
        else
            pres = pres->right;
    }
    return 0;
}
int recursiveSearch(NODE *node, int key)
{
    int lfound, rfound;
    if(node==NULL)
        return 0;
    else if (node->data==key)
        return 1;
    else if(key<node->data)
        lfound = recursiveSearch(node->left,key);
    else if (key>node->data)
        rfound = recursiveSearch(node->right,key);
    return (lfound || rfound);
}
NODE* delete(TREE *t, int key)
{
    NODE *pres = t->head;
    NODE *prev = NULL;
    NODE *child = NULL;
    while(pres!=NULL && pres->data!=key)
    {
        prev = pres;
        if(key<pres->data)
            pres = pres->left;
        else
            pres = pres->right;
    }
    if(pres==NULL)
        printf("Not found.\n");
    else
    {
        if(pres->left==NULL || pres->right==NULL)
        {
            if (pres->left=NULL)
                child = pres->right;
            else
                child = pres->left;

            if(prev==NULL)
                return child;
            else if(pres == prev->left)
                prev->left = child;
            else
                prev->right = child;
            free(pres);
        }
        else
        {
            NODE *p = NULL;
            NODE *temp = pres->right;
            while(temp->left!=NULL)
            {
                p = temp;
                temp=temp->left;
            }
            pres->data = temp->data;
            if(p!=NULL)
                p->left = temp->right;
            else
                pres->right = temp->right;
            free(temp);
        } 
    }
    return t->head;
}
