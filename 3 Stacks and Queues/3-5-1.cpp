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
s1.push(data);
}

void myqueue :: pop()
{
if(!s2.empty())
{
s2.pop();
return;
}
else if(!s1.empty())
{
while(!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
s2.pop();
}
else
{
cout<<"Queue has no elements"<<endl;
}
}

int myqueue :: peep()
{
if(!s2.empty())
{
cout<<"Front : "<<s2.top()<<endl;
return s2.top();
}
else if(!s1.empty())
{
while(!s1.empty())
{
s2.push(s1.top());
s1.pop();
}
cout<<"Front : "<<s2.top()<<endl;
return s2.top();
}
else
{
cout<<"Queue is Empty"<<endl;
}
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

