#include <bits/stdc++.h>
using namespace std;

int n, k;
long long r[101];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
#endif

	cin >> n >> k;
	for (int i=1; i<=n; ++i) cin >> r[i];

	long long ans = LLONG_MAX;
	for (int rt = 1; rt <= n; ++rt){
		vector<vector<long long>> dp(k+1, vector<long long>(n+1, LLONG_MAX));
		vector<vector<long long>> c(n+1, vector<long long>(n+1));
		for (int i=1; i<=n; ++i){
			for (int j=i; j<=n; ++j){
				c[i][j] = c[i][j-1] + (j-i)*r[j];
			}
		}

		dp[1][1] = c[1][n];
		ans = min(ans, c[1][n]);
		for (int j=2; j<=k; ++j){
			for (int i=j; i<=n; ++i){
				dp[j][i] = dp[j][i-1];
				for (int l=1; l<i; ++l){
					dp[j][i] = min(dp[j][i], dp[j-1][l] - c[l][n] + c[l][i-1] + c[i][n]);
				}
				ans = min(ans, dp[j][i]);
			}
		}
		rotate(r+1, r+2, r+n+1);
/*
		for (int j=1; j<=k; ++j){
			for (int i=1; i<=n; ++i){
				cout << dp[j][i] << ' ';
			}
			cout<< '\n';
		}
	*/
	}


	cout << ans << '\n';
}
