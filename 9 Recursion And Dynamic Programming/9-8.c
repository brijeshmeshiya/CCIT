#include <stdio.h>

void divide(int sum,int a,int b,int c,int d)		// a= 25, b=10, c=5, d=1
{
	if(a<0 || b<0 || c<0 || d<0)
		return;
	if(a*25+b*10+c*5+d==sum)
	printf("(%d,%d,%d,%d) ",a,b,c,d);
	divide(sum,a,b,c+1,d-5);
	divide(sum,a,b+1,c,d-10);
	divide(sum,a+1,b,c,d-25);
}

int main()
{
	int sum=10;
	divide(sum,0,0,0,sum);
	printf("\n");
}