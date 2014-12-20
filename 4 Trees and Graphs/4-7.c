#include <stdio.h>
#include <stdlib.h>


struct tree {
int data;
struct tree *left,*right;
};

struct answer{
struct tree *value;
int flag;
};

struct tree *allocate(int data)
{
struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct answer* commonancestor(struct tree *h,struct tree *p,struct tree *q)
{
struct answer * temp=NULL,*l,*r;
temp=(struct answer *)malloc(sizeof(struct answer));
if(h==NULL)
	return NULL;
temp->flag=0;
temp->value=NULL;
l=commonancestor(h->left,p,q);
r=commonancestor(h->right,p,q);
if(l!=NULL && l->flag==1)
	return l;
if(r!=NULL && r->flag==1)
	return r;
if(l!=NULL && r!=NULL && ((l->value==p && r->value==q) ||  (r->value==p && l->value==q)))
{
temp->flag=1;
temp->value=h;
return temp;
}
if(h==p && l!=NULL  && l->value==q )
{
temp->value=h;
temp->flag=1;
}
if(h==p && r!=NULL && r->value==q)
{
temp->value=h;
temp->flag=1;
}
if(h==q && l!=NULL  && l->value==p )
{
temp->value=h;
temp->flag=1;
}
if(h==q && r!=NULL && r->value==p)
{
temp->value=h;
temp->flag=1;
}
if(l && (l->value==p || l->value==q))
	return l;
if(r && (r->value==p || r->value==q))
	return r;
if(h==p)
{
temp->value=p;
}
if(h==q)
{
temp->value=q;
}
return temp;
}

int main()
{
struct tree *head=allocate(10),*left=NULL,*right=NULL;
head->left=allocate(20);
head->right=allocate(30);
head->left->right=allocate(40);
head->right->left=allocate(50);
head->left->right->left=allocate(60);
head->left->right->right=allocate(70);
head->right->left->left=allocate(80);
head->right->left->right=allocate(90);
head->right->left->right->right=allocate(100);
struct answer *ans=NULL;

left=head->right->left->left;
right=head->right->left->right->right;
ans=commonancestor(head,left,right);

if(ans!=NULL && (ans->flag)==1)
	printf("Common Ancestor of %d and %d : %d\n",(left->data),(right->data),((ans->value)->data));
else
	printf("No Common Ancestor\n");
return 0;
}
