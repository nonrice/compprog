#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 3359232;
// REQUIRES: M

long long binpow(long long a, long long b){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return ans;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		long long n; cin >> n;
		cout << binpow(2, 1+n/3)-2 << '\n';
	}
}
