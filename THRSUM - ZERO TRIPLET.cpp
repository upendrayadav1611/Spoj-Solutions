#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 vector<vector<ll> > result;
void threeSum(vector<ll> A) {
	sort(A.begin(), A.end());
    long long int n = A.size();
   
    long long int c = 0;
    for (auto i = 0; i<n-2; ++i)
    {
        long long int l = i+1, r = n-1;
        if (i>0 && A[i]==A[i-1]) 
            continue;
            
        while(l<r)
        {
            long long int sum = A[i]+A[l]+A[r];
            if(sum==0)
            {
                vector<ll> temp = {A[i], A[l], A[r]};
                ll s = result.size();
                if(s>0 && result[s-1][0]==temp[0] && result[s-1][1]==temp[1] && result[s-1][2]==temp[2]);
                else
                    result.push_back(temp);
                ++l; --r;
            }
            else if(sum>0)
                --r;
            else
                ++l;
        }
    }
          
}

int main()
{
	ll t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll>a(n);
		for(i=0;i<n;i++)
		cin>>a[i];
		result.clear();
		threeSum(a);
		cout<<result.size()<<"\n";
		ll k=result.size();
		for(i=0;i<k;i++)
		{
			for(ll j=0;j<result[i].size();j++)
			cout<<result[i][j]<<" ";
			
			cout<<"\n";
		}
		
	}
}