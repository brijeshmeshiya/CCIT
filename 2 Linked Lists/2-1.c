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

void removeduplicates(struct node *h)
{
if(h==NULL || h->next==NULL)
{
return;
}
else
{
struct node *p1,*p2,*prev;
p1=h;
p2=h->next;
prev=p1;
while(p1!=NULL && p1->next!=NULL)
{
do
{
if( p2->data == p1->data)
{
prev->next = p2->next;
free(p2);
p2=prev->next;
}
else
{
prev=p2;
p2=p2->next;
}
}while(p2!=NULL);
if(p1->next!=NULL)
{
p1=p1->next;
p2=p1->next;
}
prev=p1;
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
printf("1.Insert\n2.Remove Duplicates\n3.Print\n4.Exit\n");
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
removeduplicates(head);
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
