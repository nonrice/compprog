#include <bits/stdc++.h>
using namespace std;

#define int long long

struct participant {
	int s, p, i;

	bool operator<(const participant& o) const {
		if (s != o.s) return s > o.s;
		if (p != o.p) return p < o.p;
		return i < o.i;
	}
};

void solve(){
	int m, n, h; cin >> m >> n >> h;

	vector<vector<int>> a(m, vector<int>(n));

	for (int i=0; i<m; ++i){
		for (int j=0; j<n; ++j){
			cin >> a[i][j];
		}
		sort(a[i].begin(), a[i].end());
	}

	vector<participant> perf(m);
	for (int i=0; i<m; ++i){
		perf[i].i = i+1;
	}
	for (int i=0; i<m; ++i){
		int t = 0;
		for (int j=0; j<n; ++j){
			if (t + a[i][j] <= h){
				++perf[i].s;
				t += a[i][j];
				perf[i].p += t;
			}
		}
	}

	sort(perf.begin(), perf.end());

	for (int i=0; i<m; ++i){
		if (perf[i].i == 1){
			cout << (i+1) <<  '\n';
			return;
		}
	}
}

int32_t main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
