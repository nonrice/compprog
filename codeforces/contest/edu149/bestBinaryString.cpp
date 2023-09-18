#include <bits/stdc++.h>
using namespace std;

char a[300001];

void solve(){
	cin >> a;
	const int n = strlen(a);

	if (count(a, a+n, '?') == n){
		for (int i=0; i<n; ++i) cout << '0';
		cout << '\n';
		return;
	}

	int l = 0;
	for (; l<n; ++l) if (a[l] != '?') break;
	int r = n-1;
	for (; r>=0; --r) if (a[r] != '?') break;

	memset(a, a[l], l);
	memset(a+r+1, a[r], n-r-1);

	for (int i=max(1, l); i<=r; ++i){
		if (a[i] == '?') a[i] = a[i-1];
	}

	cout << a << '\n';

}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
