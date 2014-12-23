#include <stdio.h>

void shift(int *array,int shift,int size)		// size = n
{
	int i,j;
	for(i=size-1;i>=shift;i--)
	{
		j=*(array+i);
		*(array+i)=*(array+i-shift);
		*(array+i-shift)=j;
	}
	return;
}

void print(int *array,char *msg,int size)
{
	int i;
	printf("%s : ",msg);
	for(i=0;i<size;i++)
		printf("%d ",*(array+i));
	printf("\n");
	return;
}

void merge(int *big,int *smaller,int bstart,int bsize,int ssize)
{
	int i=bstart,j=0,index=0;
	while(i<bsize && j<ssize)
	{
		if(*(big+i)>=*(smaller+j))
		{
			*(big+index)=*(smaller+j);
			j++;
		}
		else
		{
			*(big+index)=*(big+i);
			i++;
		}
		index++;
	}
	while(j<ssize)
	{
		*(big+index)=*(smaller+j);
		j++;
	}
	while(i<bsize)
	{
		*(big+index)=*(big+i);
		i++;
	}
	return;
}

int main()
{
	int array1[]={5,15,31,0,0,0,0},array2[]={8,10,22,49};
	int size1=sizeof(array1)/sizeof(int),size2=sizeof(array2)/sizeof(int);
	print(array1,(char *)"Bigger ",size1);
	print(array2,(char *)"smaller",size2);
	shift(array1,4,size1);
	print(array1,(char *)"Bigger ",size1);
	merge(array1,array2,4,size1,size2);
	print(array1,(char *)"Bigger ",size1);
	return 0;
}