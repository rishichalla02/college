#include<stdio.h>
#include<stdlib.h>

int key;
int binary(int a[],int low,int high);
int linear(int a[],int n);
main()
{
 int n,i,a[10],pos,ch;
do
{
        printf("--Menu-- \n 1.Binary Search \n 2.Linear Search \n 3.Exit");
 printf("\nEnter your choice ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1 :
  printf("\n Enter how many elements: ");
  scanf("%d",&n);
  printf("\n Enter elements of array\n");
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  printf("\n enter the elements to be searched");
  scanf("%d",&key);
  pos=linear(a,n);
  if(pos==-1)
  printf("\n element not found");
  else
  printf("\n element found at position %d",pos+1);
  break;
 case 2 :
  printf("\n Enter how many elements: ");
  scanf("%d",&n);
  printf("\n Enter elements of array\n");
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  printf("\n enter the elements to be searched");
  scanf("%d",&key);
  pos=linear(a,n);
  if(pos==-1)
  printf("\n element not found\n");
  else
  printf("\n element found at position %d",pos+1);
  break;
  
case 3 :exit(0);
 
default:printf("\n Invalid coice");
 break;
 }
}
while(ch!=3);
}
int binary(int a[],int low,int high)
{
 int mid;
 
 if(low>high)
 {
  return(-1);
 }
  mid=(low+high)/2;
  if(key==a[mid])
  {
   
   return(mid);
  }
  if(key<a[mid])
  {
   return(binary(a,low,mid-1));
}
   else
{
   return(binary(a,mid+1,high));
  }
}


int linear(int a[],int n)
{
 int i;
 for(i=0;i<n;i++)
 {
 if(a[i]==key)
 return(i);
 }
 return(-1);
}