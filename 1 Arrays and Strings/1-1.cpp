#include <iostream>
#include <stdio.h>

using namespace std;

bool areunique(char *s)
{
bool visited[256]={0};
while(*s!='\0')
{
if(visited[(int) *s] == 1)
	return false;
else
	visited[(int )*s] = 1;
s++;
}
return true;
}

int main()
{
char i[1000000];
printf("Enter String (Without Spaces) : ");
scanf("%s",i);
if(areunique(i))
	printf("All Characters Are Unique\n");
else
	printf("All Characters Are Not Unique\n");
return 0;
}
