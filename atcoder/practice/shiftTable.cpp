#include <bits/stdc++.h>
using namespace std;

constexpr int M = 998244353;

long long binpow(long long a, long long b){
	long long ans = 1;
	while (b){
		if (b & 1) ans = ans*a % M;
		a = a*a % M;
		b >>= 1;
	}

	return ans;
}

char s[100001];
bool a[100000];
bool b[100000];
map<int, long long> c;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	cin >> s;
	for (int i=0; i<n; ++i) a[i] = (s[i] == '#');

	long long ans = 0;
	for (int m=1; m<n; ++m){
		if (n % m == 0){
			memcpy(b, a, m);
			for (int i=m; i<n; ++i) b[i%m] &= a[i];
			c[m] = binpow(2, count(b, b+m, true));
			ans = (ans + c[m]) % M;
		}
	}

	for (auto& [m, u] : c){
		for (auto [d, v] : c){
			if (d == m) break;
			if (m % d == 0){
				ans = (ans-v+M) % M;
				u = (u-v+M) % M;
			}
		}
	}

	cout << ans << '\n';
}
