#include <stdio.h>
#include <stdlib.h>

struct tree *ind[10];

struct tree{
int data;
struct tree *left,*right;
};

struct tree *allocate(int data)
{
struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void traverse(struct tree *h,int level)
{
if (h==NULL)
	return ;
traverse(h->left,level+1);
traverse(h->right,level+1);
h->left=NULL;
h->right=ind[level];
ind[level]=h;
return ;
}

int main()
{
int i;
struct tree *head;
for(i=0;i<10;i++)
	ind[i]=NULL;
head=allocate(1);
head->left=allocate(2);
head->right=allocate(3);
traverse(head,0);
printf("%d %d %d\n",ind[0]->data,ind[1]->data,ind[1]->right->data);
return 0;
}
