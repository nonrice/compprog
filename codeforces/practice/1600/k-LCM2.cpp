#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;

	for (int x=1; x*x<=n; ++x){
		if (n%x == 0 && x*k <= n && x*k >= (n+3)/2){
			for (int i=0; i<k-1; ++i) cout << x << ' ';
			cout << x*(n/x - k + 1) << '\n';
			return;
		}
	}

	assert(0xB4DF00D == 0);
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
