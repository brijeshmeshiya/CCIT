#include <iostream>

using namespace std;

class stack{
int space[5][3];
int counts[5];
int maxsize;
int maxstack;
public:
stack();
void push(int);
void pop();
void pop(int);
};

stack :: stack()
{
maxsize=3;
maxstack=5;
for(int i=0;i<maxstack;i++)
	counts[i]=0;
}

void stack :: push(int data)
{
int i;
for(i=0;i<maxstack;i++)
	if(counts[i]<maxsize)
		break;
if(i==maxstack)
	cout<<"Stack Overflow"<<endl;
else
{
space[i][counts[i]]=data;
counts[i]++;
cout<<"Successfully Pushed into Stack No. "<<i+1<<endl;
}
}

void stack :: pop()
{
int i;
for(i=maxstack-1;i>=0;i--)
	if(counts[i]>0)
		break;
if(i<0)
	cout<<"Stack Underflow"<<endl;
else
{
counts[i]--;
cout<<"Popping from stack :  "<<i+1<<" value = "<<space[i][counts[i]]<<endl;
}
}

void stack :: pop(int index)
{
if(counts[index]>0)
{
cout<<"Popping from stack :  "<<index+1<<" value = "<<space[index][counts[index]-1]<<endl;
counts[index]--;
}
else
{
cout<<"Underflow in Stack No. "<<index+1<<endl;
}
}

int main()
{
stack s1;
while(1)
{
cout<<"\n1.Push\n2.Pop\n3.Pop From Specified Stack\n4.Exit\n"<<endl;
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
cout<<"Enter Stack No. (1-5) : ";
cin>>j;
s1.pop(j-1);
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

