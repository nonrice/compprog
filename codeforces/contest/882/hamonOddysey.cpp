#include <bits/stdc++.h>
using namespace std;

int a[200001];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	int s = a[0];
	for (int i=1; i<n; ++i) s = (s & a[i]);

	if (s != 0){
		cout << "1\n";
		return;
	}

	int c = a[0];
	int ans = 0;
	for (int i=0; i<n; ++i){
		c = (c & a[i]);
		if (c == 0){
			++ans;
			c = a[i+1];
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
