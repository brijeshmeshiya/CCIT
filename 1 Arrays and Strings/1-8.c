#include <stdio.h>

// Mtthod : Rabin Carp algorithm

int hashing(char *s,int len)
{
int hash=0;
if(s)
{
while(len>0)
{
hash=hash+(*s-48);
s++;
len--;
}
}
return hash;
}

int length(char *s)
{
int len=0;
if(s)
{
while(*s)
{
len++;
s++;
}
}
return len;
}

int check(char *s1,char *s2)
{
int ans=0;
if(s1 && s2)
{
while(*s1!='\0' && *s1==*s2)
{
s2++;
s1++;
}
if(*s1=='\0')
	return 1;
}
return 0;
}

int issubstring(char *s1,char *s2)	// s1 : lookinto , s2 = lookfor
{
int ans=0,hash,i,len,temphash;
char *save=s1;
if(s1 && s2 && length(s1)>=length(s2))
{
len=length(s1);
hash=hashing(s2,length(s2));
temphash=hashing(s1,length(s2));
if(temphash==hash && check(s2,s1)){
	return 1;
}
s1=s1+length(s2);
for(i=1;i<len-length(s2)+1;i++)
{
temphash=temphash-*(save)+*(s1);
save++;
s1++;
if(temphash==hash && check(s2,save)){
	return 1;
}
}
}
return ans;
}

void copytwice(char *s)
{
int len,i;
if(s)
{
i=0;
len = length(s);
while(i<len)
{
*(s+len)=*s;
s++;
i++;
}
*(s+len) = '\0';
}
}

int main()
{
char s1[10000],s2[10000];
gets(s1);
gets(s2);
printf("%s == %s : ",s1,s2);
copytwice(s1);
if(issubstring(s1,s2))
	printf("Yes\n");
else
	printf("No\n");
return 0;
}
