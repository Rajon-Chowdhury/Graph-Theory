#include<bits/stdc++.h>
#define PII pair<int, int>
#define LL long long
using namespace std;
struct Edge2
{
    int u, v, w;
};

const int N = 305, INF = 1e9+7;
int n,m;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
vector<pair<int,int>>gr[N];


vector<int> Dijkstra(int s)
{
    vector<int> dis(n+1, INF);
    priority_queue<PII, vector<PII>, greater<PII> > pq;

    dis[s] = 0;
    pq.push(PII(0, s));

    while (pq.size())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dis[u]) continue;

        for (auto pr: gr[u])
        {
            int v = pr.first;
            int w = pr.second;
            if (d + w >= dis[v])    continue;
            dis[v] = d + w;
            pq.push(PII(d+w, v));
        }
    }
    return dis;
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin>>t;

    for (int cs = 1; cs<=t; ++cs)
    {
        for (int i=0; i<N; i++)
            gr[i].clear();

        cin>>n>>m;

        vector<Edge2> edges;
        for (int i=1; i<=m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;

            Edge2 e = {u, v, w};
            edges.push_back(e);

            gr[u].push_back(PII(v, w));
            gr[v].push_back(PII(u, w));
        }

        vector<int> ds = Dijkstra(1);
        vector<int> dt = Dijkstra(n);

        assert(ds[n] == dt[1]);
        int dd = ds[n];

        if (dd >= INF)  {
            cout<<"Case "<<cs<<": -1 -1"<<endl;
            continue;
        }

        for (int i=0; i<N; i++)
            gr[i].clear();

        Dinic solver(n+1,1,n);

        for (auto e: edges)
        {
            int nd1 = ds[e.u] + dt[e.v] + e.w;
            int nd2 = ds[e.v] + dt[e.u] + e.w;
            if (nd1 == dd || nd2 == dd)  continue;
            gr[e.u].push_back(PII(e.v, e.w));
            gr[e.v].push_back(PII(e.u, e.w));
            solver.add_edge(e.u, e.v, e.w);
            solver.add_edge(e.v, e.u, e.w);
        }

        ds = Dijkstra(1);
        dd = ds[n];

        if (dd >= INF) {
            cout<<"Case "<<cs<<": -1 -1"<<endl;
            continue;
        }

        cout<<"Case "<<cs<<": "<<dd<<" "<<solver.flow()<<endl;
    }
}
