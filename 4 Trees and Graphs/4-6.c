#include <stdio.h>
#include <stdlib.h>


struct tree {
int data;
struct tree *left,*right,*parent;
};

struct tree * allocate(struct tree *parent,int data)
{
struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
temp->parent=parent;
return temp;
}

struct tree *successor(struct tree *h)
{
struct tree *temp,*prev,*min;
if(h==NULL)
	return NULL;
if(h->right!=NULL)
{
temp=h->right;
prev=temp;
min=prev;
while(temp!=NULL && temp->left==NULL)
{
prev=temp;
temp=temp->right;
}
if(prev->left==NULL && temp==NULL)
	return min;
prev=temp->left;
temp=temp->left;
while(temp!=NULL)
{
prev=temp;
temp=temp->left;
}
return prev;
}
else
{
if(h->parent==NULL)
	return NULL;
temp=h->parent;
prev=h;
while(temp!=NULL && temp->left!=prev)
{
prev=temp;
temp=temp->parent;
}
if(temp!=NULL && temp->left==prev)
	return temp;
return NULL;
}
}

int main()
{
struct tree *temp,*head=allocate(NULL,20);
head->right=allocate(head,40);
head->right->right=allocate(head->right,60);
head->right->left=allocate(head->right,30);
head->right->left->left=allocate(head->right->left,25);
temp=head->right->left->left;
if(successor(temp)!=NULL)
	printf("Successor of %d is %d\n",temp->data,successor(temp)->data);
else
	printf("No Successor\n");
return 0;
}
