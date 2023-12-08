#include<stdio.h>
#include<stdlib.h>

struct Node
{   
    struct Node*prive;
    int info;
    struct Node *next;
}*head=NULL;


void pushFront()
{
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter Data for the node to be inserted at front : ");
    scanf("%d",&node->info);
    node->next=NULL;
    if(head==NULL)
    {        
        head=node;
    }
    else
    {   node->prive=NULL;
        node->next=head;
        head=node;
    }    
}
void PushAtPostion()
{
    int pos,count;
    struct Node *temp=head,*temp1=NULL;

    printf("Enter position to insert at any  ");
    scanf("%d",&pos);

    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(pos<=0 || pos>count)
    {
        printf("Invalide Position \n");
        return ;
    }
    else if (pos==1)
    {
          struct Node *node=(struct Node*) malloc(sizeof(struct Node));
           node->prive=NULL;
    printf("\nEnter Data for the node to be inserted at any position : ");
    scanf("%d",&node->info);

    node->next=head;
    head->prive=node;
    head=node;
    }
    else
    {
        count=0;
        temp=head;
        while (count<pos-2)
        {
            temp=temp->next;
            count++;
        }
         struct Node *node=(struct Node*) malloc(sizeof(struct Node));
           node->prive=temp;
    printf("\nEnter Data for the node to be inserted at position : ");
    scanf("%d",&node->info);
    node->next=temp->next;
    temp->next->prive=node;
    temp->next=node;
        
    }
    
    
}

void pushEnd()
{
    struct Node *node=(struct Node*) malloc(sizeof(struct Node));
    printf("\nEnter Data for the node to be inserted at end : ");
    scanf("%d",&node->info);
    node->prive=NULL;
    node->next=NULL;
    if(head==NULL)
    {
        head=node;
    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=NULL)
        {

            temp=temp->next;   

        }        
        node->prive=temp;
        temp->next=node;
        
    }    
}



void popFront()
{
    if(head==NULL)
    {
        printf("\nDoubly link list is already empty, you cannot delete anything from the list.");
    }
    else if(head->next==NULL)
    {
        printf("\nDeleted element is : %d", head->info);
        head=NULL;
    }
    else
    {
        struct Node *temp;        
        printf("\nDeleted element is : %d", head->info);
        temp=head;
        head=head->next;
        head->prive=NULL;
        free(temp);
    }
}

void PopAtPostion()
{
     int pos,count;
    struct Node *temp=head,*temp1=NULL;
    if(head==NULL)
    {
        printf("\nDoubly link list is already empty, you cannot delete anything from the list.");
    }
   

    printf("Enter position to delete at any position ");
    scanf("%d",&pos);
    
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(pos<=0 || pos>count)
    {
        printf("Invalid Position \n");
        return ;
    }
    else if (pos==1)
    {
        temp1=head;
        printf("DElete Element is %d \n",head->info);
        head->next->prive=NULL;
        head=head->next;
        free(temp1);
    }
    else
    {
        count=0;
        temp=head;
        while (count<pos-2)
        {
            temp=temp->next;
            count++;
        }
         temp1=temp->next;
         printf("\n Deleted element is : %d", temp1->info);
         temp->next=temp1->next;
         temp1->next->prive=temp;
         free(temp1);
       }
    
}
void popEnd()
{
   
    
    if(head==NULL)
    {
        printf("\nDoubly link list is already empty, you cannot delete anything from the list.");
    }

    else if (head->next==NULL)
    {
        head=NULL;
        printf("Delete Element is %d \n",head->info);
       
    }
    else
    {
        struct Node *temp=head,*prive=NULL;
        while (temp->next!=NULL)
        {
            prive=temp;
            temp=temp->next;
        }

        printf("Delete Element is %d \n",temp->info);
        prive->next=NULL;
        free(temp);

       }
}

void display()
{
    if(head==NULL)
    {
        printf("\nYour Doubly List is empty...");
    }
    else
    {
        struct Node *temp=head;
        while(temp!=NULL)
        {
            printf(" %d ", temp->info);
            temp=temp->next;
        }
    }
}

int main()
{
    int ch=0;
    do
    {
        printf("\nEnter 1. to Insert node at the front of the Doubly List.");
        printf("\nEnter 2. to Insert node at the end of the Doubly List.");
        printf("\nEnter 3. to Insert node in At any position the Doubly List.");
        printf("\nEnter 4. to Delete first node from the Doubly List.");
        printf("\nEnter 5. to Delete the node  at any position from the Doubly List.");
        printf("\nEnter 6. to Delete the node Last position from the Doubly List.");
        printf("\nEnter 7. to Display the Doubly List.");
        printf("\nEnter 8. to exit.");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                pushFront();
                break;
            case 2:
                pushEnd();
                break;
            case 3:
                PushAtPostion();
                break;
            case 4:
                popFront();
                break;
            case 5:
                PopAtPostion();
                break;
            case 6:
                popEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("\nInvalid option selected.");
        }
    }while(ch>=1 && ch<=8);
    return 0;
}