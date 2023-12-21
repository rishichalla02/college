#include<stdio.h>
#include<stdlib.h>

struct student
{
    int no;
    char name[50];
    int sem;
    char branch[10];
}s[10];

void scan(int n)
{
    int i=0;
    for (i=0; i<n; i++)
    {
      printf("\n Enter roll Number : ");
      scanf("%d",&s[i].no);
      printf("\n Enter Name : ");
      scanf("%s ",&s[i].name);
      printf("\n Enter Semester : ");
      scanf("%d",&s[i].sem);
      printf("\n Enter Branch : ");
      scanf("%s",&s[i].branch);
    }
}    
void print(int n)
{
    int i=0;
    for (i=0; i<n; i++)
    {
       printf("\n roll No. : %d",s[i].no);
        printf("\n Name : %s ",s[i].name);
        printf("\n Semester : %d",s[i].sem);
        printf("\n Branch : %s",s[i].branch);
        printf("\n--------------------------");
    }
}

int main()
{
     int c, a;
    printf("How many data you want to enter");
    scanf("%d",&a);
    while(1)
    {
    printf("\n 1) Add data 2) Print data 3) exit");
    scanf("%d",&c);
    switch(c)
      {
        case 1 :
             scan(a);
             break;
        case 2 :
            print(a);    
            break;
        case 3 :
            exit(0);
        default:
            printf("\n Invalid choise");
      }
    }
    return 0;
}
