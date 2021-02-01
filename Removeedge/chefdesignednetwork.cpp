#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'


using namespace std;

lli maxEdge(lli n)
{
	return (n * (n + 1))/2;
}

lli minEdge(lli n)
{
	return n-1;
}

lli solveOdd(lli n , lli m)
{
	if(m > maxEdge(n) || m < minEdge(n))
	return -1;

	if(n == 1)
	return m;

	if(m == minEdge(n))
	return 2;

	if(m >= n && m <= n+1)
	return 2;

	if(m <= 2*n)
	return 3;

	lli ans = 3;
	lli tot = 2*n;
	int cnt = 0;

	while(1)
	{
		tot += n / 2 + (cnt % 2);
		cnt++ , ans++;

		if(tot >= m)
		return ans;
	}
}

lli solveEve(lli n , lli m)
{
	if(m > maxEdge(n) || m < minEdge(n))
	return -1;

	if(m == minEdge(n))
	{
		if(n == 2)
		return 1;

		return 2;
	}

	if(m >= n && m <= n+1)
	return 2;

	if(m <= 2*n)
	return 3;

	lli res = (m - 2 * n - 1) / (n / 2);
	return res + 4;
}
int main()
{
	lli t , n , m;
	cin>>t;

	while(t--)
	{
		cin>>n>>m;
		if(n % 2)
		cout<<solveOdd(n , m)<<endl;

		else
		cout<<solveEve(n , m)<<endl;
	}
}
