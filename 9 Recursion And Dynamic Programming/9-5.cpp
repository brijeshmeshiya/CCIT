#include <iostream>
#include <cstring>

using namespace std;


void string_permute(string original,string created,int pos,int size)
{
	if(pos>size)
		return;
	if((pos+1)==size)
	{
		for(int i=0;i<size;i++)
			cout<<created.substr(0,i)<<original.at(pos)<<created.substr(i)<<endl;
		return;
	}
	for(int i=0;i<=created.length();i++)
			string_permute(original,created.substr(0,i)+original.at(pos)+created.substr(i),pos+1,size);
	return;
}

int main()
{
	string_permute("abcde","",0,4);
	return 0;
}