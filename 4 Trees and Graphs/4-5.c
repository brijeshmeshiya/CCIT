#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct tree 
{
int data;
struct tree *left,*right;
};

struct tree *allocate(int data)
{
struct tree *temp = (struct tree * )malloc(sizeof(struct tree));
temp->data = data;
temp->left = NULL;
temp->right= NULL;
return temp;
}

int isbst(struct tree *h,int min,int max)
{
int flag=0;
if (h==NULL)
	return 1;
if(h->data<=max && h->data>=min)
	flag=1;
return flag & isbst(h->left,min,h->data) & isbst(h->right,h->data,max);
}

int main()
{
struct tree *head = allocate(20);
head->left=allocate(200);
if(isbst(head,INT_MIN,INT_MAX))
	printf("Yes\n");
else
	printf("No\n");
return 0;
}
