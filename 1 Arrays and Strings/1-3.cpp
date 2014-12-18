#include <iostream>
#include <stdio.h>

using namespace std;

int leng(char *s)
{
if(s)
{
int counter=0;
while(*s!='\0')
{
s++;
counter++;
}
return counter;
}
return 0;
}

bool arepermutation(char *s,char *t)
{
int i,track[256]={0};
if(leng(s)==leng(t))
{
while(*s!='\0')
{
track[(int)*s]++;
s++;
}
while(*t!='\0')
{
track[(int)*t]--;
t++;
}
for(i=0;i<256;i++)
{
if(track[i]!=0)
	return false;
}
return true;
}
return false;
}

int main()
{
char s[10000],t[10000];
printf("Enter Two Strings : ");
scanf("%s %s",s,t);
if(arepermutation(s,t))
	printf("Yes");
else
	printf("No");
return 0;
}
