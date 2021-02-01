#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

/*
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/

void trace(int x)
{
    cerr << x;
}
void trace(long x)
{
    cerr << x;
}
void trace(long long x)
{
    cerr << x;
}
void trace(unsigned x)
{
    cerr << x;
}
void trace(unsigned long x)
{
    cerr << x;
}
void trace(unsigned long long x)
{
    cerr << x;
}
void trace(float x)
{
    cerr << x;
}
void trace(double x)
{
    cerr << x;
}
void trace(long double x)
{
    cerr << x;
}
void trace(char x)
{
    cerr << '\'' << x << '\'';
}
void trace(const char *x)
{
    cerr << '\"' << x << '\"';
}
void trace(const string &x)
{
    cerr << '\"' << x << '\"';
}
void trace(bool x)
{
    cerr << (x ? "true" : "false");
}

template <typename A, typename B>                         void trace(const pair <A, B> &x)
{
    cerr << '{';
    trace(x.first);
    cerr << ',';
    trace(x.second);
    cerr << '}';
}
template <typename A, typename B, typename C>             void trace(const tuple <A, B, C> &x)
{
    cerr << '{';
    trace(get <0> (x));
    cerr << ',';
    trace(get <1> (x));
    cerr << ',';
    trace(get <2> (x));
    cerr << '}';
}
template <typename A, typename B, typename C, typename D> void trace(const tuple <A, B, C, D> &x)
{
    cerr << '{';
    trace(get <0> (x));
    cerr << ',';
    trace(get <1> (x));
    cerr << ',';
    trace(get <2> (x));
    cerr << ',';
    trace(get <3> (x));
    cerr << '}';
}
template <typename T>                                     void trace(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? "," : ""), trace(i);
    cerr << "}";
}
template <size_t N>                                       void trace(bitset <N> v)
{
    cerr << '{';
    for (size_t i = 0; i < N; i++) cerr << static_cast <char> ('0' + v[i]);
    cerr << '}';
}
void _print()
{
    cerr << "]\n";
}
template <typename T, typename... V>                      void _print(T t, V... v)
{
    trace(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template <typename T> using ordered_set                = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map  = tree <T1, T2, less <T1>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> bool MIN(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template <class T> bool MAX(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

template <class T> T binaryExpo(T a, T p)
{
    if (p == 0)
    {
        return 1LL;
    }
    if (p == 1)
    {
        return a;
    }
    if (p & 1)
    {
        return a * binaryExpo(a, p - 1);
    }
    T ret = binaryExpo(a, p / 2);
    return ret * ret;
}
template <class T> T bigMod(T a, T p, T m)
{
    if (p == 0)
    {
        return 1LL % m;
    }
    if (p == 1)
    {
        return a % m;
    }
    if (p & 1)
    {
        return (a % m * bigMod(a, p - 1, m)) % m;
    }
    T ret = bigMod(a, p / 2, m) % m;
    return (ret * ret) % m;
}
template <class T> T modInv(T a, T m)
{
    return bigMod(a, m - 2, m);
}

template <typename T> string num_str(T num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}
long long str_num(string s)
{
    long long num;
    istringstream iss(s);
    iss >> num;
    return num;
}

inline long long ON(long long mask, int pos)
{
    return mask |= (1LL << pos);
}
inline long long OFF(long long mask, int pos)
{
    return mask &= ~(1LL << pos);
}
inline long long TOGGLE(long long mask, int pos)
{
    return mask ^= (1LL << pos);
}
inline bool CHECK(long long mask, int pos)
{
    return (bool)(mask >> pos & 1LL);
}

inline int ONE(long long mask)
{
    return __builtin_popcountll(mask);
}
inline int LZERO(long long mask)
{
    return 31 - __builtin_clzll(mask);
};
inline int TZERO(long long mask)
{
    return __builtin_ctzll(mask);
};

int dr4[] = {+1, -1, +0, +0};                       // 4 Direction - DOWN, UP, RIGHT, LEFT
int dc4[] = {+0, +0, +1, -1};
int dr8[] = {+0, +0, +1, -1, +1, +1, -1, -1};       // 8 Direction - RIGHT, LEFT, DOWN, UP, RIGHT-DOWN, LEFT-DOWN, UP-RIGHT, UP-LEFT
int dc8[] = {+1, -1, +0, +0, +1, -1, +1, -1};
int drk[] = {-1, +1, -2, -2, -1, +1, +2, +2};       // knight Moves
int dck[] = {-2, -2, -1, +1, +2, +2, +1, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define ll              long long int
#define ull             unsigned long long int
#define endl            '\n'
#define pii             pair <int, int>
#define pll             pair <ll, ll>
#define mk              make_pair
#define ff              first
#define ss              second
#define all(a)          (a).begin(), (a).end()
#define rall(a)         (a).rbegin(), (a).rend()
#define eb              emplace_back
#define pb              push_back
#define pf              push_front
#define allUpper(a)     transform(all(a), a.begin(), :: toupper)
#define allLower(a)     transform(all(a), a.begin(), :: tolower)
#define LINE            cerr << __LINE__ << " ";
#define memo(a, b)      memset(a, b, sizeof a)
#define sz(a)           (int)(a.size())
#define ook             order_of_key
#define fbo             find_by_order

#define int             long long int

const int maxn = 1e4 + 5;
const int logn = 19;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const int maxbit = 6;

struct Node
{
    int v, w;
    Node(int v, int w)
        : v(v), w(w) {}

    bool operator < (const Node &other) const
    {
        return w > other.w;
    }
};

vector < vector <Node> > graph;
int dist[maxn];
int city;
int road;
int ballon;
int myCost;
int myBallon;

int dijkstra(int src = 1)
{
    for (int i = 1; i < maxn; i++)
    {
        dist[i] = INF;
    }
    priority_queue <Node> pq;
    pq.emplace(src, 0);
    dist[src] = 0;
    while (sz(pq))
    {
        int u = pq.top().v;
        pq.pop();
        for (Node it : graph[u])
        {
            int v = it.v;
            int w = it.w;
            if (MIN(dist[v], dist[u] + w))
            {
//                        debug(u, v, dist[v]);
                pq.emplace(v, dist[v]);
            }
        }
    }
    return dist[city];
}

struct Edge
{
    int u, v, cost, ballon;
    Edge(int u = 0, int v = 0, int cost = 0, int ballon = 0)
        : u(u), v(v), cost(cost), ballon(ballon) {}
};

signed main()
{


    cin >> city >> road >> myCost >> myBallon;
    vector <Edge> edges(road);
    for (Edge &it : edges)
    {
        cin >> it.u >> it.v >> it.cost >> it.ballon;
    }
    int lo = 0;
    int hi = 1e10;
    int maxi = 0;
    while (lo <= hi)
    {
        int mid = lo + hi >> 1;
        graph.clear();
        graph.resize(city + 1);
        for (Edge it : edges)
        {
            int u = it.u;
            int v = it.v;
            int w = it.cost;
            if (it.ballon >= mid)
            {
                debug(u, v, w);
                graph[u].eb(v, w);
                graph[v].eb(u, w);
            }
        }
        int cost = dijkstra();
        if (cost <= myCost)
        {
            maxi = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    int ans = min(maxi, myBallon);
    cout << ans << endl;




    return 0;
}

