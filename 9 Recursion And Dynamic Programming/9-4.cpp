#include <iostream>
#include <cmath>

using namespace std;

void print_iterative(int *array,int size)
{
	int i,j,k;
	for(i=0;i<pow(2,size);i++)
	{
		j=0;
		k=i;
		cout<<"{";
		while(j<size)
		{
			if(k%2==1)
				cout<<array[j]<<",";
			k=k>>1;
			j++;
		}
		cout<<"} "<<endl;
	}
	cout<<endl;
}

int main()
{
	int a[]={2,3,5,9,1},size=sizeof(a)/sizeof(int);
	print_iterative(a,size);
	return 1;
}