#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* next;
};

int main()
{
  struct node* first;
  int ch,x,y;
  void insert_tail(struct node **, int);
  void insert_head(struct node **, int);
  void display(struct node*);  
  void delete_node(struct node **,int);  
  void delete_pos(struct node **,int);  
  void reverse(struct node **);
  void insert_pos(struct node **, int,int);
  first=NULL;

  while(1)
  {
    display(first);
    printf("\n1..Insert tail\n");
    printf("2..Insert head\n");
    printf("3..Display\n");
    printf("4..delete a node \n");
    printf("5..Delete at position\n");
    printf("6..reverse list..\n");
    printf("7..insert position\n");
    printf("8..Exit\n");

    scanf("%d",&ch);

    switch(ch)
    {
       case 1:printf("Enter the number\n");
              scanf("%d",&x);
              insert_tail(&first,x);
              break;
     case 2:printf("Enter the number\n");
              scanf("%d",&x);
              insert_head(&first,x);
              break;
      case 3:display(first);
             break;
      case 4:printf("Enter the value of the element\n");
              scanf("%d",&x);
              delete_node(&first,x);
              break;
      case 5:printf("Enter the position\n");
              scanf("%d",&x);
              delete_pos(&first,x);
              break;
      case 6:reverse(&first);
             break;
      case 7:printf("Enter the value and the position\n");
              scanf("%d %d",&x,&y);
              insert_pos(&first,x,y);
              break;

     }
  }
}

void insert_tail(struct node **p, int x)
  {
     struct node *temp,*q;
    //create a node

     temp=malloc(sizeof(struct node));
     temp->data = x;
     temp->next=NULL;

     //if it is the first node 
     if(*p==NULL)
     *p=temp;
    else
     {
       q=*p;//copy the first node's address       
       //go to the last node
       while(q->next!=NULL)
         q=q->next;
       q->next=temp;//link the new node to the last node
     }
 }

  void insert_head(struct node** p, int x)
  {
    struct node *temp;
    //create a node
    temp=malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    
    if(*p==NULL)//if this is first node
      *p=temp;  
    else
      {
        temp->next=*p;//link with the first node
         *p=temp; // update first with address of the newly added node
      }

  }

  void display(struct node *q)
  {
    if(q==NULL)
      printf("\nThe list is empty\n"); 
    else
      {
        //move forward till you go beyond the last node
        while(q!=NULL)
        {
          printf("%d->",q->data);
          q=q->next;//go to the next node
        }
      }            
  }

void reverse(struct node **p)
  {
    struct node *curr, *prev, *temp;
    prev=NULL;
    curr=*p;//point to the first node

    while(curr!=NULL)
    {
    temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
    *p=prev;//modify first
 }
   
void delete_node(struct node **p, int x)
  {
    struct node *prev, *q;
    prev=NULL;
    q=*p; //copy the address of the first node

    //move forward until the node to be deleted is found
   // or the you go beyond the last node

   while((q!=NULL)&&(q->data!=x))
   {
      prev=q;
      q=q->next;
   }
  if(q==NULL)
   printf("\nNode is not found..\n");
  else if(prev==NULL)//fisrt node to be deleted
   *p=q->next;//copy second node's address into first
  else
   prev->next=q->next;
  free(q);
  }

/*void insert_pos(struct node **p, int x, int pos)
  {
   int i;
   struct node* prev, *temp, *q;

   //create a node

   temp=malloc(sizeof(struct node));
   temp->data=x;
   temp->next=NULL;

   q=*p;
   prev=NULL;
   i=1;
   while((q!=NULL)&&(i<pos))
   {
     prev=q;
     q=q->next;
    i++;
  }
   
  if(q!=NULL)
  {
    if(prev==NULL)//first position
    {
      temp->next=q;
       *p=temp;
    }
    else//some where in the middle
    {
      prev->next=temp;
      temp->next=q;
    }
   }
  else//q==NULL
  {
     if(i==pos)
     {
       if(prev==NULL)//list empty, first node inserted if pos =1
          *p=temp;
      else
        prev->next=temp;//insert at end
     }
    else
      printf("Invalid position");
  }
 }

      
  void delete_pos(struct node **p, int pos)
  {
    struct node *prev, *q;
    int i;

    q=*p;
    i=1;
    prev=NULL;
    //move forward unitl the position is found
    while((q!=NULL)&&(i<pos))
    {
      prev=q;
      q=q->next;
      i++;
    }
    if(q==NULL)
      printf("Invalid position");
    else if(prev==NULL)//first position
      *p=q->next;//copy address of second node in first.
    else
      prev->next=q->next;
    free(q);
  }*/


  
 //deleting all the ocuurances of a node
  /*void delete_node(struct node **p, int x)
  {
    struct node *prev, *q,*temp;
    prev=NULL;
    q=*p;

    while(q!=NULL)
    {
      if(q->data==x)
      {
        temp=q;
        if(prev==NULL)//deleting the first node
        {
          *p=q->next;
           q=*p;
        }
       else
        {
        prev->next=q->next;
        q=q->next;
         }
       free(temp);
       }        
   else
      { 
        prev=q;
        q=q->next;
      }
    }
 }*/

  
  
  /*void delete_node(struct node **p,int x)
  {
    struct node *prev,*q,*temp;;
    q=*p;
    prev=NULL;
    while(q!=NULL)
    {
      if(q->data==x)
      {
       temp=q;
       if(prev==NULL)
       {
        *p=q->next;
         q=*p;
        }
       else
       {
        prev->next=q->next;
        q=q->next;
       }
       free(temp);
     }
     else
      {
        prev=q;
        q=q->next;
      }
    }
    printf("done..\n");
   }*/





 



















































 

    





   
      











    
