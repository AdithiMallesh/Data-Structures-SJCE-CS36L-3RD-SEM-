/*9. To implement Priority Queue with dynamic memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include <stdio.h>
#include <stdlib.h>

#define QUEUE 10

typedef struct {
    int *ele;
    int f, r;
    int cnt;
} Priority;
void Menu() {
    printf("1.element insert \n");
    printf("2. element to delete \n");
    printf("3. displaythe queue \n");
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
    q->cnt = QUEUE;
    q->f = 0;
    q->r = -1;

    q->ele = (int*) malloc(q->cnt * sizeof(int));
}

void insert(Priority* q) {
    if (q->r == q->cnt-1) {

        printf("Reallocating queue. \n");
        q->cnt *= 2;
        q->ele= (int*) realloc(q->ele, q->cnt* sizeof(int));
    }

    int item;
    printf("Enter element to enqueue: ");
    scanf("%d", &item);
    *(q->ele + ++q->r) = item;
}

void delete(Priority* q) {
    if (q->f > q->r) {
        printf("Queue is empty. \n");
        return;
    }

    int mini = 0, min = *q->ele, i;
    for (i = q->f; i <= q->r; i++) {
        if (*(q->ele + i) < min) {
            min = *(q->ele + i);
            mini = i;
        }
    }

    for (i = mini; i < q->r; i++)
        *(q->ele+ i) = *(q->ele + i + 1);

    q->r--;

    printf("Deleted %d \n", min);
}


void display(Priority *q) {
    if (q->f > q->r) {

        printf("Queue is empty. \n");
        return;
    }

    int i;
    for (i = q->f; i <= q->r; i++)
        printf("%d ", *(q->ele + i));
}