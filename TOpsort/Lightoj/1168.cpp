#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
#define umap unordered_map
#define uset unordered_set
#define PQ priority_queue

#define fastio ios_base::sync_with_stdio(false)
#define printa(a,L,R) for(int i=L;i<R;i++) cout<<a[i]<<(i==R-1?'\n':' ')
#define printv(a) printa(a,0,a.size())
#define print2d(a,r,c) for(int i=0;i<r;i++) for(int j=0;j<c;j++) cout<<a[i][j]<<(j==c-1?'\n':' ')
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fbo find_by_order
#define ook order_of_key
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define SQ(x) ((x)*(x))
#define issq(x) (((ll)(sqrt((x))))*((ll)(sqrt((x))))==(x))
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define inf 1e18
#define E 2.71828182845904523536
#define gamma 0.5772156649
#define nl "\n"
#define lg(r,n) (int)(log2(n)/log2(r))
#define pf printf
#define sf scanf
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d",&a,&b,&c)
#define pf1(a)                printf("%d\n",a);
#define pf2(a,b)              printf("%d %d\n",a,b)
#define pf3(a,b,c)            printf("%d %d %d\n",a,b,c)
#define sf1ll(a)              scanf("%lld",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pf1ll(a)              printf("%lld\n",a);
#define pf2ll(a,b)            printf("%I64d %I64d\n",a,b)
#define pf3ll(a,b,c)          printf("%I64d %I64d %I64d\n",a,b,c)
#define _ccase printf("Case %lld: ",++cs)
#define _case cout<<"Case "<<++cs<<": "
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }

#define asche cerr<<"Ekhane asche\n";
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define toint(a) atoi(a.c_str())
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
string tostr(int n)
{
    stringstream rr;
    rr<<n;
    return rr.str();
}
inline void yes()
{
    cout<<"YES\n";
    exit(0);
}
inline void no()
{
    cout<<"NO\n";
    exit(0);
}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 random(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
/*------------------------------Graph Moves----------------------------*/
//Rotation: S -> E -> N -> W
//const int fx[] = {0, +1, 0, -1};
//const int fy[] = {-1, 0, +1, 0};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

const int mod=1e9+7;
const int N=3e3+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
int n,m;
vector<int>adj[N],rev[N],com[N];
int in[N];
int out[N];
int cnt=0,ha=1,cm=0;
int InwhichCom[N];
bool vis[N];
int child;
stack<int>st;
void ini()
{
    ha=1;
    cnt=0;
    cm=0;
    mem(vis,0);
    mem(out,0);
    mem(in,0);
    for(int i=0; i<N; i++) adj[i].clear(),com[i].clear(),rev[i].clear();
}
void dfs(int u)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }

    st.push(u);
}
void dfs2(int u)
{
    vis[u]=1;
    //cout<<cnt<<" "<<u<<endl;
    com[cnt].pb(u);
    InwhichCom[u]=cnt;
    for(auto v:rev[u])
    {
        if(vis[v]) continue;
        dfs2(v);
    }
}
void ssc()
{
    ha=0;
    mem(vis,0);
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(vis[u]==0)
        {
            cnt++;
            dfs2(u);
        }
    }
}
bool check()
{
    for(int i=1; i<=cnt; i++)
    {
        int xx=0;
        for(auto v:com[i])
        {
           for(auto w:adj[v]){
              int x=InwhichCom[w];
              if(x!=i) xx++;
           }
        }
        if(xx>=2) return false;

    }
    return true;

}
void Count(int u)
{
        vis[u] = 1;
        cm++;
        for(int i=0;i<adj[u].size();i++){
                 int v = adj[u][i];
                 if(vis[v]==0) Count(v);
        }
}
map<int,int>mp;
int main()
{

    int t,cs=1;
    cin>>t;
    while(t--)
    {
        ini();
        cin>>child;
        for(int i=1; i<=n; i++) adj[i].clear();
        mem(vis,0);
        while(child--)
        {
            int m;
            cin>>m;
            for(int i=1; i<=m; i++)
            {
                int a,b;
                cin>>a>>b;
                adj[a].pb(b);
                rev[b].pb(a);
                out[a]++;
                in[b]++;
                mp[a]=1,mp[b]=1;
            }
        }

        for(int i=0; i<N; i++)
        {
            if(vis[i]==0&&(in[i]||out[i])) dfs(i);
        }
        ssc();
        mem(vis,0);
        bool flag=check();
        Count(0);
        //debug(cm);
        if(flag&&cm==mp.size())cout<<"Case "<<cs++<<": YES"<<endl;
        else cout<<"Case "<<cs++<<": NO"<<endl;
        mp.clear();

    }


}
