#include <iostream>
#include <limits.h>

using namespace std;

void findsequence(int *array,int start,int end)
{
	int i,j,minindex=INT_MAX,maxindex=INT_MIN,minn,maxx;
	if(end-start+1<3)
		return;

	// Finding Increasing Left & Right Subsequence 
	
	for(i=1;i<end;i++)
	{
		if(array[i]<array[i-1] && minindex>i)
			minindex=i;
	}

	for(i=end-1;i>=0;i--)
	{
		if(array[i]>array[i+1] && maxindex<i)
			maxindex=i;
	}


	if(minindex==INT_MAX || maxindex==INT_MIN)
	{
		cout<<"Sorting Not needed"<<endl;
		return;		
	}


	cout<<"Printing : Minindex = "<<minindex<<" Maxindex = "<<maxindex<<endl;

	//FInding Min And Max that need to be Sorted
	minn=array[minindex];
	maxx=array[maxindex];

	for(i=minindex;i<=end;i++)
		if(minn>array[i])
			minn=array[i];

	for(i=maxindex;i>=0;i--)
		if(maxx<array[i])
			maxx=array[i];

	cout<<"Printing : Min = "<<minn<<" Max = "<<maxx<<endl;

	//Finding Position to put Minimum And Maximum

	for(i=0;i<end;i++)
		if(array[i]>=minn)
		{
			minindex=i;
			break;
		}

	for(i=maxindex+1;i<=end;i++)
		if(array[i]>=maxx)
		{
			maxindex=i-1;
			break;
		}

	cout<<"Location needs to be Sorted : "<<minindex<<" To "<<maxindex<<endl;

	return;
}

int main()
{
	// Only Works for Non Decreasing Array
	int array[]={1,2,4,7,3,16,18,19},size=sizeof(array)/sizeof(int);
	findsequence(array,0,size-1);
	return 0;
}