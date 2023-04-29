#include <bits/stdc++.h>
using namespace std;

map<int, int> fs;

void solve(){
	fs.clear();

	int n; cin >> n;

	while (n--){
		int x; cin >> x;

		for (int d = 2; d * d <= x; d++) {
			while (x % d == 0) {
				++fs[d];
				x /= d;
			}
		}
		if (x > 1) ++fs[x];
	}

	int rm = 0;
	int ans = 0;
	for (auto [f, cnt] : fs){
		ans += cnt/2;
		rm += cnt%2;
	}
	ans += rm/3;

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
