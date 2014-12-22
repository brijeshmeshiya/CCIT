#include <iostream>
#include <map>

using namespace std;

void min_heapify(int *array,int index,int size)
{
	int side=0,minimum=*(array+index),left=index*2+1,right=left+1;
	if(left<size && minimum>*(array+left)){
		side=1;
		minimum=*(array+left);
	}
	if(right<size && minimum>*(array+right)){
		side=2;
		minimum=*(array+right);
	}
	if(side!=0){
		*(array+index*2+side)=*(array+index);
		*(array+index)=minimum;
		min_heapify(array,index*2+side,size);
	}
	return ;
}

void remove(int *array,int &size)
{
	size--;
	*(array)=*(array+size);
	min_heapify(array,0,size);
	return;
}

void insert(int *array,int data,int &size)
{
	int parent,swap,child;
	*(array+size)=data;
	child=size;
	size++;
	parent=(size/2)+(size%2?0:-1);
	while(parent>=0 && *(array+child)<*(array+parent)){
		swap=*(array+parent);
		*(array+parent)=*(array+child);
		*(array+child)=swap;
		child=parent;
		parent=(size/2)+(size%2?0:-1);
	}
	return;
}

int main()
{
	int size,print;
	map <int,bool> dict;
	cout<<"How many sequence of nos. : ";
	cin>>size;
	int array[size],index=0;
	array[index++]=1;
	cout<<"Sequence : ";
	for(int j=0;j<size;j++)
	{
		print=array[0];
		cout<<print<<" ";
		dict[print]=1;
		remove(array,index);
		if(dict.find(print*3)==dict.end())
		{
			dict[print*3]=1;
			insert(array,print*3,index);
		}
		if(dict.find(print*5)==dict.end())
		{
			dict[print*5]=1;
			insert(array,print*5,index);
		}
		if(dict.find(print*7)==dict.end())
		{
			dict[print*7]=1;
			insert(array,print*7,index);
		}
	}
	cout<<endl;
	return 0;
}