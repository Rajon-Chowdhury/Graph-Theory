#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>adj[27];

int cv(char ch)
{
    return ch-'A';
}

int vis[27],clr[27];
stack<int>ans;

void dfs(int u)
{
    if(vis[u]==1)return;
    vis[u]=1;

    int sz=adj[u].size();
    for(int j=0; j<sz; j++)
    {
        int v=adj[u][j];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }

    ans.push(u);

}
int main()
{
    vector<string>str;
    while(1)
    {
        string s;
        cin>>s;
        if(s=="#") break;
        str.push_back(s);
    }
    string pre=str[0];
    for(int i=1; i<str.size(); i++)
    {
        string cur=str[1];
        int prelen=pre.size();
        int curlen=cur.size();
        int len=min(prelen,curlen),f=0;
        for(int j=0; j<len; j++)
        {
            int x=cv(pre[j]),y=cv(cur[j]);
            if(pre[j]!=cur[j])
            {
                adj[x].push_back(y);
                f=1;
            }
        }

    }
    for(int j=25; j>=0; j--)
    {
        if(vis[j]==0)
        {
            dfs(j);
        }
    }
    while(!ans.empty())
    {
        int tt=ans.top();
        ans.pop();
        char tmp=tt+'A';
        printf("%c",tmp);

    }
}
