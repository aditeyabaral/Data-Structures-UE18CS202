//program to implement a binary seach tree
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
void insert(struct tnode **,int);
struct tnode* rinsert(struct tnode *, int);
struct tnode* tdelete(struct tnode*,int );
int search(struct tnode*, int);
int rsearch(struct tnode *,int);
void preorder(struct tnode*);
void inorder(struct tnode*);
void postorder(struct tnode*);
int smallest(struct tnode*);
int largest(struct tnode*);
void main()
{
  struct tnode *root;
  int ch,num,k;
   root=NULL;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2..Recursively insert..");
      printf("\n3..search..");
      printf("\n4..search recursively.");
      printf("\n5..Preorder Traversal");
      printf("\n6..Inorder Traversal.");
      printf("\n7..Postorder Traversal.");
      printf("\n8..smallest element..");
      printf("\n9..largest element..");
      printf("\n10..Delete a node");
      printf("\n11.exit");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 insert(&root,num);
                 break;
       case 2 :printf("Enter the element");
                 scanf("%d",&num);
                 root=rinsert(root,num);
                 break;
       case 3:printf("Enter the element");
               scanf("%d",&num);
               k=search(root,num);
               if(k)
                 printf("Element found...\n");
              else
                 printf("Not found..\n");
              break;
       case 4:printf("Enter the element");
               scanf("%d",&num);
               k=rsearch(root,num);
               if(k)
                 printf("Element found...\n");
              else
                 printf("Not found..\n");
              break;

       case 5: printf("Preorder traversal..\n");
               preorder(root);
               break;
       case 6:printf("Inorder traversal..\n");
               inorder(root);
               break;

       case 7: printf("Postorder traversal..\n");
               postorder(root);
               break;
       case 8 :printf("Smallest Element = %d",smallest(root));
               break;
       case 9 : printf("Largert element=%d",largest(root));
                break;
       case 10:printf("Enter the key to be deleted");
               scanf("%d",&num);
               root=tdelete(root,num);
                 break;
       case 11:exit(0);
       }
    }
  }    
  

   struct tnode* tdelete(struct tnode *t, int key)
   {
     struct tnode *temp, *curr,*prev, *q, *p;
     prev=NULL;
     curr=t;

     //find key
     while((curr!=NULL)&&(curr->data!=key))   
     {
       prev=curr;
       if(key <curr->data)
          curr=curr->left;
      else
          curr=curr->right;
     }

     if(curr==NULL)//key not found
       return t;
    //if key found
    //if key has one subtree or no subtrees
   if((curr->left==NULL)||(curr->right==NULL))
   {
     //get the address of the non empty subtree
     if(curr->left==NULL)
        q=curr->right;
     else
        q=curr->left;
   
     if(prev==NULL)//deleting root with one subtree
       return q;//q is the new root
    else if(curr==prev->left)
       prev->left=q;
    else
        prev->right=q;
    free(curr);
  }
 else//both subtrees present
 {
    //find inorder successor
    p=NULL;//parent of inorder successor
    temp=curr->right;
     while(temp->left!=NULL)
     {
      p=temp;
      temp=temp->left;
     }
    //inorder successor found (temp) p- parent
     curr->data = temp->data;
     if(p!=NULL)
       p->left=temp->right;
     else
       curr->right=temp->right;
     free(temp);
    }
  return t;
 }








   

















 int smallest(struct tnode *t)
 {
  while(t->left!=NULL)
    t=t->left;
  return(t->data);

 }


 int largest(struct tnode *t)
 {
   while(t->right!=NULL)
    t=t->right;
   return(t->data);
}


 int search(struct tnode *t, int x)
 {
  
   struct tnode *curr;
   curr=t;

   while(curr!=NULL)
   {
     if(x==curr->data)
       return 1;
     else if(x<curr->data)
       curr=curr->left;
     else
       curr=curr->right;
   }
   return 0;
 }

 //one more way to search for a element in the tree
 /* int search(struct tnode* t, int x)
  {
   struct tnode *curr;

   while((curr!=NULL)&&(curr->data!=x))
   {
     if(x<curr->data)
       curr=curr->left;
    else
       curr=curr->right;
   }
   if(curr==NULL)//not found
    return 0;
   return 1;
 }*/

 //recursively search for x
 int rsearch(struct tnode *t, int x)
 {
   int l;
  if(t==NULL)
   return 0;
  if(x==t->data)
  return 1;
  if(x< t->data)
  l=rsearch(t->left,x);//search in left subtree
 else 
   l=rsearch(t->right,x);//search in right subtree
 return l;
}
  
 void insert(struct tnode **t, int x)
 {

   struct tnode *temp,*curr,*prev;
  //create a node for x

  temp=malloc(sizeof(struct tnode));
  temp->data=x;
  temp->left=temp->right=NULL;

  //if it is the first element
  //make root point to temp
  if(*t==NULL)
    *t=temp;
  else
  {
    curr=*t;
    prev=NULL;

   //find place for x

    while(curr!=NULL) 
    {
      prev=curr;
      if(x<curr->data)//move left
        curr=curr->left;
      else
        curr=curr->right;//move right
    }
   if(x<prev->data)
     prev->left=temp;
   else
     prev->right=temp;
 }
}
 void preorder(struct tnode *t)
   {
     if(t!=NULL)
     {
        printf("%d ",t->data);
        preorder(t->left);
        preorder(t->right);
     }
  }

void inorder(struct tnode *t)
   {
     if(t!=NULL)
     {
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
     }
  }

void postorder(struct tnode *t)
   {
     if(t!=NULL)
     {
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->data);
     }
  }

  struct tnode* rinsert(struct tnode* t, int x)
  {
    struct tnode *temp;

    //empty tree, first element inserted, when called first time
    if(t==NULL)
    {
      temp=(struct tnode*)malloc(sizeof(struct tnode));
      temp->data=x;
      temp->left=temp->right=NULL;
      return temp;
    }
     if(x<t->data)
     //insert into the left subtree
     //and return the root of the left subtree
     t->left=rinsert(t->left,x);
   else
      //insert into the left subtree
      //and return the root of the left subtree
      t->right=rinsert(t->right,x);
   return t;
  }

  











 

































