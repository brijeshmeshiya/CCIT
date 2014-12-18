#include <stdio.h>

void print(int x[][4],int ,int );

void transform(int mat[4][4],int m,int n)
{
int row,col,i,j,flagr=1,flagc=1;
col=n;
row=m;
if(row>0 && col>0)
{
for(i=0;i<col;i++)
{
	flagc &= mat[0][i];
}
for(i=0;i<row;i++)
{
	flagr &= mat[i][0];
}
for(i=1;i<row;i++)
{
for(j=1;j<col;j++)
{
mat[i][0] &= mat[i][j];
mat[0][i] &= mat[j][i];
}
}
for(i=1;i<row;i++)
{
for(j=1;j<col;j++)
{
if(mat[i][0]==0)
	mat[i][j]=0;
if(mat[0][i]==0)
	mat[j][i]=0;
}
}
if(flagr==0)
{
for(i=0;i<row;i++)
	mat[i][0]=0;
}
if(flagc==0)
{
for(i=0;i<col;i++)
	mat[0][i]=0;
}
}
return;
}

void print(int x[][4],int m,int n)
{
int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%3d ",x[i][j]);
}
printf("\n");
}
}

int main()
{
int r=3,c=4,mat[][4]={1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1}; //works only if elements are either 0 or 1
printf("Before : \n");
print(mat,r,c);
transform(mat,r,c);
printf("After : \n");
print(mat,r,c);
return 0;
}
