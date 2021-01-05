/*2.	Implement circular single linked list with  header node to perform the following operations
      i) Insert by order    ii ) Delete by position  iii) Search  for an item by key
             Display the list contents after each operation*/

#include <stdio.h>
#include <stdlib.h>
struct node {
    int info;
    struct node* link;
};
typedef struct node* Node;
Node createCLL() {
    Node header = (Node) malloc(sizeof(struct node));
    header->info = 0;
    header->link = NULL;
    return header;
}
void insertByOrder(Node H) {
    H->info++;
    Node newNode = (Node) malloc(sizeof(struct node));
    printf("Enter element to insert by order: ");
    scanf("%d", &newNode->info);

    if (H->link == NULL) {
        newNode->link = newNode;
        H->link = newNode;
        return;
    }

    if (H->link->info < newNode->info) {
        newNode->link = H->link->link;
        H->link->link = newNode;
        H->link = newNode;
        return;
    }

    Node tempNode = H->link->link, prevNode = H->link;

    while (tempNode->info < newNode->info){
        prevNode = tempNode;
        tempNode = tempNode->link;
    }

    newNode->link = tempNode;
    prevNode->link = newNode;
}
void deleteAtPos(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int pos;
    printf("Enter position to delete at: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > H->info) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1 && H->link->link == H->link) {
        free(H->link);
        H->link = NULL;
        return;
    }

    int cnt = 1;
    Node tempNode = H->link->link, prevNode = H->link;
    while (cnt < pos) {
        prevNode = tempNode;
        tempNode = tempNode->link;
        cnt++;
    }
    prevNode->link = tempNode->link;
    free(tempNode);

    if (pos == H->info) {
        H->link = prevNode;
    }

    H->info--;
}
void search(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    int key;
    printf("Enter your key to search: ");
    scanf("%d", &key);

    if (H->link->link->info == key) {
        printf("Element %d found at position 1", key);
        return;
    }

    int cnt = 1;
    Node tempNode = H->link->link;
    do {
        tempNode = tempNode->link;
        cnt++;
    } while (tempNode != H->link->link && tempNode->info != key);

    if (tempNode == H->link->link) {
        printf("Key not found in list.\n");
        return;
    }

    printf("Element %d found at position %d\n", key, cnt);
}
void display(Node H) {
    if (H->info == 0) {
        printf("List is empty. \n");
        return;
    }

    Node tempNode = H->link->link;
    do {
        printf("%d ", tempNode->info);
        tempNode = tempNode->link;
    } while (tempNode != H->link->link);
    putchar('\n');
}
int main() {
    Node header = createCLL();
    int isRunning = 1, ch;
    while(isRunning==1)
    {
        printf("0:Display\n1:Insert by order\n2:delete at pos\n3:search\n4:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0: display(header);
                break;
        case 1:insertByOrder(header);
                display(header);
                break;
       case 2: deleteAtPos(header);
                display(header);
                break;   
        case 3: search(header);
                break;                                  
        default: exit(0);
        }
    }
    return 0;
}