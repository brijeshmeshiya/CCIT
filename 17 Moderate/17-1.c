#include <stdio.h>

void swap1 (int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	return;
}

void swap2 (int &a,int &b)
{
	a^=b;
	b^=a;
	a^=b;
	return;
}

int main()
{
	int x=100,y=10;
	printf("X = %3d and Y = %3d\n",x,y);
	swap2(x,y);
	printf("X = %3d and Y = %3d\n",x,y);
	return 0;
}