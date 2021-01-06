/*6. To implement ordinary Queue with dynamic memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include<stdio.h>
#include<stdlib.h>
int size;
struct Queue
{	
	int *ele;
	int f, r;
};
typedef struct Queue QUE;
void Insert(QUE *);
void Delete(QUE *);
void Disp(QUE *);
int main( )
{
	int ch;
	QUE Q;
	Q.f = 0; Q.r = -1;
	system("clear");
	printf("Enter the size of the queue\n");
	scanf("%d", &size);
	Q.ele= (int *)malloc(size*sizeof(int));
	for( ; ; )
	{
		printf("Enter choice : \n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: Insert(&Q); Disp(&Q); break;
			case 2: Delete(&Q);Disp(&Q);break;
			case 3: Disp(&Q);break;
			case 4: exit(0);
		}
	}
}
void Insert( QUE *Q)
{
	int ele;
	if(Q->r==size-1)
	{	
		printf("Queue full\n");
		printf("Reallocating queue by doubling the size...\n");
		Q->ele = (int *)realloc( Q->ele,size*2);
	}
	printf("Enter item : ");
	scanf("%d", &ele);
	Q->r++;
	Q->ele[Q->r] =ele;
}
void Delete(QUE *Q)
{
	if(Q->f>Q->r)
	{	
		printf("Queue Empty\n");
		return;
	}
	printf("deleted %d\n", Q->ele[Q->f++]);
	if(Q->f>Q->r)
	{
		Q->f=0;
		Q->r=-1;
	}
}
void Disp(QUE *Q)
{	int i;
	if(Q->f>Q->r)
	{	printf("Queue Empty\n");
		return;
	}
	for(i=Q->f; i<=Q->r; i++)
		printf("%d  ", Q->ele[i]);
}	