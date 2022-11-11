template <typename T>
struct SegTree {
    T* t;
    int n;
    
    SegTree(T* a, int n){
        this->n = n;
        t = a;
        for (int i=n*2-1; i>=0; --i){
            if (i >= n) t[i] = a[i-n];
            else t[i] = comb(t[i*2], t[i*2+1]);
        }
    }

    void set(int i, T v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = comb(t[i] + t[i^1]);
        }
    }

    T query(int l, int r){
        T total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total = comb(total, t[l++]);
            if (r%2) total = comb(total, t[--r]);
        }
        return total;
    }

    T comb(T a, T b){
        return a+b;
    }
};

