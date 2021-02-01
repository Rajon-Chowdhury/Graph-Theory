#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define m 100005
vector <int> adj[m];
bool visited[m];
int cnt=0;
    int dfs(int s) {
         cnt++;
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false){
             dfs(adj[s][i]);
         }
        }
        return cnt;
    }

    void initialize() {
        for(int i = 0;i < 10;++i)
         visited[i] = false;
    }

    int main() {
        int nodes, edges, x, y,mx,E,N,MN=0,ME=0,mch=0;
        cin >> nodes;
        cin >> edges;
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;
         adj[x].push_back(y);
         adj[y].push_back(x);
        }

        initialize();

        for(int i = 1;i <= nodes;++i) {
             cnt=0;
         if(visited[i] == false)     {
             N=dfs(i);
             E=N-1;

             float ch;
             ch=float(E)/float(N);

             if(ch>mch){
               ME=E;
               MN=N;
               mch=ch;
             }

         }
        }
        if(ME>MN) cout<<">1"<<endl;
        else{
       cout<<ME<<"/"<<MN<<endl;
        }
        return 0;
    }
