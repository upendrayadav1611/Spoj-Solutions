#include<bits/stdc++.h>
 
using namespace std;
#define ll long long int
 
 
ll a[55][55],dis[55][55],ch[55][55];
void floyd(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=a[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>=(dis[i][k]+dis[k][j])){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
int main()
{   
    int t;
    cin>>t;
   for(int tt=1;tt<=t;tt++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j];
        }
        
        floyd(n);
        int q;
        cin>>q;
        ll ans=0;
        int s,d;
        while(q--){
            cin>>s>>d;
            ans+=dis[s][d];
        }
        cout<<"Case #"<<tt<<": ";
        cout<<ans<<"\n";
    }
    
    return 0;
} 