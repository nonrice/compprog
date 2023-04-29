#include <bits/stdc++.h>
using namespace std;

long long a[200000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	sort(a, a+n);
	if (a[0] != 1){
		cout << "NO\n";
		return;
	}
	long long s = 1;
	for (int i=1; i<n; ++i){
		if (s < a[i]){
			cout << "NO\n";
			return;
		}
		s += a[i];
	}

	cout << "YES\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
