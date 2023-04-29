#include <bits/stdc++.h>
using namespace std;

void solve(){
	int q; cin >> q;

	long long mx=LLONG_MAX, mn=0;
	while (q--){
		int t; cin >> t;
		long long a, b; cin >> a >> b;
		if (t == 1){
			int n; cin >> n;
			long long cmn = a*(n-1)-b*(n-2)+1, cmx = a*n-b*(n-1);
			if (n == 1) cmn = 1;
			if ((cmn >= mn && cmn <= mx) || (cmx >= mn && cmn <= mx)){
				mn = max(cmn, mn);
				mx = min(cmx, mx);
				cout << "1 ";
			} else {
				cout << "0 ";
			}
		} else {
			long long e = max(1LL, (mx-b + (a-b-1))/(a-b));
			if ((e == 1 ? 0 : a*(e-1)-b*(e-2)) >= mn){
				cout << "-1 ";
			} else {
				cout << e << ' ';
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
