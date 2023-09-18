#include <bits/stdc++.h>
using namespace std;

struct segment {
	int l, r;
};

int n, m, k;
int p[100001], q[100000];
segment a[100000];

bool check(int x){
	memset(p, 0, (n+1)*sizeof(int));
	for (int i=0; i<=x; ++i) p[q[i]] = 1;
	for (int i=1; i<=n; ++i) p[i] += p[i-1];
	for (int i=0; i<m; ++i){
		if (2 * (p[a[i].r] - p[a[i].l-1]) > a[i].r-a[i].l+1) return true;
	}
	return false;
}

void solve(){
	cin >> n >> m;
	for (int i=0; i<m; ++i) cin >> a[i].l >> a[i].r;
	cin >> k;
	for (int i=0; i<k; ++i) cin >> q[i];

	int cur = k-1;
	if (!check(cur)){
		cout << "-1\n";
		return;
	}

	for (int step=k-1; step>=1; step/=2){
		while (check(cur - step)) cur -= step;
	}

	cout << cur+1 << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
