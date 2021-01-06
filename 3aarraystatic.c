/*Develop a menu driven program to implement various operations on array
storage representation with static memory allocation.*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int last_index=-1;
void read(int a[])
{
 int n,i;
 printf("enter the number of elements to read:");
scanf("%d",&n);
if(n>MAX)
 printf("array overflowed\n");
 else
 {
printf("enter the array elements:\n");
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 last_index=n-1;
 }
}
void display(int a[])
{
 int i;
 if(last_index<0)
  printf("the array is empty\n");
 else
 {
 for(i=0;i<=last_index;i++)
printf("%d ",a[i]);
 printf("\n");
  }
}
void InsertPosition(int a[])
{
 int p,i,data;
 printf("enter the position where data is to be inserted:");
 scanf("%d",&p);
 printf("enter the data to be inserted:");
 scanf("%d",&data);
 if(p>last_index+2)
 printf("invalid position\n");
else if(last_index+2>MAX)
 printf("array overflowed\n");
else
 {
 for(i=last_index;i>=p-1;i--)
  a[i+1]=a[i];
 a[p-1]=data;
 last_index++;
  }
  }
void DeletePosition(int a[])
{
 int p,i;
 printf("enter the position in which data is to be deleted:");
scanf("%d",&p);
 if(last_index<0)
 printf("the array is empty\n");
 else if(p-1>last_index)
 printf("invalid index entery\n");
 else
 {
 printf("the data being deleted is %d",a[p-1]);
  for(i=p-1;i<last_index;i++)
 a[i]=a[i+1];
 last_index--;
  }
}
void InsertOrder(int a[])
{
 int data,i;
 printf("enter the data to be inserted:");
 scanf("%d",&data);
 if(last_index+2>MAX)
 printf("array overflowed\n");
else
{
 for(i=last_index;i>=0&&a[i]>data;i--)
{
 a[i+1]=a[i];
 }
 a[i+1]=data;
 last_index++;
 }
}
void DeleteElement(int a[])
{
 int data, i,p;
printf("enter the data to be deleted:");
scanf("%d",&data);
 if(last_index<0)
printf("the list is empty\n");
else
 {
 for(i=0;i<=last_index;i++)
 {
 if(a[i]==data)
 break;
}
 if(i>last_index)
 printf("the element not found\n");
 else
{
for(p=i;p<last_index;p++)
 a[p]=a[p+1];
 last_index--;
}
 }
 }
int menu()
{
int choice;
 printf("1. read\n");
printf("2. display\n");
 printf("3. insert by position\n");
 printf("4. delete by position\n");
printf("5. insert by order\n");
printf("6. delete element by data\n");
 printf("7. exit\n");

    printf("enter the choice number:");

    scanf("%d",&choice);

    return choice;

}

 

int main()

{

    int a[MAX];

    while(1){

    switch(menu())

    {

    case 1:

        read(a);

        break;

    case 2:

        display(a);

        break;

    case 3:

        InsertPosition(a);

        break;

    case 4:

        DeletePosition(a);

        break;

    case 5:

        InsertOrder(a);

        break;

    case 6:

         DeleteElement(a);

         break;

    case 7:

         exit(0);

    default:

        printf("wrong choice entry\n");

    }

       getch();

       system("cls");

    }

    return 0;

}

 

 

