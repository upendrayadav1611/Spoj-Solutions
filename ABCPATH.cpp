#include<bits/stdc++.h>
using namespace std;
char ch[55][55];
bool vis[55][55];
int mx;
int dx[]={-1,1,0,0,-1,1,-1,1};
int dy[]={0,0,1,-1,1,1,-1,-1};
int h,w;
set<char>st;
bool isvalid(int row,int col)
{
	return row>=0&&row<h&&
			col>=0&&col<w;
}
void bfs(pair<int,int>a)
{
	memset(vis,false,sizeof(vis));
	vis[a.first][a.second]=true;
	queue<pair<int,int>>q;
	q.push(a);
	st.clear();
	st.insert(ch[a.first][a.second]);
	while(!q.empty())
	{
		pair<int,int>p=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			int rx=p.first+dx[i];
			int ry=p.second+dy[i];
			if(isvalid(rx,ry)&&ch[rx][ry]==ch[p.first][p.second]+1&&!vis[rx][ry])
			{   
			    vis[rx][ry]=true;
			    //cout<<ch[rx][ry]<<"\n";
				q.push({rx,ry});
				st.insert(ch[rx][ry]);
			}
		}
		
	}
}
int main()
{
	//cin>>h>>w;
	int t=1;
	while( scanf("%d %d",&h,&w) , h != 0 , w != 0 )
	{
    	int i,j;
    	mx=0;
    	for(i=0;i<h;i++)
    	{
    		for(j=0;j<w;j++)
    		cin>>ch[i][j];
    	}
    	for(i=0;i<h;i++)
    	{
    		for(j=0;j<w;j++)
    		{   
    		    if(ch[i][j]=='A')
    		    {
        			bfs({i,j});
        			if(st.size()>mx)
        			mx=st.size();
    		    }
    		}
    	}
    	cout<<"Case "<<t<<": ";
    	cout<<mx<<"\n";
    	//cin>>h>>w;
    	t++;
	}
}