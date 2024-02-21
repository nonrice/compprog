#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int a[1001], b[1001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for (int i=1; i<=n; ++i){
		cin >> b[i];
	}

	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (abs(a[i]-b[j]) <= 4){
				dp[i][j] = dp[i-1][j-1]+1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	cout << dp[n][n] << '\n';
}
