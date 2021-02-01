#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000
int tim[51][51],cost[51][51];
int n,t;
int totaltime;
int dp[55][55];

int func(int pos,int rem)
{
    cout<<pos<<" "<<rem<<endl;
    if(rem==0 && pos<n) return INF;
    if(rem<0) return INF;
    if(pos>n)
        return 0;

    int &r=dp[pos][rem];

    if(r!=-1) return r;

    r=INF;

    for(int i=2; i<=n; i++)
    {
     if(pos!=n&&i!=pos)
     r=min(r,cost[pos][i]+func(i,rem-tim[pos][i]));

    }
    return r;

}
int main()
{

    cin>>n>>t;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>tim[i][j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>cost[i][j];
    memset(dp,-1,sizeof dp);
    int tcost=func(1,t);
    int ttime=INT_MAX;
    for(int i=1; i<=t; i++)
    {
        if(dp[n][i]!=-1)
        {
            ttime=i;
            break;
        }
    }
    cout<<tcost<<" "<<ttime<<endl;



}

