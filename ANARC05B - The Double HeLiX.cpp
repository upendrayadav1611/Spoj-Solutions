#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll binary_search(ll a[],ll low,ll high,ll val)
{
	while(low<high)
	{	
		ll mid=low+(high-low)/2;
		if(a[mid]==val)
		return mid;
		if(a[mid]<val)
		return binary_search(a,mid+1,high,val);
		else
		return binary_search(a,low,mid,val);
	}
	return -1;
}
ll max(ll a, ll b)
{
	if(a<b)
	return b;
	return a;
}
int main()
{
	int n,m;
	while(1)
	{
		cin>>n;
		if(n==0)
		break;
		ll a[n],i;
		for(i=0;i<n;i++)
		cin>>a[i];
		cin>>m;
		ll b[m];
		for(i=0;i<m;i++)
		cin>>b[i];
		ll idx=-1,sum1=0,sum2=0,mx=0,j;
		for(i=0;i<n;i++)
		{	
			sum1=sum1+a[i];
			ll k=binary_search(b,idx+1,m,a[i]);
			if(k!=-1)
			{
				for(j=idx+1;j<=k;j++)
				{
					sum2=sum2+b[j];
				}
				mx=mx+max(sum1,sum2);
				sum1=sum2=0;
				idx=k;
				
			}
		}
		for(j=idx+1;j<m;j++)
		sum2=sum2+b[j];
		mx=mx+max(sum1,sum2);
		cout<<mx<<"\n";
		
		
	}
}