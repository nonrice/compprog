#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x, k; cin >> x >> k;

	if (x%k != 0){
		cout << "1\n" << x << '\n';
		return;
	} else {
		for (int i=1; i<x; ++i){
			if (i%k != 0 && (x-i)%k != 0){
				cout << "2\n" << i << ' ' << x-i << '\n';
				return;
			}
		}
	}
	
	assert(1 == 2);
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
