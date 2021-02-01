#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false)
const int mx=400005;

vector<pair<int,int>>adj[mx];
int low[mx],in[mx];
int disco=1,n,m;
stack<int>st;
int onstack[mx];
bool vis[mx],visi[mx];
int scc=0;
int mxcom=0,mxnode;
int com[mx];

void dfs(int u,int par){

      low[u]=in[u]=disco++;
      vis[u]=1;
      onstack[u]=1;
      st.push(u);
      for(auto x:adj[u]){
          int v=x.first;
          if(v==par) continue;
          if((vis[v]==true)&&(onstack[v]==true)){
            low[u]=min(low[u],in[v]);
          }
          else if(vis[v]==false){
             dfs(v,u);
             if(onstack[u]==true)
              low[u]=min(low[u],low[v]);
          }
      }
      if(in[u]==low[u]){
        scc++;
        int v;
        int cnt=0;
        while(1){
            v=st.top();
            com[v]=scc;
            cnt++;
            st.pop();
            onstack[v]=false;
            if(v==u) break;
        }
        if(cnt>mxcom){
            mxcom=cnt;
            mxnode=u;
        }
      }
}

pair<int,int>E[mx];

void dfs2(int u,int par){
      visi[u]=1;
    // cout<<u<<endl;
     for(auto x:adj[u]){
        int v=x.first;
        int id=x.second;
        if(v==par) continue;
       // cout<<v<<" "<<id<<endl;
        if(visi[v]==1){
          E[id]={u,v};
        }
        else{
            //cout<<u<<" "<<com[u]<<" "<<v<<" "<<com[v]<<endl;
            dfs2(v,u);
            E[id]={v,u};
        }

     }
}
int main(){
     fastio;
     cin>>n>>m;
     for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        E[i]={u,v};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
     }
     dfs(1,-1);

     dfs2(mxnode,-1);
     cout<<mxcom<<endl;
     for(int i=1;i<=m;i++){
        cout<<E[i].first<<" "<<E[i].second<<endl;
     }

}
