#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[10005];
int deg[10005];
#define vi vector<int>

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        deg[y]++;
    }
    vector<int>ans;
    priority_queue<int,vi,greater<int> > q;

    for(int i=1; i<=n; i++)
    {
        if(deg[i]==0) q.push(i);
    }

    while(q.size())
    {
        int u=q.top();
        ans.push_back(u);
        q.pop();
        for(int v:adj[u])
        {
            deg[v]--;
            if(deg[v]==0)
            {
                q.push(v);
            }
        }
    }
    if(ans.size()<n) cout<<"Sandro fails."<<endl;
    else
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}
