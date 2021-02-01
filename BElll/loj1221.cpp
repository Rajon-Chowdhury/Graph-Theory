#include<bits/stdc++.h>
using namespace std;
const long long INF=20000000002L;
struct Edge
{
    int from,to;
    long long w;

};
vector<Edge>edges;
long long int dist[205];
int ce,cv;
bool bellman()
{
    long long int now;
    int from,to;
    for(int v=1; v<cv; v++) //n-1 times iteration needed
    {
        for(int e=0; e<ce; e++)
        {
            from=edges[e].from;
            to=edges[e].to;
            now=dist[from]+edges[e].w;
            if(now<dist[to])
            {
                dist[to]=now;
            }
        }
    }
    // n-1 times iteration korar por arekbar iteration korbo
    // negative cycle detect korar jonno

    for(int e=0; e<ce; e++)
    {
        from=edges[e].from;
        to=edges[e].to;
        now=dist[from]+edges[e].w;
        if(now<dist[to])
            return true;

    }
    return false;

}
int main()
{
    int t,cs=1,expenses,income,p;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&cv,&ce,&p);
        printf("Case %d: ",cs++);

        edges=vector< Edge > (ce);

        for(int k=0; k<ce; k++)
        {
            scanf("%d %d %d %d",&edges[k].from,&edges[k].to,&income,&expenses);
            edges[k].w=p*expenses-income;
        }


        fill(dist,dist+cv,0);
        bool flag=bellman();
        if(flag==true)
            printf("YES\n");
        else
            printf("NO\n");

    }
}
