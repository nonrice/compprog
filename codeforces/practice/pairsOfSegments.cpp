#include <bits/stdc++.h>
using namespace std;

struct segment {
	int l, r;

	bool operator<(const segment& o) const {
		return r < o.r;
	}
};

segment a[2000];
segment p[2000*1999];

void solve(){
	int n; cin >> n;

	for (int i=0; i<n; ++i) cin >> a[i].l >> a[i].r;

	int nxt = 0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			if (i != j && max(a[i].l, a[j].l) <= min(a[i].r, a[j].r)){
				p[nxt].l = min(a[i].l, a[j].l);
				p[nxt++].r = max(a[i].r, a[j].r);
			}
		}
	}

	sort(p, p+nxt);
	int end = -1;
	int cnt = 0;
	for (int i=0; i<nxt; ++i){
		if (p[i].l > end){
			cnt += 2;
			end = p[i].r;
		}
	}

	cout << n-cnt << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}


