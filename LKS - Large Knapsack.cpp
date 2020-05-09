// For explanation: geeksforgeeks.org/space-optimized-dp-solution-0-1-knapsack-problem/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int KnapSack(int val[], int wt[], int n, int W) 
{ 
   
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i < n; i++)
        for(int j=W; j>=wt[i]; j--) 
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);  
    return dp[W]; 
} 
int main()
{
	int k,n,i;
	scanf("%d%d",&k,&n);
    int wt[n],val[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&val[i],&wt[i]);
		
	}
	cout<<KnapSack(val,wt,n,k)<<"\n";
	return 0;
	
}
