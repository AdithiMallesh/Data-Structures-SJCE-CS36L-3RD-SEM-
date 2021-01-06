/*5. Develop a menu driven program to implement Circular singly linked list with

various operations such as
i) Insertion and Deletion at front/rear
ii) Insertion and Deletion at the specified position
iii) Delete by Key
iv) Search by key
v) Create an ordered list
vi) Reverse a list
vii) Creating a copy of the list */

#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *link;
};
typedef struct NODE * node;
node InsertFront(node);

node InsertRear(node);
node DeleteFront(node);
node DeleteRear(node);
node InsertPos(node);
node DeletePos(node);
node InsertByOrder(node);
node DeleteKey(node);
void Search(node);

void Disp(node);
int NE=0;
int main()
{
   int ch;
   node last= NULL;   // L2=NULL; //  system("clear")
   for(;;)
   {
      printf("\nenter choice:\n1:InsertFront\n2:Disply\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:InsertByOrder\n9:DeleteByKey\n10:Search Key\n");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1: last =InsertFront(last);
		//printf("in main %d\n", first->info);
		Disp(last);
		break;
	case 2: Disp(last); break;
	case 3: last=InsertRear(last); Disp(last); break;
	case 4: last = DeleteFront(last); Disp(last); break;
	case 5: last = DeleteRear(last); Disp(last); break;
	case 6: last = InsertPos(last); Disp(last); break;
	case 7: last = DeletePos(last); Disp(last);break;
	case 8: last = InsertByOrder(last); Disp(last);break;
	case 9: last = DeleteKey(last);Disp(last);break;
	case 10: Search(last); break;

	default:exit(0);
     }
 }
 //getch();
 }
 node InsertFront(node L)
    {
       node NN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NE++;
       if(L==NULL)
       {
       NN->link=NN;
       return NN;
       }
       NN->link = L->link;
       L->link= NN;
       return L;
    }
node InsertRear(node L)
    {
       node NN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);

       NE++;

       if(L== NULL)
       {
	   NN->link = NN;
       return NN;
       }
      NN->link = L->link;
      L->link = NN;
// L=NN; return L
       return NN;
    }


  void Disp(node L)
   {    node TP;
       if(L==NULL)
       {
	 printf("empty\n");
	 return;

	 }
	 TP = L->link;
       printf("\nList is:\n");
      do
       {
	 printf("%d ",TP->info);
	 TP=TP->link;
       }while(TP!=L->link);
  }
  node DeleteFront(node L)
  {  node ND;
     if(L==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
       ND=L->link;
       printf("\ndeleted %d",ND->info);
       if(L->link ==L)
       L=NULL;
       else
	L->link = ND->link; // L->link->link
       free(ND);
       NE--;
       return L;
  }

 node DeleteRear(node L)
  {  node  PL;
     if(L==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
       NE--;


	  printf("\ndeletd %d",L->info);
	   if(L->link==L)
	     {  free(L);
	     return  NULL;
	      }

	   PL= L->link;
	      while(PL->link !=L)
		     PL = PL->link;
	     PL->link =L->link;

	  free(L);
	  return PL;


  }
   node InsertPos(node L)
    {
       node NN,TN,PN;
       int pos,cnt;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->link=NN;


       printf("\nenter position   from 1 to %d:" ,NE+1);
       scanf("%d",&pos);
       if(pos>=1 && pos<=NE+1)
       {

	    if(pos==1)   // insertfront()
	    {
	       NE++;
	     if(L==NULL)  return NN;

	      NN->link=L->link;
	      L->link= NN;
	      return L;
	     }
	     if(pos == NE+1)
	     {      NE++;
		NN->link= L->link ;
		L->link = NN;
		return NN;
	     }
	 NE++;
	 TN=L->link;   // PN=F
	 PN=NULL;
	 cnt=1;
	 while(cnt<pos)  // cnt<pos-1
	 {
	    PN=TN; // PN= Pn->link cnt++
	    TN=TN->link;
	    cnt++;
	 }
	 PN->link=NN;
	 NN->link=TN;

	return L;
       }
       else

       printf("Invalid position Retry:\n");
       return L;

   }
 node DeletePos(node L)
  {  node TN,PN;
     int pos,cnt;
     if(L == NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
	printf("\nenter position:");
	scanf("%d",&pos);
       if(pos>=1 && pos<=NE)
       {

	 if(pos==1)
	 { NE--;
	   printf("\ndeleted:%d ", L->link->info);
	   if(L==L->link)

	  {

	   free(L); return NULL;
	   }
	   TN = L->link;
	   L->link=TN->link;
	   free(TN);
	   return L;
	 }
	 TN = L->link;
	 PN = NULL;
	 cnt = 1;
	 while(cnt<pos)
	 {
	    PN = TN;
	    TN = TN->link;
	    cnt++;
	 }
	 PN->link = TN->link;
	 printf("\ndeleted:%d ",TN->info);
	 free(TN);
	 if(pos==NE){ NE --; return PN;}
	  NE--;  return L;

       }
       else
	printf("\nInvalid position Retry:");
	return L;
  }
   node InsertByOrder(node L)
    {
       node NN,TN,PN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);

       NN->link=NN;
       NE++;
       if(L==NULL)
	return NN;

	if(NN->info < L->link->info)   //insertfront()
	 {
	  NN->link=L->link;
	  L->link = NN;
	  return L;
	 }
	if(NN->info > L->info)   //rearinsert()
	 {
	  NN->link=L->link;
	  L->link = NN;
	  return NN;
	 }
	TN=L->link;
	PN=NULL;
	do
	{
	  PN=TN;
	  TN=TN->link;
	} while(TN->info < NN->info );
	PN->link=NN;
	NN->link=TN;
	return L;

 }
 node DeleteKey(node L)
  {  node TN,PN;
     int info;// key
     int pos,cnt;
     if(L==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
	printf("\nenter key to be deleted:");
       scanf("%d",&info);

       if(L->link->info==info)
       {  NE--;
	 printf("\ndeleted %d", L->link->info);
	 if(L==L->link){  free(L);  return NULL ;}

	 TN=L->link;
	 L->link=TN->link;
	 free(TN);
	 return L;
       }
       TN=L->link;
       PN=NULL;
       do{

	 PN=TN;
	 TN=TN->link;
       }
       while(TN->info != info && TN!=L->link);

       if(TN==L->link)
       {
	printf("\nseraching node doesn't exist");
	return L;
       }
       PN->link=TN->link;
       printf("\ndeleted %d ", TN->info);
       free(TN);
       NE--;
       if(TN==L) return PN;
       return L;
 }
 void Search(node L)
 {
   node NS;

   int info, pos, flag = 0;
   if(L==NULL)

   {  printf("empty list");
       return ;
   }

   printf("\nenter the key to be searched");
   scanf("%d",&info);
   NS=L->link;
   pos=1;

   do
   {
     if(NS->info==info){flag = 1; break;}
      NS=NS->link;
       pos++;
   }
   while(NS!=L->link);

     if(flag==0)

      printf("\nSearching node doesn't exist in the list");

     else
     printf("\nnode with info %d exists at position %d", NS->info, pos);
}