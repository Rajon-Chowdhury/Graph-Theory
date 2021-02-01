#include<bits/stdc++.h>

using namespace std;
map< int, int > visited;

void BFS(int s, map< int, vector< int > >G)
{
    queue< int >q;
    q.push(s);
    visited[s] = 0;
    while(!q.empty())
    {
        int top = q.front();
        for(int i=0; i<G[top].size(); i++)
        {
           int n = G[top][i];
           if(!visited.count(n))
           {
               visited[n] = visited[top] + 1;
               q.push(n);
           }
        }
        q.pop();
    }
}



int main()
{
    int edges, T=0;
    while(scanf("%d",&edges)==1 &edges!=0)
    {
        map< int,vector< int > >G;
        for(int i=0; i<edges; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int TTL, source;
        while(scanf("%d %d", &source, &TTL)==2)
        {
            if(source==0 && TTL==0) break;
            map< int, int>::iterator it;
            visited.clear();
            BFS(source,G);
            int count=0;
            for(it=visited.begin(); it!=visited.end();++it)
            {
                if((*it).second>TTL){
                    ++count;
                }
            }
            count = count + G.size()-visited.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++T,count, source, TTL);
        }
    }
    return 0;
}
