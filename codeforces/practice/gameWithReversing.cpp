#include <bits/stdc++.h>
using namespace std;

char a[100001], b[100001];

void solve(){
	int n; cin >> n;
	cin >> a >> b;

	int d = 0;
	for (int i=0; i<n; ++i) d += (a[i] != b[i]);

	reverse(a, a+n);
	int dr = 0;
	for (int i=0; i<n; ++i) dr += (a[i] != b[i]);
	
	if (d <= 1){
		cout << d << '\n';
		return;
	}

	if (dr == 0){
		cout << "2\n";
		return;
	}

	cout << min(2*d-1 + !(d%2), 2*dr-1 + dr%2) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
