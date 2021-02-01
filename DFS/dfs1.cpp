#include<bits/stdc++.h>
using namespace std;

   vector <int> adj[10];
    bool visited[10];

    void dfs(int s) {

        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i){
         if(visited[adj[s][i]] == false){
             cout<<adj[s][i]<<" ";
             dfs(adj[s][i]);}
        }
    }

    void initialize() {
        for(int i = 0;i < 10;++i)
         visited[i] = false;
    }

    int main() {
        int nodes, edges, x, y, connectedComponents = 0,sn;
        cin >> nodes;
        cin >> edges;
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;

         adj[x].push_back(y);
         adj[y].push_back(x);
        }

        initialize();
        cin>>sn;
        dfs(sn);

        return 0;
    }
