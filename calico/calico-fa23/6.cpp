#include <bits/stdc++.h>
using namespace std;

long long dp(long long n, long long k){
	if (k%2 == 0) return k/2;
	if (n==1 && k==1) return 1;
	if (k > 1) return dp(n - k/2, 1) + k/2;
	return 1 + dp(n-1, n-1);
}

void solve(){
	long long n, k; cin >> n >> k;
	cout << dp(n, k) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
