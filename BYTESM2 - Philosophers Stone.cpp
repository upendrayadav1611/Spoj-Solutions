#include<bits/stdc++.h>
using namespace std;
int a[104][104],dp[104][104];
int h,w;
int compute()
{
	int i,j;
	memset(dp,0,sizeof(dp));
	for(i=0;i<w;i++)
	{
		dp[0][i]=a[0][i];
	}
	for(i=0;i<h-1;i++)
	{
		for(j=0;j<w;j++)
		{
			if(j>0)
			dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+a[i+1][j-1]);
			if(j<w-1)
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
			
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
		}
	}
	int ans=-1;
	for(i=0;i<w;i++)
	{
		ans=max(ans,dp[h-1][i]);
	}
	return ans;
}
int main()
{
	int t,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>h>>w;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)	
			cin>>a[i][j];
		}
		cout<<compute()<<"\n";
	}
	
	
}