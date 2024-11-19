#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int d[26][26];
char s[100002];
int dp[51][26], dp1[51][26];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("cowmbat.in", "r", stdin);
	freopen("cowmbat.out", "w", stdout);
#endif

	int n, m, k; cin >> n >> m >> k;
	cin >> (s+1);
	for (int i=0; i<m; ++i){
		for (int j=0; j<m; ++j){
			cin >> d[i][j];
		}
	}

	for (int k=0; k<m; ++k){
		for (int i=0; i<m; ++i){
			for (int j=0; j<m; ++j){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	/*
	for (int i=0; i<m; ++i){
		for (int j=0; j<m; ++j) cout << d[i][j] << ' ';
		cout << '\n';
	}
	*/

	for (int i=1; i<=n; ++i){
		for (int j=1; j<=k; ++j){
			for (int l=0; l<m; ++l){
				dp[j][l] = INT_MAX;
				if (j <= i){
					if (j == k){
						dp[k][l] = min(dp1[k-1][l], dp1[k][l]);
					} else if (j == 1) {
						for (int c=0; c<m; ++c){
							if (c != l){
								dp[j][l] = min(dp[j][l], dp1[k][c]);
							}
						}
					} else {
						dp[j][l] = dp1[j-1][l];
					}

					if (dp[j][l] != INT_MAX){
						dp[j][l] += d[s[i]-'a'][l];
					}
				}
			}
		}
		swap(dp, dp1);
	}

	int ans = INT_MAX;
	for (int i=0; i<m; ++i) ans = min(ans, dp1[k][i]);

	cout << ans << '\n';
}
