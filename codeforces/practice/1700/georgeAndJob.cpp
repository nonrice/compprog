#include <bits/stdc++.h>
using namespace std;

long long dp[5001][5001];
long long a[5001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n, m, k; cin >> n >> m >> k;
	for (int i=1; i<=n; ++i) cin >> a[i];

	for (int i=1; i<=k; ++i){
		long long w = 0;
		for (int j=1; j<=n; ++j){
			w += a[j] - ((j-m>=1) ? a[j-m] : 0);
			if (j >= i*m){
				dp[i][j] = max(dp[i][j-1], w + dp[i-1][j-m]);
			}
		}
	}

	cout << dp[k][n] << '\n';
}
