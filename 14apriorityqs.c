/* 14 a) 9. To implement Priority Queue with static memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include <stdio.h>

#define MAX 10

typedef struct {
    int ele[MAX];
    int f, r;
} Priority;
void Menu() {
    printf("1. insert element\n");
    printf("2. delete element\n");
    printf("3. display the queue \n");
    printf("4. exit \n");
}

int main() {
    Priority q;
    initQueue(&q);

    int exit = 1;
    while (exit) {
        Menu();
        printf("Enter your choice: ");
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert(&q);
                    display(&q);
                    break;
            case 2: delete(&q);
                    display(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit = 0;
                    break;
            default:
                    printf("Invalid choice. \n");
        }
    }
    return 0;
}
void initQueue(Priority* q) {
    q->f = 0;
    q->r = -1;
}

void insert(Priority* q) {
    if (q->r == MAX) {

        printf("Queue is full. \n");
        return;
    }

    int item;
    printf("Enter element to insert: ");
    scanf("%d", &item);
    q->ele[++q->r] = item;
}

void delete(Priority* q) {
    if (q->f> q->r) {
        printf("Queue is empty. \n");
        return;
    }

    int mini = 0, min = q->ele[0], i;
    for (i = q->f; i <= q->r; i++) {
        if (q->ele[i] < min) {
            min = q->ele[i];
            mini = i;
        }
    }

    for (i = mini; i < q->r; i++)
        q->ele[i] = q->ele[i+1];

    q->r--;

    printf("deleted %d \n", min);
}


void display(Priority *q) {
    if (q->f> q->r) {

        printf("Queue is empty. \n");
        return;
    }

    int i;
    for (i = q->f; i <= q->r; i++)
        printf("%d ", q->ele[i]);
}
