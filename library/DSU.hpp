struct DSU {
    vector<int> p;

    DSU(int sz){
        p = vector<int>(sz);
        while (sz--) p[sz] = sz;
    }
    
    int find(int v){
        if (v == p[v]) return v;
        return p[v] = find(p[v]);
    }

    void merge(int u, int v){
        p[find(u)] = find(v);
    }
};

