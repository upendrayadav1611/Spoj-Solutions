#include<bits/stdc++.h>
using namespace std;
char ch[1005][1005];
int vis[1005][1005];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int length=0,mx=0;
int x,y,c,r,id;
void dfs(int a,int b)
{
	vis[a][b]=id;
	length++;
	if(length>mx)
	{
		mx=length;
		x=a;
		y=b;
	}
	for(int j=0;j<4;j++)
	{
		int cx=a+dx[j];
		int cy=b+dy[j];
		if(cx<0||cy<0||cx>=r||cy>=c||vis[cx][cy]||ch[cx][cy]=='#')
		continue;
		dfs(cx,cy);
	}
	length--;
	vis[a][b]=0;
}
int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>c>>r;
		for(i=0;i<r;i++)
		{
			
			cin>>ch[i];
		}
		length=0,mx=0;
		id++;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(ch[i][j]!='#')
				{
					dfs(i,j);
					i=r;
					break;
				}
			}
		}
		length=0,mx=0;
		id++;
		dfs(x,y);
		printf("Maximum rope length is %d.\n", mx - 1);
	}
}
