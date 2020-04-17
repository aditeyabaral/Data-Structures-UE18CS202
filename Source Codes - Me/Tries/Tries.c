#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trienode
{
    int end;
    struct trienode* child[255];
};
typedef struct trienode NODE;
struct stack
{
    int index;
    NODE *node;
};
typedef struct stack STACK;
STACK s[255];
int top = -1;
NODE* create();
void insert(NODE*, char*);
void display(NODE*);
void display_length(NODE*,int);
void display_prefix(NODE*,char*);
int search(NODE*,char*);
void delete(NODE*,char*);
int check(NODE*);
void push(NODE*,int);
STACK pop();
char word[20];
int len;
int main()
{
    NODE* root = create();
    char s[20];
    while(1)
    {
        printf("Enter string : ");
        scanf("%s",s);
        if(!strcmp(s,"0")) break;
        insert(root,s);
    }
    len = 0;
    display(root);
    len = 0;
    printf("Enter length to print : ");
    int c;
    scanf("%d",&c);
    display_length(root,c);
    len = 0;
    printf("Enter prefix : ");
    scanf("%s",s);
    display_prefix(root,s);
    printf("Enter to search : ");
    scanf("%s",s);
    printf("Found : %d\n", search(root,s));
    printf("Enter word to delete : ");
    scanf("%s",s);
    delete(root,s);
    len = 0;
    display(root);
}
NODE* create()
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->end = 0;
    for (int i=0;i<255;i++)
        node->child[i] = NULL;
    return node;
}
void insert(NODE* root,char *key)
{
    int index;
    NODE* pres = root;
    for(int i = 0;key[i]!='\0';i++)
    {
        index = key[i];
        if(pres->child[index]==NULL)
            pres->child[index] = create();
        pres = pres->child[index];
    }
    pres->end = 1;
}
void display(NODE* pres)
{
    for(int i = 0;i<255;i++)
    {
        if(pres->child[i]!=NULL)
        {
            word[len++] = i;
            if(pres->child[i]->end==1)
            {
                for(int j=0;j<len;j++)
                    printf("%c",word[j]);
                printf("\n");
            }
            display(pres->child[i]);
        }
    }
    len--;
}
void display_length(NODE* pres,int count)
{
    for(int i = 0;i<255;i++)
    {
        if(pres->child[i]!=NULL)
        {
            word[len++] = i;
            if(pres->child[i]->end==1 && len==count)
            {
                for(int j=0;j<len;j++)
                    printf("%c",word[j]);
                printf("\n");
            }
            display_length(pres->child[i],count);
        }
    }
    len--;
}
void display_prefix(NODE* root, char* key)
{
    int index;
    NODE* pres = root;
    for(int i=0;key[i]!='\0';i++)
    {
        index = key[i];
        if(pres->child[index]!=NULL)
        {
            word[len++] = index;
            pres = pres->child[index];
        }
    }
    if(pres->end)
    {
        for(int j=0;j<len;j++)
            printf("%c",word[j]);
        printf("\n");
    }
    display(pres);
}
int search(NODE* root,char* key)
{
    int index;
    NODE* pres = root;
    for(int i=0;key[i]!='\0';i++)
    {
        index = key[i];
        if(pres->child[index] == NULL) return 0;
        pres = pres->child[index];
    }
    return (pres->end);
}
void delete(NODE* root,char* key)
{
    int index;
    NODE* pres = root;
    for(int i=0;key[i]!='\0';i++)
    {
        index = key[i];
        if(pres->child[index]==NULL) return;
        push(pres,index);
        pres = pres->child[index];
    }
    pres->end = 0;
    push(pres,-1);
    STACK temp;
    while(1)
    {
        temp = pop();
        if(temp.index!=-1)
            temp.node->child[temp.index] = NULL;
        if(temp.node == root || temp.node->end || check(temp.node))
            break;
        else
            free(temp.node);
    }
}
int check(NODE* node)
{
    for(int i = 0;i<255;i++)
    {
        if(node->child[i]!=NULL)
            return 1;
    }
    return 0;
}
void push(NODE* node, int index)
{
    top++;
    s[top].index = index;
    s[top].node = node;
}
STACK pop()
{
    top--;
    return s[top+1];
}