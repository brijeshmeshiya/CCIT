#include <stdio.h>

void reverse(char *s)
{
char *front,*end;
front=s;end=s;
while(*end!='\0')
	end++;
end--;
char c;
while(front<end)
{
c = *front;
*front = *end;
*end = c;
front++;
end--;
}
return ;
}

int main()
{
char buf[100000];
printf("Enter String to Reverse : ");
scanf("%s",buf);
reverse(buf);
printf("Reversed : %s\n",buf);
return 0;
}
