#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }
    
    set<int> r;
    int j = 0;
    for (int i=0; i<m; ++i){
        if (j<n && b[i] == a[j]){
            r.insert(a[j]);
            ++j;
        } else if (r.count(b[i])){
            continue;
        } else {
            cout << "TIDAK\n";
            return;
        }
    }

    cout << "YA\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}