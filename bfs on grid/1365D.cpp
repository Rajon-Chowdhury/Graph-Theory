#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]= {-1,0,1,0};
int dy[]= {0,1,0,-1};
int n,m;
string s[55];
bool vis[55][55];
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;

    return true;
}
bool bfs(int sx,int sy)
{

    queue<pair<int,int>>q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int curx=dx[i]+x;
            int cury=dy[i]+y;
            if(valid(curx,cury)&&!vis[curx][cury]&&s[curx][cury]=='.')
            {

                q.push({curx,cury});
                if(curx==n-1&&cury==m-1)
                {
                    return true;
                }
                vis[curx][cury]=true;
            }
        }
    }
    return false;
}

void solve()
{
    int gx=-1,gy=-1,bx=-1,by=-1;
    cin>>n>>m;
   memset(vis,0,sizeof vis);
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='G'&&(gx==-1))
            {
                gx=i,gy=j;
            }
            if(s[i][j]=='B'&&(bx==-1))
            {
                bx=i,by=j;
            }
        }
    }
    char ch='G';
    bool flag=true;
    if(gx>=0&&gy>=0)
        flag=bfs(gx,gy);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==n-1&&j==m-1) continue;
            if(s[i][j]=='.'&&!vis[i][j])
            {
                vis[i][j]=true;
                s[i][j]='#';
            }
        }
    }
    ch='B';
    bool flag2=false;

    if(bx>=0&&by>=0&&gx>=0)
    {
        flag2=true;
        flag2=bfs(bx,by);


    }
    if(gx==-1){
        cout<<"Yes"<<endl;
        return;
    }
    if((flag==true&&flag2==false))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }


}
int main()
{
    int t,cs=0;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
/*
100
2 2
BG
B.
2 2
#G
..
2 2
BG
#.
2 2
BB
#.
2 2
.G
B.
2 2
#.
B.
2 2
.B
..
2 2
..
G.
*/


