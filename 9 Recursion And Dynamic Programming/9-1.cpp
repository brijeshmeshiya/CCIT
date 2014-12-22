#include <iostream>

using namespace std;

int reach(int goal)
{
	if(goal<0)
		return -1;
	else if(goal==0)
		return 0;
	int i,cache[goal];
	cache[1]=1;
	cache[2]=2;
	cache[3]=4;
	i=4;
	while(i<=goal){
		cache[i]=cache[i-1]+cache[i-2]+cache[i-3];
		i++;
	}
	return cache[goal];
}

int main()
{
	int n;
	cout<<"Stair Length : ";
	cin>>n;
	cout<<"Possible Path to reach at End = "<<reach(n)<<endl;
	return 0;
}