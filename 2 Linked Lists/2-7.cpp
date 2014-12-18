#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
}*head=NULL,*temp=NULL,*global;

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

bool ispalindrome(struct node *h)
{
if(h==NULL)
	return true;
else
{
bool flag = ispalindrome(h->next);
if(global->data == h->data)
{
global=global->next;
return flag;
}
else
{
global=global->next;
return false;
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
printf("\n1.Insert\n2.Is Palindrome\n3.Print\n4.Exit\n");
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
global=head;
if(ispalindrome(head)==1)
	printf("Yes\n");
else
	printf("No\n");
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
