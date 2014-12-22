#include <iostream>
#include <iomanip>

using namespace std;

void print(bool *array,int size)
{
	int i;
	for(i=0;i<size;i++)
		cout<<setw(3)<<*(array+i)<<" ";
	cout<<endl;
}

int main()
{
	int n,i,j;
	cout<<"Enter Nos. of Locker : ";
	cin>>n;
	bool locker[100]={0};
	for(int i=0;i<n;i++)
		locker[i]=1;
	cout<<"Pass "<<setw(3)<<0<<" : ";
		print(locker,n);
	for(i=1;i<n;i++)
	{
		cout<<"Pass "<<setw(3)<<i<<" : ";
		for(j=i;j<n;j=j+i+1)
		{
			locker[j]^=1;
		}
		print(locker,n);
	}
	cout<<"Locker : ";
	for(int i=0;i<n;i++)
		if(locker[i]==1)
			cout<<(i+1)<<" ";
	cout<<endl;
}
