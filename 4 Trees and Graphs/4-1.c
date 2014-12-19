#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct tree{
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

int isbalanced(struct tree *h)
{
int left,right;
if (h==NULL)
	return 0;
else
{
left=isbalanced(h->left);
right=isbalanced(h->right);
if(abs(left-right)>1)
	printf("Node with Value : %d is Unbalanced\n",(h->data));	
else
	printf("Node with Value : %d is Balanced\n",(h->data));
return MAX(left,right)+1;
}
}


int main()
{
struct tree *head;
head=allocate(1);
head->left=allocate(2);
head->left->left=allocate(3);
head->right=allocate(4);
isbalanced(head);
return 0;
}
