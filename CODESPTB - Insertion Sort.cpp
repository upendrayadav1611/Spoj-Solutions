#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll insertionSort(ll arr[], ll n)  
{  
    ll i, key, j;
    ll cnt=0;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
            cnt++;
        }  
        arr[j + 1] = key;  
    }  
    return cnt;
}  
int main()
{
	ll t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll a[n];
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		printf("%lld\n",insertionSort(a,n));
	}
}
  