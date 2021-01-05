/*Implement Binary Tree with the following operations:
a) Insertion
b) Traversals
c) Search
d) Finding Height
f)  Creating a Copy of the tree
d) Deletion*/
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
node DELETE(node R){
    if(R==NULL){
        printf("Tree is empty\n");
        return NULL;
    }
    int info;
    printf("Enter the info of the node to be deleted:");
    scanf("%d",&info);
    
    /*ROOT WITH CHILDREN*/
    if(R->info==info && (R->left!=NULL || R->right!=NULL)){
        printf("Root node can't be deleted unless it has no child.\n");
        return R;
    }
    /*CASE 1: ROOT WITH NO CHILDREN*/
    if(R->info==info && R->left==NULL && R->right==NULL){
        printf("Deleted root node with info = %d\n",R->info);
        free(R);
        return NULL;
    }
    
    
    node PN;
    node ND=SEARCH(R,info,&PN);  /*ND=NODE TO BE DELETED*/
    if(ND==NULL){
        printf("Node with info = %d doesn't exist in the tree\n",info);
        return R;
    }else{
        printf("Deleting node info = %d and it's parent node info = %d\n",ND->info,PN->info);
    }

    /*CASE 2: LEAF NODE*/
    if(ND->left==NULL && ND->right==NULL){
        if(ND==PN->left) PN->left=NULL;
        else PN->right=NULL;
        free(ND);
    }

    /*CASE 3: NON-LEAF WITH ONE CHILD*/
    else if((ND->left!=NULL && ND->right==NULL)
            ||(ND->left==NULL && ND->right!=NULL)){
                
                if(ND->right==NULL)      /*LEFT CHILD*/
                {
                    if(ND==PN->left) PN->left=ND->left;
                    else PN->right=ND->left;
                }
                                        /*RIGHT CHILD*/
                else{
                    if(ND==PN->left) PN->left=ND->right;
                    else PN->right=ND->right;
                }
            free(ND);
        }
    
    /*CASE 4:NON-LEAF WITH TWO CHILDREN*/
    else{
        node IS=ND->right, ISP = ND;
        //? IS= inorder successor, ISP= inorder successor's parent.
        while(IS->left!=NULL){
            ISP=IS;
            IS=IS->left;
        }
        ND->info=IS->info;
        if(IS->left==NULL && IS->right==NULL){
            if(IS==ISP->left) ISP->left=NULL;
            else ISP->right=NULL;
        }else{
            if(IS==ISP->left) ISP->left=IS->right;
            else ISP->right=IS->right;
        }
        free(IS);
    }
    printf("Node deleted with info: %d\n",info);
    return R;
}

int HEIGHT(node R){
    if(R==NULL) return 0;
    
    int leftHeight=HEIGHT(R->left);
    int rightHeight=HEIGHT(R->right);

    if(leftHeight>rightHeight) return leftHeight+1;
    return rightHeight+1;
}

node CREATECOPY(node R){
    if(R==NULL) return NULL;
    node temp=(node)malloc(sizeof(struct NODE));
    temp=R;
    temp->left=CREATECOPY(R->left);
    temp->right=CREATECOPY(R->right);
    temp->info=R->info;
    return temp;
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
    while(1){
        printf("\n0.Exit\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Find height\n6.Create a copy of tree\n7.Find total no. of nodes\n8.Find total no. of leaves\n9.Find total no. of non-leaves\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 0: exit(0);
            case 1: root=INSERT(root); break;
            case 2: displayTree(root); break;
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
            case 4: root = DELETE(root);
                    displayTree(root);
                    break;
            case 5: if(root==NULL) printf("Tree is empty\n");
                    else printf("Height of the tree: %d\n",HEIGHT(root)-1);
                    break;
            case 6: if(root==NULL){
                        printf("Tree is empty\n");
                    }else {
                        node copy = CREATECOPY(root);
                        printf("Copy of the tree created:\n");
                        displayTree(copy);
                    }
                    break;
            case 7: printf("number of nodes in tree: %d\n",NODES(root));
                    break;
            case 8: printf("number of leaves in tree: %d\n",LEAVES(root));
                    break;
            case 9: printf("number of non-leaves in tree: %d\n",NODES(root)-LEAVES(root));
                    break;
            default: printf("INVALID");
        }
    }
}