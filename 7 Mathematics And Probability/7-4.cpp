#include <iostream>

using namespace std;

int negative(int x)
{
int answer=0;
int diff = (x>=0)?-1:1;
while((answer+x)!=0)
	answer+=diff;
return answer;
}

int multiply(int a,int b)
{
bool flag=0;
int answer=0;
if(a<0)
{
negative(a);
flag^=1;
}
if(b<0)
{
negative(b);
flag^=1;
}
while(b)
{
answer+=a;
b+=negative(1);
}
if(flag)
	answer=negative(answer);
return answer;
}

int division(int a,int b)
{
int answer=0,diff=b;
bool flag=0;
if(b==0)
	return 0;
if(a<0)
{
negative(a);
flag^=1;
}
if(b<0)
{
negative(b);
flag^=1;
}
if(a<b)
	return answer;
while(a>=b)
{
answer+=1;
b+=diff;
}
return answer;
}

int main()
{
int x=5,y=24;
cout<<"Multiply : "<<multiply(x,y)<<endl;
cout<<"Subtraction : "<<(x+(negative(y)))<<endl;
cout<<"Division : "<<division(y,x)<<endl;
return 0;
}

