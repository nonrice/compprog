#include <bits/stdc++.h>
using namespace std;

struct query {
	int d, i;

	bool operator<(const query& o) const {
		return d<o.d;
	}
};

int a[100001], b[100001];
query qs[100000];
long long ans[100000];

void solve(){
	int n, k, q; cin >> n >> k >> q;
	
	for (int i=1; i<=k; ++i){
		cin >> a[i];
	}
	for (int i=1; i<=k; ++i){
		cin >> b[i];
	}
	for (int i=0; i<q; ++i){
		qs[i].i = i;
		cin >> qs[i].d;
	}

	sort(qs, qs+q);
	int j=0;
	for (int i=1; i<=k; ++i){
		while (qs[j].d <= a[i] && j<q){
			ans[qs[j].i] =  b[i-1] + 1LL * (b[i]-b[i-1]) * (qs[j].d-a[i-1]) / (a[i]-a[i-1]);
			++j;
		}
	}

	for (int i=0; i<q; ++i){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
