#include <stdio.h>

int length(char *s)
{
int l=0;
if(s){
while(*s!='\0')
{
s++;
l++;
}
}
return l;
}

void compress(char *s)
{
char temp[10000];
char *save=s;
char *t=s;
int count,counter=0;
while(*t!='\0')
{
count=0;
while(*t!='\0' && *t==*s)
{
count++;
t++;
}
temp[counter]=*s;
counter++;
if(count>0 && count<=9)
{
temp[counter]=count+48;
counter++;
}
else if(count>0 && count<=99)
{
temp[counter+1]=(count%10)+48;
count/=10;
temp[counter]=count%10+48;
counter=counter+2;
}
s=t;
}
temp[counter]='\0';
s=save;
if(length(temp)<length(s))
	printf("%s\n",temp);
else
	printf("%s\n",s);
return;
}

int main()
{
char s[10000];
gets(s);
compress(s);
return 0;
}
