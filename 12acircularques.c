/*  12 a) To implement Circular Queue with static  memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include <stdio.h>
#include<stdlib.h>
#define size 10

void insert(int[], int);
void delete(int[]);
void display(int[]);
int f =  - 1;
int r =  - 1;
void insert(int queue[], int item)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    { printf("queue overflow");
        return;
     } else if (r ==  - 1)
    {
        r++;
        f++;
    }
    else if (r == size - 1 && f > 0)
    { r = 0;
    }  else
    {
        r++; }
    queue[r] = item;
}
void display(int queue[])
{ int i;
    if (f > r)
    { for (i = f; i < size; i++)
        {   printf("%d ", queue[i]);
        }
        for (i = 0; i <= r; i++)
            printf("%d ", queue[i]);
    }  else
    { for (i = f; i <= r; i++)
            printf("%d ", queue[i]);
    }
}

void delete(int queue[])
{  if (f ==  - 1)
    { printf("Queue underflow ");
    }
    else if (f == r)
    { printf("\n %d  is deleted", queue[f]);
        f =  - 1;
        r =  - 1;
    }
    else  {
        printf("\n %d is deleted", queue[f]);
        f++;
    }
}
int main()
{
    int n, choice;
    int queue[size];
    while(1)
    {
        printf("\n1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nenter element to be insert: ");
                scanf("%d", &n);
                insert(queue, n);
                break;
            case 2:
                delete(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        }
    }
}