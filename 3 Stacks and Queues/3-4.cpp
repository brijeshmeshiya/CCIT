#include <iostream>
#include <cstdlib>

using namespace std;

class stack{
int *array;
int counts;
int capacity;
int label;
public:
stack(int ,int);
int getlabel();
void push(int d);
void pop();
void movedisk(int,stack*,stack*);
void moveto(stack *);
int peep();
stack current();
};

stack :: stack(int cap,int labl)
{
capacity=cap;
label=labl;
array = (int *)malloc(sizeof(int)*cap);
counts=0;
}

void stack :: push(int data)
{
if(counts>capacity)
{
cout<<"Stack Overflow"<<endl;
}
else
{
if(counts!=0 && *(array+counts-1)<data)
{
cout<<"Disk Move can't be possible"<<endl;
}
else
{
*(array+counts)=data;
counts++;
}
}
}

int stack ::  getlabel()
{
return label;
}

void stack :: pop()
{
if(counts<=0)
{
cout<<"Stack Underflow"<<endl;
}
else
{
counts--;
}
}

int stack :: peep()
{
if(counts<=0)
{
cout<<"Tower "<<getlabel()<<" is Empty => can't Peep"<<endl;
}
else
{
return *(array+counts-1);
}
}

void stack :: moveto(stack *s)
{
int temp = peep();
pop();
(*s).push(temp);
cout<<"Moving Disk "<<temp<<" From Tower "<<getlabel()<<" to Tower "<<(*s).getlabel()<<endl;
}

stack stack :: current()
{
return *this;
}

void stack :: movedisk(int n,stack* destination,stack* buffer)
{
if(n>0)
{
movedisk(n-1,buffer,destination);
moveto(destination);
(*buffer).movedisk(n-1,destination,this);
}
}

int main()
{
stack s1(10,1);
stack s2(10,2);
stack s3(10,3);
s1.push(4);
s1.push(3);
s1.push(2);
s1.push(1);
s1.movedisk(4,&s3,&s2);
return 0;
}
