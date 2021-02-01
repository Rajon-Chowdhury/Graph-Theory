#include<bits/stdc++.h>
using namespace std;
#define M 60
#define N 60
bool bpm(int m,int n,int adj[M][N],int u,bool vis[],int match[])
{
    for (int v = 0; v < n; v++)
    {

        if (adj[u][v] && !vis[v])
        {
            vis[v] = true;
            if (match[v] < 0 || bpm(m,n,adj,match[v],
                                    vis, match))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int bipertite(int m,int n,int adj[M][N])
{

    int match[N];

    memset(match, -1, sizeof(match));

    int result = 0;
    for (int u = 0; u < m; u++)
    {

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        if (bpm(m,n,adj,u, vis, match))
            result++;
    }
    return result;
}



int main()
{
    int t,i,j,ca;
    cin>>t;
    for(ca=1; ca<=t; ca++)
    {
        int adj[M][N];
        int n,m;
        cin>>m>>n;
        int manh[60]={},manage[60]={},mand[60]={};
        for(i=0; i<m; i++)
        {
            cin>>manh[i]>>manage[i]>>mand[i];
        }
        int wh[60]={},wage[60]={},wd[60]={};
        for(i=0; i<n; i++)
        {
            cin>>wh[i]>>wage[i]>>wd[i];
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                int a,b,c=mand[i],d=wd[j];
                a=abs(manh[i]-wh[j]);
                b=abs(manage[i]-wage[j]);
                if(a<=12&&b<=5&&(c==d))
                {
                    adj[i][j]=true;
                }
                else
                {
                    adj[i][j]=0;
                }
            }
        }
        printf("Case %d: ",ca);
        cout<<bipertite(m,n,adj)<<endl;
    }
    return 0;
}

