#include <bits/stdc++.h>
using namespace std;

// Thanks, https://codeforces.com/blog/entry/18051

template <typename T>
struct SegTree {
	T* t;
	int n;

	// initial array belongs in t[n : 2*n]
	SegTree(T* t, int n) : t(t), n(n) { 
		for (int i = n - 1; i > 0; --i) t[i] = comb(t[i<<1], t[i<<1|1]);
	}

	void modify(int p, T value){
		for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = comb(t[p], t[p^1]);
	}

	T query(int l, int r){
		T res = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1){
			if (l&1) res = comb(res, t[l++]);
			if (r&1) res = comb(res, t[--r]);
		}
		return res;
	}

	inline T comb(T a, T b){
		return max(a, b);
	}
};


int a[200000], b[400000];
map<int, vector<int>> chg;
map<int, int> xf;

void solve(){
	chg.clear();
	xf.clear();

	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i) cin >> b[i+n];
	int m; cin >> m;
	for (int i=0; i<m; ++i){
		int xi; cin >> xi;
		++xf[xi];
	}

	for (int i=0; i<n; ++i){
		if (a[i] < b[i+n]){
			cout << "NO\n";
			return;
		}
		if (a[i] > b[i+n]) chg[b[i+n]].push_back(i);
	}

	SegTree st(b, n);
	for (auto& [x, p] : chg){
		sort(p.begin(), p.end());
		int razors = 1;
		for (int i=1; i<p.size(); ++i){
			if (st.query(p[i-1], p[i]) > x) ++razors;
		}
		if (razors > xf[x]){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
