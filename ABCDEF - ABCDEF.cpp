#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,i,j,k;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	vector<ll>lhs,rhs;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				ll p=a[i]*a[j]+a[k];
				lhs.push_back(p);
				if(a[i]!=0)
				{
					p=a[i]*(a[j]+a[k]);
					rhs.push_back(p);
				}
			}
		}
	}
	ll ans=0;
	sort(rhs.begin(),rhs.end());
	sort(lhs.begin(),lhs.end());
	for(i=0;i<rhs.size();i++)
	{
		ans=ans+upper_bound(lhs.begin(),lhs.end(),rhs[i])-lower_bound(lhs.begin(),lhs.end(),rhs[i]);	
	}
	cout<<ans<<"\n";
	
}
