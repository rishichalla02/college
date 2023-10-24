#include<stdio.h>

struct student
{
    int no;
    char name[50];
    int sem;
    char branch[10];
}s[10];

void scan (int n)
{
    for (int i = 0;i<n; i++)
    {
      printf("\nEnter roll Number :");
      scanf("%d",&s[i].no);
      printf("\nEnter Name :");
      scanf("%s",&s[i].name);
      printf("\nEnter Semester :");
      scanf("%d",&s[i].sem);
      printf("\nEnter Branch :");
      scanf("%s",&s[i].branch);  
    }
}    
void print(int n)
{
    for (int i = 0;i<n; i++)
    {
       printf("\nroll No. :%d",s[i].no);
        printf("\nName :%s",s[i].name);
        printf("\nSemester :%d",s[i].sem);
        printf("\nBranch :%s",s[i].branch);
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
    switch (c)
    {
    case 1 :
            scan (a);
        break;
    case 2 :
            print (a);    
        break;
    default:
            printf("exit");
        break;
    }
    }
    return 0;
}
