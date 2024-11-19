#include <bits/stdc++.h>
using namespace std;

char s[200001];

void solve(){
	int n, m; cin >> n >> m;
	cin >> s;
	
	vector<int> e({ -1 });
	for (int i=1; i<n; ++i){
		if (s[i] != s[i-1]) e.push_back(i-1);
	}
	e.push_back(n-1);
	e.push_back(n);

	set<pair<int, int>> u;
	for (int i=0; i<m; ++i){
		int l, r; cin >> l >> r; --l; --r;
		
		auto sl = lower_bound(e.begin(), e.end(), l);
		auto sr = lower_bound(e.begin(), e.end(), r);
		if (s[l] == '0') ++sl;
		if (s[r] == '1') --sr;

		if (sl < sr){
			u.emplace( s[l]=='0' ? *(--sl)+1 : l, s[r]=='1' ? *sr : r);
		} else {
			u.emplace( -1, -1 );
		}
	}

	//for (auto [x, y] : u) cout << x << ' ' << y << '\n';

	cout << u.size() << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
