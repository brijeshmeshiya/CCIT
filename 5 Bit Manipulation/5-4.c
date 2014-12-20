#include <stdio.h>

int main()
{
int i=0;
for(i=0;i<1000;i++)
{
if(((i)&(i-1))==0)
{
printf("%d ",i);
}
}
printf("\n");
return 0;
}
