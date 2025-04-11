template<typename T, T (*F)(T, T), T D = T{}>
struct segtree {
    int n;
    vector<T> t;

    segtree(int n) : n(n){
        t = vector<T>(2*n, D);
    }

    segtree(vector<T>& a) : n(a.size()){
        t = vector<T>(2*n);
        copy(a.begin(), a.end(), t.begin()+n);
        for (int i=n-1; i>=0; --i){
            t[i] = F(t[i*2], t[i*2+1]);
        }
    }

    void set(int i, T v){
        i += n;
        t[i] = v;
        while (i/2 > 0){
            t[i/2] = F(t[i], t[i^1]);
            i /= 2;
        }
    }
    
    // query [l, r)
    T query(int l, int r){
        T ans = D;
        l += n;
        r += n;
        while (l < r){
            if (l&1){
                ans = F(ans, t[l]);
                ++l;
            }
            if (r&1){
                --r;
                ans = F(ans, t[r]);
            }
            l /= 2;
            r /= 2;
        }

        return ans;
    }
};

