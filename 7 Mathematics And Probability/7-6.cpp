#include <iostream>
#include <map>
#define VERTICAL 90
#define NA 0.110430	//Setting some random value

using  namespace std;

double slope(double x1,double y1,double x2,double y2)
{
	// If points are same
	if(x1==x2 && y1==y2)
		return NA;
	if(x1-x2!=0.0)
		return (y1-y2)/(x1-x2);
	else
		return NA; 
}

int main()
{
	map<double,map<double,int> > hash;
	int size=3,points[3][2]={{1,1},{2,2},{3,3}},maximum=0;
	double slopexy,c1,maximumslope=0,maximumc=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i!=j)
			{
				slopexy=slope(points[i][0],points[i][1],points[j][0],points[j][1]);
				c1=points[i][1]-slopexy*points[i][0];
				hash[slopexy][c1]++;
			}
		}
	}
	for(map<double,map<double,int> >::iterator outer_iter=hash.begin(); outer_iter!=hash.end(); ++outer_iter) 
	{
    	for(map<double,int>::iterator inner_iter=outer_iter->second.begin(); inner_iter!=outer_iter->second.end(); ++inner_iter)
        {
        	//cout<<outer_iter->first<<" ==> "<<inner_iter->first<<" => "<<inner_iter->second<<endl;
        	if(maximum<inner_iter->second)
        	{
        		maximum=inner_iter->second;
        		maximumslope=outer_iter->first;
        		maximumc=inner_iter->first;
        	}
        }
    }
    cout<<"Line is Y = "<<maximumslope<<" * X + "<<maximumc<<endl;
}