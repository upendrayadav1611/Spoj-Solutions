#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int a[205][205],dis[205][205],ch[205][205];
void floyd(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0)
            dis[i][j]=1e8;
            else
            dis[i][j]=a[i][j];
            ch[i][j]=0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]==(dis[i][k]+dis[k][j])){
                    //dis[i][j]=dis[i][k]+dis[k][j];
                    ch[i][j]=1;
                }
            }
        }
    }
}
int main()
{   
    int t;
    cin>>t;
   while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin>>a[i][j];
        }
        
        floyd(n);
        vector<pair<int,int>>ans;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dis[i][j]!=0&&ch[i][j]==0&&dis[i][j]==a[i][j])
                ans.push_back({i,j});
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }
    
    return 0;
} 