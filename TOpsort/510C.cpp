#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
using namespace std;
vector<int>adj[27];
bool has_cycle=false;
int cv(char c)
{   //cout<<c-'a'<<"  ^^^^ "<<endl;
    return c-'a';
}
int vis[27],clr[27];
stack<int>ans;
void dfs(int u)
{
    if(vis[u]==1)return;
    vis[u]=1;
    clr[u]=grey;
    int sz=adj[u].size();
    for(int j=0;j<sz;j++)
    {    int v=adj[u][j];
        if(clr[v]==grey && vis[v]==1)
        {
            has_cycle=true;
        }
       else if(vis[v]==0)
        {
            dfs(v);
        }
    }
    clr[u]=black;
    ans.push(u);

}
main()
{
    int n,flag=0;
    cin>>n;
    string ak[n+10],t1,t2;
    cin>>ak[0];
    for(int i=1;i<n;i++)
    {
        cin>>ak[i];
        t1=ak[i-1];int l1=t1.size(),f=0;
        t2=ak[i];int l2=t2.size(),l;l=min(l1,l2);
        for(int j=0;j<l;j++)
        {
            if(t1[j]!=t2[j])
            {    f=1;
               adj[cv(t1[j])].push_back(cv(t2[j]));
               //cout<<cv(t1[j])<<"  ## "<<cv(t2[j])<<endl;
                break;
            }
        }
        if(f==0 && l1>l2)
        {
            flag=1;
        }

    }
    for(int j=25;j>=0;j--)
    {
        if(vis[j]==0)
        {
            dfs(j);
        }
    }
    if(has_cycle==true || flag)
    {
        cout<<"Impossible"<<endl;
    }
    else
    {   while(!ans.empty()){
        int tt=ans.top();
        ans.pop();
        char tmp=tt+'a';
        printf("%c",tmp);
    } cout<<endl;
    }

    return 0;
}
