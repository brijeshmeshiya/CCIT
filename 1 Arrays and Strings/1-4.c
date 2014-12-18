#include <stdio.h>

int length(char *s){
if(s){
int counter=0; while(*s!='\0'){s++;counter++;} return counter;	
}
return 0;
}

int occurrence(char *s,char t){
if(s){
int occur=0; 
while(*s!='\0')
{
if(*s==t)
{
++occur;
}
s++;
}
return occur;
}
return 0;
}

void reverse(char *t){
if(t){char *x,r;x=t+length(t)-1;while(t<x){r=*x;*x=*t;*t=r;t++;x--;}}
}

void extend(char *s,char toreplace,char *replacewith){
reverse(replacewith);
int shifts,counts = occurrence(s,toreplace);
if(counts){
shifts=counts*(length(replacewith)-1);
char *tmp,*last;
last=s+length(s)-1;
tmp=last+shifts;
while(last<=tmp && last>=s){
if(*last!=toreplace)
{
*tmp=*last;
tmp--;
last--;
}
else
{
char *x=replacewith;
while(*x!='\0')
{
*tmp=*x;
tmp--;
x++;
}
last--;
}
}
}
return ;
}

int main(){
char a,b[10],c[10000];
printf("Enter String : ");
gets(c);
printf("Enter Character and Its Replacement : ");
fflush(stdin);
scanf("%c",&a);
scanf("%s",b);
printf("%s %c ---> %s\n",c,a,b);
extend(c,a,b);
printf("O/P : %s\n",c);
return 0;
}
