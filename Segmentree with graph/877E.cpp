#include <bits/stdc++.h>

#define fi first
#define se second


const long long N = 200200;
const long long Q = 100100;
const long long mod = 998244353;
const long long block = 500;

using namespace std;

int n;
int a[N];
int b[N];
int tim;
int tin[N];
int tout[N];
int t[4 * N];
bool lz[4 * N];
vector < int > v[N];

void dfs(int x)
{
        tin[x] = (++tim);
        b[tin[x]] = a[x];
        for(int y: v[x]){
                dfs(y);
        }
        tout[x] = tim;
}

void build(int x, int l, int r)
{
        if(l == r){
                t[x] = b[l];
                return;
        }
        int m = (l + r) / 2;
        build(x * 2, l, m);
        build(x * 2 + 1, m + 1, r);
        t[x] = t[x * 2] + t[x * 2 + 1];
}

void push(int x, int l, int r)
{
        if(!lz[x]){
                return;
        }
        int m = (l + r) / 2;
        lz[x] ^= 1;
        lz[x * 2] ^= 1;
        lz[x * 2 + 1] ^= 1;
        t[x * 2] = m - l + 1 - t[x * 2];
        t[x * 2 + 1] = r - m - t[x * 2 + 1];
}

void update(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return;
        }
        if(l == tl && r == tr){
                t[x] = r - l + 1 - t[x];
                lz[x] ^= 1;
                return;
        }
        push(x, l, r);
        int m = (l + r) / 2;
        update(x * 2, l, m, tl, min(m, tr));
        update(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
        t[x] = t[x * 2] + t[x * 2 + 1];
}

int query(int x, int l, int r, int tl, int tr)
{
        if(tl > tr){
                return 0;
        }
        if(l == tl && r == tr){
                return t[x];
        }
        push(x, l, r);
        int m = (l + r) / 2;
        return query(x * 2, l, m, tl, min(m, tr)) + query(x * 2 + 1, m + 1, r, max(m + 1, tl), tr);
}

void solve()
{
        cin >> n;
        for(int i = 2; i <= n; i++){
                int x;
                cin >> x;
                v[x].push_back(i);
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        dfs(1);
        build(1, 1, n);
        int m;
        cin >> m;
        for(int i = 1; i <= m; i++){
                string s;
                int x;
                cin >> s >> x;
                if(s == "get"){
                        cout << query(1, 1, n, tin[x], tout[x]) << "\n";
                }
                else{
                        update(1, 1, n, tin[x], tout[x]);
                }
        }
}

int main()
{

        int TE=1;
                while(TE--)
                solve();
        return 0;
}
