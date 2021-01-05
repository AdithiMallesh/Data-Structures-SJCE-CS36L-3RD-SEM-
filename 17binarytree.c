/*17.	Develop a menu driven program to implement Binary Tree/Binary search tree to perform the following operations.
i)Insertion   ii)  Traversing in different order(Depth first Traversal)    iii)  Search and display the node and its parent node.    iv)  Count No of Leaves    
*/
/*18.	Develop a menu driven program to implement Binary Tree/Binary search tree to perform the following operations.
i)Insertion   ii)  Traversing in different order(Depth first Traversal)    iii)  Search and display the node and its parent node.    iv)  Count No of non Leaves    
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{
    int info;
    struct NODE* left;
    struct NODE* right;
};
typedef struct NODE* node;

node INSERT(node R){
    int i;
    char dir[10];
    node NN=(node)malloc(sizeof(struct NODE));
    printf("Enter the info:");
    scanf("%d",&NN->info);
    NN->left=NN->right=NULL;
    if(R==NULL){
        printf("node inserted as the root\n");
        return NN;
    }
    direct: printf("Enter the direction:");
    scanf("%s",dir);
    node CN=R,PN=NULL;  /*CN=CURRENT NODE  PN=PREVIOUS NODE*/
    for(i=0;i<strlen(dir);i++){
        PN=CN;
        if(CN==NULL) break;
        if(dir[i]=='L' || dir[i]=='l') CN=CN->left;
        else if(dir[i]=='R' || dir[i]=='r') CN=CN->right;
        else break;
    }
    if(i!=strlen(dir) || CN!=NULL){
        printf("Invalid direction or node already exit at given direction\n");
        goto direct;
    }
    if(dir[i-1]=='L' || dir[i-1]=='l') PN->left=NN; 
    else if(dir[i-1]=='R' || dir[i-1]=='r') PN->right=NN; 
    printf("Insertion successfull\n");
    return R;
}

void inOrder(node R){
    if(R==NULL) return;
    inOrder(R->left);
    printf("%d ",R->info);
    inOrder(R->right);
}
void postOrder(node R){
    if(R==NULL) return;
    postOrder(R->left);
    postOrder(R->right);
    printf("%d ",R->info);
}
void preOrder(node R){
    if(R==NULL) return;
    printf("%d ",R->info);
    preOrder(R->left);
    preOrder(R->right);
}

void displayTree(node R){
    if(R==NULL){
        printf("Tree is empty\n");
        return;
    }
    printf("\nInOrder Traversal: "); inOrder(R);
    printf("\nPostOrder Traversal: "); postOrder(R);
    printf("\nPreOrder Traversal: "); preOrder(R);
    printf("\n");
}

node SEARCH(node R, int info,node* PN)   /*PN=PARENT NODE*/
{
    if(R==NULL) return NULL;
    node NS=NULL;   /*NS=node to be searched*/
    if(R->info==info){
        NS=R;
    }
    if(NS==NULL){
        *PN=R;
        NS=SEARCH(R->left,info,PN);
    }
    if(NS==NULL){
        *PN=R;
        NS=SEARCH(R->right,info,PN);
    }
    return NS;
}
int NODES(node R){
    if(R==NULL) return 0;
    return NODES(R->left)+1+NODES(R->right);
}
int LEAVES(node R){
    if(R==NULL) return 0;
    if(R->left==NULL && R->right==NULL) return 1;
    return LEAVES(R->left)+LEAVES(R->right);
}
int main(){
    int choice,info;
    node root=NULL;
    node NS=NULL;
    node PN=NULL;
    while(1)
    {
        printf("0.Exit\n ");
        printf("1.insert\n");
        printf("2.display\n");
        printf("3.search\n");
        printf("4.no of leaves \n");
        printf("5.no of non leaves \n");
        printf(" enter chaince\n");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: root=INSERT(root);
                        break;
            case 2: displayTree(root);
                         break;
            case 3: printf("Enter the info of the node to be searched:");
                    scanf("%d",&info);
                    if(root==NULL){
                        printf("Tree is empty\n");
                    }else if(root->info==info){
                        printf("Searching node info = %d and it is the root of the tree\n",root->info);
                    }else{
                        NS=SEARCH(root,info,&PN);
                        if(NS==NULL){
                            printf("Node with info = %d doesn't exist in the tree\n",info);
                        }else{
                        printf("Searching node info = %d and it's parent node info = %d\n",NS->info,PN->info);
                        }
                    }
                    break;
            case 4: printf("number of leaves in tree: %d\n",LEAVES(root));
                    break;
            case 5: printf("number of non-leaves in tree: %d\n",NODES(root)-LEAVES(root));
                    break;
            default: printf("INVALID");
        }
    }
}