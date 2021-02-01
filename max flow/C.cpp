#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18+10
int a[500005];
int l[500005],r[500005];
int sm=0,rsum[500005];
main()
{
    int n,h;
    cin>>n>>h;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        l[i]=max(l[i-1]+1LL,a[i]);

        sm+=a[i];
    }
    for(int i=n; i>0; i--)
    {
        r[i]=max(r[i+1]+1LL,a[i]);
        rsum[i]=r[i]+rsum[i+1];
    }
    int ans=LLONG_MAX,csum=a[1],lsum=l[1];
    for(int i=2; i<n; i++)
    {
        if(a[i]>h) continue;
        int x=l[i-1];
        int y=r[i+1];
        if(x<h && y<h)
        {
            int cv=(lsum-csum)+rsum[i+1]-(sm-csum-a[i])+(h-a[i]);
            ans=min(ans,cv);
        }
        csum+=a[i];
        lsum+=l[i];
    }
    if(ans==LLONG_MAX) ans=-1;
    cout<<ans<<endl;

}
