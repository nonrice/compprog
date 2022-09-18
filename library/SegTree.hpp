template <typename T>
struct SegTree {
    const vector<T>& t;
    int n;
    
    SegTree(vector<T>& a) : t(a){
        n = a.size()/2;
        for (int i=n*2-1; i>=0; --i){
            t[i] = (i >= n) ? a[i-n] : t[i*2]+t[i*2+1];
        }
    }

    void modify(int i, T v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = t[i] + t[i^1];
        }
    }

    T query(int l, int r){
        T total = 0;
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) total += t[l++];
            if (r%2) total += t[--r];
        }
        return total;
    }
};

