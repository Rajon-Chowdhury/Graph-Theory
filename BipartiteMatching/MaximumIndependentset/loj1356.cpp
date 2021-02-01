#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli unsigned long long
#define ll long long
#define endl '\n'
using namespace std;
const int NX = 500000 + 10;
const int MX = 40000 + 10 ;
const int INF = 1 << 29 ;
int check[NX] , prime[NX] , id , n ;
int num[MX];
int save[MX];
vector < int > adj[MX];
int dist[MX] , match[MX] ;
int q[NX] ,  pos[NX] ;

/// prime calculation
#define mxx 1000006
bitset <mxx> mark;
vector <int> primes;

void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mxx * 1.0) + 2;
    for (int i = 4; i < mxx; i += 2) mark[i] = 1;
    for (int i = 3; i < mxx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mxx; j += i)
                    mark[j] = 1;
        }
    }
}
void init(){
     for(int i=1;i<=n+1;i++) adj[i].clear(),match[i]=0;
     memset(pos,0,sizeof pos);
}

bool bfs()
{
    int f = 0 , b = 0 , i ;
    for(int i=1;i<=n;i++)
    {
        if( match[i] == 0 )
        {
            dist[i] = 0 ;
            q[f++] = i ;
        }
        else dist[i] = INF ;
    }
    dist[0] = INF ;
    while( b < f )
    {
        int x = q[b++] ;
        if( x == 0 ) continue ;
        int sz = adj[x].size();
        for(int i=0;i<sz;i++)
        {
            int y = adj[x][i];
            if( dist[match[y]] == INF )
            {
                dist[match[y]] = dist[x] + 1 ;
                q[f++] = match[y];
            }
        }
    }
    return dist[0] != INF ;
}
bool dfs(int x)
{
    if( x )
    {
        int sz = adj[x].size();
        for(int i=0;i<sz;i++)
        {
            int y = adj[x][i];
            if( dist[match[y]] == dist[x] + 1 && dfs(match[y]))
            {
                match[x] = y ;
                match[y] = x ;
                return 1 ;
            }
        }
        dist[x] = INF ;
        return 0 ;
    }
    return 1 ;
}
int hopcropt()
{
    int matching = 0 ;
    while( bfs() )
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            if( match[i] == 0 && dfs(i) )
            {
                matching++;
            }
        }
    }
    return n - matching ;
}
int main(){
        sieve();
        int t,cs=1;
        scanf("%d",&t);
        while(t--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            pos[num[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int x=num[i];
            int cot=0;
            for(int k=0;primes[k]*primes[k]<=x;k++)
            {
                int f=0;
                while(x%primes[k]==0)
                {
                    f=1;
                    x/=primes[k];
                }
                if(f) save[++cot]=primes[k];
            }
            if(x>1) save[++cot]=x;
            for(int k=1;k<=cot;k++)
            {
                //cout<<save[k]<<endl;
                int y=num[i]/save[k];

                if(pos[y])
                {
                    //cout<<i<<" "<<pos[y]<<endl;
                    adj[i].push_back(pos[y]);
                    adj[pos[y]].push_back(i);

                }
            }
        }
        int res=hopcropt();

        printf("Case %d: %d\n",cs++,res);


    }

}
