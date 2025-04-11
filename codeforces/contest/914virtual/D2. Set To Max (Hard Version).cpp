#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template <typename T, T (*F)(T, T)>
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
        int p = log2_floor(r-l+1);
        if (p == 0){
            return t[0][l];
        }
        return F(t[p][l], query(l+(1<<p), r));
    }

    T query(int l, int r){
        int p = log2_floor(r-l+1);
        return F(t[p][l], t[p][r-(1<<p)+1]);
    }

    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
};

int min_wrap(int a, int b){
    return min(a, b);
}

int max_wrap(int a, int b){
    return max(a, b);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }
    
    int ma = 0, mb = 0;
    for (int i=0; i<n; ++i){
        ma = max(a[i], ma);
        mb = max(b[i], mb);
        if (a[i] > b[i]){
            cout << "NO\n";
            return;
        }
    }
    if (ma != mb){
        cout << "NO\n";
        return;
    }
    
    sparse_table<int, max_wrap> sa(a);
    sparse_table<int, min_wrap> sb(b);

    vector<vector<int>> s(n), e(n+1);
    map<int, vector<int>> p;
    for (int i=0; i<n; ++i){
        p[a[i]].push_back(i);
    }
    for (int h=1; h<=ma; ++h){
        for (auto i : p[h]){
            int r = i;
            for (int s=n; s>=1; s/=2){
                while (r+s<n && sb.query(i, r+s) >= h && sa.query(i, r+s) <= h){
                    r += s;
                }
            }
            int l = i;
            for (int s=n; s>=1; s/=2){
                while (l-s>=0 && sb.query(l-s, i) >= h && sa.query(l-s, i) <= h){
                    l -= s;
                }
            }
            s[l].push_back(h);
            e[r+1].push_back(h);
        }
    }

    multiset<int> mx;
    for (int i=0; i<n; ++i){
        for (auto v : s[i]){
            mx.insert(v);
        }
        for (auto v : e[i]){
            mx.erase(mx.find(v));
        }
        if (!mx.empty()){
            a[i] = *(--mx.end());
        }
    }
    
    for (int i=0; i<n; ++i){
        if (a[i] != b[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
