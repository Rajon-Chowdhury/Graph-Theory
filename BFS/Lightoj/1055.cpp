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


inline void normal(ll &a){a %= MOD;(a < 0) && (a += MOD);}
inline ll modMul(ll a, ll b){a %= MOD, b %= MOD;normal(a), normal(b);return (a*b)%MOD;}
inline ll modAdd(ll a, ll b){a %= MOD, b %= MOD;normal(a), normal(b);return (a+b)%MOD;}
inline ll modSub(ll a, ll b){a %= MOD, b %= MOD;normal(a), normal(b);a -= b;normal(a);return a;}
inline ll modPow(ll b, ll p){ll r = 1;while(p){if(p&1)r = modMul(r, b);b = modMul(b, b);p >>= 1;}return r;}
inline ll modInverse(ll a){return modPow(a, MOD-2);}
inline ll modDiv(ll a, ll b){return modMul(a, modInverse(b));}


/// geometry TEMPLATE

const double eps = 1e-9;
const double PI = acos(-1.0);
int sign(double x) { return (x > eps) - (x < -eps); }
struct PT {
    double x, y;
    PT() { x = 0, y = 0; }
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &a) const { return PT(x + a.x, y + a.y); }
    PT operator - (const PT &a) const { return PT(x - a.x, y - a.y); }
    PT operator * (const double a) const { return PT(x * a, y * a); }
    friend PT operator * (const double &a, const PT &b) { return PT(a * b.x, a * b.y); }
    PT operator / (const double a) const { return PT(x / a, y / a); }
    bool operator == (PT a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (PT a) const { return !(*this == a); }
    bool operator < (PT a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (PT a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    PT perp() { return PT(-y, x); }
    double arg() { return atan2(y, x); }
    PT truncate(double r) { // returns a vector with norm r and having same direction
        double k = norm();
        if (!sign(k)) return *this;
        r /= k;
        return PT(x * r, y * r);
    }
};
inline double dot(PT a, PT b) { return a.x * b.x + a.y * b.y; }
inline double dist2(PT a, PT b) { return dot(a - b, a - b); }
inline double dist(PT a, PT b) { return sqrt(dot(a - b, a - b)); }
inline double cross(PT a, PT b) { return a.x * b.y - a.y * b.x; }
inline int orientation(PT a, PT b, PT c) { return sign(cross(b - a, c - a)); }
PT perp(PT a) { return PT(-a.y, a.x); }
PT rotateccw90(PT a) { return PT(-a.y, a.x); }
PT rotatecw90(PT a) { return PT(a.y, -a.x); }
PT rotateccw(PT a, double t) { return PT(a.x * cos(t) - a.y * sin(t), a.x * sin(t) + a.y * cos(t)); }
PT rotatecw(PT a, double t) { return PT(a.x * cos(t) + a.y * sin(t), -a.x * sin(t) + a.y * cos(t)); }
double SQ(double x) { return x * x; }
double rad_to_deg(double r) { return (r * 180.0 / PI); }
double deg_to_rad(double d) { return (d * PI / 180.0); }
double get_angle(PT a, PT b) {
    double costheta = dot(a, b) / a.norm() / b.norm();
    return acos(max((double)-1.0, min((double)1.0, costheta)));
}




//Prime Number Generator

#define mxx 1000006
bitset <mxx> mark;
vector <int> primes;

void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mxx * 1.0) + 2;
    for (int i = 4; i < mxx; i += 2) mark[i] = 1;
    for (int i = 3; i < mxx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mxx; j += i)
                    mark[j] = 1;
        }
    }
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
#define sf2ll(a,b)            scanf("%lld %lld",&a,&b)
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
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
inline void yes(){cout<<"YES\n";exit(0);}
inline void no(){cout<<"NO\n";exit(0);}
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ll dx[]={1,0,-1,0,1,-1,-1,1};
//ll dy[]={0,1,0,-1,1,1,-1,-1};
//random_device rd;
//mt19937 random(rd());
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}


