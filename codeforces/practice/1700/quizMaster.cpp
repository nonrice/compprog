#include <bits/stdc++.h>
using namespace std;

int a[100000];
vector<int> fs[100000];
int pro[100001];

void solve(){
	int n, m; cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);

	for (int i=0; i<n; ++i){
		fs[i].clear();
		for (int f=1; f*f<=a[i] && f<=m; ++f){
			if (a[i]%f == 0){
				fs[i].push_back(f);
				if (f*f != a[i] && a[i]/f<=m) fs[i].push_back(a[i]/f);
			}
		}
	}

	memset(pro, 0, (m+1)*sizeof(int));
	int k = 0;
	int r = 0;
	bool ok = false;
	for (; r<n; ++r){
		for (auto t : fs[r]){
			if (pro[t]++ == 0){
				++k;
				if (k == m) ok = true;
			}
		}
		if (ok) break;
	}
	
	if (!ok){
		cout << "-1\n";
		return;
	}

	int ans = a[r]-a[0];
	for (int l=1; l<n; ++l){
		for (auto t : fs[l-1]){
			if (--pro[t] == 0) --k;
		}

		while (k < m){
			++r;
			if (r == n) goto done;
			for (auto t : fs[r]){
				if (pro[t]++ == 0) ++k;
			}
		}

		ans = min(ans, a[r]-a[l]);
	}

done:
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
