#include <stdio.h>

int max(int a,int b)
{
	return a-((a-b)&((a-b)>>31));
}

void contiguouslargestsum(int *array,int size)
{
	int i,maximum_so_far=0,current_maximum=0,start=0,end=0;
	for(i=0;i<size;i++)
	{
		current_maximum=max(*(array+i),current_maximum+*(array+i));
		if(current_maximum==*(array+i))
			start=i;
		maximum_so_far=max(current_maximum,maximum_so_far);
		if(maximum_so_far==current_maximum)
			end=i;
	}
	printf("Sequence :\n");
	for(i=start;i<=end;i++)
	{
		printf("%d ",*(array+i));
	}
	printf("\nMaximum Sum : %d\n",maximum_so_far);
}

int main()
{
	int arr[]={2,-8,3,-2,4,-10},size=sizeof(arr)/sizeof(int);
	contiguouslargestsum(arr,size);
	return 0;
}