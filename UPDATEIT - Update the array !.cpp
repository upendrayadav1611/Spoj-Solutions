#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxN = 1000001;
//ll ar[maxN];
ll st[4*maxN] , lazy[4*maxN];
 
 
ll query(ll si , ll ss , ll se , ll qs , ll qe)
{
	if(lazy[si] != 0)
	{
		ll dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return 0;
 
	if(ss >= qs && se <= qe)
	return st[si];
 
	ll mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}
 
void update(ll si , ll ss , ll se , ll qs , ll qe , ll val)
{
	if(lazy[si] != 0)
	{
		ll dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return;
 
	if(ss >= qs && se <= qe)
	{
		ll dx = (se - ss + 1) * val;
		st[si] += dx;
 
		if(ss != se)
		lazy[2*si] += val , lazy[2*si+1] += val;
		return;
	}
 
	ll mid = (ss + se) / 2;
	update(2*si , ss , mid , qs , qe , val);
	update(2*si+1 , mid+1 , se , qs , qe , val);
 
	st[si] = st[2*si] + st[2*si+1];
}
 
 
int main()
{
	ll n ,t, q , code , l , r , val;
	cin>>t;
	while(t--)
	{
    	cin>>n>>q;
    	memset(st,0,sizeof(st));
        memset(lazy,0,sizeof(lazy));
    
     
    	while(q--)
    	{
    			cin>>l>>r>>val;
    			update(1 , 0 , n-1 , l , r , val);
    		
    	}
    	ll m;
    	cin>>m;
    	while(m--)
    	{
    	    cin>>l;
    	    cout<<query(1,0,n-1,l,l)<<"\n";
    	}
	}
}