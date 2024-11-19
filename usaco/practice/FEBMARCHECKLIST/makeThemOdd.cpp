#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	set<int, greater<int>> s;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		s.insert(x);
	}

	int ans = 0;
	while (!s.empty()){
		int x = *s.begin();
		s.erase(s.begin());
		if (x&1){
			continue;
		}
		s.insert(x/2);
		++ans;
	}
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
