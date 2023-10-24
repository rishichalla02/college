#include<stdio.h>
#include<stdlib.h>

int stack[5];
int MAX=5;
int top=-1;

void PUSH()
{
    if (top>=MAX-1)
    {
        printf("\n Stack Overflow");
    }
    else
    {
        printf("\n Enter an Element :");
        scanf("%d",&stack[++top]);
    }  
}

void POP()
{
    if (top<0)
    {
        printf("\n Stack Underflow");
    }
    else
    {
        printf("\n Deleted Element is : %d",stack[top]);
        top--;
    }
}

void DISPLAY()
{
    int i=0;
    if (top<0)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n Element available in Stack are >> ");
        for ( i = 0; i <=top; i++)
        {
            printf("%d ",stack[i]);
        }
    }
}

int main()
{
    int ch=0;
    do
    {
        printf("\n Enter 1. to PUSH an element");
        printf("\n Enter 2. to POP an element");
        printf("\n Enter 3. to DISPLAY an element");
        printf("\n Enter 4. to exit an element");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            exit(0);
            default:
                printf("\n Invalid option selected");
        }
    } while (ch>=1 && ch<=4);
    return 0;  
}