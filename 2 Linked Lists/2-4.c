#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
}*head=NULL,*temp=NULL;

void insert(int d)
{
if(head==NULL)
{
head = (struct node *)malloc(sizeof(struct node));
head->data=d;
head->next=NULL;
return ;
}
else
{
temp = (struct node *)malloc(sizeof(struct node));
temp->data=d;
temp->next=head;
head=temp;
return ;
}
}

void partition(struct node *h,int k)
{
if(h==NULL)
	return;
else
{
struct node *p1=h,*p2;
int n=0,i=0;
while(p1!=NULL)
{
if((p1->data)<=k)
	i++;
n++;
p1=p1->next;
}
if(i==0 || i==n)
	return;
else
{
p1=h;
p2=h;
while(i>0)
{
p2=p2->next;
i--;
}
while(p2!=NULL)
{
if(p1->data<=k)
	p1=p1->next;
else if(p2->data>k)
	p2=p2->next;
else if(p1->data>k && p2->data<=k)
{
p1->data+=p2->data;
p2->data=p1->data-p2->data;
p1->data=p1->data-p2->data;
p1=p1->next;
p2=p2->next;
}
}
return;
}
}
}

void print(struct node *t)
{
while(t!=NULL)
{
printf("%d -> ",t->data);
t=t->next;
}
printf("\n");
return;
}

int main()
{
int n,i,j;
while(1)
{
printf("\n1.Insert\n2.Make Partition\n3.Print\n4.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
{
printf("Enter Number : ");
scanf("%d",&i);
insert(i);
break;
}
case 2:
{
printf("Enter Partition Element : ");
scanf("%d",&i);
partition(head,i);
break;
}
case 3:
{
print(head);
break;
}
default:
{
return 0;
}
}
}
return 0;
}
