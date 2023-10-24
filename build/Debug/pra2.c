#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,*ptr, i, ch=0;
    printf("\nEnter intitial size of a list :");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    for( i = 0; i <n; i++)
    {
        printf("\nEnter an Element ;");
        scanf("%d",&ptr[i]);
    }
    printf("\n\nElements are >>");
    for (i = 0; i <n; i++)
    {
        printf("%d >>",ptr[i]);
    }
    do
    {
        printf("\n\nEnter 1. to Add an Element");
        printf("\n\nEnter 2. to Delete Last Element");
        printf("\n\nEnter 3. to Display List");
        printf("\n\nEnter 4. to Reset List");
        printf("\n\nEnter 5. to Exit");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
               ptr=realloc(ptr,++n);
               printf("\nEnter an Element :");
               scanf("%d",&ptr[n-1]);
            break;
        case 2:
            n=n-1;
            ptr=realloc(ptr,n);
            printf("\nLast Element Deleted...");
            break;
        case 3:
            printf("\n\nElements are >>");
            for (i = 0; i<n; i++)
            {
               printf("%d >>",ptr[i]);
            }
            break;
        case 4:
            ptr=(int*)calloc(n,sizeof(int));
            printf("\nElement are reset");
            for (i = 0; i <n; i++)
            {
                printf("%d >>",ptr[i]);
            }
            break;
        case 5:
            exit(0);
        }

    } while (ch<=5 && ch>0);
    return 0;
}