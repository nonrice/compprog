struct SegTree {
    vector<int> t;
    int n;
    
    SegTree(vector<int>& a){
        n = a.size();
        t = vector<int>(n*2);
        for (int i=n*2-1; i>=0; --i){
            t[i] = (i >= n) ? a[i-n] : t[i*2]+t[i*2+1];
        }
    }

    void modify(int i, int v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = t[i] + t[i^1];
        }
    }

    int query(int l, int r){
        int total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total += t[l++];
            if (r%2) total += t[--r];
        }
        return total;
    }
};

