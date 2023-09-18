#include <bits/stdc++.h>
using namespace std;

struct query {
	int l, r, i;
};

long long a[200001];
query qs[200000];
long long ans[200000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n, q; cin >> n >> q;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=0; i<q; ++i){
		cin >> qs[i].l >> qs[i].r;
		qs[i].i = i;
	}

	// --- Mo's algorithm ---
	const int B = n/sqrt(q);
	sort(qs, qs+q, [=](const query& a, const query& b){
		if (a.l/B != b.l/B) return a.l/B < b.l/B;
		return a.r < b.r;
	});
	// ----------------------

	long long cur = a[1];
	int l=1, r=1;
	for (int i=0; i<q; ++i){
		for (; l<qs[i].l; ++l) cur -= a[l];
		for (; l>qs[i].l; --l) cur += a[l-1];
		for (; r<qs[i].r; ++r) cur += a[r+1];
		for (; r>qs[i].r; --r) cur -= a[r];
		
		ans[qs[i].i] = cur;
	}

	for (int i=0; i<q; ++i) cout << ans[i] << '\n';
}
