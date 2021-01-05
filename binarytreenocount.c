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

node DELETE(node R)
{
    if(R==NULL)
    {
        printf("Tree is empty\n");
        return NULL;
    }
    int info;
    printf("Enter the info of the node to be deleted:");
    scanf("%d",&info);
    
    
    /*ROOT WITH NO CHILDREN*/
    if(R->ele==info && R->lf==NULL && R->rt==NULL)
    {
        printf("Deleted root node with info = %d\n",R->ele);
        free(R);
        return NULL;
    }
    
    node PN;
    node ND=SEARCH(R,info,&PN);
    if(ND==NULL)
    {
        printf("INVALID\n",info);
        return R;
    }
    else
    {
        printf("Deleting node info = %d and it's parent node info = %d\n",ND->ele,PN->ele);
    }

    /*LEAF NODE*/
    if(ND->lf==NULL && ND->rt==NULL)
    {
        if(ND==PN->lf) PN->lf=NULL;
        else PN->rt=NULL;
        free(ND);
    }

    /*NON-LEAF WITH ONE CHILD*/
    else if((ND->lf!=NULL && ND->rt==NULL)
            ||(ND->lf==NULL && ND->rt!=NULL))
            {
                
                if(ND->rt==NULL)              /*LEFT CHILD*/
                {
                    if(ND==PN->lf) PN->lf=ND->lf;
                    else PN->rt=ND->lf;
                }
                
                else
                {
                    if(ND==PN->lf) PN->lf=ND->rt;     /*RIGHT CHILD*/
                    else PN->rt=ND->rt;
                }
            free(ND);
        }
    
    /*NON-LEAF WITH TWO CHILDREN*/
    else
    {
        node IS=ND->rt, ISP = ND;
        //? IS= INORDER successor, ISP= INORDER successor's parent.
        while(IS->lf!=NULL){
            ISP=IS;
            IS=IS->lf;
        }
        ND->ele=IS->ele;
        if(IS->lf==NULL && IS->rt==NULL){
            if(IS==ISP->lf) ISP->lf=NULL;
            else ISP->rt=NULL;
        }else{
            if(IS==ISP->lf) ISP->lf=IS->rt;
            else ISP->rt=IS->rt;
        }
        free(IS);
    }
    printf("Node deleted with info: %d\n",info);
    return R;
}

int HEIGHT(node R)
{
    if(R==NULL) return 0;
    
    int leftHeight=HEIGHT(R->lf);
    int rightHeight=HEIGHT(R->rt);

    if(leftHeight>rightHeight) 
    return leftHeight+1;
    return rightHeight+1;
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
        printf("4.Delete a node from the tree\n");
        printf("5.Height of the tree\n");
        printf("6.Create a copy of given tree\n");
        printf("7.Exit\n");
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
            case 4: root = DELETE(root);
                    DISPLAY(root);
                    break;
            case 5: printf("Height of the tree is : %d\n",HEIGHT(root));
                    break;
            case 6: if(root==NULL){
                        printf("Tree is empty\n");
                    }else {
                        node copy = CREATECOPY(root);
                        printf("Copy of the tree is created:\n");
                        DISPLAY(copy);
                    }
            case 7: exit(0);
                    break;
            default: printf("INVALID CHOICE");
        }
    }
}

