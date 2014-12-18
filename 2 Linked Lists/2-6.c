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

void addloop(struct node *h,int x)
{
if(h!=NULL)
{
if(h->next==NULL && h->data==x)
{
h->next=h;
return;
}
struct node *t=h,*r=NULL;
while(t->next!=NULL)
{
if(t->data==x)
	r=t;
t=t->next;
}
if(t->data==x)
	r=t;
if(r!=NULL)
	t->next=r;
}
return;
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

struct node *detectloop(struct node *h)
{
if(h==NULL || h->next==NULL)
	return NULL;
else
{
struct node *slow,*fast;
slow=h->next;
fast=h->next->next;
while(slow!=NULL && fast!=NULL && slow!=fast)
{
slow=slow->next;
fast=fast->next;
if(fast!=NULL)
{
	fast=fast->next;
}
else
	return NULL;
}
if(fast==NULL || slow==NULL)
	return NULL;
else if(slow==fast)
	return slow;
}
}

void printloop(struct node *h)
{
struct node *temp,*tmp=NULL;
int counts=0;
temp=detectloop(h);
if(temp!=NULL)
{
while(h!=temp)
{
h=h->next;
temp=temp->next;
}
tmp=temp->next;
while(tmp->next!=h)
	tmp=tmp->next;
if(tmp->next==h)
	tmp->next=NULL;
printf("Loop at Value : %d\n",temp->data);
}
return ;
}

int main()
{
int n,i,j;
while(1)
{
printf("\n1.Insert\n2.Insert Loop Element\n3.Find Loop Element\n4.Print\n5.Exit\n");
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
printf("Enter Value : ");
scanf("%d",&i);
addloop(head,i);
break;
}
case 3:
{
printloop(head);
break;
}
case 4:
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
