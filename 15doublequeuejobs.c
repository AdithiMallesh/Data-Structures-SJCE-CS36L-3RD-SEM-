/*15.	To implement  Double Ended  Queue of Jobs (where each Job is associated with the attributes: Jobid, Jobname, Time required to complete the job) 
 with  dynamic  memory  allocation mechanism using array storage representation.(Represent Queue using structure)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size;
struct Queue
{	
	int Jobids;
  char Jobname[20];
  char time[20];
};
int f, r;
typedef struct Queue QUE;
void InsertRear(QUE *);
void DeleteFront(QUE *);
void InsertFront(QUE *);
void DeleteRear(QUE *);
void Disp(QUE *);
int main( )
{
	int ch;
	QUE *Q;
	f = 0; r = -1;
	printf("Enter the size of the queue\n");
	scanf("%d",&size);
	Q=(QUE *)malloc(size*sizeof(QUE));
  printf("%ld",sizeof(*Q));
	for( ; ; )
	{
		printf("\nEnter choice : \n1:InsertFront\n2:InsertRear\n3:DeleteFront\n4:DeleteRear\n5:Display\n6:Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: InsertFront(Q);
              Disp(Q);
              break;
			case 2: InsertRear(Q);
              Disp(Q);
              break;
			case 3: DeleteFront(Q);
              Disp(Q);
              break;
			case 4: DeleteRear(Q);
              Disp(Q);
              break;
			case 5: Disp(Q);
              break;
			case 6: exit(0);
		}
	}
}
void InsertRear(QUE *Q)
{
  int id; 
  char name[20];
  char time[20];
	if(r==size-1)
	{	
		printf("Queue full\n");
		printf ("Reallocating queue by doubling the size\n");
		Q=(QUE*)realloc(Q,size*2);
	}
	printf("Enter id : ");
	scanf("%d", &id);
  
  printf("Enter name : ");
	scanf("%s", name);
  printf("Enter time : "); 
	scanf("%s", time);
  printf("here");
	++r;
  printf("here:%ld\n",sizeof(Q));
	(Q+r)->Jobids = id;
  strcpy((Q + r)->Jobname, name);
  strcpy((Q + r)->time, time);
}

void DeleteFront(QUE *Q)
{
	if(f>r)
	{	
		printf("Queue Empty\n");
		return;
	}
	printf("deleted %d\n", (Q+f++)->Jobids);
}

void InsertFront(QUE *Q)
{	
	int id;
  char name[20];
  char time[20];
	if(f==0 && r==size-1)
	{	printf("Queue Full\n");
		printf("Reallocating queue by doubling the size\n");
		Q=(QUE *)realloc(Q,size*2);
	}
  else if(f==0){ 
		printf("Front Insertion is not possible\n");
  }
	printf("Enter id : ");
	scanf("%d", &id);
  printf("Enter name : ");
	scanf("%s", name);
  printf("Enter time : ");
	scanf("%s", time);
  
	if(f>r){
    ++r;
    (Q+r)->Jobids = id;
    strcpy((Q + r)->Jobname, name);
    strcpy((Q + r)->time, time);
  }	
	else{
    if(f>0){
      --f;
		  (Q+f)->Jobids= id;
      strcpy((Q + f)->Jobname, name);
      strcpy((Q + f)->time, time);
    }  
	  
  }
	
}
void DeleteRear(QUE *Q)
{
	if(f>r)
	{	
    printf("Queue Empty\n");
		return;
	}
	printf("Deleted %d\n",(Q + r--)->Jobids);
}		
void Disp(QUE *Q)
{	int i;
	if(f>r)
	{	printf("Queue Empty\n");
		return;
	}
	for(i=f; i<=r; i++){
    printf("id-%d  ", (Q+i)->Jobids);
		printf("name-%s ", (Q+i)->Jobname);
		printf("time-%s \n ", (Q+i)->time);
  }
}	