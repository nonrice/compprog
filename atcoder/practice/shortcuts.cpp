#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 3000000000;

int x[10001], y[10001];
long double dp[36][10001];

inline long double d(int a, int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

inline long long c(long long a){
	if (a == 0) return 0;
	return (1LL)<<(a-1);
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> x[i+1] >> y[i+1];
	}

	long double ans = INF;
	for (int i=0; i<=min(35, n-2); ++i){
		dp[i][0] = INF;
		fill(dp[i]+2, dp[i]+i+2, INF);
		for (int j=i+2; j<=n; ++j){
			dp[i][j] = dp[i][j-1] + d(j, j-1);
			for (int k=1; k<=min(j-2, i); ++k){
				dp[i][j] = min(dp[i][j], dp[i-k][j-1-k] - c(i-k) + c(i) + d(j, j-1-k)); 
			}
		}
		ans = min(ans, dp[i][n]);
	}

	cout << fixed << setprecision(10) << ans << '\n';
}
