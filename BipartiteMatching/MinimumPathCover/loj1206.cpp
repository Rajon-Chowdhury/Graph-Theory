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
const int N=3e5+9;
const ld eps=1e-9;
const ld PI=acos(-1.0);
//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}


const int maxn=550;
int m;
bool vis[maxn];
vector<int>adj[maxn];
struct data
{
    int tym,sx,sy,dx,dy;
};
data ara[maxn];
bool seen[501];
int match[501];
bool validd(int i,int j)
{
    //int t1=abs(ara[i].sx-ara[i].dx)+abs(ara[i].sy-ara[i].dy);
    //int t2=abs(ara[i].dx-ara[j].sx)+abs(ara[i].dy-ara[j].sy);
    //int ttime=t1+t2+1;
    //return ara[i].tym+ttime<=ara[j].tym;
    /// time for reach the destination of first taxi
    int t1=ara[i].tym+abs(ara[i].sx-ara[i].dx)+abs(ara[i].sy-ara[i].dy);
    /// time for reach source of second taxi from first one
    int t2=abs(ara[i].dx-ara[j].sx)+abs(ara[i].dy-ara[j].sy);
    /// time for start of the second taxi
    int t3=ara[j].tym;
    return t1+t2<t3;


}
bool dfs(int src)
{

    for(auto x:adj[src])
    {
        if(seen[x])
            continue;
        seen[x]=true;
        if(match[x]==-1||dfs(match[x]))
        {
            match[x]=src;
            return true;
        }
    }
    return false;

}
int BPM()
{
    mem(seen,0);
    mem(match,-1);
    int cnt=0;
    for(int i=0; i<m; i++)
    {
        mem(seen,0);
        if(dfs(i))
        {
            cnt++;
        }
    }
    return cnt;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int ts=1; ts<=t; ts++)
    {
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            adj[i].clear();
            int hh,mm;
            scanf("%d:%d%d%d%d%d",&hh,&mm,&ara[i].sx,&ara[i].sy,&ara[i].dx,&ara[i].dy);
            ara[i].tym=hh*60+mm;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(i==j) continue;
                if(validd(i,j))
                {
                    adj[i].push_back(j);
                }
            }
        }
        int ans=m-BPM();
        printf("Case %d: %d\n",ts,ans);
    }
}
