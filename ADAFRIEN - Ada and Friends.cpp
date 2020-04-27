#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<string,ll>mp;
bool comp(pair<string,ll>a,pair<string,ll>b)
{
    return a.second>b.second;
}
int main()
{
    
    ll n,k;
    cin>>n>>k;
    ll e;
    while(n--)
    {
        string s;
        cin>>s>>e;
        mp[s]+=e;
    }
    ll ans=0;
    vector<pair<string, ll>> vec;

	// copy key-value pairs from the map to the vector
  
  for (auto it2=mp.begin(); it2!=mp.end(); it2++) 
  {
    vec.push_back(make_pair(it2->first, it2->second));
  }
    sort(vec.begin(),vec.end(),comp);
    for(int  i=0;i<vec.size();i++)
    {
        if(k>0)
        {
            ans=ans+vec[i].second;
            k--;
        }
        else
        {
            break;
        }
        
    }
    cout<<ans<<"\n";
    
}