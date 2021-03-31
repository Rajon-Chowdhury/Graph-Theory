#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205;
set<int>adj[N];
vector<pair<int,int>>ans;
void Euler(int u){
   while(adj[u].size()){
      int v=*adj[u].begin();
      adj[u].erase(v);
      adj[v].erase(u);
      if(u>0 && v>0)
      ans.push_back({u,v});
      Euler(v);
   }
}
int main(){
     int t;
     cin>>t;
     while(t--){
        int n,m,cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            adj[i].clear();
         ans.clear();
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        for(int i=1;i<=n;i++){
            int deg=adj[i].size();
            if(deg&1){
                adj[0].insert(i);
                adj[i].insert(0);
            }
            else{
                cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            Euler(i);
        }
        cout<<cnt<<endl;
        for(auto x:ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
     }
}
