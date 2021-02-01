#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int MOD=1e9+7;
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


inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a*b)%MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a+b)%MOD;
}
inline ll modSub(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    while(p)
    {
        if(p&1)r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a)
{
    return modPow(a, MOD-2);
}
inline ll modDiv(ll a, ll b)
{
    return modMul(a, modInverse(b));
}



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


string numTostring(ll num,string s)
{
    while(num>0)
    {
        ll r=num%10;
        num/=10;
        s+=r+'0';
    }
    reverse(s.begin(),s.end());
    return s;
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


const int N=1e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


vector<pii>adj[N];
bool vis[N][2];
int dist[N][2];
struct Node
{
    int distance,node,id;
    Node() {}
    Node(int _d,int _n,int _id)
    {
        distance=_d;
        node=_n;
        id=_id;
    }
    bool operator<(const Node & p)const{
      p.distance<distance;
    }
};
struct compare
{
    bool operator()(Node a,Node b)
    {
        return a.distance > b.distance;
    }
};

void Dijkstra(int src)
{
    priority_queue < Node,vector<Node>,compare > pq;
    pq.push(Node(0,src,0));
    dist[src][0] = 0;
    while(!pq.empty())
    {
        int u=pq.top().node,d=pq.top().distance,id=pq.top().id;
        pq.pop();
        //cout<<"age -->"<<endl;
        //cout<<u<<" "<<d<<" "<<id<<endl;
        if(vis[u][id]) continue;
        vis[u][id]=1;
        //cout<<"pore--->"<<endl;
        //cout<<u<<" "<<d<<" "<<id<<endl;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].first,w=adj[u][i].second;
            if(dist[v][0]>d+w)
            {
                dist[v][1]=dist[v][0];
                //cout<<"fst ->>"<<endl;
                //cout<<v<<" ";
                debug(dist[v][1]);
                dist[v][0]=d+w;
                pq.push(Node(dist[v][0],v,0));
                pq.push(Node(dist[v][1],v,1));
            }
            else if(dist[v][0]!=d+w&& dist[v][1]>d+w)
            {
                //cout<<"sec ->>"<<endl;

                dist[v][1]=d+w;
                //cout<<v<<" ";
                debug(dist[v][1]);
                pq.push(Node(dist[v][1],v,1));

            }
        }
    }
}
void init()
{
    memset(vis,0,sizeof vis);
    for(int i=0; i<N; i++)
        dist[i][0] = dist[i][1] = 1e8;
    for(int i=0; i<N; i++)
        adj[i].clear();
}
int main()
{
    fastio;
    int t,n,m,u,v,w,cs=1;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            adj[u].pb(MP(v,w));
            adj[v].pb(MP(u,w));
        }
        Dijkstra(1);
        cout<<"Case "<<cs++<<": "<<dist[n][1]<<endl;
    }
}









