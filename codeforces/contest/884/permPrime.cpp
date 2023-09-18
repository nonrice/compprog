#include <bits/stdc++.h>
using namespace std;

int ans[200000];

void solve(){
	int n; cin >> n;

	if (n == 1){
		cout << "1\n";
		return;
	} else if (n == 2){
		cout << "2 1\n";
		return;
	}

	ans[0] = 2;
	ans[1] = 1;
	ans[n-1] = 3;
	for (int i=2; i<n-1; ++i){
		ans[i] = i+2;
	}
	swap(ans[1], ans[n/2]);

	for (int i=0; i<n; ++i){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
