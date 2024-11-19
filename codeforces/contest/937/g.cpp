#include <bits/stdc++.h>
using namespace std;

#define getb(m, i) (((m)>>(i)) & 1)
#define unsetb(m, i) ((m)&(~(1<<(i))))

string w[16], g[16];
bool adj[16][16];
vector<vector<bool>> dp;

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> g[i] >> w[i];
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			adj[i][j] = false;
			if (i == j){
				continue;
			}
			if (w[i]==w[j] || g[i]==g[j]){
				adj[i][j] = true;
			}
		}
	}

	int ans = 0;
	dp = vector<vector<bool>>(n+1, vector<bool>(1<<n));
	for (int m=1, u=0; u<n; m<<=1, ++u){
		dp[u][m] = true;
	}
	for (int m=0; m<(1<<n); ++m){
		for (int v=0; v<n; ++v){
			if (!getb(m, v)){
				continue;
			}
			for (int u=0; u<n; ++u){
				if (adj[u][v] && dp[u][unsetb(m, v)]){
					dp[v][m] = true;
					break;
				}
			}
			if (dp[v][m]){
				ans = max(ans, __builtin_popcount(m));
			}
		}
	}

	cout << n-ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
