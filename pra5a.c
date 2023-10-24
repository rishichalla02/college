#include<stdio.h>

int queue[10];
int size=10;
int rear=-1;
int front=-1;

void insert()
{
    if (rear>=size-1)
    {
       printf("\n Queue is Full !! ");
    }
    else
    {
        printf("\n Enter an element : ");
        scanf("%d",&queue[++rear]);
    }
}

void delete()
{
    if (rear==-1)
    {
        printf("\n Queue is empty !!");
    }
    else
    {
        printf("\n Deleted element is : %d",queue[++front]);
    if (rear==front)
     {
         front=-1;
         rear=-1;
     }   
    }
}

void display()
{
    int i=0;
    if (rear==-1)
    {
        printf("\n Queue is empty !!");
    }
    else
    {
        printf("\n Elements are >> ");
        for ( i= front+1; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }   
}

int main()
{
int ch=0;

    do
    {
        printf("\nEnter 1. to insert element");
        printf("\nEnter 2. to delete element");
        printf("\nEnter 3. to display element");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;

        default:
                printf("\n Invalid choise");
            break;
        }
    }while (ch>=1 && ch<=3);
     return 0;
} 