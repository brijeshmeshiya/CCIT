#include <iostream>
#define INF 90

using namespace std;

double slope(double x1,double y1,double x2,double y2)
{
	// If points are same
	if(x1==x2 && y1==y2)
		return 0;
	if(x1-x2!=0.0)
		return (y1-y2)/(x1-x2);
	else
		return INF; 
}

int main()
{
	// Represents two lines (x1,y1) to (x2,y2) and (p1,q1) to (p2,q2)
	// Program is to check if lines will intersect or not if extended
	double x1=0,x2=5,y1=5,y2=5,p1=2,p2=5,q1=2,q2=6;
	double slopexy,slopepq;
	slopexy=slope(x1,y1,x2,y2);
	slopepq=slope(p1,q1,p2,q2);
	if(slopexy==slopepq && (slopexy==slope(p1,q1,x1,y1) || slopexy==slope(p1,q1,x2,y2)))
		cout<<"Both lines are same"<<endl;
	else if(slopexy==slopepq)
		cout<<"Lines Are Parallel"<<endl;
	else	
		cout<<"Lines will Intersect"<<endl;
	return 0;
}