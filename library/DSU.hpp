struct DSU {
	vector<int> t;
	vector<int> sz;

	// construct DSU for vertices [0, n-1]
	DSU(int n){
		t = vector<int>(n);
		sz = vector<int>(n, 1);
		iota(t.begin(), t.end(), 0);
	}

	// get representative for vertice u
	int find(int u){
		if (u == t[u]) return u;
		return t[u] = find(t[u]);
	}

	// merge components of u and v, return false if they were not merged prior
	bool merge(int u, int v){
		int pu = find(u);
		int pv = find(v);
		if (pu != pv){
			if (sz[pu] < sz[pv]){
				swap(pu, pv);
			}
			t[pv] = pu;
			sz[pu] += sz[pv];
		}
		return pu == pv;
	}
};

