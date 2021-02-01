#include<bits/stdc++.h>
using namespace std;
#define int long
main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>adj(n);
    vector<int>a(m),b(m);
    for(int i=0; i<m; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    queue<int> q;
    q.push(0);
    vector<int> d(n, INT_MAX);
    d[0] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v: adj[u])
            if (d[v] == INT_MAX)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
    vector<vector<int>> inc(n);
    for(int i=0; i<m; i++)
    {
        if (d[a[i]] + 1 == d[b[i]])
            inc[b[i]].push_back(i);
        if (d[b[i]] + 1 == d[a[i]])
            inc[a[i]].push_back(i);
    }

    vector<int> f(n);
    vector<string> result;

    for(int i=1; i<=k; i++)
    {
        string s(m,'0');
        for(int j=1; j<n; j++)
            s[inc[j][f[j]]]='1';
        result.push_back(s);
        bool ok=false;
        for(int j=1; j<n; j++)
        {
            if(f[j]+1<inc[j].size())
            {
                ok=true;
                f[j]++;
                break;
            }
            else
            {
                f[j]=0;
            }
        }
        if(!ok) break;
    }
    cout<<result.size()<<endl;
    for(auto x:result)
        cout<<x<<endl;
}
