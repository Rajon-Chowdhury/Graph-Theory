#include<bits/stdc++.h>
using namespace std;
char ar[35][35];
bool vis[35][35];
int dist[35][35];
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int n;
bool isValid(int x,int y)
{
    if(x>n || x<1 || y>n || y<1) return false;
    if(vis[x][y] || ar[x][y]=='T') return false;
    return true;
}
void bfs(int srx,int sry)
{
    queue<pair<int,int>>q;
    q.push({srx,sry});
    dist[srx][sry]=0;
    vis[srx][sry]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        int d=dist[x][y];
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nwx=x+dx[i];
            int nwy=y+dy[i];
            if(isValid(nwx,nwy))
            {
                dist[nwx][nwy]=d+1;
                vis[nwx][nwy]=1;
                q.push({nwx,nwy});
            }
        }

    }
}
int main()
{
    int srx,sry,ex,ey;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>ar[i][j];
            if(ar[i][j]=='S') srx=i,sry=j;
            if(ar[i][j]=='E') ex=i,ey=j;
        }
    }
    bfs(srx,sry);
    cout<<dist[ex][ey]<<endl;
}
