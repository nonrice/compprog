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
		// combine operation here
	}
};

