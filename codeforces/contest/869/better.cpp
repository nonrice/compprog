#include <bits/stdc++.h>
using namespace std;

int a[200010], p[200010];
bool b[200010] = { true };

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	for (int i=0; i<n; ++i) cin >> a[i];

	for (int i=1; i<n; ++i){
		if (a[i] > a[i-1]){
			b[i] = true;
			b[i-1] = true;
		}
	}

	for (int i=1; i<=n; ++i){
		p[i] = p[i-1] + b[i-1];
	}

	while (q--){
		int l, r; cin >> l >> r;
		int inc = 0;
		if (b[r-1] == false) ++inc;
		if (b[l-1] == false) ++inc;
		if (inc == 2 && r == l) --inc;
		cout << p[r]-p[l-1]+inc << '\n';
	}
}
