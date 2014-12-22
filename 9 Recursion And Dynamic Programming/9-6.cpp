#include <iostream>

using namespace std;

void print_paranthesis(string s,int left,int right,int count)
{
	if(left<right || count<0)
		return;
	if(left==right && count==0)
	{
		cout<<s<<endl;
		return ;
	}
	print_paranthesis(s+"(",left+1,right,count-1);
	print_paranthesis(s+")",left,right+1,count-1);
}

int main()
{
	int n=5;
	print_paranthesis("",0,0,n*2);
}
