#include <iostream>
#include <cstdlib>

using namespace std;

struct tree {
int data;
struct tree *left,*right;
};

struct tree * allocate(int x)
{
struct tree * temp = (struct tree *)malloc(sizeof(struct tree));
temp->data=x;
temp->left=NULL;
temp->right=NULL;
return temp;
}

bool areequal(struct tree *h,struct tree *x)
{
if(h==NULL && x==NULL)
	return true;
if((h==NULL && x!=NULL) || (h!=NULL && x==NULL))
	return false;
if(h->data == x->data)
	return areequal(h->left,x->left) & areequal(h->right,x->right); 
return false;
} 

bool traverse(struct tree *h,struct tree *x)
{
if(h==NULL)
	return 0;
bool flag=0;
if(areequal(h,x))
	return 1;
if(h->left!=NULL && traverse(h->left,x)==1)
	return 1;
if(h->right!=NULL && traverse(h->right,x)==1)
        return 1;
return 0;
}

int main()
{
struct tree *head=allocate(10),*temp;
head->left=allocate(20);
head->right=allocate(30);
head->left->right=allocate(40);
head->right->left=allocate(50);
head->left->right->left=allocate(60);
head->left->right->right=allocate(70);
head->right->left->left=allocate(80);
head->right->left->right=allocate(90);
head->right->left->right->right=allocate(100);
temp=allocate(40);
temp->left=allocate(60);
temp->right=allocate(70);
if(traverse(head,temp)==1)
	cout<<"Found"<<endl;
else
	cout<<"Not Found"<<endl;
return 1;
}
