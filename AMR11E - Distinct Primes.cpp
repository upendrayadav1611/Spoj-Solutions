// for Explanation: https://www.geeksforgeeks.org/nth-smart-number/
#include<bits/stdc++.h>
using namespace std;
int primes[30004];
vector<int>vec;
void calculate()
{
	for(int i=2;i<30004;i++)
	{
		if(primes[i]==0)
		{
			primes[i]=1;
			for(int j=i*2;j<30004;j=j+i)
			{
				primes[j]-=1;
				if(primes[j]+3==0)
				vec.push_back(j);
			}
		}
	}
	sort(vec.begin(),vec.end());
}
int main()
{
	int t,n;
	cin>>t;
	calculate();
	while(t--)
	{
		cin>>n;
		cout<<vec[n-1]<<"\n";
	}
}