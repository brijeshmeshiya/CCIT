#include <stdio.h>

void swap(int *x,int *y)
{
*x=*x+*y;
*y=*x-*y;
*x=*x-*y;
return ;
}

void rotate(int image[][3],int n)
{
int i,j;
for(i=0;i<n;i++)
	for(j=i+1;j<n;j++)
		swap(&image[i][j],&image[j][i]);

for(i=0;i<n;i++)
	for(j=0;j<n/2;j++)
		swap(&image[i][j],&image[i][n-j-1]);

return ;
}

void print(int image[][3],int n)
{
int i,j;
for(i=0;i<n;i++){
	for(j=0;j<n;j++)
{		printf("%2d ",image[i][j]);}
	printf("\n");}
}

void main()
{
int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
rotate(matrix,3);
print(matrix,3);
return;
}
