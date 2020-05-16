#include<bits/stdc++.h> 
// https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
using namespace std; 
#define ll long long int
ll sumOfDigitsFrom1ToN(ll n) 
{ 
    if (n<10) 
      return n*(n+1)/2;
    ll d = log10(n);
    ll *a = new ll[d+1]; 
    a[0] = 0, a[1] = 45; 
    for (ll i=2; i<=d; i++) 
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));
    ll p = ceil(pow(10, d));
    ll msd = n/p;
    return msd*a[d] + (msd*(msd-1)/2)*p +   
           msd*(1+n%p) + sumOfDigitsFrom1ToN(n%p); 
} 
int main()
{
	ll a,b;
	while(1)
	{
		cin>>a>>b;
		if(a==-1&&b==-1)
		break;
		cout<<sumOfDigitsFrom1ToN(b)-sumOfDigitsFrom1ToN(a-1)<<"\n";  
	}
	return 0;
}