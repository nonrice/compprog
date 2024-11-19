#include <bits/stdc++.h>
using namespace std;

int a[100];
int dp[100][101];
int c[100][100];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	for (int i=0; i<n; ++i){
		c[i][i] = (a[i] != 0);
		for (int j=i+1; j<n; ++j){
			c[i][j] = c[i][j-1] + (a[j] != j-i);
		}
	}
	for (int i=0; i<n; ++i){
		dp[i][1] = c[0][i];
		for (int k=2; k<=i+1; ++k){
			dp[i][k] = INT_MAX;
			for (int j=k-2; j<i; ++j){
				dp[i][k] = min(dp[i][k], dp[j][k-1] + c[j+1][i]);
			}
		}
	}

	for (int i=1; i<=n; ++i){
		cout << dp[n-1][i] << '\n';
	}
}
