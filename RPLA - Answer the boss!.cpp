#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005];
int in[100005];
vector<pair<int,int>>ans;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)
    return a.first<b.first;
    return a.second<b.second;
}
void Kahn(int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    int level=1;
    while(!q.empty())
    {   
        int p=q.size();
        while(p--){
            int cur=q.front();
            q.pop();
            ans.push_back({level,cur});
            for(int node:vec[cur])
            {
                in[node]--;
                if(in[node]==0)
                q.push(node);
            }
        }
        level++;
    }
    
}
 
 
 
int main()
{
    int n,m,x,y,t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	    {
	    	in[i]=0;
	    	vec[i].clear();
	    }
	    while(m--)
	    {
	        cin>>x>>y;
	        vec[y].push_back(x);
	        in[x]++;
	    }
	    ans.clear();
	    cout<<"Scenario #"<<j<<":\n";
	    Kahn(n);
	    sort(ans.begin(),ans.end(),cmp);
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	    }
    }
    return 0;
    
} 