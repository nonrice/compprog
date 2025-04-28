#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }

    map<pair<int, int>, int> p;
    for (int i=0; i<n; ++i){
        p[{ a[i], b[i] }] = i;
    }

    vector<pair<int, int>> ans;
    int f = -1;
    for (int i=0; i<n; ++i){
        pair<int, int> u({ b[i], a[i] });
        if (!p.count(u)){
            cout << "-1\n";
            return;
        }
   
        int c = p[u];
        int d = n-i-1;
        if (a[i] == b[i]){
            if (n%2 == 0 || (f != -1 && f != a[i])){
                cout << "-1\n";
                return;
            }
            d = n/2;
            f = a[i];
        }
        if (p[u] == d){
            continue;
        }
        pair<int, int> v({ a[d], b[d] });
        swap(a[c], a[d]);
        swap(b[c], b[d]);
        swap(p[u], p[v]);
        ans.emplace_back(c+1, d+1);
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans){
        cout << x << ' ' << y << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
