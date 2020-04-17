#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node* link;
};
typedef struct node NODE;
struct list
{
    NODE *head;
};
typedef struct list LIST;
void init(LIST*);
int length(LIST*);
void sum(LIST*,LIST*,LIST*);
void display(LIST*);
void insert(LIST*,int);
int main()
{
    LIST *l1 = (LIST*)malloc(sizeof(LIST));
    LIST *l2 = (LIST*)malloc(sizeof(LIST));
    LIST *l3 = (LIST*)malloc(sizeof(LIST));
    init(l1);
    init(l2);
    init(l3);
    printf("Enter number 1 : ");
    char ch;
    while((ch=getchar())!='\n')
    {
        insert(l1,ch-48);
    }
    printf("Enter number 2 : ");
    while((ch=getchar())!='\n')
    {
        insert(l2,ch-48);
    }
    printf("Sum = \n");
    sum(l1,l2,l3);
    display(l3);
}
void init(LIST *l)
{
    l->head=NULL;
}
void insert(LIST *l, int val)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->key = val;
    node->link = NULL;
    if(l->head==NULL)
    {
        l->head = node;
    }
    else
    {
        node->link = l->head;
        l->head = node;
    }
}
void sum(LIST *l1, LIST *l2, LIST *l3)
{
    LIST *num1, *num2;
    if(length(l1)>length(l2))
    {
        num1 = l1;
        num2 = l2;
    }
    else
    {
        num1 = l2;
        num2 = l1;
    }
    NODE *pres1 = num1->head;
    NODE *pres2 = num2->head;
    int carry=0, sum;
    while(pres2!=NULL)
    {
        sum = pres1->key+pres2->key;
        carry = 0;
        if(sum>9)
        {
            carry = sum/10;
            sum = sum%10;
        }
        insert(l3,sum);
        pres1->link->key+=carry;
        pres1 = pres1->link;
        pres2=pres2->link;
    }
    while(pres1->link!=NULL)
    {
        if(pres1->key>9)
        {
            insert(l3,pres1->key%10);
            pres1->link->key+=pres1->key/10;
        }
        insert(l3,pres1->key);
        pres1 = pres1->link;
    }
    if(pres1->key>9)
    {
        insert(l3,pres1->key%10);
        insert(l3,pres1->key/10);
    }
    else
        insert(l3,pres1->key);
}
int length(LIST*l)
{
    int ctr = 0;
    if (l->head == NULL)
        return 0;
    else
    {
        NODE *node = l->head;
        while (node!=NULL)
        {
            ctr++;
            node = node->link;
        }
        return ctr;
    }
}
void display(LIST* l)
{
    NODE* node = l->head;
    while(node!=NULL)
    {
        printf("%d",node->key);
        node = node->link;
    }
    printf("\n");
}