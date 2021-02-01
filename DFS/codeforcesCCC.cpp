#include<bits/stdc++.h>

#define MX 100005
using namespace std;
typedef long long ll;

int cnt;
int chk[MX];
vector< int > vt[MX];

int dfs(int n){
     int i, j, k;
     chk[n]=1;
     int c=1;
     for(i=0; i<vt[n].size(); ++i){
          j=vt[n][i];
          if(!chk[j]){
               k=dfs(j);
               if(k%2==0) cnt++;
               c+=k;
          }
     }
     return c;
}

int main(){
     int i, j, k;
     int n, u, v;
     cin >> n;
     for(i=0; i<n-1; ++i){
          scanf("%d %d", &u, &v);
          vt[u].push_back(v);
          vt[v].push_back(u);
     }
     if(n&1){
          cout << -1 << endl;
          return 0;
     }
     dfs(1);
     cout << cnt << endl;
}
