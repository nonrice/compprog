#include <bits/stdc++.h>
using namespace std;

inline long long sq(long long x){
	return x*x;
}

long long sx, sy;
long long x[200001], y[200001];
long double p[200001];

inline long double d(int i, int j){
	return p[j] - p[i];
}

inline long double d(long long x1, long long y1, long long x2, long long y2){
	return sqrtl(sq(x1-x2) + sq(y1-y2));
}

inline long long dt(int i){
	return d(x[i-1], y[i-1], sx, sy) + d(sx, sy, x[i], y[i]);
}

long double dp[200001][2];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	cin >> sx >> sy;
	for (int i=1; i<=n; ++i){
		cin >> x[i] >> y[i];
	}

	for (int i=1; i<=n; ++i){
		p[i] = p[i-1] + sqrtl(sq(x[i]-x[i-1]) + sq(y[i]-y[i-1]));
	}

	dp[1][0] = d(sx, sy, x[1], y[1]);
	dp[1][1] = 2*dp[1][0];
	cout << dp[1][0] << ' ' << dp[1][1] << '\n';
	for (int i=2; i<=n; ++i){
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + dt(i);

		dp[i][0] = LLONG_MAX;
		for (int j=max(1, i-k); j<i; ++j){
			dp[i][0] = min(dp[i][0], dp[j][1] + d(j, i));
		}

		cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	}

	cout << d(x[n], y[n], sx, sy) + min(dp[n][0], dp[n][1]) << '\n';

}
