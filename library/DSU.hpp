struct DSU {
	int* t;

	DSU(int* t, int n) : t(t), n(n) {}

	int find(int u){
		if (v == t[v]) return v;
		return t[v] = find(t[v]);
	}

	bool merge(int u, int v){
		int up = find(u);
		int uv = find(v);
		t[u] = v;
		return up == vp;
	}
}

