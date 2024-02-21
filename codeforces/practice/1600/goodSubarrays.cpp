#include <bits/stdc++.h>
using namespace std;

map<int, int> f;

void solve(){
	f.clear();
	f[0] = 1;

	int n; cin >> n;
	int p = 0;
	long long ans = 0;
	for (int i=0; i<n; ++i){
		char x; cin >> x;
		p += x - '1';
		ans += f[p];
		++f[p];
	}
	
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
