#include <stdio.h>
#include <stdlib.h>

struct tree {
int data;
struct tree *left,*right;
};

struct tree * allocate(int data)
{
struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void printpath(struct tree *h,int sum,int *array,int size)
{
int i,s=0,j;
if(h==NULL)
	return;
*(array+size)=h->data;
for(i=size;i>=0;i--)
{
s=s+*(array+i);
if(s==sum)
{
printf("Path : ");
for(j=i;j<=size;j++)
	printf("%3d ",*(array+j));
printf("\n");
}
}
printpath(h->left,sum,array,size+1);
printpath(h->right,sum,array,size+1);
return;
}

int main()
{
int array[100]={0};
struct tree *head=allocate(10);
head->right=allocate(3);
head->right->left=allocate(2);
head->left=allocate(8);
head->left->left=allocate(13);
head->left->right=allocate(5);
printpath(head,5,array,0);
}
