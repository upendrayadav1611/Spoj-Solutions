#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        ll n;
        cin>>n;
        deque <ll> q;
        cout<<"Case "<<i<<":\n";
        while(n--)
        {
            ll p,x;
            string s;
            
            cin>>p;
            if(p==1)
            {
                cin>>s>>x;
                if(s[0]=='F')
                q.push_front(x);
                else
                q.push_back(x);
            }
            else if(p==2)
            {
                cin>>s;
                if(s[0]=='F')
                q.pop_front();
                else
                q.pop_back();
                
            }
            else
            {
                cin>>s>>x;
                if(s[0]=='D')
                {
                    cout<<q.at(x-1)<<"\n";
                }
                else
                {
                    int k=find(q.begin(),q.end(),x)-q.begin();
                    cout<<k+1<<"\n";
                }
            }
        }
        
    }
}