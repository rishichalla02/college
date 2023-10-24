#include<stdio.h>

void main()
{
    int arr[100],n,i,key;
    printf("How many elements are added : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the elements to search : ");
    scanf("%d",&key);
    int result;
    result=search(arr,n,key);
    if (result==-1)
    {
        printf("\n Element is not present ");
    }
    else
    {
        printf("\n Element is present ");
    }
}

int search(int arr[100],int n, int x)
{
    int low,high,mid;
    low=0;
    high=n-1;

    while (low<=high)
    {
       mid=(low+high)/2;
       if (x==arr[mid])
       {
         return mid;
       }
       else if(x<arr[mid])
       {
        low=mid-1;
       }
       else
       {
        high=mid+1;
       }
    }
    return -1;
}