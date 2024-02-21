#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;

	int p = 1;
	for (int i=0; i<n; ++i){
		int a; cin >> a;
		p *= a;
	}

	if (2023 % p){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	cout << 2023/p << ' ';
	for (int i=0; i<k-1; ++i) cout << 1 << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
