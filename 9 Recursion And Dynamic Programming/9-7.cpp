#include <iostream>

using namespace std;

void fillcolor(char *screen,char toreplace,char replacewith,int r,int c,int row,int column)
{
	if(r>row || r<0 || c>column || c<0)
		return;
	if(*(screen+r*column+c)==toreplace)
	{
		*(screen+r*column+c)=replacewith;
		fillcolor(screen,toreplace,replacewith,r+1,c,row,column);
		fillcolor(screen,toreplace,replacewith,r-1,c,row,column);
		fillcolor(screen,toreplace,replacewith,r,c-1,row,column);
		fillcolor(screen,toreplace,replacewith,r,c+1,row,column);
	}
}

void print(char *screen,int rows,int columns)
{
	cout<<"Screen : "<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<*(screen+i*columns+j)<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	char screen[5][5]={{'R','G','B','R','G'},{'R','G','G','R','Y'},{'Y','B','C','O','B'},{'W','W','P','Y','G'},{'Y','P','G','R','B'}};
	print((char *)screen,5,5);
	fillcolor((char *)screen,'R','G',1,3,5,5);
	print((char *)screen,5,5);
}