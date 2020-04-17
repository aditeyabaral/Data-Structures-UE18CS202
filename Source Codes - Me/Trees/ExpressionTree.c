#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node* left;
    struct node* right;
};
typedef struct node NODE;
struct tree
{
    NODE *head;
};
typedef struct tree TREE;
NODE *stack[100];
int top = -1;
NODE* createTree(char*);
int empty();
void push(NODE*);
NODE* pop();
int Operator(char);
int evalExpression(NODE*);
int main()
{
    TREE *tree = (TREE*)malloc(sizeof(TREE));
    char postfix[100];
    printf("Enter postfix : ");
    scanf("%s",postfix);
    tree->head = createTree(postfix);
    int eval = evalExpression(tree->head);
    printf("Value = %d\n",eval);

}
NODE *createTree(char *postfix)
{
    int i = 0;
    while(postfix[i]!='\0')
    {
        NODE *node = (NODE*)malloc(sizeof(NODE));
        node->data=postfix[i];
        node->left = node->right = NULL;
        if(Operator(postfix[i]))
        {
            node->right = pop();
            node->left = pop();
            push(node);
        }
        else
            push(node);
        i++;
    }
    return pop();
}
void push(NODE* x)
{
    top++;
    stack[top]=x;
}
NODE *pop()
{
    top-=1;
    return stack[top+1];
}
int empty()
{
    if(top==-1)
        return 1;
    return 0;
}
int Operator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%')
        return 1;
    return 0;
}
int evalExpression(NODE *node)
{
    char ch=node->data;
    int val;
    if(Operator(ch))
    {
        switch(ch)
        {
            case '+':
                return (evalExpression(node->left)+evalExpression(node->right));
            case '-':
                return (evalExpression(node->left)-evalExpression(node->right));
            case '/':
                return (evalExpression(node->left)/evalExpression(node->right));
            case '*':
                return (evalExpression(node->left)*evalExpression(node->right));
            case '%':
                return (evalExpression(node->left)%evalExpression(node->right));
        }
    }
    else
    {
        printf("Enter value for %c : ",ch);
        scanf("%d", &val);
        return val;
    }
}