#include<bits/stdc++.h>
using namespace std;

using namespace std;
set<int> ar[100001];
vector<pair<int,int>>bridges;
int in[100001], low[100001], vis[100001];
int timer;

/// find brige
void dfs(int node, int p = -1)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    for(int child : ar[node])
    {
        if(child == p) continue;

        if(vis[child])
            low[node] = min(low[node], in[child]);

        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);

            if(low[child] > in[node])	//this edge is a bridge
            {
                bridges.push_back({node, child});
            }
        }
    }
}
void dfs0(int node)
{
    vis[node] = 1;
    for(int child : ar[node])
        if(!vis[child])
            dfs0(child);
}
/// has cycle
//function returns true if a cycle is found
bool hasCycle(int node ,int p = -1)
{
	vis[node] = 1;
	for(int child : ar[node])
	if(child != p)
	{
		if(vis[child])
		return true;

		if(hasCycle(child , node))
		return true;
	}

	return false;
}


int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        timer=0,bridges.clear();
        for(int i=1; i<=n; i++) ar[i].clear(),vis[i]=0;
        for(int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            ar[x].insert(y);
            ar[y].insert(x);
        }
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
                dfs(i);
        }
        for(auto e:bridges)
            ar[e.first].erase(e.second),ar[e.second].erase(e.first);

          for(int i=1;i<=n;i++) vis[i]=0;

            int cycleCount = 0;
        for(int i=1; i<=n; i++)
            if(ar[i].size() > 0 && !vis[i])
                dfs0(i), cycleCount++;

        if(cycleCount != 1)
            cout<<"-1\n";
        else
        {
            int maxDegree = 0;
            int resNode = INT_MAX;


            //finding node with highest degree
            for(int i=1; i<=n; i++)
                if(ar[i].size() > maxDegree)
                    maxDegree = ar[i].size(), resNode = i;
                else if(ar[i].size() == maxDegree)
                    resNode = min(resNode, i);


            for(int i=1; i<=n; i++) ar[i].erase(resNode), vis[i] = 0;
            ar[resNode].clear();


            //checking if no cycle exist
            for(int i=1; i<=n; i++)
                if(!vis[i])
                {
                    if(hasCycle(i))
                    {
                        resNode = -1;
                        break;
                    }
                }
            cout<<resNode<<endl;
        }
    }
}

