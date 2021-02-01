#include<bits/stdc++.h>
using namespace std;
#define ll long long
int parent[100005];
int rnk[100005];
int data[100005];

void make_set(int v)
{
    parent[v] = v;
    rnk[v] = 0;
    data[v]=v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        data[a]=max(data[a],data[b]);
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        make_set(i);
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        union_sets(u,v);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        int x=find_set(u);
        int y=find_set(v);
        if(x==y)
        {
            cout<<"TIE"<<endl;
        }
        else
        {
            int ans=data[x]>data[y]?u:v;
            cout<<ans<<endl;
        }
    }
}
