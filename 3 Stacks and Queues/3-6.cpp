#include <iostream>
#include <stack>
using namespace std;

class myqueue{
stack <int> s1,s2;
public:
void push(int);
void pop();
int peep();
};

void myqueue :: push(int data)
{
while(!s1.empty() && s1.top()>data)
{
s2.push(s1.top());
s1.pop();
}
s1.push(data);
while(!s2.empty())
{
s1.push(s2.top());
s2.pop();
}
}

void myqueue :: pop()
{
if(!s1.empty())
	s1.pop();
else
	cout<<"Stack Underflow"<<endl;
}

int myqueue :: peep()
{
if(!s1.empty()){
	cout<<"Top : "<<s1.top()<<endl;
	return s1.top();
}
else
	cout<<"Stack is Empty"<<endl;
}

int main()
{
myqueue q1;
while(1)
{
cout<<"\n1.Push\n2.Pop\n3.Peep\n4.Exit\n"<<endl;
int n,i,j;
cin>>n;
switch(n)
{
case 1:
{
cout<<"Enter Element : ";
cin>>i;
q1.push(i);
break;
}
case 2:
{
q1.pop();
break;
}
case 3:
{
q1.peep();
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

