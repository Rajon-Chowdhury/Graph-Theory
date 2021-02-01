#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200008
int par[mx],deg[mx];
ll a[mx];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        cin>>par[i];
        deg[par[i]]++;
    }
    queue<int>q;
    vector<int>forw,backw;
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        if(deg[i]==0)
            q.push(i);
    }
    while(q.size())
    {
        int u=q.front();
        q.pop();
        ans+=a[u];
        if(a[u]>=0) forw.push_back(u);
        else backw.push_back(u);
        if(par[u]!=-1)
        {
            if(a[u]>=0) a[par[u]]+=a[u];
            deg[par[u]]--;
            if(deg[par[u]]==0) q.push(par[u]);
        }
    }

    cout<<ans<<endl;
    for (int x: forw)   cout<<x<<" ";
    reverse(backw.begin(), backw.end());
    for (int x: backw)    cout<<x<<" ";

}
