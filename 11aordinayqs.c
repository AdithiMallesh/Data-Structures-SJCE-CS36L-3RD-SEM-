/*11. To implement ordinary Queue with static memory allocation
mechanism using array storage representation.(Represent Queue using structure)*/
#include <stdio.h>
#include<stdlib.h>
#define MAX 10
void insert();
void delete();
void display();
int queue[MAX];
int r = - 1;
int f = 0;
int main()
{
int choice;
while (1)
{
printf("1.Insert element to queue \n");
printf("2.Delete  element from queue \n");
printf("3.Display queue \n");
printf("4.Exit \n");
printf("Enter your choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(1);
default:
printf("invalid");
}
}
}
void insert()
{
int ele;
if(r == MAX - 1)
printf("Queue Overflow ");
else
{
if(f== - 1)
f = 0;
printf("enter element to be inserted  : ");
scanf("%d", &ele);
r = r + 1;
queue[r] =ele;}
}
void delete()
{
if(f == - 1 || f > r)
{
printf("Queue Underflow \n");
return;
}
else
{
printf("Element is deleted from the queue : %dn", queue[f]);
f = f + 1;
}
}
void display()
{
int i;
if(f == - 1)
printf("Queue is empty /n");
else
{
printf(" TheQueue is : ");
for(i = f; i <= r; i++)
printf("%d ", queue[i]);
printf("n");
}
}
