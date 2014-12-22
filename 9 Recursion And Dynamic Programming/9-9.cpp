#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <cstdlib>

using namespace std;

void transform(bool *temp,bool *board,int r,int c,int row)
{
	int i,j,k;
	for(int i=0;i<row;i++)
		for(j=0;j<row;j++)
		{
			*(temp+i*row+j)=*(board+i*row+j);
			if(i==r || j==c)
				*(temp+i*row+j)=1;
			else if(abs(r-i)==abs(c-j))
				*(temp+i*row+j)=1;
		}
	return;
}

void find_queen(bool *board,int current,int row,int queen,string position)
{
	int i,j,k;
	bool temp[10][10];
	if(queen<0 || current>row)
		return;
	if(queen==0)
	{
		cout<<position<<endl;
		return;
	}
	for(i=0;i<row;i++)
	{
		if(*(board+current*row+i)==0)
		{
			transform((bool *)temp,(bool *)board,current,i,row);
			find_queen((bool *)temp,current+1,row,queen-1,position+"("+(char)(i+48)+","+(char)(current+48)+") ");
		}
	}
}

int main()
{
	bool square[5][5]={0};
	int row=4,column=row;
	find_queen((bool *)square,0,row,row,"");
	return 0;
}