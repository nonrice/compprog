#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
int p[1000000];

bool test(int l){
	memset(p, 0, sizeof(int)*a[0].size());

	for (int i=0; i<a.size(); ++i){
		int suf = 0;
		for (int j=0; j<a[i].size(); ++j){
			if (a[i][j] >= l){
				++suf;
			} else {
				suf = 0;
			}

			if (suf >= l){
				++p[j];
				if (p[j] == l) return true;
			} else {
				p[j] = 0;
			}
		}
	}

	return false;
}

void solve(){
	int n, m; cin >> n >> m;
	
	a = vector<vector<int>>(n, vector<int>(m));
	for (auto& r : a){
		for (auto& v : r) cin >> v;
	}

	int ans = 0;
	for (int step=1000000; step>=1; step/=2){
		while (test(ans+step)){
			ans += step;
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}

