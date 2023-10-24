#include<stdio.h>
#define size 10

int cqueue[size];
int front=-1;
int rear=-1;

void insert()
{
    int item;
    if ((front==0 && rear==size-1) || (front==rear+1))
    {
        printf("Queue overflow !! \n");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(rear==size-1)
        rear=0;
        else
            rear=rear+1;
    }
    printf("Input the element for insertion in queue :");
    scanf("%d",&item);
    cqueue[rear]=item;
}

void delete()
{
    if(front==-1)
    {
        printf("Queue underflow !!\n");
        return;
    }
    printf("Element deleted from queue is:%d\n",cqueue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        if(front==size-1)
        front=0;
        else
        front=front+1;
    }
}

void display()
{
    int i;
    if (front==-1)
    {
        printf("Queue is empty !!\n");
        return;
    }
    printf("Queue elements:\n");
    if(front<=rear)
    {
        for (i=front;i<=rear;i++)
        {
            printf("%d ",cqueue[i]);
        }
    }
    else
    {
        for (i=front;i<size-1;i++)
        {
            printf("%d ",cqueue[i]);
        }
        for (i=0;i<rear;i++)
        {
            printf("%d ",cqueue[i]);
        }  
    }
     printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\nEnter 1. to insert an element");
        printf("\nEnter 2. to delete an element");
        printf("\nEnter 3. to display an element");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: insert();
            break;
        case 2: delete();
            break;
        case 3: display();
            break;
        default:
                printf("Wrong choice\n");
        }
    } while (choice!=4);
     return 0;
    
}