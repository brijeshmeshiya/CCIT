#include <iostream>
#include <queue>

using namespace std;

class animal{
queue <int> cat,dog;
int time;
public:
animal();
void enqueue(int type);
void dequeueany();
void dequeuedog();
void dequeuecat();
};

animal :: animal()
{
time=0;
}

void animal :: enqueue (int type)
{
time++;
if(type==1)
{
//Cat
cat.push(time);
}
else if(type==2)
{
//Dog
dog.push(time);
}
}

void animal :: dequeueany()
{
if(!cat.empty() && !dog.empty())
{
if(cat.front()>dog.front())
{
dog.pop();
cout<<"Dog Is Dequeued"<<endl;
}
else
{
cat.pop();
cout<<"Cat is Dequeued"<<endl;
}
}
else if(!cat.empty() && dog.empty())
{
cat.pop();
cout<<"Cat is Dequeued"<<endl;
}
else if(cat.empty() && !dog.empty())
{
dog.pop();
cout<<"Dog Is Dequeued"<<endl;
}
else
{
cout<<"No Animal in Shelter"<<endl;
}
}

void animal :: dequeuecat()
{
if(!cat.empty())
{
cat.pop();
cout<<"Cat is Dequeued"<<endl;
}
else
{
cout<<"No Cat In Shelter"<<endl;
}
}

void animal :: dequeuedog()
{
if(!dog.empty())
{
dog.pop();
cout<<"Dog is Dequeued"<<endl;
}
else
{
cout<<"No Dog In Shelter"<<endl;
}
}


int main()
{
animal a1;
while(1)
{
cout<<"\n1.Enqueue\n2.DeueueAny\n3.Dequeue Selected\n4.Exit\n"<<endl;
int n,i,j;
cin>>n;
switch(n)
{
case 1:
{
cout<<"Enter Type (cat =1 , dog =2) : ";
cin>>i;
a1.enqueue(i);
break;
}
case 2:
{
a1.dequeueany();
break;
}
case 3:
{
cout<<"Enter Type (cat =1 , dog =2) : ";
cin>>i;
if(i==1)
	a1.dequeuecat();
else if(i==2)
	a1.dequeuedog();
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

