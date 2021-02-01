#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  mx 510
#define INF 1e9
int wt[mx][mx];
vector<int>G[mx];
int dist[mx];
struct data
{
    int city,dist;
    bool operator<(const data &p) const
    {
        return p.dist>dist;
    }

};
void dijstra(int src)
{
    int len;
    priority_queue<data>Q;
    data u,v;
    u.city=src;
    u.dist=0;
    dist[u.city]=0;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();
        if(u.dist!=dist[u.city]) continue;

        len =G[u.city].size();
        for(int i=0; i<len; i++)
        {
            v.city=G[u.city][i];
            v.dist=max(u.dist,wt[u.city][v.city]);
            if(v.dist<dist[v.city])
            {
                dist[v.city]=v.dist;
                Q.push(v);
            }
        }
    }


}
int main()
{
    int t,cs=1;
    int cities,roads;
    scanf("%d",&t);
    int p,q,w;
    int src;
    while(t--)
    {
        for(int i=0; i<mx; i++)
        {
            G[i].clear();
            dist[i]=INF;
            for(int j=0; j<mx; j++)
            {
                wt[i][j]=INF;
                wt[j][i]=INF;
            }
        }
        scanf("%d%d",&cities,&roads);
        for(int i=0; i<roads; i++)
        {
            scanf("%d %d %d",&p,&q,&w);
            if(w<wt[p][q])
            {
                wt[p][q]=w;
                wt[q][p]=w;
                G[p].push_back(q);
                G[q].push_back(p);
            }
        }
        scanf("%d",&src);
        dijstra(src);
        printf("Case %d:\n",cs++);
        for(int i=0; i<cities; i++)
        {
            if(dist[i]==INF)
                printf("Impossible\n");
            else
                printf("%d\n",dist[i]);
        }

    }
}
