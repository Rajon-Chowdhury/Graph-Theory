#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)
#define MAXX 21

using namespace std;

int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};

char graph[MAXX][MAXX];
bool visited[MAXX][MAXX];
int width, height;
struct DATA{
    int x, y;
    void set(int i, int j)
    {
        x = i;
        y = j;
    }
};


int bfs(DATA u)
{

    mem(visited, false);

    queue<DATA> Q;
    DATA v;
    Q.push(u);
    visited[u.x][u.y] = true;
    int total = 1;

    while( ! Q.empty() )
    {
        u = Q.front();
        loop(i, 4)
        {
            v.set(u.x+dirx[i], u.y + diry[i]);


            if(-1 < v.x && v.x < width && -1 < v.y && v.y < height && graph[v.y][v.x]=='.' && !visited[v.x][v.y] )
            {


                visited[v.x][v.y] = true;
                Q.push(v);
                total++;
            }
        }
        Q.pop();
    }
    return total;

}


int main()
{
    DATA point;
    int kases, kaseno = 0;
    getint(kases);
    while(kases--)
    {
        getint(width); getint(height);

        loop(i, height)
        {
            scanf("%s", graph[i]);
            loop(j, width)
            {
                if(graph[i][j] == '@')
                {
                    point.set(j, i);
                }
            }
        }

        printf("Case %d: %d\n", ++kaseno, bfs(point));
    }
    return 0;
}
