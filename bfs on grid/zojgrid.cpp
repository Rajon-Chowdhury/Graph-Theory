
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
typedef pair<int, int> pii;
typedef long long LL;
const double PI = acos(-1.0);
const int N = 45;
struct edge
{
    int to, nxt;
    edge() {}
    edge(int _to, int _nxt): to(_to), nxt(_nxt) {}
};
edge E[(N * N * 4) << 1];
int head[N * N], tot;
int d[N * N];
bitset<N*N>vis;
bool link[N * N][N * N];
char pos[N][N];
int id[N][N], dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
int n, m;

void init()
{
    CLR(head, -1);
    tot = 0;
    CLR(id, 0);
    CLR(link, false);
}
inline void add(int s, int t)
{
   // cout<<tot<<" "<<s<<" "<<t<<" "<<" "<<head[s]<<endl;
    E[tot] = edge(t, head[s]);
    head[s] = tot++;
}
void bfs(int s)
{
    CLR(d, INF);
    vis.reset();
    queue<int>Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; ~i; i = E[i].nxt)
        {
            if(u==1)
             cout<<i<<endl;
            int v = E[i].to;
            if (!vis[v])
            {
                vis[v] = 1;
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
}


inline bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}



void dfs(int x, int y, int ID)
{
   // cout<<x<<" "<<y<<" "<<ID<<endl;
    id[x][y] = ID;
    for (int i = 0; i < 4; ++i)
    {
        int vx = x + dir[i][0];
        int vy = y + dir[i][1];
        if (check(vx, vy) && pos[vx][vy] == pos[x][y] && !id[vx][vy])
            dfs(vx, vy, ID);
    }
}
int main(void)
{
    int tcase, i, j;
    scanf("%d", &tcase);
    while (tcase--)
    {
        init();
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; ++i)
            scanf("%s", pos[i]);
        int cntid = 0;
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                if (!id[i][j])
                    dfs(i, j, ++cntid);
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int ii = i + dir[k][0];
                    int jj = j + dir[k][1];
                    if (check (ii, jj) && pos[ii][jj]!= pos[i][j] && !link[id[i][j]][id[ii][jj]] && !link[id[ii][jj]][id[i][j]]) // link array to prevent unwanted side weight
                    {
                        //cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<endl;
                        add(id[i][j], id[ii][jj]);
                        add(id[ii][jj], id[i][j]);
                        link[id[i][j]][id[ii][jj]] = link[id[ii][jj]][id[i][j]] = true;
                    }
                }
            }
        }
        int ans = n * m;
        for (i = 1; i <= cntid; ++i)
        {
            bfs(i);
            ans = min(ans, *max_element(d + 1, d + cntid + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=3e3+5;
const ll mod=998244353;

string s, t;
ll dp[MX][MX];

ll func(ll pos, ll len){
     ll &r=dp[pos][len];
     if(r!=-1) return r;
     r=0;
     if(len==1){
          if(pos>=t.length() || s[0]==t[pos]) r=(r+2)%mod;
     }
     else{
          if(pos>=t.length() || s[len-1]==t[pos]) r=(r+func(pos+1, len-1))%mod;
          if(pos+len-1>=t.length() || s[len-1]==t[pos+len-1]) r=(r+func(pos, len-1))%mod;
     }
     return r;
}

int main(){
     ll i, j, k;
     cin >> s >> t;
     ll ans=0;
     memset(dp, -1, sizeof dp);
     for(i=t.length(); i<=s.length(); ++i){
          ans+=func(0, i);
          ans%=mod;
     }
     cout << ans << endl;
}
