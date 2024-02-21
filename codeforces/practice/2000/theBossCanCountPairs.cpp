#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int a[200000];
map<int, map<int, int>> m;

int cnt(int x, int y){
	if (m.find(x) == m.end() || m.find(y) == m.end()){
		return 0;
	}
	if (m[x].size() > m[y].size()){
		swap(x, y);
	}

	int ans = 0;
	for (auto [k, v] : m[x]){
		if (x == y && x*y-k < k){
			break;
		}
		if (x == y && k+k == x*y){
			ans += v*(v-1)/2;
		} else {
			auto it = m[y].find(x*y-k);
			if (it != m[y].end()){
				ans += m[y][x*y-k] * v;
			}
		}
	}

	return ans;
}

void solve(){
	m.clear();

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	for (int i=0; i<n; ++i){
		int b_i; cin >> b_i;
		++m[a[i]][b_i];
	}

	long long ans = 0;
	for (int e=2; e<=2*n; ++e){
		for (int f=1; f*f<=e; ++f){
			if (e%f == 0){
				ans += cnt(f, e/f);
			}
		}
	}
	
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
