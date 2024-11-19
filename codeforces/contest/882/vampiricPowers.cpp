#include <bits/stdc++.h>
using namespace std;

bool p[257] = { true };

void solve(){
	memset(p+1, false, 256);

	int n; cin >> n;
	int cp = 0;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		cp = (cp ^ x);
		p[cp] = true;
	}

	int ans = 0;
	for (int i=0; i<=256; ++i){
		for (int j=0; j<i; ++j){
			if (p[i] && p[j]) ans = max(ans, (i ^ j));
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
