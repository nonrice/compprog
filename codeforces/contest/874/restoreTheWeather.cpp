#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100000];
multiset<int> b;
int ans[100000];

void solve(){
	b.clear();

	int n, k; cin >> n >> k;
	for (int i=0; i<n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n);
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		b.insert(x);
	}

	for (int i=0; i<n; ++i){
		auto it = b.lower_bound(a[i].first-k);
		a[i].first = *it;
		b.erase(it);
	}

	for (int i=0; i<n; ++i){
		ans[a[i].second] = a[i].first;
	}

	for (int i=0; i<n; ++i) cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
