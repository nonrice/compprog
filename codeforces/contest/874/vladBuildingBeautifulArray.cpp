#include <bits/stdc++.h>
using namespace std;

int a[200000];

void solve(){
	int n; cin >> n;

	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	sort(a, a+n);
	bool o = false;
	for (int i=0; i<n; ++i){
		if (a[i]%2 != a[0]%2){
			if (!o){
				cout << "NO\n";
				return;
			}
		}
		if (a[i]%2 == 1) o = true;
	}

	cout << "YES\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
