#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int a[50003];
struct data {
    int sum, pref, suff, ans;
};
data t[4*50003];

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = val;
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) 
    {
        t[v].sum=t[v].pref=t[v].suff=t[v].ans=a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
data query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    if(r<=tm)
    return query(v*2,tl,tm,l,r);
    else if(l>tm)
    return query(v*2+1,tm+1,tr,l,r);
    else
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int main()
{
    int n,m,i;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
            cout<<query(1,1,n,x,y).ans<<"\n";
        
        
        
    }
    
    
}