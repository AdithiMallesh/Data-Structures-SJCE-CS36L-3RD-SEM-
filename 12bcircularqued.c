/*12 b)To implement Circular Queue with  dynamic memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include<stdio.h>
#include<stdlib.h>
int size;
struct circular
{
	int *ele;
	int f, r;
	int cnt;
};
typedef struct circular QUE;
void Insert(QUE *);
void Delete(QUE *);
void Disp(QUE *);
int main( )
{
	int ch;
	QUE Q;
	Q.f = 0; Q.r = -1; Q.cnt = 0;
	system("clear");
	printf("Enter the size of the queue\n");
	scanf("%d", &size);
	Q.ele=(int*)malloc(size*sizeof(int));
	for( ; ; )
	{
 		printf("Enter choice:\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : Insert(&Q); Disp(&Q); break;
			case 2 : Delete(&Q); Disp(&Q); break;
			case 3 : Disp(&Q); break;
			default : exit(0);
		}
	}
}
void Insert(QUE *Q)
{
	int item;
	if(Q->cnt==size)
	{
		printf("Queue full\n");
		printf("Reallocating queue by doubling the size...\n");
		size = size*2;
		Q->ele = (int*)realloc(Q->ele,size);
	}
	printf("Enter item : ");
	scanf("%d", &item);
	Q->r = (Q->r+1)%size;
	*(Q->ele+Q->r) = item;
	Q->cnt++;
}
void Delete(QUE *Q)
{
	if(Q->cnt==0)
	{
		printf("Queue empty\n");
		return;
	}
	printf("deleted %d\n", *(Q->ele+Q->f));
	Q->f=(Q->f+1)%size;
	Q->cnt--;
}
void Disp(QUE *Q)
{	int i, j;
	if(Q->cnt==0)
	{	printf("Queue empty\n");
		return;
	}
	j = Q->f;
	for(i=1;i<=Q->cnt;i++)
	{
		printf("%d ", *(Q->ele+j));
		j = (j+1)%size;
	}
}