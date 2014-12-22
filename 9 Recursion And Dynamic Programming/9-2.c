#include <stdio.h>

int paths(int x,int y)
{
	int matrix[1000][1000],i,j;
	if(x<0 || y<0)
		return 0;
	else if((x==0 || y==0 ) && (x|y!=0))
		return 1;
	else if(x==0 && y==0)
		return 0;
	for(i=0;i<=x;i++)
		matrix[i][0]=1;
	for(j=0;j<=y;j++)
		matrix[0][j]=1;
	for(i=1;i<=x;i++)
		for(j=1;j<=y;j++)
			matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];
	return matrix[x][y];
}

int main()
{
	int x,y;
	printf("Enter Goal Coordinate (x,y) : ");
	scanf("%d %d",&x,&y);
	printf("Possible Paths from (0,0) to (%d,%d) are %d\n",x,y,paths(x,y));
}