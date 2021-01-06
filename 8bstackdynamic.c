/*Develop a menu driven program to implement Stack with  dynamic
memory allocation mechanism using array storage representation.(Represent
Stack using structure) */
#include <stdio.h>
#include <stdlib.h>

#define INIT_STACK_SIZE 100

typedef struct stack {
    int top;
    int size;
    int *data;
} Stack;

void push(Stack* s) {
    if (s->top == s->size-1) {
        printf("Stack is full. Resizing stack \n");
        s->size = s->size * 2;
        s->data = (int*) realloc(s->data, s->size*sizeof(int));
    }

    int ele;
    printf("Enter element to push into stack: ");
    scanf("%d", &ele);

    *(s->data + ++s->top) = ele;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty. Stack underflow. \n");
        return -1;
    }
    int popedEle = *(s->data + s->top--);
    printf("Popped element : %d\n", popedEle);
    return popedEle;
}

int peek(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty. \n");
        return -1;
    }
    printf("Top of the stack has the element : %d\n", *(s->data + s->top));
    return *(s->data + s->top);
}

void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty. \n");
        return;
    }

    int i;
    printf("top = %d, size= %d\n", s->top, s->size);
    for (i = 0; i <= s->top; i++)
        printf("%d ", *(s->data + i));
    printf("\n");
}

void initStack(Stack *s) {
    s->top = -1;
    s->size= INIT_STACK_SIZE;
    s->data = (int*) malloc(s->size * sizeof(int));
}

void deleteStack(Stack *s) {
    free(s->data);
}

void Menu() {
    printf("\n\n\n\n\n\n");
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
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
    deleteStack(&s);
    return 0;
}