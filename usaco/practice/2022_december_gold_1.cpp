#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int p[2001], c[2001], x[2001];

int dp[2][2001][2001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, a, b; cin >> n >> a >> b;
	for (int i=1; i<=n; ++i){
		cin >> p[i] >> c[i] >> x[i];
	}

	int ans = 0;
	bool buf = 0;
	for (int i=1; i<=n; ++i){
		for (int j=0; j<=a; ++j){
			for (int k=0; k<=b; ++k){
				dp[buf][j][k] = dp[!buf][j][k];
				for (int dk=max(0, (c[i]-j)*x[i]); dk<=min(k, c[i]*x[i]); ++dk){
					dp[buf][j][k] = max(dp[buf][j][k], dp[!buf][j - (c[i] - dk/x[i])][k-dk] + p[i]);
				}
				ans = max(ans, dp[buf][j][k]);
			}
		}
		buf ^= 1;
	}

	cout << ans << '\n';
}
