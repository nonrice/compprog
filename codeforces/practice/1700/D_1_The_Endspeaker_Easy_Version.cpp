#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
	int n, m; cin >> n >> m;		
	vector<int> a(n), b(m);
	for (auto& v : a){
		cin >> v;
	}
	for (auto& v : b){
		cin >> v;
	}

	vector<vector<long long>> dp(n+1, vector<long long>(m));

	vector<long long> p(n+1);
	for (int i=0; i<n; ++i){
		p[i+1] = p[i] + a[i];
	}

	for (int i=n-1; i>=0; --i){
		for (int k=m-1; k>=0; --k){
			dp[i][k] = (k==m-1) ? LLONG_MAX : dp[i][k+1];

			int j = i-1;
			for (int s=n-i; s>=1; s/=2){
				while (j+s<n && p[j+s+1]-p[i] <= b[k] && dp[j+s+1][k] != LLONG_MAX){
					j += s;
				}
			}

			if (j != i-1){
				dp[i][k] = min(dp[i][k], dp[j+1][k] + m - (k+1));
			}
		}
	}

	debug(dp);

	if (dp[0][0] == LLONG_MAX){
		cout << "-1\n";
	} else {
		cout << dp[0][0] << '\n';
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}