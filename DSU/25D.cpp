#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[50010];
int dp[50010][505];
bool vis[50010];

int n,k,ans;
void dfs(int v,int p){

      dp[v][0]=1;

   for(int i=0;i<adj[v].size();i++){
     int x=adj[v][i];

     if(p==x) continue;
     dfs(x,v);

     for(int c=1;c<=k;c++){
      cout<<v<<" "<<x<<" "<<dp[v][c-1]<<" "<<dp[x][k-c]<<endl;
      ans+=dp[v][c]*dp[x][k-c];
     }
     for(int j=1;j<=k;j++){
      dp[v][j]+=dp[x][j] ;
     }

   }
}
int main()
{
       cin>>n>>k;
       for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++){
                dp[i][j] = dp[n][j] = 0LL;

            }

        }

     for(int i=0;i<n-1;i++){
          int a,b;
          cin>>a>>b;
          adj[a].push_back(b);
          adj[b].push_back(a);
     }

     dfs(1,-1);

     cout<<ans<<endl;


}
