#include <bits/stdc++.h>
using namespace std;

int b[200000];
bool vis[200000];

void solve(){
	int n, k; cin >> n >> k;
	memset(vis, 0, n);
	for (int i=0; i<n; ++i) cin >> b[i];

	int s = n-1;
	for (int i=0; i<min(n, k); ++i){
		if (b[s] > n){
			cout << "No\n";
			return;
		}
		vis[s] = true;
		s -= b[s];
		if (s < 0) s += n;
		if (vis[s]){
			cout << "Yes\n";
			return;
		}
	}

	cout << "Yes\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
