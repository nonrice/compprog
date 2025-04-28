#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

inline int mn(pair<int, int> x){
    return min(x.first, x.second);
}

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> c(n);
    for (int i=0; i<n; ++i){
        cin >> c[i].first;
    }
    for (int i=0; i<n; ++i){
        cin >> c[i].second;
    }

    sort(c.begin(), c.end(), [&](const auto& u, const auto& v){
        return mn(u) < mn(v);
    });
    int f = 0;
    int t = 0;
    for (int i=0; i<n; ++i){
        if (c[i].first > c[i].second){
            swap(c[i].first, c[i].second);
            ++f;
        }
    }

    bool p = false;
    bool l[2] = { 1, 0 };
    for (int i=0; i<n; ++i){
        if (i>0 && c[i].second < c[i-1].second){
            cout << "NO\n";
            return;
        }
        if (i>0){
            l[i%2] |= c[i].first>c[i-1].second;
        }
        if (i==n-1 || c[i].second < c[i+1].first){
            p |= l[i%2];
        }
    }

    if (f%2==0 || p){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
