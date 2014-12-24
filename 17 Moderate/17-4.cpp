#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <iomanip>

using namespace std;

int flip(int x)
{
	return 1^x;
}

int sign(int x)
{
	return flip((x>>31)&(0x1));
}

int max(int a,int b)
{
	int signa=sign(a);
	int signb=sign(b);
	int signaminusb=sign(a-b);
	cout<<signa<<" "<<signb<<" "<<signaminusb<<endl;
	// Follow Truth table Given Below
	int x=(signa&signb&signaminusb)|(signa&flip(signb)&signaminusb)|(flip(signa)&flip(signb)&signaminusb)|(signa&flip(signb)&flip(signaminusb));
	return x*a+b*flip(x);
}

int main()
{
	int x=INT_MAX,y=INT_MIN;
	printf("Max out of %d And %d = %d\n",x,y,max(x,y));
	return 0;
}

/*
					  Truth Table To Answer Critical/Edge Test Cases

						 A 		 B 			A-B 	  Answer
						+ve		+ve			+ve			A
						-ve 	-ve 		-ve			B
						+ve		-ve			+ve			A
						-ve		+ve			-ve			B
						+ve 	+ve 		-ve 		B
						-ve 	-ve 		+ve 		A
						+ve 	-ve 		-ve 		A
						-ve	 	+ve 		+ve 		B
*/