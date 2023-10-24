#include<stdio.h>

void main()
{
    int arr[10],i,key,n=10;
    printf("\n Enter 10 numbers :");
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
printf("\n Enter number to search : ");
scanf("%d",&key);

int result;
result=search(arr,n,key);
if(result==-1)
{
    printf("No is not present");
}
else
 {
    printf("No is present");
 }
}
int search(int arr[10],int n,int x)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (arr[i]==x)
        {
            return 1;
        }
    }        
    return -1;
}