#include <bits/stdc++.h>
using namespace std;

char a[101];

void solve(){
	int n; cin >> n;
	cin >> a;

	int cur = 0;
	char ch = a[0];
	int mx = 0;
	for (int i=0; i<n; ++i){
		if (a[i] == ch) ++cur;
		else {
			ch = a[i];
			cur = 1;
		}

		mx = max(mx, cur);
	}

	cout << mx+1 << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
