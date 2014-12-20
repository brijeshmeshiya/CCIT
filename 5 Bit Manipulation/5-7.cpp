#include <iostream>
#include <cmath>

using namespace std;

int sendbit(int x,int y)
{
x=x/pow(2,y-1);
return x%2;
}

int maxbits(int x)
{
int i=0;
while(x>0)
{
i++;
x=x/2;
}
return i;
}

int main()
{
// Partitioning is not done to make it simple
int array[]={0,7,2,3,4,6,5};
int maxsize=sizeof(array)/sizeof(int);
int times = maxbits(maxsize);
string s;
int i,j,k,l,m;
i=0;j=0;k=0;
cout<<"Missing No. ";
while(i<times)
{
i++;
j=0;
k=0;
for(l=0;l<maxsize;l++)
{
if(sendbit(array[l],i)==1)
	j++;
else
	k++;
}
if(!(j==k || j<k))
	s='0'+s;
else
	s='1'+s;
}
cout<<s<<endl;
return 0;
}
