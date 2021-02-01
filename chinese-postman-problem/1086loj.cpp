#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define set(x,n) (x^(1<<n))
#define check(x,n) (x&(1<<n))
int n;
int edge[1050];
ll floyd[1050][1050];
int edge_count[1028];
int ans;
ll dp[1<<17];

int floyd_warshal()
{
	long long t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(floyd[i][j] == 0) {
				floyd[i][j] = INT_MAX;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(floyd[i][k] != INT_MAX and floyd[k][j] != INT_MAX) {
					t = floyd[i][k] + floyd[k][j];
					if(t < floyd[i][j]) {
						floyd[i][j] = t;
					}
				}

			}
		}
	}
}
ll chinesepostman(int bit){
   int x;
   ll mini;
   int i;
   mini=INT_MAX;
   if(bit==0)
    return 0;
   if(dp[bit]!=-1)
    return dp[bit];

	for(i = 1; i <= n; i++) {
		if(check(bit, i)) {
			break;
		}
	}

	for (int j = i + 1; j <= n; j++) {
		int temp = bit;

		if(check(bit, i) and check(bit, j )) {
			temp = set(temp, i);
			temp = set(temp, j);

			mini = min(mini, floyd[i][j] + chinesepostman(temp));
		}
	}



	return dp[bit] = mini;

}
int main()
{
   int t,cs=1;
   cin>>t;
   while(t--){

	int x;
	int y;
	int start;
	long long mini;
	long long w;
	int m;
	int bit;



	memset(edge_count, 0, sizeof edge_count);
	memset(dp, -1, sizeof dp);




	ans = 0;
	bit = 0;

	cin >> n; //no of joints
	cin >> m; // no of streets

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			floyd[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < m; i++) {


		cin >> x; // street starting point
		cin >> y; // street ending point
		cin >> w; // street length

		ans += w;

		floyd[x][y] = min(w, floyd[x][y]);
		floyd[y][x] = min(w, floyd[y][x]);


		edge_count[x]++;
		edge_count[y]++;

	}



	floyd_warshal(); // calculate the shortest path between all the joints


	for (int i = 1; i <= n; i++) {
		if(edge_count[i] % 2 == 1) {
			bit = set(bit, i); // mark joints with odd degree
		}

	}
	 ans += chinesepostman(bit); // try all combination of odd vertices and choose the combination with minimum distance


	 printf("Case %d: %d\n", cs++, ans);
}

}
