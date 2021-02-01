

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

const int mod=1e9+7;
const int N=3e3+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


vector<int> adj[N];
int deg[N];

bool vis[N];
vector<int> leaves;

void dfs(int u, int p)
{
    vis[u] = p;
    for (int v: adj[u])
        if (v != p)
            dfs(v, u);
    if (adj[u].size() <= 1)
        leaves.push_back(u);
}

int dep(int u, int p)
{
    int ans = 0;
    for (int v: adj[u])
        if (v!=p)
            ans = max(ans, 1+dep(v, u));
    return ans;
}


pair<int, int> getcenter(int u)
{
    leaves.clear();
    dfs(u, -1);

    queue<int> q;
    for (int x: leaves)
    {
        deg[x] = 0;
        q.push(x);
    }

    int ans = 0;
    while(q.size())
    {
        ans = q.front();
        q.pop();

        for (int v: adj[ans])
        {
            deg[v]--;
            if (deg[v] == 1)    q.push(v);
        }
    }
    int d=dep(ans, -1);
   return make_pair(d, ans);
}

int main()
{

    int n, m;
    cin>>n>>m;

    for (int i=1; i<=m; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i=1; i<=n; i++)
        deg[i] = adj[i].size();

    vector<pair<int, int>> centers;
    for (int i=1; i<=n; i++)
    {
        if (vis[i])     continue;
        centers.push_back(getcenter(i));
    }

    sort(centers.rbegin(), centers.rend());
    vector<pair<int, int>> ans;

    for (int i=1; i<centers.size(); i++)
    {
        int u = centers[0].second;
        int v = centers[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ans.emplace_back(u, v);
    }

    int dd = 0;
    for (int i=1; i<=n; i++)
        dd = max(dd, dep(i, -1));
    cout<<dd<<endl;
    for (auto it: ans)
        cout<<it.first<<" "<<it.second<<"\n";
}


