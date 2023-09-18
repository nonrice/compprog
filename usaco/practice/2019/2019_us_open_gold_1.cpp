#include <bits/stdc++.h>
using namespace std;

int a[400];
int c[400][400];
int dp[401][400];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
#endif
	
	int n, k; cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> a[i];

	for (int i=0; i<n; ++i){
		int mx = 0, t = 0;
		for (int j=i; j<n; ++j){
			mx = max(mx, a[j]);
			t += a[j];
			c[i][j] = mx * (j-i+1) - t;
		}
	}

	for (int i=0; i<n; ++i) dp[0][i] = c[0][i];
	for (int i=1; i<=k; ++i){
		for (int j=i; j<n; ++j){
			dp[i][j] = INT_MAX;
			for (int k=j-1; k>=0; --k){
				dp[i][j] = min(dp[i][j], dp[i-1][k] + c[k+1][j]);
			}
		}
	}

	cout << dp[k][n-1] << '\n';
}
