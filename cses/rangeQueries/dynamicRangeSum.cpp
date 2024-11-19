#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree {
    vector<T> t;
    int n;
    
    SegTree(vector<T>& a){
        n = a.size();
        t = vector<T>(n*2);
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

int main(){
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for (long long& v : a) cin >> v;

    SegTree<long long> st(a);
    while (q--){
        int t, a, b; cin >> t >> a >> b;
        if (t == 1){
            st.modify(--a, b);
        } else {
            cout << st.query(--a, b) << '\n';
        }
    }
}

