#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll par[N],Rank[N];

struct Edge{
    ll u,v,w;
    bool operator<(Edge const& other){
           return w<other.w;
     }
};
vector<Edge>edges;
void init(){
   for(int i=1;i<N;i++)
    par[i]=i,
    Rank[i]=1;
}
int find_par(int u){
    if(par[u]==u) return u;
    return par[u]=find_par(par[u]);
}
void Union(ll a,ll b){
    a=find_par(a);
    b=find_par(b);
    if(Rank[a]<Rank[b])
        swap(a,b);
    par[b]=a;
    Rank[a]+=Rank[b];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        init();
        edges.clear();
        for(int i=1;i<=m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        sort(edges.begin(),edges.end());
        ll cnt=0;
        for(auto x:edges){
            if(find_par(x.u)!=find_par(x.v)){
                cnt+=log2(x.w);
                Union(x.u,x.v);
            }
        }
        cout<<cnt+1<<endl;
    }
}
