#include<bits/stdc++.h>
using namespace std;
struct edge{
  int a;
  int b;
  int w;
};
int par[10001];
bool comp(edge a,edge b)
{
    if(a.w<b.w)
        return true;
    return false;
}
int find(int a)
{
    if(par[a]==-1)return a;
    return par[a]=find(par[a]);
}
void merge1(int a,int b)
{
    par[a]=b;
}

edge ar[100001];
int main()
{   int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)par[i]=-1;
    for(int i=0;i<m;i++)
    {
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    sort(ar,ar+m,comp);
    int sum=0,a,b;
    for(int i=0;i<m;i++)
    {
        a=find(ar[i].a);
        b=find(ar[i].b);
        if(a!=b)
        {
            sum+=ar[i].w;
            merge1(a,b);
        }
    }
    cout<<sum<<endl;
}
