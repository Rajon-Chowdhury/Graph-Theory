#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fastio ios_base::sync_with_stdio(false)
int n,m;
vector<pair<int,int>>adj[10005];
ll cost[10][10005];
void dijkstra(int id,int src){

       for(int i=1;i<=n;i++) cost[id][i]=INT_MAX;
       cost[id][src]=0;
       priority_queue<pii,vector<pii>,greater<pii>>pq;
       pq.push({0,src});
       while(!pq.empty()){
         auto p=pq.top();
         pq.pop();
         int u=p.second;
         for(auto x:adj[u]){
            int v=x.first;
            int w=x.second;
            if(cost[id][v]>cost[id][u]+w){
                cost[id][v]=cost[id][u]+w;
                pq.push({cost[id][v],v});
            }
         }
       }

}
int main(){

      while(scanf("%d%d",&n,&m)==2){
         for(int i=1;i<=n;i++) adj[i].clear();
         for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
         }
         int course;
         scanf("%d",&course);
         vector<pair<int,ll>>res;
         for(int i=1;i<=course;i++){
            int c;
            scanf("%d",&c);
            int id[n+5];
            for(int k=1;k<=n;k++) id[k]=-1;

            vector<int>arr;
            for(int j=0;j<c;j++){
                int x;
                scanf("%d",&x);
                //cout<<x<<endl;
                id[x]=j;
                dijkstra(j,x);
                arr.push_back(x);
            }
           // for(int k=1;k<=n;k++){
            //    cout<<cost[0][k]<<endl;
            //}

            ll ans=LONG_MAX;
            ll st_cost[c+3][c+5];
            int node[c+5][c+5],home=INT_MAX;
            for(int fst=0;fst<c;fst++){
                for(int lst=0;lst<c;lst++){
                    st_cost[fst][lst]=INT_MAX;
                    for(int hm=1;hm<=n;hm++){
                       // cout<<hm<<" "<<id[hm]<<endl;
                        if(id[hm]==-1){
                           // st_cost[fst][lst]=min(st_cost[fst][lst],cost[fst][hm]+cost[lst][hm]);
                            if(cost[fst][hm]+cost[lst][hm]<st_cost[fst][lst]){
                                st_cost[fst][lst]=cost[fst][hm]+cost[lst][hm];
                                node[fst][lst]=hm;
                               // cout<<fst<<" "<<lst<<" "<<st_cost[fst][lst]<<endl;
                            }
                        }
                    }
                }
            }
            int st=0;
            sort(arr.begin(),arr.end());
            do{
              int fst=id[arr[0]],lst=id[arr[c-1]];
              //cout<<fst<<" "<<lst<<endl;
              ll sum=st_cost[fst][lst];
              for(int k=1;k<c;k++){
                  sum+=cost[id[arr[k-1]]][arr[k]];
              }
              if(sum<ans){
                  ans=sum;
                  home=node[fst][lst];
              }
              else if(sum==ans){
                   home=min(home,node[fst][lst]);
              }

            }while(next_permutation(arr.begin(),arr.end()));

            res.push_back({home,ans});
         }
         for(auto x:res)
          printf("%d %d\n",x.first,x.second);
         //res.clear();
         printf("---\n");
      }
}
