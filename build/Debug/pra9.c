#include <stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int n)   
 {
    for (int i = 0; i < n - 1; i++)
     {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1])
             {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    printf("Select sorting method:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}