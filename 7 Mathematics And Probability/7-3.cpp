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

// In the form y=mx+c
// Prints if lines will intersect
void intersect(double m1,double c1,double m2,double c2)
{
	double x=0,y=0;
	if(m1!=m2){
		x=(c1-c2)/(m2-m1);
		y=m1*x+c1;
		cout<<"Intersecting of y="<<m1<<"*x+"<<c1<<" And y="<<m2<<"*x+"<<c2<<" is ("<<x<<" ,"<<y<<")"<<endl;
	}
}

int main()
{
	// Represents two lines (x1,y1) to (x2,y2) and (p1,q1) to (p2,q2)
	// Program is to check if lines will intersect or not if extended
	double x1=1,x2=2,y1=1,y2=2,p1=1,p2=4,q1=1,q2=2,c1,c2;
	double slopexy,slopepq;
	slopexy=slope(x1,y1,x2,y2);
	slopepq=slope(p1,q1,p2,q2);
	if(slopexy==slopepq && (slopexy==slope(p1,q1,x1,y1) || slopexy==slope(p1,q1,x2,y2)))
		cout<<"Both lines are same"<<endl;
	else if(slopexy==slopepq)
		cout<<"Lines Are Parallel"<<endl;
	else
	{	
		cout<<"Lines will Intersect"<<endl;
		if(x1!=0)
			c1=y1/(slopexy*x1);
		else if(x2!=0)
			c1=y2/(slopexy*x2);
		if(p1!=0)
			c2=q1/(slopepq*p1);
		else if(p2!=0)
			c2=q2/(slopepq*p2);
		if((x1!=0 || x2!=0) && (p1!=0 || p2!=0))
			intersect(slopexy,c1,slopepq,c2);
	}
	return 0;
}