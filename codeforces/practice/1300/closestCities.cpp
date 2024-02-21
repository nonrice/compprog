#include <bits/stdc++.h>
using namespace std;

int a[100000];
int l[100000], r[100000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	l[0] = 0;
	for (int i=1; i<n; ++i){
		l[i] = l[i-1];
		if (i != n-1 && a[i+1]-a[i] < a[i]-a[i-1]){
			l[i] = i;
		}
	}
	r[n-1] = n-1;
	for (int i=n-2; i>=0; --i){
		r[i] = r[i+1];
		if (i != 0 && a[i]-a[i-1] < a[i+1]-a[i]){
			r[i] = i;
		}
	}

	for (int i=0; i<n; ++i) cout << l[i] << ' ';
	cout << '\n';
	for (int i=0; i<n; ++i) cout << r[i] << ' ';
	cout << '\n';

	int q; cin >> q;
	while (q--){
		int u, v; cin >> u >> v; --u, --v;
		if (v > u){
			cout << max(0, a[v]-a[r[u]]) + min(v-u, r[u] - u) << '\n';
		} else {
			cout << max(0, a[l[u]]-a[v]) + min(u-v, u - l[u]) << '\n';
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
