#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *link;
};
typedef struct NODE *node;
node InsertFront(node);

node InsertRear(node);
node DeleteFront(node);
node DeleteRear(node);
node InsertPos(node);
node DeletePos(node);
node InsertByOrder(node);
node DeleteKey(node);
void Search(node);
node CreateCopy(node);
node Reverse(node);
void Disp(node);
int NE=0;
int main()
{
   int ch;
   node first= NULL, L2=NULL;
   for(;;)
   {
      printf("\nenter choice:\n1:InsertFront\n2:Disply\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:InsertByOrder\n9:DeleteByKey\n10:Search Key\n11:Create Copy\n12:Reverse\n");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1: first =InsertFront(first); // insertfront(&first)
		//printf("in main %d\n", first->info);
		Disp(first);
		break;
	case 2: Disp(first); break;
	case 3: first=InsertRear(first); Disp(first); break;
	case 4: first = DeleteFront(first); Disp(first); break;
	case 5: first = DeleteRear(first); Disp(first); break;
	case 6: first = InsertPos(first); Disp(first); break;
	case 7: first = DeletePos(first); Disp(first);break;
	case 8: first = InsertByOrder(first); Disp(first);break;
	case 9: first = DeleteKey(first);Disp(first);break;
	case 10: Search(first); break;
	case 11: L2=CreateCopy(first);printf("\ncopy of the list is:");Disp(L2); break;
	case 12: first = Reverse(first);printf("\nReversed list is:");Disp(first); break;
	default:exit(0);
     }
 }
 }
 node InsertFront(node F)  // node *F= &first
    {
       node NN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->link=F; // NN->link = *F
       NE++;
       return NN;      
    }
node InsertRear(node F)
    {
       node NN,TN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->link=NULL;
       NE++;

       if(F== NULL)
       return NN;
       TN=F;
       while(TN->link!=NULL)
       TN=TN->link;
       TN->link=NN;
       return F;
    }


  void Disp(node F)
   {
       if(F==NULL)
       {
	 printf("empty\n");
	 return;
       }
       printf("\nList is:\n");
       while(F != NULL)
       {
	 printf("%d ",F->info);
	 F=F->link;
       }
  }
  node DeleteFront(node F)
  {  node ND;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
       ND=F;
       printf("\ndeleted %d",ND->info);
       F=F->link;
       free(ND);
       NE--;
       return F;
  }

 node DeleteRear(node F)
  {  node LN,PL;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
       NE--;

       if(F->link==NULL)
	{
	  printf("\ndeletd %d",F->info);
	  free(F);
	  return NULL;  // F=NULL  return F;
	}
       LN=F;
       PL=NULL;
       while(LN->link!=NULL)
       { PL=LN;
	 LN=LN->link;
       }
     printf("\ndelted %d\n", LN->info);

     PL->link=NULL;
     free(LN);
     return F;
  }

node InsertPos(node F)
    {
       node NN,TN,PN;
       int pos,cnt;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->link=NULL;


       printf("\nenter position   from 1 to %d:" ,NE+1);
       scanf("%d",&pos);
       if(pos>=1 && pos<=NE+1)
       {
	    NE++;
	    if(pos==1)   // insertfront()
	    {
	    NN->link=F;
	    return NN;
	     }
	 TN=F;   // PN=F
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


       }
       else

       printf("Invalid position Retry:\n");
       return F;

    }

 node DeletePos(node F)
  {  node TN,PN;
     int pos,cnt;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
	printf("\nenter position:");
       scanf("%d",&pos);
       if(pos>=1 && pos<=NE)
       {
	 NE--;
	 if(pos==1)
	 { TN=F;
	   printf("\ndeleted:%d ", TN->info);
	   F=F->link;
	   free(TN);
	   return F;
	 }
	 TN=F;
	 PN=NULL;
	 cnt=1;
	 while(cnt<pos)
	 {
	    PN=TN;
	    TN=TN->link;
	    cnt++;
	 }
	 PN->link=TN->link;
	 printf("\ndeleted:%d ",TN->info);
	 free(TN);
       }
       else
	printf("\nInvalid position Retry:");
	return F;
  }

  node InsertByOrder(node F)
    {
       node NN,TN,PN;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NE++;
       NN->link=NULL;
       if(F==NULL)
	return NN;

	if(NN->info <F->info)
	 {
	  NN->link=F;
	  return NN;
	 }
	TN=F;
	PN=NULL;
	while(TN->info < NN->info && TN!=NULL)
	{
	  PN=TN;
	  TN=TN->link;
	}
	PN->link=NN;
	NN->link=TN;
	return F;

 }


 node DeleteKey(node F)
  {  node TN,PN;
     int info;
     int pos,cnt;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
	printf("\nenter key to be deleted:");
       scanf("%d",&info);

       if(F->info==info)
       {
	 TN=F;
	 F=F->link;
	 printf("\ndeleted %d", TN->info);
	 free(TN); NE--;
	 return F;
       }
       TN=F;
       PN=NULL;
       while(TN->info != info && TN!=NULL)
       {
	 PN=TN;
	 TN=TN->link;
       }
       if(TN==NULL)
       {
	printf("\nseraching node doesn't exist");
	return F;
       }
       PN->link=TN->link;
       printf("\ndeleted %d ", TN->info);
       free(TN);
       NE--;
       return F;
 }
 void Search(node F)
 {
   node NS;
   int info, pos;
   if(F==NULL)

   {  printf("empty list");
       return ;
   }

   printf("\nenter the key to be searched");
   scanf("%d",&info);
   NS=F;
   pos=1;
   while(NS->info != info && NS!=NULL)
   {
     NS=NS->link;
       pos++;
   }
     if(NS==NULL)

      printf("\nSearching node doesn't exist in the list");

     else
     printf("\nnode with info %d exists at position %d", NS->info, pos);
}
node CreateCopy(node F)
{
  node SL=NULL,NN,TN;
  if(F==NULL)
  return NULL;

  while(F!=NULL)
  {
    NN=(node)malloc(sizeof(struct NODE));
    NN->info=F->info; NN->link=NULL;
    if(SL==NULL)
     SL=NN;
    else
    {
      TN=SL;
      while(TN->link!=NULL)
      {
	TN=TN->link;
      }
      TN->link=NN;
   }
   F=F->link;
  }
  return SL;
}
node Reverse(node F)
{
   node LN, TN=NULL;
   if(F==NULL)  return NULL;
   while(F!=NULL)
   {
      LN = F;
	F=F->link;
      LN->link=TN;
      TN=LN;

   }
   return LN;
}

