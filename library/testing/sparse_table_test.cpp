#include <bits/stdc++.h>
using namespace std;

template<typename T>
T add (T a, T b){
    return a + b;
}

template <typename T, T (*F)(T, T)=add, T D = T{}>
struct sparse_table {
    int n, m;
    vector<vector<T>> t;

    sparse_table(vector<T>& a) : m(a.size()){
        n = log2_floor(m)+1;
        t = vector<vector<T>>(n, vector<T>(m));
        copy(a.begin(), a.end(), t[0].begin()); 
        for (int i=1; i<n; ++i){
            for (int j=0; j+(1<<i)<=m; ++j){
                t[i][j] = F(t[i-1][j], t[i-1][j + (1<<(i-1))]);
            }
        }
    }
    
    // query [l, r)
    T query_disjoint(int l, int r){
        int p = log2_floor(r-l);
        if (p == 0){
            return t[0][l];
        }
        return (l == r) ? D : F(t[p][l], query(l+(1<<p), r));
    }
    
    // query [l, r)
    T query(int l, int r){
        int p = log2_floor(r-l);
        return (l == r) ? D : F(t[p][l], t[p][r-(1<<p)+1]);
    }

    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
};

int min_wrap(int a, int b){
    return min(a, b);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    sparse_table<int, min_wrap> t(a);
    while (q--){
        int l, r; cin >> l >> r;
        --l;
        cout << t.query(l, r) << '\n';
    }
}

