#include <stdio.h>
#include <string.h>

int areequal(char *a,char *b)
{
	int i=0,l = strlen(a);
	for(i=0;i<l;i++)
	{
		if(*a!=*b)
			return 0;
		a++;
		b++;
	}
	return 1;
}

void find(char *a,char *b)
{
	char *p1=b,*p2=b;
	int i,l1=strlen(a),l2=strlen(b),count=0;
	p1=p2;
	while(p1)
	{
		i=l1;
		while(i>0 && p2 && *p2!=' ')
		{
			i--;
			p2++;
		}
		if(!p2)
			goto L;
		if((i==0 && p2 && *p2==' ') || (i==0 && *p2=='\0'))
		{
			if(areequal(a,p1)==1)
				count++;
		}
		else if(i==0 && p2<(b+l2) && *p2!=' ')
		{
			while(*p2 && *p2!=' ')
			{
				p2++;
			}
			if(!p2)
				goto L;
			while(p2 && *p2==' ')
				p2++;
			if(!p2)
				goto L;
		}
		else if(i!=0 && p2<(b+l2) && *p2==' ')
		{
			while(p2 && *p2==' ')
				p2++;
			if(!p2)
				goto L;
		}
		else
			goto L;
		p1=p2;
	}
L:	printf("Found %d Times\n",count);
}

int main()
{
	find((char *)"Searching",(char *)"hello world Searching hello hel losearching Searching");
	return 0;
}