//program to implement Linear probling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct element
{
   int key;
   char name[100];
   int mark;
};
void display(struct element *, int);
void insert_to_hash(struct element*, int, int, char*, int*);
void delete_from_hash(struct element *,int ,int ,int *);
void search_in_hash(struct element *,int ,int key,int );
int main()
{
  struct element *hashtable;
  int i,n,ch,key,no_elements;
  char name[100];
  int tablesz;
  printf("Enter the table size..");
  scanf("%d",&tablesz);
  //create hash table
  hashtable=malloc(tablesz* sizeof(struct element));
   for(i=0;i<tablesz;i++)
     hashtable[i].mark=0;
   no_elements=0;
  
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
              insert_to_hash(hashtable,tablesz,key,name,&no_elements);
              break;
       case 2: printf("Enter the key for deletion..\n");
               scanf("%d",&key);
               delete_from_hash(hashtable,tablesz,key,&no_elements);
               break;
        case 3: printf("Enter the key to search..\n");
               scanf("%d",&key);
               search_in_hash(hashtable,tablesz,key,no_elements);
               break;
        case 4:display(hashtable,tablesz);
    }
  }
 
}

 void search_in_hash(struct element *ht,int size,int key,int count)
  {
    int i,index;
    if(count==0)
    {
     printf("table empty..\n");
     return;
     }
     index = key % size;
     i=0;
     while((ht[index].key!=key) && (i<count))
     {
       index=(index+1)%size;
       if(ht[index].mark==1)
          i++;
     }
     if(ht[index].key==key)
     {
       printf("\nkey found..Details are..\n");       
       printf("Key = %d, name = %s",ht[index].key,ht[index].name);
     }
     else
      printf("Key not found");
     return;
  }


  void delete_from_hash(struct element *ht,int size,int key,int *count)
  {
    int i,index;
    printf("count = %d\n",*count);
    if(*count==0)
    {
     printf("table empty..\n");
     return;
     }
     index = key % size;
     i=0;
     while((ht[index].key!=key) && (i<*count))
     {
       index=(index+1)%size;
       if(ht[index].mark==1)
          i++;
     }
     if(ht[index].key==key)
     {
       ht[index].mark=0;
       (*count)--;
     }
     else
      printf("Key not found");
     return;
  }



 
  void display(struct element *ht, int size)
  {
    int i;
    for(i=0;i<size;i++)
    {
      printf("%d :", i);
      if (ht[i].mark!=0)
         printf("Key = %d, name = %s",ht[i].key,ht[i].name);
      printf("\n");
    }
  }  

  


 void insert_to_hash(struct element*ht, int size, int key, char *name, int *count)
   {
      int index;
     if(size==*count)
    {
      printf("Table full.. cannot insert\n");
      return;
    }
     index=key %size;

     while(ht[index].mark!=0)
        index=(index +1)%size;

    ht[index].key=key;
    strcpy(ht[index].name,name);
    ht[index].mark=1;

    (*count)++;
    return;
  }



     
