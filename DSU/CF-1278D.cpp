#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int id[N], comp[N];
int par[N];

void init() {
    for (int i=0; i<N; i++)     par[i] = i;
}

int find(int u) {
    if (par[u]==u)  return u;
    return par[u] = find(par[u]);
}

int edges = 0;
void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if(u==v) {
        cout<<"NO"<<endl;
        exit(0);
    }
    edges++;
    par[u] = v;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    init();

    for (int i=1; i<=n; i++) {
        int x, y;
        cin>>x>>y;
        id[x] = i;
        id[y] = -i;
        comp[x] = y;
        comp[y] = x;
    }

    set<pair<int, int>> st;

    for (int i=1; i<=2*n; i++) {
        if (id[i] < 0) {
            st.erase({i, -id[i]});
        }
        else {
            int y = comp[i];
            for (auto pr: st) {
                if (pr.first > y)  break;
                merge(pr.second, id[i]);
            }
            st.insert({y, id[i]});
        }
    }

    if (edges == n-1) cout<<"YES"<<endl;
    else                cout<<"NO"<<endl;
}
