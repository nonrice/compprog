#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1000000000;

void solve(){
	int n, m; cin >> n >> m;

	vector<string> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	array<vector<vector<int>>, 2> dp = {
		vector<vector<int>>(n, vector<int>(m, INF)),
		vector<vector<int>>(n, vector<int>(m, INF))
	};
	dp[0][0][0] = 0;
	dp[1][0][0] = INF;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			if (a[i][j] == '0'){
				if (i > 0){
					dp[1][i][j] = min(dp[1][i][j], dp[1][i-1][j]+1);
					dp[1][i][j] = min(dp[1][i][j], dp[0][i-1][j]+1);
				}
				if (j > 0){
					dp[1][i][j] = min(dp[1][i][j], dp[1][i][j-1]);
				}
			} else {
				if (i > 0){
					dp[0][i][j] = min(dp[0][i][j], dp[1][i-1][j]);
					dp[0][i][j] = min(dp[0][i][j], dp[0][i-1][j]);
				}
				if (j > 0){
					dp[0][i][j] = min(dp[0][i][j], dp[0][i][j-1]);
				}
			}
			//cout << "(" << dp[0][i][j] << ' ' << dp[1][i][j] << ") ";
		}
		//cout << '\n';
	}

	int ans = min(dp[0][n-1][m-1], dp[1][n-1][m-1]);
	if (ans >= INF){
		cout << "-1\n";
		return;
	}
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
