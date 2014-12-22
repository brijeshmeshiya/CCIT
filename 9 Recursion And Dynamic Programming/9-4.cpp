#include <iostream>
#include <cmath>

using namespace std;

string s[1024];		// Set it Equal to nos. of solutions

void print_recursive(int *array,int current,int size)
{
	if(current>=size)
		return;
	int i=pow(2,current),j,k;
	for(j=0;j<i;j++)
		s[j+i]=s[j];
	for(j=0;j<i;j++)
		s[j+i]=s[j+i]+(char)(*(array+current)+48)+",";
	print_recursive(array,current+1,size);
}	

int main()
{
	int a[]={2,3,5,9,1},size=sizeof(a)/sizeof(int);
	s[0]="{";
	print_recursive(a,0,size);
	for(int i=0;i<pow(2,size);i++)
		cout<<s[i]<<"}"<<endl;
	return 1;
}