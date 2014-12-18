#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

void insertend(struct node **head,struct node **end,int d)
{
if(*head==NULL)
{
*head=(struct node *)malloc(sizeof(struct node));
(*head)->data=d;
(*head)->next=NULL;
*end=*head;
}
else
{
struct node *tmp;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->data=d;
tmp->next=NULL;
(*end)->next=tmp;
*end=tmp;
}
return;
}

struct node * sumback(struct node *h1,struct node *h2)
{
if(h1==NULL && h2!=NULL)
	return h2;
else if(h1!=NULL && h2==NULL)
	return h1;
else if(h1==NULL && h2==NULL)
	return NULL;
else
{
struct node *answer=NULL,*tail=NULL;
int data=0,carry=0;
while(h1!=NULL && h2!=NULL)
{
data=h1->data+h2->data+carry;
if(data>9)
{
data=data%10;
carry=1;
}
else
	carry=0;
insertend(&answer,&tail,data);
h1=h1->next;
h2=h2->next;
}
if(h1!=NULL)
{
while(h1!=NULL)
{
data=h1->data+carry;
if(data>9)
{
data=data%10;
carry=1;
}
else
	carry=0;
insertend(&answer,&tail,data);
h1=h1->next;
}
}
else if(h2!=NULL)
{
while(h2!=NULL)
{
data=h2->data+carry;
if(data>9)
{
data=data%10;
carry=1;
}
else
	carry=0;
insertend(&answer,&tail,data);
h2=h2->next;
}
}
else
{
if(carry>0)
	insertend(&answer,&tail,carry);
}
return answer;
}
}

struct node *reverse(struct node *current,struct node *prev)
{
if(current==NULL)
	return prev;
else
{
struct node *temp;
temp = reverse(current->next,current);
current->next=prev;
return temp;
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
struct node *head1=NULL,*head2=NULL,*end1=NULL,*end2=NULL,*sum=NULL;
while(1)
{
printf("\n1.Insert \n2.Sum it\n3.Print\n4.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
{
printf("\nSelect List (1-2) : ");
scanf("%d",&j);
printf("Enter Number : ");
scanf("%d",&i);
if(j==1)
	insertend(&head1,&end1,i);
else
	insertend(&head2,&end2,i);
break;
}
case 2:
{
head1=reverse(head1,NULL);
head2=reverse(head2,NULL);
sum=sumback(head1,head2);
sum=reverse(sum,NULL);
head1=reverse(head1,NULL);
head2=reverse(head2,NULL);
printf("\nSum : ");
print(sum);
break;
}
case 3:
{
print(head1);
print(head2);
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
