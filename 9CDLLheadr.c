/*9.	Implement circular double  linked list with  header node  perform the following operations
i)Insert by position ii) Delete rear iii) Search  for an item by value
             Display the list contents after each operation*/
#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};
typedef struct NODE * node;
void insertByPosition(node H){
    int position,count=1;
    printf("Enter the position for new node to be inserted:\n");
    scanf("%d",&position);
    if(position>=1 && position<=H->data+1)
    {

    node n,temp=H;
    n=(node)malloc(sizeof(struct NODE));
    printf("Enter the data:\n");
    scanf("%d",&n->data);
        while(count<position){
            temp=temp->next;
            count++;
        }
        n->next=temp->next;
        n->prev=temp;
        temp->next=n;
        n->next->prev=n;
        H->data++;
    }else{
        printf("Invalid Position\n");
    }
}
void deleteRear(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    node ptr=H->prev;
    printf("Node deleted at rear with data:%d\n",ptr->data);
    ptr->prev->next=H;
    H->prev=ptr->prev;
    H->data--;
    free(ptr);
}
void findNode(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    int position=1,data;
    printf("Enter the data of the node to be searched:\n");
    scanf("%d",&data);
    node temp=H->next;
    while(temp!=H && temp->data!=data){
        temp=temp->next;
        position++;
    }
    if(temp==H){
        printf("Node with data %d doesnt exist\n",data);
    }else{
        printf("Node with data %d exists at position: %d\n",data,position);
    }
}

void display(node H){
    if(H->data==0){
        printf("Empty List\n");
        return;
    }
    node temp;
    temp=H->next;
    printf("Total no. of nodes:%d\n",H->data);
    printf("CDLL:\t");
    while(temp!=H){
        printf("(%d)<->",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice;
    node head;
    head=(node)malloc(sizeof(struct NODE));
    head->data=0;//*keeps the count of total no. of nodes
    head->prev=head->next=head;
    while(1){
        printf("\n1:Insert by pos\n2:delete rare \n3: search by key \n4:display\n5:exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
           
             case 1: insertByPosition(head);    
                    display(head);
                    break;
            case 2: deleteRear(head);    
                    display(head);
                    break;
           
            case 3: findNode(head);
                    break;
             case 4: display(head);
                          break;
            default:exit(0);
        }
    }
    return 0;
}
