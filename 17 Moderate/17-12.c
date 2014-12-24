#include <stdio.h>

int print(int *array,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",*(array+i));
	printf("\n");
}

void merge(int *array,int start,int mid,int end)
{
	int i=start,j=mid+1,counter=0;
	int temp[end-start+1];
	while(i<=mid && j<=end)
	{
		if(*(array+i)>*(array+j))
		{
			temp[counter]=*(array+j);
			j++;
		}
		else
		{
			temp[counter]=*(array+i);
			i++;
		}
		counter++;
	}
	while(i<=mid)
	{
		temp[counter]=*(array+i);
		i++;
		counter++;
	}
	while(j<=end)
	{
		temp[counter]=*(array+j);
		j++;
		counter++;
	}
	for(i=0;i<counter;i++)
		*(array+i+start)=temp[i];
	return;
}

void merge_sort(int *array,int start,int end)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		merge_sort(array,start,mid);
		merge_sort(array,mid+1,end);
		merge(array,start,mid,end);
	}
}

void findpair(int *array,int start,int end,int sum)
{
	int *p=array,*q=(array+end);
	while(p<q)
	{
		if(*p+*q>sum)
		{
			q--;
		}
		else if(*p+*q<sum)
		{
			p++;
		}
		else
		{
			printf("(%d,%d) ",*p,*q);
			p++;
		}
	}
	printf("\n");
}

int main()
{
	int arr[]={1,2,4,7,10,11,12,6,16,-4,0,-5,-10,32,-2,18,19},size=sizeof(arr)/sizeof(int);
	merge_sort(arr,0,size-1);
	findpair(arr,0,size-1,10);
	return 0;
}