#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll getMaxArea(ll hist[], ll n) 
{ 
    stack<int> s; 
    ll max_area = 0;
    ll tp; 
    ll area_with_top; 
    ll i = 0; 
    while (i < n) 
    { 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++);
        else
        { 
            tp = s.top();  
            s.pop(); 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 
int main()
{
	ll n,i,ar,mx=0;
	cin>>n;
	while(n!=0)
	{
		ll a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<getMaxArea(a,n)<<"\n"; 
		cin>>n;
	}
}