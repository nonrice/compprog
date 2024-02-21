#include <bits/stdc++.h>
using namespace std;

map<int, long long> p;

void solve(){
	p.clear();

	int n; cin >> n;
	long long ans = 0;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		ans += (n-i)*p[x];
		p[x] += i+1;
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
