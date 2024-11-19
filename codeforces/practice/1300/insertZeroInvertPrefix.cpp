#include <bits/stdc++.h>
using namespace std;

int a[100000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	if (a[n-1] == 1){
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	int c = 0;
	for (int i=n-1; i>=0; --i){
		if (a[i] == 0){
			cout << "0 ";
			c = 0;
		} else {
			++c;
			if (i == 0 || a[i-1] == 0){
				cout << c << ' ';
			} else {
				cout << "0 ";
			}
		}
	}

	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
