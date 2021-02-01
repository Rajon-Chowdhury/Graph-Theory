#include<bits/stdc++.h>
using namespace std;
vector<int>ar[1001];
int vis[1001],in[1001],low[1001];
set<int>ans;
int tim;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=tim++;
    int child_cnt=0;
    for(int child:ar[node])
    {
        if(child==par) continue;

        if(vis[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            child_cnt++;
            low[node]=min(low[node],low[child]);
            if(in[node]<=low[child] && par!=-1)
                ans.insert(node);
        }
    }
    if(par==-1&&child_cnt>1)
        ans.insert(node);
}
int main()
{
    int n,m,a,b;

    while(1)
    {
        cin>>n>>m;
        if(n==0&&m==0)
            break;
        for(int i=1; i<=n; i++)
            ar[i].clear(),vis[i]=0;
        ans.clear();
        tim=1;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
                dfs(1,-1);
        }
        cout<<ans.size()<<endl;

    }

}
