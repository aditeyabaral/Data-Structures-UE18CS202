#include<stdio.h>
#include<string.h>
struct student
  {
    char name[100];
    int srn;
    char address[100];
  };

int main()
{
  struct student s;
  struct student *p;
  void display(struct student*);

    strcpy(s.name,"abcd");
    s.srn=100000;
    strcpy(s.address,"defgh");
  
    p=&s;
    display(p);
    
  }

  void display(struct student *p)
  {
    printf("\nName = %s",p->name);
    printf("\nSRN = %d",p->srn);
    printf("\naddress = %s",p->address);
  }   





  
 
