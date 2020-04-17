//program to implement a threaded binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
  bool lthread;
  bool rthread;
};
struct tnode *insert(struct tnode *,int);

void inorder(struct tnode*);
struct tnode *inordersuccessor(struct tnode*);
void main()
{
  struct tnode *root;
  int ch,num,k;
  root=NULL;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2..Inorder Traversal.");
      printf("\n3.exit");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 root=insert(root,num);
                 break;
         
         case 2:printf("Inorder traversal..\n");
               inorder(root);
               break;

         case 3:exit(0);
       }
    }
  }    
    
  
 struct tnode* insert(struct tnode *t, int x)
 {
    struct tnode *curr, *prev,*temp;
    //prev=NULL;
    curr=t;
    temp=malloc(sizeof(struct tnode));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->rthread=true;
    temp->lthread=true;

    while(curr!=NULL)
    {
       if(x < curr->data)
       {
        if(curr->lthread==false)
          curr=curr->left;
        else
          break;
       }
      else
       {
         if(curr->rthread==false)
           curr=curr->right;
         else
           break;
        }
     }
     if(curr==NULL)//inserting first element
        return temp;
     else if(x < curr->data)
      {
        temp->left=curr->left;
        temp->right=curr;
        curr->lthread=false;
        curr->left=temp;
      }
     else
      {
         temp->right=curr->right;
         temp->left=curr;
         curr->rthread=false;
         curr->right=temp;
      }
      return t;
   
   }   

  void inorder(struct tnode *t)
  {
    printf("Inside inorder..\n");
    struct tnode *curr;
    if(t==NULL)
     printf("Empty tree");
   else
    {
      curr=t;
      while(curr->lthread==false)
        curr=curr->left;
      while(curr!=NULL)
      {
        printf("%d   ",curr->data);
        curr=inordersuccessor(curr);
      }
    }
  }

   struct tnode* inordersuccessor(struct tnode *t)
   {
      if(t->rthread==true)
        return t->right;
      t=t->right;
      while(t->lthread==false)
        t=t->left;
      return t;
    }



























