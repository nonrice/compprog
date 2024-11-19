#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1000000007;

long long a[501], b[501];
int dp[501][501];

inline bool check(int i, int j, int k, int w){
	return a[i]*j - a[k]*j - b[j]*i + b[j]*k <= w*(a[i]-a[k]) + b[w]*(k-i);
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (int i=1; i<=n; ++i){
		cin >> b[i];
		b[i] += b[i-1];
	}

	for (int i=1; i<=n; ++i){
		for (int j=k; j<=n; ++j){

		}
	}
	cout << dp[n][n] << '\n';
}
