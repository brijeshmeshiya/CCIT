#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map <int,string> look;

void defined();

void convert(int x,string y)
{
	int z,f1=0,f2=0,f3=0;
	z=x/1000000;
	if(z!=0)
	{
		f1=1;
		x=x%1000000;
		y=y+look[z*10]+" ";
	}
	z=x/100000;
	if(z!=0)
	{
		f1=1;
		x=x%100000;
		y=y+look[z%10]+" ";
	}
	if(f1==1)
		y=y+"Lakh ";
	z=x/10000;
	if(z!=0)
	{
		f2=1;
		x=x%10000;
		y=y+look[z*10]+" ";
	}
	z=x/1000;
	if(z!=0)
	{
		f2=1;
		x=x%1000;
		y=y+look[z]+" ";
	}
	if(f2==1)
		y=y+"Thousand ";
	z=x/100;
	if(z!=0)
	{
		x=x%100;
		y=y+look[z]+" Hundred ";
	}
	z=x/10;
	if(z!=0)
	{
		x=x%10;
		y=y+look[z*10]+" ";
	}
	y=y+look[x];
	cout<<y<<endl;
	return;
}

int main()
{
	defined();
	int n;
	cout<<"Enter Any no. : ";
	cin>>n;
	convert(n,"");
	return 0;
}

void defined()
{
look[1] 	= "One";
look[2] 	= "Two";
look[3] 	= "Three";
look[4] 	= "Four";
look[5] 	= "Five";
look[6] 	= "Six";
look[7] 	= "Seven";
look[8] 	= "Eight";
look[9] 	= "Nine";
look[10] 	= "Ten";
look[11] 	= "Eleven";
look[12] 	= "Twelve";
look[13] 	= "Thirteen";
look[14] 	= "Fourteen";
look[15] 	= "Fifteen";
look[16] 	= "Sixteen";
look[17] 	= "Seventeen";
look[18] 	= "Eighteen";
look[19] 	= "Nineteen";
look[20] 	= "Twenty";
look[30] 	= "Thirty";
look[40] 	= "Fourty";
look[50] 	= "Fifty";
look[60] 	= "Sixty";
look[70] 	= "Seventy";
look[80] 	= "Eighty";
look[90] 	= "Ninty";
look[100] 	= "Hundred";
look[1000] 	= "Thousand";
look[100000]= "Lakh";
}