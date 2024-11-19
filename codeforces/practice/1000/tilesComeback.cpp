#include <bits/stdc++.h>
using namespace std;

int a[200000];

void solve(){
	int n, k; cin >> n >> k;
	for (int i=0; i<n; ++i) cin >> a[i];

	int x=0, y=count(a, a+n, a[n-1]);
	for (int i=0; i<n; ++i){
		if (a[i] == a[0]) ++x;
		else if (a[i] == a[n-1]) --y;

		if (x>=k && y>=k){
			cout << "YES\n";
			return;
		}
	}
	
	cout << "NO\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
