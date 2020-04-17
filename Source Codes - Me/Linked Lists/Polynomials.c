#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coeff;
    int x;
    int y;
    struct node *link;
};
typedef struct node NODE;
struct list
{
    NODE *head;
};
typedef struct list LIST;
void insert(LIST*,int,int,int);
void display(LIST*);
LIST* add(LIST*,LIST*);
int eval(LIST*);
int main()
{
    LIST *l1 = (LIST*)malloc(sizeof(LIST));
    LIST *l2 = (LIST*)malloc(sizeof(LIST));
    l1->head = NULL;
    l2->head = NULL;
    int cof,x,y;
    printf("Polynomial 1 - \n");
    while(1)
    {
        printf("Enter coefficient, x and y power : ");
        scanf("%d %d %d",&cof,&x,&y);
        if(cof==0) break;
        insert(l1,cof,x,y);
    }
    printf("Polynomial 2 - \n");
    while(1)
    {
        printf("Enter coefficient, x and y power : ");
        scanf("%d %d %d",&cof,&x,&y);
        if(cof==0) break;
        insert(l2,cof,x,y);
    }
    display(l1);
    display(l2);
    LIST *l3 = add(l1,l2);
    display(l3);
}
void insert(LIST *l, int cof, int x, int y)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->coeff = cof;
    node->x = x;
    node->y = y;
    node->link = NULL;
    if(l->head == NULL)
        l->head = node;
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        int flag = 0;
        while (pres!=NULL)
        {
            if(pres->x==x && pres->y==y)
            {
                pres->coeff+=cof;
                flag = 1;
                break;
            }
            prev = pres;
            pres = pres->link;
        }
        if (flag==0)
        {
            prev->link = node;
            node->link = pres;
        }
    }
}
void display(LIST *l)
{
    NODE *node = l->head;
    while(node!=NULL)
    {
        printf("%dx^%dY^%d + ",node->coeff,node->x,node->y);
        node = node->link;
    }
    printf("\n");
}
int eval(LIST* l)
{
    int sum = 0;
    NODE *node = l->head;
    int x,y;
    printf("Enter value of x and y : ");
    scanf("%d %d",&x,&y);
    while(node!=NULL)
    {
        sum = sum + node->coeff*pow(x,node->x)*pow(y,node->y);
        node = node->link;
    }
    return sum;
}
LIST* add(LIST *l1, LIST* l2)
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    l->head = NULL;
    int cof,x,y;
    NODE *pres1 = l1->head;
    while(pres1!=NULL)
    {
        insert(l,pres1->coeff,pres1->x,pres1->y);
        pres1 = pres1->link;
    }
    pres1 = l2->head;
    while(pres1!=NULL)
    {
        insert(l,pres1->coeff,pres1->x,pres1->y);
        pres1 = pres1->link;
    }
    return l;
}