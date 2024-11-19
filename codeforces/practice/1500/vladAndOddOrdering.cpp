#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n, k; cin >> n >> k;

	for (long long p=1; p<=n; p*=2){
		if ((n - n/p) < k && (n - n/(p*2)) >= k){
			cout << (2*(k-(n - n/p))-1)*p << '\n';
			return;
		}
	}
	cout << "-1\n"e
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
