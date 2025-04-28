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

    vector<pair<int, int>> b(n);
    for (int i=0; i<n; ++i){
         cin >> b[i].first;
    }
    for (int i=0; i<n; ++i){
         cin >> b[i].second;
    }

    sort(b.begin(), b.end(), [&](const pair<int, int>& x, const pair<int, int>& y){
        return x.second-x.first < y.second-y.first;
    });

    long long r = 0;
    for (auto [a, s] : b){
        if (s-a > r){
            cout << "NO\n";
            return;
        }
        r += a;
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
