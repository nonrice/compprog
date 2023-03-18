struct DSU {
	int* p;

	DSU(int* p, int sz){
		this->p = p;
		while (sz--) p[sz] = sz;
	}
	
	int find(int v){
		if (v == p[v]) return v;
		return p[v] = find(p[v]);
	}

	bool merge(int u, int v){
		int up = find(u);
		int vp = find(v);
		p[up] = vp;
		return up == vp;
	}
};

