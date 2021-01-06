/*13a) To implement Double Ended Queue with static  memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include<stdio.h>
#define size 100
struct Queue
{	
	int items[100];
	int f, r;
};
typedef struct Queue QUE;
void InsertRear(QUE *);
void DeleteFront(QUE *);
void InsertFront(QUE *);
void DeleteRear(QUE *);
void Disp(QUE *);
void main( )
{
	int ch;
	QUE Q;
	Q.f = 0; Q.r = -1;
	system("clear");
	for( ; ; )
	{
		printf("Enter choice : \n1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:Display\n6:Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: InsertFront(&Q); Disp(&Q); break;
			case 2: InsertRear(&Q);Disp(&Q);break;
			case 3: DeleteFront(&Q);Disp(&Q);break;
			case 4: DeleteRear(&Q);Disp(&Q);break;
			case 5: Disp(&Q);break;
			case 6: exit(0);
		}
	}
}
void InsertRear( QUE *Q)
{
	int item;
	if(Q->r==size-1)
	{	
		printf("Queue full\n");
		return;
	}
	printf("Enter item : ");
	scanf("%d", &item);
	Q->r++;
	Q->items[Q->r] = item;
}
void DeleteFront(QUE *Q)
{
	if(Q->f>Q->r)
	{	
		printf("Queue Empty\n");
		return;
	}
	printf("deleted %d\n", Q->items[Q->f++]);
}
void InsertFront(QUE *Q)
{	
	int item;
	if(Q->f==0 && Q->r==size-1)
	{	printf("Queue Full\n");
		return;
	}
	printf("Enter item : ");
	scanf("%d", &item);
	if(Q->f>Q->r)
		Q->items[++Q->r]=item;
	else
	if(Q->f>0)
		Q->items[--Q->f]=item;
	else
		printf("Front Insertion is not possible\n");
}
void DeleteRear(QUE *Q)
{
	if(Q->f>Q->r)
	{	printf("Queue Empty\n");
		return;
	}
	printf("Deleted %d\n",Q->items[Q->r--]);
}		
void Disp(QUE *Q)
{	int i;
	if(Q->f>Q->r)
	{	printf("Queue Empty\n");
		return;
	}
	for(i=Q->f; i<=Q->r; i++)
		printf("%d  ", Q->items[i]);
}
	