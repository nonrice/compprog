#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return ans;
}

constexpr long long M = 1000000007;

void solve(){
	long long n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	long long s = 0;
	long long p = 0;
	for (int i=0; i<n; ++i){
		s = (s + p*a[i]%M) % M;
		p = (p + a[i]) % M;
	}


	cout << s * binpow(n*(n-1)/2 % M, M-2, M) % M << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
