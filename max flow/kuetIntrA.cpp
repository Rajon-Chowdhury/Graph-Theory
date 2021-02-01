#include<bits/stdc++.h>
using namespace std;

int C,K,flow;

vector<vector<pair <int, int>>> g;
int parent[10005];
map<pair<int,int>,int>ballon,cost;
int vs[10005];
int tcost=0,s,n;
int bfs()
{

    int vis[10001],top,x;
    memset(vis, 0, sizeof vis);

    stack <int> q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty())
    {
        top = q.top();
        q.pop();
        for (int i = 0; i < g[top].size(); i++)
        {
            x = g[top][i].first;
            if(ballon[{top,x}] > 0 and vis[x] == 0)
            {
                q.push(x);
                vis[x] = 1;
                if(vs[x]==0)
                {
                    tcost+=cost[ {top,x}];
                }
                parent[x] = top;
            }
        }
    }
    return vis[n] == 1;

}


int main()
{

    int x,y,w,CS=1,k,c,p,ans,m;
    memset(vs,0,sizeof vs);


    for (int cs = 1; cs <= CS; cs++)
    {
        scanf("%d", &n);
        scanf("%d", &m);
        scanf("%d", &C);
        scanf("%d", &K);

        vector < vector < pair <int, int> > > tg(n+2);

        swap(tg, g);
        ans = 0;

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            scanf("%d", &y);
            scanf("%d", &c);
            scanf("%d", &w);
            ballon[ {x,y}] += w;
            ballon[ {y,x}] += w;
            cost[ {x,y}]=c;
            cost[ {y,x}]=c;
            g[x].push_back(make_pair(y, w));
            g[y].push_back(make_pair(x, w));
        }


        while(bfs())
        {
            k = n;
            flow = INT_MAX;
            while(k != s)
            {
                p = parent[k];
                flow = min(flow, ballon[{k,p}]);
                k = parent[k];


            }
            k = n;
            while(k != s)
            {
                p = parent[k];
                ballon[{k,p}] -= flow;
                ballon[{p,k}] -= flow;
                k = parent[k];
            }
            if(flow+ans>K) break;
            ans += flow;
        }

        printf("Case %d: %d\n", cs, ans);
    }


}

