#include <iostream>
#include <iomanip>

using namespace std;

int findpattern(int x,int y,int z)
{
int k=x;
for(int j=0;j<31;j++)
{
if(k%2==y && (k>>1)%2==z)
	return j;
k=k>>1;
}
return -1;
}

int trailingones(int x,int y)
{
int counts=0,z=x;
for(int j=0;j<y;j++)
{
if(z%2==1)
	counts++;
z=z>>1;
}
return counts;
}

int getmax(int x,int y,int counts)
{
for(int j=0;j<=y;j++)
{
x=x>>1;
}
x=x^1;
x=x<<1;
for(int j=0;j<(y-counts);j++)
{
x=x<<1;
}
for(int j=0;j<counts;j++)
{
x=x<<1;
x=x^1;
}
return x;
}

int getmin(int x,int y,int counts)
{
for(int j=0;j<y;j++)
{
x=x>>1;
}
x=x>>1;
x=x^1;
x=x<<1;
x=x^1;
for(int j=0;j<counts;j++)
{
x=x<<1;
x=x^1;
}
for(int j=0;j<(y-counts);j++)
	x=x<<1;
return x;
}

void print(int x)
{
int t=x;
string s="";
for(int i=0;i<15;i++)
{
s=(char)((t%2)+48)+s;
t=t>>1;
}
cout<<setw(7)<<x<<" : "<<s<<endl;
}


int main()
{
int x=15625,y;
y=x;
int minx=findpattern(x,1,0);
cout<<"I/p : ";
print(x);
if(minx!=-1)
{
int counts=trailingones(x,minx);
x=getmax(x,minx,counts);
cout<<"Max : ";
print(x);
}
int maxx=findpattern(y,0,1);
if(maxx!=-1)
{
int counts=trailingones(y,maxx);
cout<<"Min : ";
y=getmin(y,maxx,counts);
print(y);
}
else
{
cout<<"No Minimum"<<endl;
}
return 0;
}
