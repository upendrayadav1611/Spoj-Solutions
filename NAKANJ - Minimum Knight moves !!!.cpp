#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
bool vis[9][9];
int rowNum[] = {-2, -2, 2, 2,-1,-1,1,1}; 
int colNum[] = {1,-1,1,-1,2,-2,2,-2}; 


bool isValid(int row, int col) 
{ 
    return (row >= 1) && (row <=8) && 
           (col >= 1) && (col <= 8); 
} 
int bfs(pair<int,int>a,pair<int,int>b)
{
    memset(vis,false,sizeof(vis));
    vis[a.fi][a.se]=true;
    queue<pair<pair<int,int>,int>>q;
    q.push({a,0});
    while(!q.empty())
    {
        pair<pair<int,int>,int>p=q.front();
        q.pop();
        if(b.fi==p.fi.fi&&b.se==p.fi.se)
                return p.se;
        for (int i = 0; i < 8; i++) 
        { 
            int row = p.fi.fi + rowNum[i]; 
            int col = p.fi.se + colNum[i];
            if (isValid(row, col) &&!vis[row][col]) 
            { 
                vis[row][col] = true; 
                
                
                q.push({{row,col},p.se+1}); 
            } 
        } 
    }
    
}
int main()
{
    int q,i,j,s,d,x,y,t;
    cin>>t;
    while(t--)
    {
	    string s1,s2;
	    cin>>s1>>s2;
	    x=s1[0]-'a'+1;
	    y=s1[1]-'0';
	    s=s2[0]-'a'+1;
	    d=s2[1]-'0';
	    cout<<bfs({x,y},{s,d})<<"\n";
	    
    }


}