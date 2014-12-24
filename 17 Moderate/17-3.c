#include <stdio.h>
#include <math.h>

int min (int a,int b)
{
	return (a>b?b:a);
}

int trailingzeroes(int x)
{
	int i=0,j=0,cfive=0;
	for(i=1;i<=x;i++)
	{
		if(i%5==0)
		{
			j=i;
			while(j!=0 && j%5==0)
			{
				cfive++;
				j=j/5;
			}
		}
	}
	return cfive;
}

int main()
{
	int n=200;
	printf("Trailing Zeroes in %d ! = %d\n",n,trailingzeroes(n));
	return 0;
}