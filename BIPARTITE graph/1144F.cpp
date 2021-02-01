#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

vector<ll>ar[300001];
ll col[300001],vis[300005];
ll zero,one;


ll dfs(ll node,ll c)
{
    vis[node]=1;
    col[node]=c;
    for(ll child:ar[node])
    {
        if(vis[child]==0)
        {
            ll code=dfs(child,c^1);
            if(code==-1)
            {
                return -1;
            }
        }
        else
        {
            if(col[child]==col[node])return -1;
        }
    }
    return 0;
}
vector<pair<int,int>>edge;
int main()
{
    ll n,m,a,b;

    cin>>n>>m;


    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
        edge.push_back({a,b});
    }
    ll res=1;


    int flag=dfs(1,0);

    if(flag==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0; i<m; i++)
        {
            int x=edge[i].first;
            cout<<col[x];

        }
    }
}

