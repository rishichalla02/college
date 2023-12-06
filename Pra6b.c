#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node*createNode(int data){
    struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack
{
    struct Node*top;
};
void printstack(struct Stack*stack)
{
    struct Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");    
}



void push(struct Stack*stack, int data){
    struct Node*newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack){
    if (stack->top==NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node*temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

struct Queue
{
    struct Node*front;
    struct Node*rear;
};

void printqueue(struct Queue* queue)
{
    struct Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void enqueue(struct Queue* queue, int data){
    struct Node* newNode = createNode(data);
    if (queue->rear==NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue){
    if (queue->front==NULL)
    {
        printf("Queue Underflow\n");
        return-1;
    }
    int data=queue->front->data;
    struct Node *temp=queue->front;
    queue->front=queue->front->next;
    if(queue->front==NULL)
    {
        queue->rear=NULL;
        
    }
    free(temp);
    return data;

}

int main()
{
    int ch,number;
    struct Stack stack ;
    struct Queue queue;
    stack.top=NULL;
    queue.front=queue.rear=NULL;
    
    do
    {
        printf("Enter Your Choice \n");
        printf("1 ) Stack\n");
        printf("2 ) Queue\n");
        printf("Entre : ");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("Enter 1 for push in stack\n");
            printf("Enter 2 for pop in stack\n");
            scanf("%d",&ch);

            if(ch==1)
            {
                printf("Enter value ");
                scanf("%d",&number);
                push(&stack,number);

                printstack(&stack);

            }
            else if (ch==2)
            {
                number=pop(&stack);
                printf("popped from stack %d\n",number);
                   printstack(&stack);
            }
            else
            {
                printf("Enter Valide choice \n");
            }            

        }
        else if (ch==2)
        {
              printf("Enter 1 for Enqueue \n");
            printf("Enter 2 for Dequeue \n");
            scanf("%d",&ch);

            if(ch==1)
            {
                printf("Enter value ");
                scanf("%d",&number);
                enqueue(&queue,number);
                printqueue(&queue);

            }
            else if (ch==2)
            {
                number=dequeue(&queue);
                printf("dequeued from queue %d\n",number);
                printqueue(&queue);
            }
            else
            {
                printf("Enter Valide choice \n");
            }            
        }
        
        printf("If Exit then continue 0 : ");
        scanf("%d",&ch);

        
    } while (ch==0);
    

    return 0;
    }

