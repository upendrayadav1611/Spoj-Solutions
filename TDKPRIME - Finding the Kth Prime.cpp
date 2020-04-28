#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool prime[90000001];
vector<int>vec;
void sieve()
{
    int maxn=90000000;
    
    prime[0]=prime[1]=true;
    for(int i=2;i*i<maxn;i++)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=maxn;j=j+i)
            prime[j]=true;
            
        }
    }
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i])
        vec.push_back(i);
    }
    
}
int main()
{
    ll q;
    cin>>q;
    sieve();
    while(q--)
    {
        ll n;
        cin>>n;
        cout<<vec[n-1]<<"\n";
        
    }
    return 0;
}