#include <stdio.h>

// Also works in case of Duplicate
int magicindex(int *array,int start,int end)
{
	int mid;
	if(start>end)
		return -1;
	if(start==end)
		return (start==array[start]?start:-1);
	mid=(start+end)/2;
	if(mid==array[mid])
		return mid;
	if(magicindex(array,start,mid-1) !=-1)
		return magicindex(array,start,mid-1);
	return magicindex(array,mid+1,end);
}

int main()
{
	int a[]= {-5,-2,0,1,2,3,4,8,8,10,22,24,35};
	int size=sizeof(a)/sizeof(int);
	printf("Magic Index = %d\n",magicindex(a,0,size-1));
	return 0;
}