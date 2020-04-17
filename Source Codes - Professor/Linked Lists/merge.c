#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};

void display(struct node*);
void insert_order(struct node**,int);
void createlist(struct node**);
void merge(struct node*,struct node*,struct node**);
int main()
{
  struct node *first,*second,*third;
  first=NULL;
  second=NULL;
  third=NULL;
 printf("Creating the first List..\n");
 createlist(&first);
 display(first);
 printf("\nCreating the second List..\n");
 createlist(&second);
 display(second);
 printf("\nMerging the lists..\n");
 merge(first,second,&third);
 display(third);
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

void createlist(struct node**p)
{
  int x;
  while(1)
  {
    printf("\nEnter the number..\n");
    scanf("%d",&x);
     if(x==0)
       break;
    insert_order(p,x);
  }
}

void insert_order(struct node** p,int x)
 {
  struct node *temp,*prev,*q;

  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->next=NULL;

  q=*p;//copy address of the first node
  prev=NULL;

  while((q!=NULL)&&(x>q->data))
  {
    prev=q;
    q=q->next;
  }
  if(q!=NULL)//position found,x<q->data
  {
   if(prev==NULL)//first position, insert as the first node
    { temp->next=q;
    *p=temp;
    }
   else//insert somewhere in middle
   {
    prev->next=temp;
    temp->next=q;
   }
  }
  else//q==NULL,
  {
    if(prev==NULL)//empty list,insert the node as the first node 
      *p=temp;
    else
     prev->next=temp;//insert at the end of the list
 }
}
  
void insert_tail(struct node **p, int x)
  {

   struct node *temp, *q;
    //create node
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data = x;
     temp->next=NULL;

     //if list empty
     if(*p==NULL)
       *p=temp;
     else
     {
       q=*p;//copy the address of teh first node of the list
     //keep moving till you stop at the last node
      while(q->next!=NULL)
       q=q->next;
      
      q->next=temp;//link the last node to new node
     }
  }
   

void merge(struct node* p,struct node* q,struct node** t)
{
  while((p!=NULL)&&(q!=NULL))
  {
    if(p->data <= q->data)
    {
      insert_tail(t,p->data);
      p=p->next;
    }
   else
   {
     insert_tail(t,q->data);
      q=q->next;
   }
  }
  if(p==NULL)//end of the first list
  {
    while(q!=NULL)//copy all the elements of the second list
    {
      insert_tail(t,q->data);
      q=q->next;
    }
  }
  else// q==NULL end of the second list
  {
    while(p!=NULL)//copy all the elements of the first list
    {
      insert_tail(t,p->data);
      p=p->next;
     }
   }
}