string numTostring(ll num,string s){while(num>0){ll r=num%10;num/=10;s+=r+'0';}reverse(s.begin(),s.end()); return s;}

/*------------------------------Graph Moves----------------------------*/
//Rotation: S -> E -> N -> W
const int fx[] = {0, +1, 0, -1};
const int fy[] = {-1, 0, +1, 0};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/


const int N=1e2+9;

//ll gcd(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
char mp[15][15];
int srcx[3],srcy[3];
int edx[3],edy[3],edp,n;
int dis[11][11][11][11][11][11];
struct Node{
   int ax,ay,bx,by,cx,cy;
   Node(){};
   Node(int a,int b,int c,int d,int e,int f){
    ax=a,ay=b;
    bx=c,by=d;
    cx=e,cy=f;

   }
};
int bfs(int ax,int ay,int bx,int by,int cx,int cy){
    queue<Node>Q;
    mem(dis,-1);
    Node P(ax,ay,bx,by,cx,cy);
    Q.push(P);
    dis[ax][ay][bx][by][cx][cy] = 0;
    while(!Q.empty()){
        Node tmp=Q.front();
        Q.pop();
        int ax = tmp.ax, ay = tmp.ay;
        int bx = tmp.bx, by = tmp.by;
        int cx = tmp.cx, cy = tmp.cy;
         for(int i = 0; i < 4; i++)
        {
            int nax = ax + fx[i], nay = ay + fy[i];
            int fa = 0,fb = 0,fc = 0;
            if(nax < 0 || nay < 0 || nax >= n || nay >= n || mp[nax][nay] == '#')
            {
                nax = ax, nay = ay; fa = 1;
            }
            int nbx = bx + fx[i], nby = by + fy[i];
            if(nbx < 0 || nby < 0 || nbx >= n || nby >= n || mp[nbx][nby] == '#' )
            {
                nbx = bx, nby = by; fb = 1;
            }
            int ncx = cx + fx[i], ncy = cy + fy[i];
            if(ncx < 0 || ncy < 0 || ncx >= n || ncy >= n || mp[ncx][ncy] == '#' )
            {
                 ncx = cx, ncy = cy; fc = 1;
            }
            if(fa && nbx == nax && nby == nay) nbx = bx, nby = by, fb = 1;
            if(fa && ncx == nax && ncy == nay) ncx = cx, ncy = cy, fc = 1;
            if(fb && nax == nbx && nay == nby) nax = ax, nay = ay, fa = 1;
            if(fb && ncx == nbx && ncy == nby) ncx = cx, ncy = cy, fc = 1;
            if(fc && nbx == ncx && nby == ncy) nbx = bx, nby = by, fb = 1;
            if(fc && nax == ncx && nay == ncy) nax = ax, nay = ay, fa = 1;


            if(dis[nax][nay][nbx][nby][ncx][ncy] >= 0) continue;

            int ans = dis[ax][ay][bx][by][cx][cy] + 1;
            dis[nax][nay][nbx][nby][ncx][ncy] = ans;
            if(mp[nax][nay] == 'X' && mp[nbx][nby] == 'X' && mp[ncx][ncy] == 'X')
                return ans;
            Q.push(Node(nax,nay,nbx,nby,ncx,ncy));
        }
    }
    return -1;

}
int main(){
     int t,cs=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", mp[i]);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mp[i][j] == 'A')
                {
                    mp[i][j] = '.';
                    srcx[0] = i; srcy[0] = j;
                }
                else if(mp[i][j] == 'B')
                {
                    mp[i][j] = '.';
                    srcx[1] = i; srcy[1] = j;
                }
                else if(mp[i][j] == 'C')
                {
                    mp[i][j] = '.';
                    srcx[2] = i; srcy[2] = j;
                }
            }
        }
        int ans = bfs(srcx[0],srcy[0],srcx[1],srcy[1],srcx[2],srcy[2]);
        printf("Case %d: ", cs++);
        if(ans == -1)
            printf("trapped\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
