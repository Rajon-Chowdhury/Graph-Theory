#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
const int MAXN=1005;
int n,m,T,a[MAXN][MAXN];
char str[MAXN];
int need[MAXN][MAXN],pos[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};
bool vis[MAXN][MAXN];
pii q[MAXN*MAXN];

bool valid(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)
        return true;
    return false;
}
bool check(int x, int y)
{
    for(int i = 0; i<4; i++)
    {
        int nx = x+pos[i][0], ny = y+pos[i][1];
        if(a[nx][ny]==a[x][y])
            return true;
    }
    return false;
}
void bfs()
{
    int fr=0,nr=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(check(i,j))
                need[i][j]=0,vis[i][j]=true,q[nr++]=mp(i,j);
        }

    }
    while(fr<nr)
    {
        pii now=q[fr++];
        for(int i=0; i<4; i++)
        {
            int nx=now.fi+pos[i][0],ny=now.se+pos[i][1];
            if(valid(nx,ny)&&!vis[nx][ny])
            {
                need[nx][ny]=need[now.fi][now.se]+1;
                vis[nx][ny]=true;
                q[nr++]=mp(nx,ny);
            }
        }
    }
}



int main()
{
    cin>>n>>m>>T;
    memset(a,-1,sizeof a);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",str+1);
        for(int j=1; j<=m; j++)
            a[i][j]=str[j]-'0';
    }
    bfs();
    int x,y;
    ll t;
    while(T--)
    {
        cin>>x>>y>>t;
        int ans;
        if(vis[x][y])
            ans=a[x][y]^(max(0ll,t-need[x][y])&1);
        else
            ans=a[x][y];
        cout<<ans<<endl;
    }

}
