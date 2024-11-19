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

struct polyhash {
	long long m, b;
	vector<long long> p;
	
	polyhash(const string& s, long long m, long long b) : m(m), b(b) {
		p = vector<long long>(s.size()+1);
		long long bp = 1;
		for (size_t i=1; i<=s.size(); ++i){
			p[i] = (p[i-1] + (s[i-1]-'a') * bp % m) % m;
			bp = bp*b % m;
		}
	}

	long long substr(int l, int r){
		return ((p[r] - p[l] + m) % m) * binpow(binpow(b, l, m), m-2, m) % m;
	}
};

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	string s; cin >> s;
	const int n = s.size();
	polyhash p = polyhash(s, 1000003967, 29);
	for (int i=n/2 + 1; i<n; ++i){
		if (p.substr(0, i) == p.substr(n-i, n)){
			cout << "YES\n" << s.substr(0, i) << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}
