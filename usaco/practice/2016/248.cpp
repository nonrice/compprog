#include <bits/stdc++.h>
using namespace std;

int dp[248][248];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> dp[i][i];

	int ans = 0;
	for (int s=1; s<n; ++s){
		for (int i=0; i+s<n; ++i){
			dp[i][i+s] = -1;
			for (int m=i; m<i+s; ++m){
				if (dp[i][m] != -1 && dp[i][m] == dp[m+1][i+s]){
					dp[i][i+s] = max(dp[i][i+s], dp[i][m]+1);
				}
			}
			ans = max(ans, dp[i][i+s]);
		}
	}

	cout << ans << '\n';
}
