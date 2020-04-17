
//program to ckeck if a binary tree
//is a BST
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
struct tnode* create();
int max(struct tnode*);
int min(struct tnode*);
void preorder(struct tnode*);
int checkbst(struct tnode *);
int main()
{
 int num,r;
 struct tnode *root;
 root=create();
 
 printf("pre order traversal..\n");
 preorder(root);
 printf("\nChecking for BST..\n");
 r=checkbst(root);
 if(r)
   printf("\nBST..\n");
 else
   printf("\nNot BST..\n");
}


void preorder(struct tnode*t)
   {
     if(t!=NULL)
      {
         printf("%d   ",t->data);
         preorder(t->left);
         preorder(t->right);
      }
    }

struct tnode *create()
  {

   int x;
    struct tnode *p;

   printf("Enter the element...");
   scanf("%d",&x);

   if(x==-1)
     return NULL;

   p=malloc(sizeof(struct tnode));
   p->data=x;

   printf("\ncreating the left subtree of %d\n",x);
   p->left=create();


   printf("\nCreating the right subtree of %d\n",x);
   p->right=create();

   return p;
 }

 int checkbst(struct tnode *t)
 {
   if(t==NULL)
    return 1;
   if(t->left!=NULL)
   {
      if(max(t->left) > t->data)   
        return 0;
   }
   if(t->right!=NULL)
   {
       if(min(t->right)<t->data)
         return 0;
   }
    if(checkbst(t->left)&&checkbst(t->right))
      return 1;
    return 0;
  }



 int max(struct tnode *t)
 {
   while(t->right!=NULL)
     t=t->right;
   return(t->data);
 }

 int min(struct tnode *t)
 {
   while(t->left!=NULL)
    t=t->left;
   return(t->data);
 }





