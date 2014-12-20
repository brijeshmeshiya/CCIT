#include <iostream>
#include <limits.h>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int mask(int start,int end)
{
int i=start,j=end,times=abs(start-end)+1,x=0;
while(times>0)
{
x=x<<1;
x=x^1;
times--;
}
j=min(start,end);
while(j>0)
{
x=x<<1;
j--;
}
return x;
}

void print(int n)
{
int i,j=n;
string s="";
for(i=0;i<32;i++)
{
s=(char)((j%2)+48)+s;
j=j>>1;
}
cout<<setw(10)<<n<<" : "<<s<<endl;
}

int leftshift(int x,int y)
{
while(y>0)
{
y--;
x=x<<1;
}
return x;
}

int main()
{
int m,n,mstart,mend,nstart,nend;
n=1024;
m=19;
nstart=2;
nend=6;
mstart=0;
mend=31;
print(m);
print(n);
int msk = mask(nstart,nend);
msk=msk^INT_MAX;
m=leftshift(m,nstart);
print(m);
print(msk); 
n=n&msk;
print(n);
n=n|m;
print(n);
return 0;
}
