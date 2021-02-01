#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<int,int>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1500;

vector < int > adj[MAX];
char grid[50][50];
bool vis[MAX];
int match[MAX];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool dfs(int src)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int x = adj[src][i];

        if(vis[x])
            continue;

        vis[x] = 1;

        if(match[x] == -1 || dfs(match[x]))
        {
            match[x] = src;
            return 1;
        }
    }
    return 0;
}
int bpm(int n)
{
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        memset(vis,0,sizeof vis);
        if(dfs(i))
            ans++;
    }

    return ans/2;
}
void init()
{
    for(int i=1; i<MAX; i++)
        adj[i].clear();
    memset(match,-1,sizeof match);
}

int main()
{
    FastRead

    int t,cs=1;

    cin >> t;

    while(t--)
    {
        init();

        int n,m,u,v,nodes=0;

        map<pii,int>mp;

        cin >> n >> m;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '*')
                    mp[pii(i,j)] = ++nodes;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(grid[i][j] == '*')
                {
                    u = mp[pii(i,j)];
                    for(int k=0; k<4; k++)
                    {
                        int x = dx[k]+i, y = dy[k]+j;

                        if(x>=1 && x<=n && y>=1 && y<=m && grid[x][y] == '*')
                        {
                            v = mp[pii(x,y)];
                            adj[u].push_back(v);
                        }
                    }
                }
            }
        }

        cout << "Case " << cs++ << ": " << nodes-bpm(nodes) << endl;
    }
}
