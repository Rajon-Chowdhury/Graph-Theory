#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
map<string,int> m;
int parr[N],R[N];
vector<pair<int,int> > v[N];
vector<pair<pair<int,int>,pair<int,int> > > sus;
bool valid[N],vis[N];
int n,cum[N];
int find(int u){
    if(u==parr[u])
        return u;
     int x=find(parr[u]);
     return x;
}
bool Union(int x,int y){
    x=find(x);
    y=find(y);
    //cout<<x<<" "<<y<<endl;
    if(x==y) return 0;
    if(R[x]>R[y]){
        parr[y]=x;
        R[x]+=R[y];
    }
    else{
        parr[x]=y;
        R[y]+=R[x];
    }
    return 1;
}
void dfs(int u,int par,int x){
     vis[u]=1;
     cum[u]=x;
     //cout<<u<<" "<<x<<endl;
     for(int i=0;i<v[u].size();i++){
          if(v[u][i].first==par) continue;
          dfs(v[u][i].first,u,(x^v[u][i].second));
     }
}
void func(){
   // cout<<n<<endl;
   for(int i=0;i<n;i++){
     //cout<<i<<" "<<vis[i]<<endl;
      if(!vis[i])
        dfs(i,i,0);
   }
   for(int i=0;i<sus.size();i++){
      int x=sus[i].first.first;
      int y=sus[i].first.second;
      //cout<<x<<" "<<y<<endl;
      int idx=sus[i].second.first;
      int r=sus[i].second.second;

      if((cum[x]^cum[y])==r)
        valid[idx]=1;
      else
        valid[idx]=0;
   }
}
int main(){
    int q1,q2;
    cin>>n>>q1>>q2;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        m[s]=i;
        parr[i]=i;
        R[i]=1;
    }
    for(int i=0;i<q1;i++){
        int t;
        string s1,s2;
        cin>>t>>s1>>s2;
        int x=m[s1],y=m[s2];
        if(Union(x,y)){
            v[x].push_back({y,t-1});
            v[y].push_back({x,t-1});
            valid[i]=1;
        }
        else{
            sus.push_back(make_pair(make_pair(x,y),make_pair(i,t-1)));
        }
    }
    func();
    for(int i=0;i<q1;i++){
        if(valid[i])
         cout<<"YES"<<endl;
        else
         cout<<"NO"<<endl;
    }
    while(q2--){
        string s1,s2;
        cin>>s1>>s2;
        int x=m[s1],y=m[s2];
        if(find(x)!=find(y)){
            cout<<3<<endl;
            continue;
        }
        int ans=(cum[x]^cum[y])+1;

        cout<<ans<<endl;
    }
}
