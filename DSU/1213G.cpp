#include <bits/stdc++.h>

using namespace std;



vector<int> p, rk;

int getp(int v)
{
    if (v == p[v]) return v;
    return p[v] = getp(p[v]);
}

long long res;

long long get(int cnt)
{
    return cnt * 1ll * (cnt - 1) / 2;
}

void merge(int u, int v)
{
    u = getp(u);
    v = getp(v);
    // cout<<u<<" "<<v<<endl;
     //cout<<rk[u]<<" "<<rk[v]<<endl;
    if (rk[u] < rk[v]) swap(u, v);

    //cout<<rk[u]<<" "<<rk[v]<<endl;
    //cout<<res<<endl;
    res -= get(rk[u]);
      //  cout<<res<<endl;
    res -= get(rk[v]);
        //cout<<res<<endl;

    rk[u] += rk[v];

    res += get(rk[u]);
        //cout<<res<<endl;

    p[v] = u;
}

int main()
{


    int n, m;
    cin >> n >> m;

    res = 0;
    p = rk = vector<int>(n, 1);
    iota(p.begin(), p.end(), 0);

    vector<pair<int, pair<int, int>>> e(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
        --e[i].second.first;
        --e[i].second.second;
    }

    vector<pair<int, int>> q(m);
    vector<long long> ans(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(e.begin(), e.end());
    sort(q.begin(), q.end());

    int pos = 0;
    for (int i = 0; i < m; ++i)
    {
        while (pos < n - 1 && e[pos].first <= q[i].first)
        {
            int u = e[pos].second.first;
            int v = e[pos].second.second;
           // cout<<endl<<endl;
            //cout<<u<<" "<<v<<endl;
            merge(u, v);
            ++pos;
        }
        ans[q[i].second] = res;
    }

    for (int i = 0; i < m; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
