#include <stdio.h>
#include <stdlib.h>
struct rownode
{
    int row;
    struct rownode *rlink;
    struct columnnode *clink;
};
typedef struct rownode ROWNODE;
struct columnnode
{
    int column, value;
    struct columnnode *link;
};
typedef struct columnnode COLNODE;
struct row
{
    ROWNODE *head;
};
typedef struct row ROW;
struct column
{
    COLNODE *head;
};
typedef struct column COL;
void init(ROW*, int);
void display(ROW*);
void insert(ROW*, int, int, int);
int main()
{
    int m,n;
    printf("Enter rows and columns : ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i<m;i++)
    {
        for (int j = 0;j<n;j++)
        {
            printf("Enter element : ");
            scanf("%d", &a[i][j]);
        }
    }
    ROW *l = (ROW*)malloc(sizeof(ROW));
    init(l, m);
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            insert(l,a[i][j],i,j);
        }
    }
    display(l);
}
void init(ROW *l, int m)
{
    ROWNODE *node = (ROWNODE*)malloc(sizeof(ROWNODE));
    node->row = 0;
    node->rlink = NULL;
    node->clink = NULL;
    l->head = node;
    ROWNODE *pres = l->head;
    pres->row = 0;
    pres->clink = NULL;
    int ctr = 1;
    while(ctr!=m)
    {
        ROWNODE *temp = (ROWNODE*)malloc(sizeof(ROWNODE));
        temp->clink = NULL;
        temp->row = ctr;
        pres->rlink = temp;
        pres = temp;
        ctr+=1;
    }
    pres->rlink = NULL;
}
void insert(ROW *l, int val, int m, int n)
{
    if(val!=0)
    {
        ROWNODE *node = l->head;
        int ctr = 0;
        while(ctr!=m)
        {
            node = node->rlink;
            ctr+=1;
        }
        COLNODE *temp = (COLNODE*)malloc(sizeof(COLNODE));
        temp->value = val;
        temp->column = n;
        temp->link=NULL;
        if (node->clink == NULL)
        {
            COL *cl = (COL*)malloc(sizeof(COL));
            cl->head = temp;
            node->clink = temp;
        }
        else
        {
            COLNODE *pres = node->clink;
            COLNODE *prev = NULL;
            while(pres!=NULL)
            {
                prev = pres;
                pres = pres->link;
            }
            prev->link = temp;
            temp->link = NULL;
        } 
    }
}
void display(ROW *l)
{
    ROWNODE *node = l->head;
    while(node!=NULL)
    {
        COLNODE *temp = node->clink;
        printf("%d->",node->row);
        while(temp!=NULL)
        {
            printf("%d,%d->", temp->column,temp->value);
            temp = temp->link;
        }
        printf("\n");
        node = node->rlink;
    }
}