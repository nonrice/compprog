#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;

	bool done = false;
	for (int i=0; i<n; ++i){
		if (!done){
			cout << 2*min(k, n-i) - 1 << ' ';
			k = max(0, k-(n-i));
			if (k == 0) done = true;
		} else {
			cout << "-2 ";
		}
	}

	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
