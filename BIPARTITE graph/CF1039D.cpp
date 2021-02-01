#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

vector<int>ar[300001];
int col[300001],vis[300005];
int zero,one;
int CC[3];
ll power(int a,int n)
{
    ll res=1;
    while(n)
    {
        if(n%2)
        {
            res=(res*a)%mod;
        }
        n>>=1;
        a=(a*a)%mod;

    }
    return res;

}
int dfs(int node,int c)
{
    vis[node]=1;
    CC[c]++;
    col[node]=c;
    for(int child:ar[node])
    {
        if(vis[child]==0)
        {
            int code=dfs(child,c^1);
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

int main()
{
    int n,m,a,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++)
            ar[i].clear(),vis[i]=0;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        ll res=0;
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                CC[0]=CC[1]=0;
                int  code = dfs(i,0);
                if(code==-1)
                {
                    flag=false;
                    break;
                }
                res=(res*(power(2,CC[0])+power(2,CC[1])))%mod;


            }
        }
        if(flag==false)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<res<<endl;
        }
    }

}
