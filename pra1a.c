#include<stdio.h>

int a[100],n;
int add()
{
    int add=0;
    for (int i = 0;i<n; i++)
    {
        add=add+a[i];
    }
    return add;
}
int avg()
    {
        float avg;
        int add=0;
        for (int i = 0;i<n; i++)
        {
            add=add+a[i];
        }
        avg=add/n;
        return avg;
    }
int min()
{
    int min=a[0];
    for (int i = 0;i<n; i++)
    {
        if (a[i]<min)
        {
            min=a[i];
        }
    }
    return min;
}
int max()
{
    int max=a[0];
    for (int i = 0;i<n; i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
int main()
{
    int i,c;
    printf("How many elements you want to enter ?");
    scanf("%d",&n);
    for (int i = 0;i<n; i++)
    {
        printf("\n a[%d]\t:\t",i);
        scanf("%d",&a[i]);
    }
    while(1)
    {
    printf("\n\n\n 1.add \n 2.max \n 3.min \n 4.avg");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("addition of all number is %d",add());
        break;
    case 2 :
        printf("max value is %d",max());
        break;
    case 3 :
        printf("min value is %d",min());
        break;
    case 4 :
        printf("avg of all number is %d",avg());
        break;
    default:
        printf("\n enter correct option");
        break;
    }
    }
    return 0;
}
