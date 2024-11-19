#include <bits/stdc++.h>
using namespace std;

int dp[10001], a[10001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
#endif
	
	int n, k; cin >> n >> k;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		int mx = a[i];
		for (int j=i-1; j>=i-k && j>=0; --j){
			dp[i] = max(dp[i], dp[j] + mx*(i-j));
			mx = max(mx, a[j]);
		}
	}

	cout << dp[n] << '\n';
}
