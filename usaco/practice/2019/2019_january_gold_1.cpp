#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

// Binary Exponentation
// binpow: Computes a^b (mod m) in O(log(b)).

long long binpow(long long a, long long b, long long m=M){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return ans;
}

int s[5000], c[5000];
set<int> C;
long long dp[5001];
long long g[5001];
map<char, long long> sz;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
#endif

	int n, m, k; cin >> n >> m >> k;
	for (int i=0; i<n; ++i){
		cin >> s[i] >> c[i];
		C.insert(c[i]);
	}
	
	dp[0] = 1;
	for (int i=1; i<=k; ++i){
		for (int j=0; j<n; ++j){
			if (i - s[j] >= 0){
				dp[i] = (dp[i] + dp[i-s[j]]) % M;
			}
		}
	}

	// w[i] = dp[k-s[i]]
	for (int j=0; j<n; ++j){
		g[c[j]] = (g[c[j]] + dp[k-s[j]]) % M;
	}

	for (int i=0; i<m; ++i){
		char e; cin >> e;
		++sz[e];
	}

	long long ans = 1;
	for (auto [e, l] : sz){
		long long cur = 0;
		for (auto j : C){
			cur = (cur + binpow(g[j], l)) % M;
		}
		ans = ans*cur % M;
	}

	cout << ans << '\n';
}

