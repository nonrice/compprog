#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const ull MOD = 1000000007;

ull binpow(ull x, ull n){
	ull ans = 1;
	while (n){
		if (n&1) ans = ans*x % MOD;
		x = x*x % MOD;
		n >>= 1;
	}
	return ans;
}

ull fact(ull n){
	ull ans = 1;
	for (ull f=2; f<=n; ++f) ans = ans*f % MOD;
	return ans;
}

int f[26];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	char ch;
	ull ans = 1;
	int n = 1;
	while ((ch = getchar_unlocked()) != '\n'){
		ans = ans*(n++) % MOD;
		++f[ch-'a'];
	}

	for (int i=0; i<26; ++i) ans = ans * binpow(fact(f[i]), MOD-2) % MOD;

	cout << ans << '\n';
}
