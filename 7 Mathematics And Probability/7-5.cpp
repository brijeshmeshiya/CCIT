#include <iostream>
#include <limits.h>
#include <float.h>

using namespace std;

double ansminx=1000,ansminy=1000,ansmaxx=0,ansmaxy=0;

double slope(double x1,double y1,double x2,double y2)
{
	// If points are same
	if(x1==x2 && y1==y2)
		return DBL_MIN;
	if(x1-x2!=0.0)
		return (y1-y2)/(x1-x2);
	else
		return DBL_MAX; 
}

bool possible(double m1,double c1,double m2,double c2,double x1,double y1,double x2,double y2)
{
	double x=0,y=0,minx,maxx,miny,maxy;
	minx=min(x1,x2);
	miny=min(y1,y2);
	maxx=max(x1,x2);
	maxy=max(y1,y2);
	if(m1!=m2){
		x=(c1-c2)/(m2-m1);
		y=m1*x+c1;
		if(x>=minx && x<=maxx && y>=miny && x<=maxy)
		{
			//cout<<" ("<<x<<","<<y<<" )";
			if(x*x+y*y>(ansmaxx*ansmaxx+ansmaxy*ansmaxy))
			{
				ansmaxx=x;
				ansmaxy=y;
			}
			if(x*x+y*y<(ansminx*ansminx+ansminy*ansminy))
			{
				ansminx=x;
				ansminy=y;
			}
			return true;
		}
		return false;
	}
	return false;
}

int main()
{
	// Not covered Critical cases
	// Represents two squares with its coordinate;
	double squares[2][8]={{0,0,0,1,1,1,1,0},{2,10,2,9,3,9,3,10}};
	double center[2][2];
	double lines[2][4][2],slopemid,interceptmid;	// Represents slope and intercept
	
	// Computing Center of Squares
	center[0][0]=(squares[0][0]+squares[0][4])/2;
	center[0][1]=(squares[0][1]+squares[0][5])/2;
	center[1][0]=(squares[1][0]+squares[1][4])/2;
	center[1][1]=(squares[1][1]+squares[1][5])/2;

	cout<<"Center 1 : "<<center[0][0]<<","<<center[0][1]<<endl;
	cout<<"Center 2 : "<<center[1][0]<<","<<center[1][1]<<endl;

	// Line joining both centers
	slopemid=slope(center[0][0],center[0][1],center[1][0],center[1][1]);
	interceptmid=center[0][1]-slopemid*center[0][1];

	// Finding Equation of lines for both Square's side	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<8;j=j+2)
		{
			lines[i][j/2][0]=slope(squares[i][j],squares[i][(j+1)%8],squares[i][(j+2)%8],squares[i][(j+3)%8]);
			lines[i][j/2][1]=squares[i][j+1]-lines[i][j/2][0]*squares[i][j];
			if(possible(slopemid,interceptmid,lines[i][j/2][0],lines[i][j/2][1],squares[i][j],squares[i][(j+1)%8],squares[i][(j+2)%8],squares[i][(j+3)%8])==1);
				//cout<<"Possible"<<endl;
		}
	}
	cout<<"Points are : ("<<ansminx<<","<<ansminy<<")"<<" And ("<<ansmaxx<<","<<ansmaxy<<")"<<endl;

	return 0;
}