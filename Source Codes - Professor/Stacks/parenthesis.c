#include<stdio.h>
void push(char *s,int*,char);
char pop(char* s, int*);
int isempty(int);
int match(char *);
int main()
{
  char expr[10];
  printf("Enter the expression\n");
  scanf("%s",expr);
  int result=match(expr);
  if(result)
   printf("Valid expression n");
 else
   printf("Invalid\n");
}


 int match(char *expr)
 {
   char ch,in,s[10];//stack
   int top,i;
   top=-1;
   i=0;

   while(expr[i]!='\0')
   {
     ch=expr[i];
     switch(ch)
     {
        case '(':
        case '{':
        case '[':push(s,&top,ch);
                 break;
        case ')':if(!isempty(top))
                 {
                   in=pop(s,&top);
                   if(in!='(')
                      return 0;//invalid, mismatch of parenthesis
                   break;
                 }
                 else
                   return 0;//invalid, extra closing parenthesis
       case '}':if(!isempty(top))
                 {
                   in=pop(s,&top);
                   if(in!='{')
                      return 0;//mismatch of parenthesis
                   break;
                 }
                 else
                   return 0;//invalid, extra closing parenthesis
      case ']':if(!isempty(top))
                 {
                   in=pop(s,&top);
                   if(in!='[')
                      return 0;//mismatch of parenthesis
                   break;
                 }
                 else
                   return 0;//invalid, extra closing parenthesis


   }//end switch
  i++;
 }//end while
  if(!isempty(top))//invalid extra opening paraenthesis
     return 0;
  return 1;
 }

void  push(char *s,int *t,char x)
  {
   ++*t;//increment top
   s[*t]=x;
  }

  char pop(char *s, int *t)
  {
    char x;
    x=s[*t];
    --*t;//decrement top
    return x;
  }
 
 int isempty(int top)
  {
    if(top==-1)
      return 1;
     return 0;
  }



  /*int match(char *expr)
  {
     int i,top;
     char s[10],ch,x;//stack
     i=0;
      top=-1;

     while(expr[i]!='\0')
     {
       ch=expr[i];
       switch(ch)
       {
           case '(':
           case '{':
           case '[':push(s,&top,ch);
                    break;
           case ')':if(!isempty(top))
                    {
                      x=pop(s,&top);
                      if(x=='(')
                        break;
                      else
                        return 0;//mismatch of parenthesis
                    }
                    else
                      return 0;//extra closing parenthesis

           case '}':if(!isempty(top))
                    {
                      x=pop(s,&top);
                      if(x=='{')
                        break;
                      else
                        return 0;//mismatch of parenthesis
                    }                    
                    else
                      return 0;//extra closing parenthesis
           case ']':if(!isempty(top))
                    {
                      x=pop(s,&top);
                      if(x=='[')
                        break;
                      else
                        return 0;//mismatch of parenthesis
                    }
                    else
                      return 0;//extra closing parenthesis

           }//end switch
           i++;
      }//end while
     if(isempty(top))
         return 1;
       return 0;//extra opening parenthesis
   }   */ 
 
    
  








