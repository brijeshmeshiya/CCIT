#include <iostream>

using namespace std;

string binaryconverter(double x)
{
if(x>=1 || x<=0)
	return "Error";
int counts=0;
double y=1;
string s="";
for(int i=0;i<32;i++)
{
y=y/2;
if(y<=x)
{
x=x-y;
s=s+'1';
counts++;
}
else
{
s=s+'0';
}
}
if(counts==0)
	s="Error";
return s;
}

int main()
{
double x;
x=0.5555;
cout<<(binaryconverter(x))<<endl;
}
