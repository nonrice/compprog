#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

void solve(){
	string s; cin >> s;
	const int n = s.size();
	map<int, vector<int>> p;
	int b = 0;
	long long ans = 0;
	for (int i=0; i<n; ++i){
		if (s[i] == '1'){
			++b;
		} else {
			--b;
		}
		p[b].push_back(i+1);
		if (b == 0){
			ans += n-i;
		}
	}

	for (auto& [k, a] : p){

		long long r = ((n+1)*a.size()%M + M - accumulate(a.begin(), a.end(), 0LL)%M) % M;
		for (int i=0; i<a.size(); ++i){
			r = (r + M - (n+1-a[i])) % M;
			ans = (ans + (a[i]+1)*r%M) % M;
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
