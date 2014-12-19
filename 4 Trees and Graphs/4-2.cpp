#include <iostream>
#include <queue>

using namespace std;

//Using BFS
bool search(int *path,int start,int end,int r,int c)
{
queue <int> q1;
q1.push(start);
bool visited[r];
visited[start]=1;
for(int i=0;i<r;i++)
	visited[r]=0;
while(!q1.empty())
{
if(q1.front()==end)
	return 1;
else
{
int index=q1.front();
for(int i=0;i<r;i++)
{
if(*((path)+index*c+i)==1 && visited[i]!=1)
{
q1.push(i);
visited[index]=1;
}
}
q1.pop();
}
}
return 0;
}

int main()
{
int path[][8]={{0,1,1,0,0,0,0,0},{1,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,1,0,1,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0}};
int r;
r=sizeof(path)/sizeof(path[0]);
if(search((int*)path,0,7,r,r))
	cout<<"Yes"<<endl;
else
	cout<<"No"<<endl;
return 0;
}
