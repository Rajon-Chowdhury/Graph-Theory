#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 10000001
string a[1001];
ll dp[1001],vis[1001];
int main()
{
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            dp[i]=INF,vis[i]=0;
        }
        dp[1]=0;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(vis[node]) continue;
            for(int j=node+1; j<=n&&j-node<=k; j++)
                if(a[node][j-1]=='1'&&dp[j]>dp[node]+1 && !vis[j])
                    dp[j]=dp[node]+1,q.push(j);
            for(int j=node-1; j>=1 && node-j<=k;j--)
                if(a[node][j-1]=='1' && dp[j]>dp[node]+1 && !vis[j])
                    dp[j]=dp[node]+1,q.push(j);
            vis[node]=1;
        }
        ll ans=dp[n];
        if(ans==INF) ans=-1;

        cout<<ans<<endl;
    }
}
