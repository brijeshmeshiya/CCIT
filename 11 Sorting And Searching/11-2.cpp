#include <iostream>
#include <cstring>

using namespace std;

void print(string *array,string msg,int size)
{
	cout<<msg<<" : ";
	for(int i=0;i<size;i++)
		cout<<array[i]<<" ";
	cout<<endl; 
	return ;
}

bool comparator(string x1,string x2)
{
	int array[256];
	int i,j,k;
	for(i=0;i<256;i++)
		array[i]=0;
	for(i=0;i<x1.length();i++)
		array[x1.at(i)]++;
	for(i=0;i<x2.length();i++)
		array[x2.at(i)]--;
	for(i=0;i<256;i++)
	{
		if(array[i]>0)
			return 1;
		else if(array[i]<0)
			return 0;
	}
	return (x1>x2?1:0);
}

void merge(string *array,int start,int mid,int end)
{
	string temp[end-start+1];
	int i=start,j=mid+1,counter=0;
	while(i<=mid && j<=end)
	{
		if(comparator(array[i],array[j])==1)
		{
			temp[counter]=array[i];
			i++;
		}
		else
		{
			temp[counter]=array[j];
			j++;
		}
		counter++;
	}
	while(i<=mid)
	{
		temp[counter]=array[i];
		i++;
		counter++;
	}
	while(j<=end)
	{
		temp[counter]=array[j];
		j++;
		counter++;
	}
	for(i=0;i<counter;i++){
		array[i+start]=temp[i];
	}
	return;
}

void mergesort(string *array,int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergesort(array,start,mid);
		mergesort(array,mid+1,end);
		merge(array,start,mid,end);
	}
}

int main()
{
	// only focusing on sorting by no. of character occurrence
	string array[]={"god","aaa","aba","bcd","dog","aab"};
	int size=sizeof(array)/sizeof(string);
	print(array,"Before : ",size);
	mergesort(array,0,5);
	print(array,"After  : ",size);
	return 0;
}