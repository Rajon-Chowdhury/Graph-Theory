#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>ar[100004];
int in[100001],low[100004],vis[100005],tim;
bool hasBrige;
vector<pair<int,int> > edge;
void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=tim++;
    for(int child:ar[node])
    {
        if(child==par) continue;
        if(vis[child])
        {
            low[node]=min(low[node],in[child]);
            if(in[node]>in[child])
                edge.push_back({node,child});
        }
        else
        {
            dfs(child,node);

            if(low[child]>in[node])
            {
                hasBrige=true;
                return;
            }
            edge.push_back({node,child});
            low[node]=min(low[node],low[child]);
        }

    }

}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    dfs(1,-1);
    if(hasBrige)
    {
        cout<<0<<endl;
    }
    else
    {
        for(pair<int,int>e:edge)
        {
            cout<<e.first<<" "<<e.second<<endl;
        }
    }

}

