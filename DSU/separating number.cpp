#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>

map<ll,ll>mp[300005];
int par[300005];
vector<ll>adj[300001];
ll ar[300005];
vii edge;
vi operations;
int find(int a){
  if(par[a]==a) return a;
  return par[a]=find(par[a]);
}
ll merge(int a,int b){
    ll res=0;
    if(mp[a].size()<mp[b].size())
        swap(a,b);
    for(ii p:mp[b]){
        if(mp[a].find(p.first)==mp[a].end())
         mp[a][p.first]=p.second;
        else
          res+=mp[a][p.first]*p.second,mp[a][p.first]+=p.second;
    }
    par[b]=a;
    return res;
}

int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<n;i++) cin>>a>>b,edge.push_back({a,b});
    for(int i=1;i<=n;i++) cin>>ar[i],mp[i][ar[i]]=1;
    for(int i=1;i<n;i++) cin>>a,operations.push_back(a);

    ll  res=0;
    vi ans;
    while(operations.size()>0){
        int idx=operations.back();
        operations.pop_back();
        a=edge[idx-1].first;
        b=edge[idx-1].second;
        ans.push_back(merge(find(a),find(b)));
    }
    while(ans.size()>0){
        cout<<ans.back()<<endl,ans.pop_back();
    }

}
