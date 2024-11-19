#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long a, b, c;
	int n;
	cin >> a >> b >> c >> n;

	vector<long long> dp(2*n+1);
	for (int i=1; i<=2*n; ++i){
		dp[i] = a*i;

		for (int j=1; j<i; ++j){
			dp[i] = min(
				dp[i],
				min(
					dp[j] + b + (i-j)/j*c + a*((i-j)%j),
					dp[j] + a*(i-j)
				)
			);
		}
	}

	long long ans = *min_element(dp.begin()+n+1, dp.end());

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
