#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int n,int m)
{
	int dp[n+1][m+1];
	int i,j;
	for(i=0;i<n+1;i++)
	{
	    for(j=0;j<m+1;j++)
	    {
	        if(i==0||j==0)
	        dp[i][j]=0;
	    }
	}
	for(i=1;i<n+1;i++)
	{
	    for(j=1;j<m+1;j++)
	    {
	        if(x[i-1]==y[j-1])
	        dp[i][j]=1+dp[i-1][j-1];
	        else
	        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	    }
	}
	return dp[n][m];
	
}
int main()
{
	int t,i,n;
		cin>>n;
		string s;
		cin>>s;
	
		string s1(n,'a');
		for(i=0;i<n;i++)
		s1[i]=s[n-i-1];
		int l=lcs(s,s1,n,n);
		cout<<n-l<<"\n";
	return 0;
}