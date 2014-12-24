#include <iostream>

using namespace std;

void match(string original,string guess)
{
	int i,hit=0,pseudohit=0,l=original.length(),ro=0,go=0,bo=0,yo=0,rg=0,gg=0,bg=0,yg=0;
	for(i=0;i<l;i++)
	{
		if(original.at(i)==guess.at(i))
			hit++;
		if(original.at(i)=='R')
			ro++;
		if(original.at(i)=='G')
			go++;
		if(original.at(i)=='B')
			bo++;
		if(original.at(i)=='Y')
			yo++;
		if(guess.at(i)=='R')
			rg++;
		if(guess.at(i)=='G')
			gg++;
		if(guess.at(i)=='B')
			bg++;
		if(guess.at(i)=='Y')
			yg++;
	}
	cout<<"Hit       : "<<hit<<endl;
	cout<<"pseudohit : "<<(min(ro,rg)+min(go,gg)+min(bo,bg)+min(yo,yg)-hit)<<endl;
}

int main()
{
	match("RGRY","RRRR");
	return 0;
}