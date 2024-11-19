#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;

	int ans = 0;
	for (int i=0; i<n; ++i){
		int a, b; cin >> a >> b;

		if (a - b > 0) ++ans;
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
