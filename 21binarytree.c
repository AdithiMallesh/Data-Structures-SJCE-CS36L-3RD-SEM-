/*21.	  Develop a menu driven program to implement Binary Tree/Binary search tree to perform the following operations.
     i)Insertion   ii)  Traversing in different order(Depth first Traversal)    iii)  Search and display the node and its parent node.    iv)  To Create a copy of the tree.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TREE
{
    int ele;
    struct TREE* lf;
    struct TREE* rt;
};
typedef struct TREE* node;
node INSERT(node R)
{
    int i;
    char dir[6];
    node NN=(node)malloc(sizeof(struct TREE));
    printf("Enter the element to be inserted:");
    scanf("%d",&NN->ele);
    NN->lf=NN->rt=NULL;
    if(R==NULL)
    {
        printf("New node inserted as the root\n");
        return NN;
    }
    direct: printf("Enter direction to insert:");
    scanf("%s",dir);
    node CN=R,PN=NULL;
    for(i=0;i<strlen(dir);i++)
    {
        PN=CN;
        if(CN==NULL) break;
        if(dir[i]=='L' || dir[i]=='l') CN=CN->lf;
        else if(dir[i]=='R' || dir[i]=='r') CN=CN->rt;
        else break;
    }
    if(i!=strlen(dir) || CN!=NULL)
    {
        printf("INVALID DIRECTION\n");
        goto direct;
    }
    if(dir[i-1]=='L' || dir[i-1]=='l')
    PN->lf=NN; 
    else if(dir[i-1]=='R' || dir[i-1]=='r') 
    PN->rt=NN; 
    printf("INSERTION SUCCESSFULL\n");
    return R;
}

void INORDER(node R)
{
    if(R==NULL) return;
    INORDER(R->lf);
    printf("%d ",R->ele);
    INORDER(R->rt);
}

void PREORDER(node R)
{
    if(R==NULL) return;
    printf("%d ",R->ele);
    PREORDER(R->lf);
    PREORDER(R->rt);
}

void POSTORDER(node R)
{
    if(R==NULL) return;
    POSTORDER(R->lf);
    POSTORDER(R->rt);
    printf("%d ",R->ele);
}

void DISPLAY(node R)
{
    if(R==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    printf("\nINORDER Traversal: "); 
    INORDER(R);
    printf("\nPREORDER Traversal: "); 
    PREORDER(R);
    printf("\nPOSTORDER Traversal: "); 
    POSTORDER(R);
    printf("\n");
}
node SEARCH(node R, int info,node* PN)
{
    if(R==NULL) return NULL;
    node NS=NULL;
    if(R->ele==info)
    {
        NS=R;
    }
    if(NS==NULL)
    {
        *PN=R;
        NS=SEARCH(R->lf,info,PN);
    }
    if(NS==NULL)
    {
        *PN=R;
        NS=SEARCH(R->rt,info,PN);
    }
    return NS;
}
node CREATECOPY(node R)
{
    if(R==NULL) return NULL;
    node temp=(node)malloc(sizeof(struct TREE));
    temp=R;
    temp->lf=CREATECOPY(R->lf);
    temp->rt=CREATECOPY(R->rt);
    temp->ele=R->ele;
    return temp;
}
int main()
{
    int ch,info;
    node root=NULL;
    node NS=NULL;
    node PN=NULL;
    while(1)
    {
        printf("1.Insert a node to the tree\n");
        printf("2.Display the tree\n");
        printf("3.Search a node in the tree\n");   
        printf("4.Create a copy of given tree\n");
        printf("5.Exit\n");
        printf("choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            
            case 1: root=INSERT(root);
                         break;
            case 2: DISPLAY(root);
                         break;
            case 3: printf("Enter the element of the node to be searched in the tree:");
                         scanf("%d",&info);
                         if(root==NULL)
                         {
                        printf("Tree is empty\n");
                        }
                        else if(root->ele==info)
                        {
                        printf("Searching node elemeny = %d and it is the root of the tree\n",root->ele);
                         }
                         else
                         {
                        NS=SEARCH(root,info,&PN);
                        if(NS==NULL)
                        {
                            printf("Node with elemnt = %d doesn't exist in the tree\n",info);
                        }
                        else
                        {
                        printf("Searching node element = %d and it's parent node element = %d\n",NS->ele,PN->ele);
                        }
                    }
                    break;
            case 4: if(root==NULL){
                        printf("Tree is empty\n");
                    }else {
                        node copy = CREATECOPY(root);
                        printf("Copy of the tree is created:\n");
                        DISPLAY(copy);
                    }
            case 5: exit(0);
                    break;
            default: printf("INVALID CHOICE");
        }
    }
}