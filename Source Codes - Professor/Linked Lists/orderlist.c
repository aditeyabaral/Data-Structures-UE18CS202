#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};

void display(struct node*);
void insert_order(struct node**,int);
int main()
{
  struct node *first;
  int x;
   first=NULL;

  while(1)
  {
    printf("\nEnter the number..\n");
    scanf("%d",&x);
     if(x==0)
       break;
    insert_order(&first,x);
    display(first);
  }
}

 void display(struct node *p)
 {
   printf("The list..\n");
   while(p!=NULL)
   {
     printf("%d->",p->data);
     p=p->next;
   }
}

 void insert_order(struct node**p ,int x)
 {
  struct node *temp,*q,*prev;

  //create a node for x

   temp=malloc(sizeof(struct node));
   temp->data = x;
   temp->next=NULL;

   //search for the position
   q=*p;
   prev=NULL;
   while((q!=NULL)&&(x>=q->data))
   {
     prev=q;
     q=q->next;
    }
   if(q!=NULL)//position found 
   {
     if(prev==NULL)//x is lowest no, insert at front
     {
       temp->next=q;
       *p=temp;//copy the address of new node in first  
     }
    else
     {
       //insert between 2nd and last but one position
       //insert between prev and q
       prev->next=temp;
       temp->next=q;
    }
 }
 else//q==NULL
   {
     if(prev==NULL)//empty list ,x is the first one
      *p=temp;
     else
    //largest no, insert after the last node   
      prev->next=temp;
  } 
} 



























  











 

