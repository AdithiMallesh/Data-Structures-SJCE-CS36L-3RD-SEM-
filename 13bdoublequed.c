/*13b). To implement Double Ended Queue with dynamic memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include<stdio.h>
#include<stdlib.h>
int size;
struct doubleq
{	
	int *ele;
	int f, r;
};
typedef struct doubleq que;
void InsertRear(que*);
void DeleteFront(que *);
void InsertFront(que *);
void DeleteRear(que *);
void Disp(que *);
int main( )
{
	int ch;
	que Q;
	Q.f = 0; Q.r = -1;
	system("clear");
	printf("Enter the size of the queue\n");
	scanf("%d",&size);
	Q.ele=(int*)malloc(size*sizeof(int));
	for( ; ; )
	{
		printf("Enter choice : \n1:to perform InsertFront\n2:to perfrom InsertRear\n3: to perform DeleteFront\n4:to perform DeleteRear\n5:Display\n6:Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: InsertFront(&Q); 
			            Disp(&Q); 
			             break;
			case 2: InsertRear(&Q);
			            Disp(&Q);
			              break;
			case 3: DeleteFront(&Q);
			            Disp(&Q);
		                	break;
			case 4: DeleteRear(&Q);
			            Disp(&Q);
			            break;
			case 5: Disp(&Q);
			            break;
			case 6: exit(0);
		}
	}
}
void InsertRear(que *Q)
{
	int item;
	if(Q->r==size-1)
	{	
		printf("Queue full\n");
		printf("Reallocating queue by doubling the size\n");
		Q->ele=(int*)realloc(Q->ele,size*2);
	}
	printf("Enter item : ");
	scanf("%d", &item);
	Q->r++;
	*(Q->ele+Q->r) = item;
}
void DeleteFront(que *Q)
{
	if(Q->f>Q->r)
	{	
		printf("Queue Empty\n");
		return;
	}
	printf("deleted %d\n", *(Q->ele+Q->f++));
}
void InsertFront(que *Q)
{	
	int item;
	if(Q->f==0 && Q->r==size-1)
	{	printf("Queue Full\n");
		printf("Reallocating queue by doubling the size\n");
		Q->ele=(int*)realloc(Q->ele,size*2);
	}
	printf("Enter item : ");
	scanf("%d", &item);
	if(Q->f>Q->r)
		*(Q->ele + ++Q->r)=item;
	else
	if(Q->f>0)
		*(Q->ele + --Q->f)=item;
	else
		printf("Front Insertion is not possible\n");
}
void DeleteRear(que *Q)
{
	if(Q->f>Q->r)
	{	printf("Queue Empty\n");
		return;
	}
	printf("Deleted %d\n",*(Q->ele+Q->r--));
}		
void Disp(que *Q)
{	int i;
	if(Q->f>Q->r)
	{	printf("Queue Empty\n");
		return;
	}
	for(i=Q->f; i<=Q->r; i++)
		printf("%d  ", *(Q->ele+i));
}
	