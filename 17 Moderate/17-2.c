#include <stdio.h>
#include <string.h>

void haswon(int *board,int rows,int cols)
{
	int tempr,tempc,i,j;
	char *msg = (char *)"Won Player";
	// Checking for all rows
	for(i=0;i<rows;i++)
	{
		if(*(board+i*cols)!=0)
		{
			j=0;
			while(j<cols-1 && *(board+i*cols+j)==*(board+i*cols+(j+1)))
				j++;
			if(j==cols-1)
			{
				printf("Player %d Won\n",*(board+i*cols));
				return;
			}
		}
	}

	//Checking for cols
	for(i=0;i<cols;i++)
	{
		if(*(board+i)!=0)
		{
			j=0;
			while(j<rows-1 && *(board+j*cols+i)==*(board+((j+1)*cols)+i))
				j++;
			if(j==rows-1)
			{
				printf("Player %d Won\n",*(board+i));
				return;
			}
		}
	}

	//Checking for Diagonals
	i=0;
	if(*(board)!=0)
	{
		j=0;
		while(i<rows-1 && j<cols-1 && *(board+i*cols+j)==*(board+(i+1)*cols+(j+1)))
		{
			i++;
			j++;
		}
		if(i==rows-1 && j==cols-1)
		{
			printf("Player %d Won\n",*(board));
			return;
		}
	}

	//Checking for Reverse Diagonal
	j=cols-1;
	i=0;
	if(*(board+j)!=0)
	{
		while(j>0 && i<rows-1 && *(board+i*cols+j)==*(board+(i+1)*cols)+(j-1))
		{
			i++;
			j--;
		}
		if(j==0 && i==rows-1)
		{
			printf("Player %d Won\n",*(board+cols-1));
			return;
		}
	} 

	printf("No One Won\n");
	return ;
}

int main()
{
	int board[][3]={1,1,1,0,1,0,2,0,0};
	int rows=3,cols=3;
	haswon((int *)board,rows,cols);
	return 0;
}