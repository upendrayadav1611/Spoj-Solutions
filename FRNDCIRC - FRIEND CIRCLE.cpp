#include<bits/stdc++.h>
using namespace std;
int par[200005],r[200005];
int find( int a)  
{  
    if (par[a]<0)  
        return a;  
    return par[a]=find(par[a]);  
}  
int merge(int a,int b)
{
	if(r[a]>r[b])
	{
		par[b]=a;
		r[a]+=r[b];
		return r[a];
	}
	else
	{
		par[a]=b;
		r[b]+=r[a];
		return r[b];
	}
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		map<string,int>mp;
		mp.clear();
		string s1,s2;
		int k=1;
		for(int i=1;i<=2*n+1;i++)
    	{
    		par[i]=-1;
    		r[i]=1;
    	}
		while(n--)
		{
    		cin>>s1>>s2;
    		
    		
    		if(!mp[s1])
    		{
    			mp[s1]=k;
    			k++;
    		}
    		if(!mp[s2])
    		{
    			mp[s2]=k;
    			k++;
    		}
    		int x=mp[s1];
    		int y=mp[s2];
    	
    		x=find(x);
    		y=find(y);
    		if(x!=y)
    		cout<<merge(x,y)<<"\n";
    		else
    		cout<<r[x]<<"\n";
		}
	}
}