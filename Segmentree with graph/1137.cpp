#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
const long long N = 200200;
vector<ll>adj[200005];
ll wt[200005];
ll tim;
ll b[N];
ll tin[N];
ll tout[N];
ll t[4 * N];
bool vis[N];
void dfs(ll x)
{
    tin[x] = ++tim;
     cout<<"IN: "<<x<<" "<<tin[x]<<endl;
    b[tin[x]] = wt[x];
    vis[x]=true;
    for(auto y: adj[x])
    {
        if(vis[y]==false)
            dfs(y);
    }
    tout[x] = tim;
    cout<<"OUT: "<<x<<" "<<tout[x]<<endl;
}
void build(ll x, ll l, ll r)
{
    cout<<x<<" "<<l<<" "<<r<<endl;
    if(l == r)
    {
        //cout<<x<<endl;
        //cout<<x<<" "<<l<<endl;
        t[x] = b[l];
        return;
    }
    ll m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = t[x * 2] + t[x * 2 + 1];
}
ll query(ll x, ll l, ll r, ll tl, ll tr)
{
    //cout<<tl<<" "<<tr<<endl;
    if(tl > tr)
    {
        return 0;
    }
    if(l == tl && r == tr)
    {
        return t[x];
    }

    ll m = (l + r) / 2;
    return query(x * 2, l, m, tl, min(m, tr)) + query(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}
void update(ll x, ll l, ll r, ll tl, ll tr,ll v)
{
    if(r<tl||l>tr)
    {
        return;
    }

    if(l <= tl && r <= tr)
    {
        if(l==r)
        t[x] = v;
        else
         t[x]=t[x]-b[l]+v;
        return;
    }

    ll m = (l + r) / 2;
    update(x * 2, l, m, tl, tr,v);
    update(x * 2 + 1, m + 1, r,  tl, tr,v);
    t[x] = t[x * 2] + t[x * 2 + 1];
}

int main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        cin>>wt[i];
    for(int i=1; i<n; i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
       // adj[v].push_back(u);
    }
    dfs(1);
    cout<<endl;
    build(1, 1, n);
    for(int i=1; i<=q; i++)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll x,v;
            cin>>x>>v;
            cout<<tin[x]<<" "<<tout[x]<<endl;
            update(1, 1, n, tin[x], tout[x],v);

        }
        else
        {
            ll x;
            cin>>x;
            cout<<tin[x]<<" "<<tout[x]<<endl;
            ll ans=query(1, 1, n, tin[x], tout[x]);
            cout<<ans<<endl;

        }
    }
}
