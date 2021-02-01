#include<bits/stdc++.h>
using namespace std;
int n, k, r;
vector<vector<pair<int,int>>> g;
int D;
vector<int> col;

void dfs(int u, int p, int f) {
    int color = 0;
    for (auto e: g[u])
        if (p != e.first) {
            if (color == f) {
                color = (color + 1) % D;
                f = -1;
            }
            col[e.second] = color;
            dfs(e.first, u, color);
            color = (color + 1) % D;
        }
}

int main() {
    cin >> n >> k;
    g.resize(n);
    vector<int> d(n);
    for (int i = 0; i + 1 < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
        d[x]++, d[y]++;
    }
    map<int,int> cnt;
    for (int dd: d)
        cnt[dd]++;

    int v = n;
    D = 0;
    for (auto p: cnt)
        if (v > k)
            D = p.first,
            v -= p.second;
        else
            break;
    col = vector<int>(n - 1);
    dfs(0, -1, -1);
    cout << D << endl;
    for (int i = 0; i + 1 < n; i++)
        cout << col[i] + 1 << " ";
}
