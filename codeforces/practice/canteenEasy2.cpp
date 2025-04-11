#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*F)(T, T), T D = T{}>
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
    
    T query_disjoint(int l, int r){
        int p = log2_floor(r-l);
        if (p == 0){
            return t[0][l];
        }
        return (l == r) ? D : F(t[p][l], query_disjoint(l+(1<<p), r));
    }
    
    T query(int l, int r){
        int p = log2_floor(r-l);
        return (l == r) ? D : F(t[p][l], t[p][r-(1<<p)]);
    }

    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
};

long long c_max(long long a, long long b){
    return max(a, b);
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }
    
    vector<int> d(2*n);
    for (int i=0; i<n; ++i){
        d[i] = b[i]-a[i];
    }
    copy(d.begin(), d.begin()+n, d.begin()+n);

    vector<long long> p(2*n+1);
    for (int i=1; i<=2*n; ++i){
        p[i] = p[i-1]+d[i-1];
    }
        
    sparse_table<long long, c_max> t(p);
    int ans = 1;
    for (int i=n; i>=1; --i){
        if (d[i-1] >= 0){
            continue;
        }
        int j=2*n;
        for (int s=2*n; s>=1; s/=2){
            while (j-s>=i+1 && t.query(i+1, j-s+1)-p[i] >= -d[i-1]){
                j -= s;
            }
        }
        ans = max(ans, j-i+1);
    }

    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
