#include <stdio.h>

int main()
{
int a=31,b=14;
int i=0,x,counts=0;
x=a^b;
if(x==0)
	printf("No bits required\n");
else
{
for(i=0;i<32;i++)
{
if(x%2==1)
	counts++;
x=x>>1;
}
printf("%d bits required\n",counts);
}
return 0;
}
