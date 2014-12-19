#include <iostream>

using namespace std;

class stack{
int array[100][2];
int size;
int counts;
public:
stack();
void push(int);
int peep();
void pop();
int getmin();
};

stack :: stack()
{
size=100;
counts=0;
cout<<"Stack is initialized"<<endl;
}

void stack :: push(int data)
{
if(counts+1==size)
{
cout<<"Stack Overflow"<<endl;
}
else
{
array[counts][0]=data;
if(counts==0)
	array[counts][1]=data;
else
{
if(array[counts-1][1]>data)
	array[counts][1]=data;
else
	array[counts][1]=array[counts-1][1];
}
counts++;
}
}

void stack :: pop()
{
if(counts==0)
{
cout<<"Stack Underflow"<<endl;
}
else
{
counts--;
cout<<"popped : "<<array[counts][0]<<endl;
}
}

int stack :: peep()
{
if(counts==0)
{
cout<<"Stack Is Empty"<<endl;
}
else
{
cout<<"Top : "<<array[counts-1][0]<<endl;
return array[counts-1][0];
}
}

int stack :: getmin()
{
if(counts==0)
{
cout<<"Stack Is Empty  "<<endl;
}
else
{
cout<<"Min : "<<array[counts-1][1]<<endl;
return array[counts-1][1];
}
}

int main()
{
stack s1;
while(1)
{
cout<<"\n1.Push\n2.Pop\n3.Peep\n4.Min. Element\n5.Exit\n"<<endl;
int n,i,j;
cin>>n;
switch(n)
{
case 1:
{
cout<<"Enter Element : ";
cin>>i;
s1.push(i);
break;
}
case 2:
{
s1.pop();
break;
}
case 3:
{
s1.peep();
break;
}
case 4:
{
s1.getmin();
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
