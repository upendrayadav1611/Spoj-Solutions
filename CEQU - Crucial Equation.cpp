#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int main()
{
	int t,i,a,b,c;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		cout<<"Case "<<i<<": ";
		if(c%gcd(a,b)==0)
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	
}