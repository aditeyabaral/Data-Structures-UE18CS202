//program to implement seperate chaining
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   int key;
   char name[100];
   struct node *next;
};

struct hash
{
  struct node *head;
  int count;
};

 void display(struct hash *, int);
 void insert_to_hash(struct hash *,int,int, char *);
 void delete_from_hash(struct hash*,int,int);
 void search_in_hash(struct hash *ht,int size,int key);
int main()
{
  struct hash *hashtable;
  int i,n,ch,key;
  char name[100];
  int tablesz;
  printf("Enter the table size..");
  scanf("%d",&tablesz);
  //create hash table
  hashtable=malloc(tablesz* sizeof(struct hash));
  for(i=0;i<tablesz;i++)
  {
    hashtable[i].head=NULL;
    hashtable[i].count=0;
  }
  while(1)
  {
    printf("\n1. Insert..");
    printf("\n2. Delete..");
    printf("\n3. Search..");
    printf("\n4. Display..");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter key..\n");
              scanf("%d",&key);
              printf("Enter name..\n");
              scanf("%s",name);
              insert_to_hash(hashtable,tablesz,key,name);
              break;
      case 2: printf("Enter the key for deletion..\n");
               scanf("%d",&key);
               delete_from_hash(hashtable,tablesz,key);
               break;
      case 3: printf("Enter the key to search..\n");
               scanf("%d",&key);
               search_in_hash(hashtable,tablesz,key);
               break;
        case 4:display(hashtable,tablesz);
    }
  }
 
}

 void  delete_from_hash(struct hash * ht,int size,int key)
  {

   struct node *prev,*temp;
   int index;
 
   index =key % size; //hash function
   
   prev=NULL;

   temp=ht[index].head;
   while((temp!=NULL)&&(temp->key!=key))
   {
     prev=temp;
     temp=temp->next;
    }
  if(temp!=NULL)//key found
  {
   if(prev==NULL)//first node
     ht[index].head=temp->next;
   else
     prev->next=temp->next;
   free(temp);
   }
 else
   printf("The record not found..\n");
 }

 
 void insert_to_hash(struct hash *ht, int size, int key, char*name)
 {
   int index;
   struct node *temp;

   temp=malloc(sizeof(struct node));
   temp->key=key;
   strcpy(temp->name,name);
   temp->next=NULL;


   index=key%size;//hash function

   temp->next=ht[index].head;
   ht[index].head=temp;
   ht[index].count++;
}


 void display(struct hash* ht, int size)
 {
    int i;
    struct node *temp;
   printf("\n");
   for(i=0;i<size;i++)
   {
     printf("%d :",i);
     if(ht[i].head!=NULL)
     {
        temp=ht[i].head;
        while(temp!=NULL)
        {
          printf("%d ",temp->key);
          printf("%s->",temp->name);
          temp=temp->next;
        }
      }
    printf("\n");
   }
  }


 void search_in_hash(struct hash *ht,int sz,int key)
 {
    int index;
   struct node *temp, *prev;

   index=key%sz;

   temp=ht[index].head;
   

   while((temp!=NULL)&&(temp->key!=key))
        temp=temp->next;
   
   if(temp!=NULL)
   {
     printf("\nRecord found..Details are..\n");
     printf("Key : %d ",temp->key);
     printf("Name : %s",temp->name);     
   }
   else
    printf("record not found..\n");
  }













