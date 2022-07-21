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
            t[i] = (i >= n) ? a[i-n] : min(t[i*2], t[i*2+1]);
        }
    }

    void modify(int i, T v){
        for (t[i+=n] = v; i>1; i/=2){
            t[i/2] = min(t[i], t[i^1]);
        }
    }

    T query(int l, int r){
        T mn = numeric_limits<T>::max();
        for (l+=n, r+=n; l<r; l/=2, r/=2){
            if (l%2) mn = min(mn, t[l++]);
            if (r%2) mn = min(mn, t[--r]);
        }
        return mn;
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    SegTree<int> st(a);
    while (q--){
        int t, a, b; cin >> t >> a >> b;
        if (t == 1){
            st.modify(--a, b);
        } else {
            cout << st.query(--a, b) << '\n';
        }
    }
}

