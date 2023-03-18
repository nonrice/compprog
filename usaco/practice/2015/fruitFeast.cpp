#include <bits/stdc++.h>
using namespace std;

bool dp[5000001][2] = { { 1 } };

int main(){
#ifndef LOCAL
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
#endif

	int t, a, b; cin >> t >> a >> b;

	for (int i=0; i<=t; ++i){
		if (i>=a) dp[i][0] |= dp[i-a][0];
		if (i>=b) dp[i][0] |= dp[i-b][0];
		if (dp[i][0]) dp[i/2][1] = true;
	}

	int ans = 0;
	for (int i=0; i<=t; ++i){
		if (i>=a) dp[i][1] |= dp[i-a][0] || dp[i-a][1];
		if (i>=b) dp[i][1] |= dp[i-b][0] || dp[i-b][1];
		if (dp[i][1] || dp[i][0]) ans = i;
	}

	cout << ans << '\n';
}
