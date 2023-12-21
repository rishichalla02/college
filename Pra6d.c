#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertBeforePosition(struct Node** head, int position, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = *head;
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* lastNode = *head;

    while (lastNode->next != *head) {
        lastNode = lastNode->next;
    }

    *head = temp->next;
    lastNode->next = *head;

    free(temp);
}

void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    free(nodeToDelete);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice=0;
    int value=0; 
    int position=0; 

    do {
        printf("\nCircular Singly Linked List Operations:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert before specified position\n");
        printf("3. Delete first node\n");
        printf("4. Delete node after specified position\n");
        printf("5. Display list\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter the position before which to insert: ");
                scanf("%d", &position);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertBeforePosition(&head, position, value);
                break;
            case 3:
                deleteFirstNode(&head);
                break;
            case 4:
                printf("Enter the position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 5:
                displayList(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}