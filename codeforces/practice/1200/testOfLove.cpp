#include <bits/stdc++.h>
using namespace std;

char s[200002];
int dp[200002];

void solve(){
	int k, n, m; cin >> n >> m >> k;

	cin >> (s+1);
	s[0] = s[n+1] = 'L';

	dp[0] = 0;
	for (int i=1; i<=n+1; ++i){
		dp[i] = 1000000000;
		if (s[i] != 'C'){
			dp[i] = dp[i-1];
			for (int j=i; j>=max(0, i-m); --j){
				if (s[j] == 'L'){
					dp[i] = min(dp[i], dp[j]);
				}
			}
			dp[i] += s[i]=='W';
		}
	}

	if (dp[n+1] <= k){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
