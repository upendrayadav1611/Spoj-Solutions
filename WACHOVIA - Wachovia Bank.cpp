#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int max_sum(int wt[],int val[], int n,int w)
{
	int dp[n+1][w+1];
	int i,j;
    for( i=0;i<n+1;i++)
    {
        for( j=0;j<w+1;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else
            dp[i][j]=-1;
        }
    }
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<w+1;j++)
		{
			if(j>=wt[i-1])
			dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][w];
}
int main()
{
	int k,n,i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&n);
	    int wt[n],val[n];
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&wt[i],&val[i]);
			
		}
		printf("Hey stupid robber, you can get %d.\n",max_sum(wt,val,n,k));
	}
	return 0;
	
}
