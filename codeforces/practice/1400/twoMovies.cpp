#include <bits/stdc++.h>
using namespace std;

int a[200000], b[200000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	for (int i=0; i<n; ++i){
		cin >> b[i];
	}

	int l=0, r=0, u=0, v=0;
	for (int i=0; i<n; ++i){
		if (a[i] == 1 && b[i] == 1){
			++u;
		} else if (a[i] == -1 && b[i] == -1){
			++v;
		} else if (a[i] == 1) {
			++l;
		} else if (b[i] == 1){
			++r;
		}
	}

	while (u){
		if (l > r){
			swap(l, r);
		}
		--u;
		++l;
	}
	while (v){
		if (l < r){
			swap(l, r);
		}
		--v;
		--l;
	}

	cout << min(l, r) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
