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

void removemiddle(struct node *h)
{
if(h==NULL || h->next==NULL)
{
return ;
}
else
{
struct node *slow=h,*fast=h->next;
while(fast!=NULL && fast->next!=NULL)
{
slow=slow->next;
fast=fast->next;
if(fast->next!=NULL)
	fast=fast->next;
}
slow->data=slow->next->data;
fast=slow->next;
slow->next=slow->next->next;
free(fast);
return ;
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
printf("1.Insert\n2.Remove Middle Element\n3.Print\n4.Exit\n");
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
removemiddle(head);
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
