#include <iostream>

using namespace std;

int SIZE= 7;
int array[7];
int count[3]={0};
int *p[3]={NULL,NULL,NULL},*b[3]={NULL,NULL,NULL};

void pop(int index)
{
if(count[index]<=0)
{
cout<<"No Elements in Stack"<<endl;
}
else
{
if(index==2 )
{
p[index]++;
count[index]--;
cout<<"Popped"<<endl;
}
else if(index==0 || index==1)
{
p[index]--;
count[index]--;
cout<<"Popped"<<endl;
}
}
return;
}

void peep(int index)
{
if(count[index]<=0)
{
cout<<"No Elements in Stack"<<endl;
}
else
{
if(index==2)
	cout<<"Top : "<<*(p[index]+1)<<endl;
else if(index==0 || index==1)
	cout<<"Top : "<<*(p[index]-1)<<endl;
}
return;
}

void push(int data,int index)
{
if(!(index>=0 && index<=2 && (SIZE-(count[0]+count[1]+count[2])>3)))
{
cout<<"Stack Overflow"<<endl;
return;
}
if(index==2 && p[index]-1!=p[index-1])
{
*p[index]=data;
cout<<"Push Successful"<<endl;
count[index]++;
p[index]--;
return;
}
else if(index==1 && p[index]+1!=p[index+1])
{
*p[index]=data;
cout<<"Push Successful"<<endl;
count[index]++;
p[index]++;
return;
}
else if(index==0 && p[index]+1!=b[index+1])
{
*p[index]=data;
cout<<"Push Successful"<<endl;
count[index]++;
p[index]++;
return;
}
else
{
int *temp;
if(index==2 || index==1)
{
cout<<"Left Shifting Required"<<endl;
temp=b[1];
b[1]--;
temp--;
while((temp+1)!=p[1])
{
*temp=*(temp+1);
temp++;
}
p[1]=temp;
push(data,index);
}
else if(index==0)
{
cout<<"Right Shifting Required"<<endl;
temp=p[1]+1;
p[1]++;
while((temp-1)!=b[1])
{
*temp=*(temp-1);
temp--;
}
*temp=*b[1];
b[1]++;
push(data,index);
}
}
}


int main()
{
if(SIZE>=3)
{
p[0]=array;
p[1]=array+SIZE/3;
p[2]=array+SIZE-1;
b[0]=p[0];
b[1]=p[1];
b[2]=p[2];
}
else
{
cout<<"Array Must be greater than No. of supported Stacks"<<endl;
}
while(1)
{
cout<<"\n1.Push\n2.Pop\n3.Peep\n4.Exit\n"<<endl;
int n,i,j;
cin>>n;
switch(n)
{
case 1:
{
cout<<"Enter Element : ";
cin>>i;
cout<<"In which Stack (1-3) : ";
cin>>j;
j--;
push(i,j);
break;
}
case 2:
{
cout<<"In which Stack (1-3) : ";
cin>>j;
j--;
pop(j);
break;
}
case 3:
{
cout<<"In which Stack (1-3) : ";
cin>>j;
j--;
peep(j);
break;
}
default:
{
return 0;
}
}
}
return 0;
}
