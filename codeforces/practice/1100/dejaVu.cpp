#include <bits/stdc++.h>
using namespace std;

int a[100000], x[30];
bool h[31];

void solve(){
	memset(h, false, 31);

	int n, q; cin >> n >> q;

	for (int i=0; i<n; ++i) cin >> a[i];
	int e = 0;
	for (int i=0; i<q; ++i){
		int v; cin >> v;
		if (!h[v]){
			h[v] = true;
			x[e++] = v;
		}
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<e; ++j){
			if (a[i] % (1<<x[j]) == 0){
				a[i] += (1<<(x[j]-1));
			}
		}
	}

	for (int i=0; i<n; ++i) cout << a[i] << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
