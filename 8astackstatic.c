/*8.Develop a menu driven program to implement Stack with static 
memory allocation mechanism using array storage representation.(Represent
Stack using structure)*/
#include <stdio.h>

#define MAX_STACKARR_SIZE 10

typedef struct stack {
    int top;
    int item[MAX_STACKARR_SIZE];
} Stack;

void push(Stack* s) {
    if (s->top == MAX_STACKARR_SIZE-1) {
        printf("Stack is full. Stack overflow. \n");
        return;
    }

    int ele;
    printf("Enter element to push into stack: ");
    scanf("%d", &ele);

    s->item[++s->top] = ele;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty. Stack underflow. \n");
        return -1;
    }
    int poped = s->item[s->top--];
    printf("Popped element : %d\n", poped);
    return poped;
}

int peek(Stack* s) {
    if (s->top== -1) {
        printf("Stack is empty. \n");
        return -1;
    }
    printf("Top of the stack has the element : %d\n", s->item[s->top]);
    return s->item[s->top];
}

void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty. \n");
        return;
    }

    printf("top = %d\n", s->top);
    int i;
    for (i = 0; i <= s->top; i++)
        printf("%d ", s->item[i]);
    printf("\n");
}

void initStack(Stack *s) {
    s->top= -1;
}

void Menu() {
    printf("1. push elements\n");
    printf("2. pop elements \n");
    printf("3. Peek from the stack\n");
    printf("4. display\n");
    printf("5. Exit\n");
}

int main() {
    Stack s;
    initStack(&s);

    int isRunning = 1;
    while (isRunning) {
        Menu();
        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push(&s);
                display(&s);
                break;
            case 2:
                pop(&s);
                display(&s);
                break;
            case 3:
                peek(&s);
                display(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                isRunning = 0;
                break;
            default:
                printf("Invalid choice. \n");
        }
    }
    return 0;
}
