#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	string s, t; cin >> s >> t;

	int ans = max(0, (int)(count(s.begin(), s.end(), '1') - count(t.begin(), t.end(),'1')));
	for (int i=0; i<n; ++i){
		if (t[i] == '1' && s[i] == '0') ++ans;
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
