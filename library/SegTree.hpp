template <typename T>
struct SegTree {
    const vector<T>& t;
    int n;
    
    SegTree(vector<T>& a) : t(a){
        n = a.size()/2;
        for (int i=n*2-1; i>=0; --i){
            if (i >= n) t[i] = a[i-n];
            else t[i] = combine(t[i*2], t[i*2+1]);
        }
    }

    void modify(int i, T v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = combine(t[i] + t[i^1]);
        }
    }

    T query(int l, int r){
        T total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total = combine(total, t[l++]);
            if (r%2) total = combine(total, t[--r]);
        }
        return total;
    }

    T combine(T a, T b){
        return a+b;
    }
};

