//PROGRAM TO CREATE AN EXPRESSION TREE
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  char data;
  struct tnode *left;
  struct tnode *right;
};
void inorder(struct tnode*);
void preorder(struct tnode*);
void postorder(struct tnode*);
struct tnode* create_exptree(char*);
int isoper(char);
void push(struct tnode**,int*,struct tnode*);
struct tnode* pop(struct tnode**,int*);
int evaluate(struct tnode*);
void main()
{
  struct tnode *root;
  int ch,num,k;
  char exp[100];
  root=NULL;
  
  printf("Enter the postfix form of the expression...");
  scanf("%s",exp);
  
  root=create_exptree(exp);
  printf("The infix expression = \n");
  inorder(root);
  printf("\nThe prefix expression = \n");
  preorder(root);
  printf("\nThe postfix expression = \n");
  postorder(root);
  printf("\nEvaluating the expression\n");
  int result = evaluate(root);
  printf("\nThe evaluation of the expression = %d\n",result);
  
}

 struct tnode* create_exptree(char* exp)
 {
  char ch;
  int top;
   struct tnode *s[100];//stack;
  struct tnode* temp;
  int i;

  i=0;
  top=-1;

  while(exp[i]!='\0')
  {
   ch=exp[i];
   temp=malloc(sizeof(struct tnode));
   temp->data=ch;
   temp->left=temp->right=NULL;

   if(isoper(ch))
   {
    temp->right=pop(s,&top);
    temp->left=pop(s,&top);
    push(s,&top,temp);
  }
  else
    push(s,&top,temp);
  i++;
 }
 return(pop(s,&top));
}


void preorder(struct tnode *t)
   {
    if(t!=NULL)
    {
     printf("%c ",t->data);
     preorder(t->left);
     preorder(t->right);
   }
 }

  void postorder(struct tnode *t)
  {
    if(t!=NULL)
    {
     
     postorder(t->left);
     postorder(t->right);
     printf("%c ",t->data);
   }
 }

void inorder(struct tnode *t)
  {
    if(t!=NULL)
    {
     inorder(t->left);
     printf("%c ",t->data);
     inorder(t->right);
   }
 }
 

  int isoper(char ch)
  {
    switch(ch)
    {
      case '+':
      case '-':
      case '*':
      case '/':return 1;
      default: return 0;
    }
  }


  void push(struct  tnode **stk, int *t, struct tnode* temp)
  {
    ++*t;
    stk[*t]=temp;
  }

  struct tnode *pop(struct tnode **stk, int *t)
  {
    struct tnode *temp;
     temp=stk[*t];
     --*t;
    return temp;
  }

 int evaluate(struct tnode *t)
 {
   int a;
   switch(t->data)
   {
     case '+':return(evaluate(t->left)+evaluate(t->right));
     case '-':return(evaluate(t->left)-evaluate(t->right));
     case '*':return(evaluate(t->left)*evaluate(t->right));
     case '/':return(evaluate(t->left)/evaluate(t->right));
     default:printf("%c = ",t->data);
             scanf("%d",&a);
             return(a);

 }
}






/* struct tnode* create_exptree(char* exp)
 {
   struct tnode* stk[10],*temp;
   int top=-1;
   int i=0;
   char ch;
   while(exp[i]!='\0')
   {
      ch=exp[i]; 
      //create a node
      temp=(struct tnode*)malloc(sizeof(struct tnode));
      temp->data=ch;
      temp->left=temp->right=NULL;
      if(isoper(ch))//if operator
      {
        temp->right=pop(stk,&top);
        temp->left=pop(stk,&top);
        push(stk,&top,temp);
     }
     else//if operand
      push(stk,&top,temp);
     i++;
   }
  return(pop(stk,&top)); 
}*/

  
     









 




  












             















  























