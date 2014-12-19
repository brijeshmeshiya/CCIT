#include <stdio.h>
#include <stdlib.h>
struct tree{
int data;
struct tree *left,*right;
};

struct tree * allocate(int data)
{
struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
temp->data=data;
return temp;
}

struct tree *createbst(int *array,int start,int end)
{
int mid;
struct tree *parent;
if(start>end)
	return NULL;
else if(start==end)
	return allocate(*(array)+start);
else
{
mid=(start+end)/2;
parent=allocate(*(array+mid));
parent->left=createbst(array,start,mid-1);
parent->right=createbst(array,mid+1,end);
return parent;
}
}

void preorder(struct tree *h)
{
if(h==NULL)
	return;
else
{
printf("%d ",h->data);
preorder(h->left);
preorder(h->right);
}
}

int main()
{
int array[] = {1,2,3,4,5,6,7};
int size = sizeof(array)/sizeof(int);
struct tree *head = createbst(array,0,size-1);
printf("Preorder : ");
preorder(head);
printf("\n");
}
