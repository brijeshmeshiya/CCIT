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

void printkth(struct node *h,int k)
{
struct node *tmp=h;
int i,j=k;
if(h!=NULL)
{
while(tmp!=NULL && k>0)
{
tmp=tmp->next;
k--;
}
if(tmp==NULL && k==0)
{
printf("Kth Element : %d \n",(h->data));
}
else if(tmp==NULL && k>0)
{
printf("List dont have %d elements\n",j);
}
else if(tmp!=NULL && k==0)
{
while(tmp!=NULL)
{
h=h->next;
tmp=tmp->next;
}
printf("Kth Element : %d\n",(h->data));
}
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
printf("1.Insert\n2.Print kth Element from last\n3.Print\n4.Exit\n");
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
printf("Position : ");
scanf("%d",&i);
printkth(head,i);
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
