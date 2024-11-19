#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<pair<int, int>> s(n);
	for (int i=0; i<n; ++i) cin >> s[i].second;
	for (int i=0; i<n; ++i){
		cin >> s[i].first;
		s[i].first = s[i].second - s[i].first + 1;
	}

	sort(s.begin(), s.end());
	long long ans = 1;
	int p = s[0].first;
	int b = s[0].first;
	for (auto [l, r] : s){
		if (l > p){
			b = p = l;
			++ans;
		}
		if (p < r){
			ans += 1LL*(r-p)*(p-b+2+r-b+1)/2;
		}
		p = max(p, r);
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
