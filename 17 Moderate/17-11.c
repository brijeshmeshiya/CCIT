#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran5()
{
	srand(time(NULL));
	int x = rand()%5;
	return x;
}

int ran7()
{
	return (ran5()+ran5()+ran5()+ran5()+ran5()+ran5()+ran5())%7;
}

int main()
{
	int i=0;
	for(i=0;i<100;i++)
		printf("%d\n",ran7());
}