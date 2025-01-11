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
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](const auto& a, const auto& b){
        int n1=min(a.first, a.second);
        int n2=min(b.first, b.second);
        int x1=max(a.first, a.second);
        int x2=max(b.first, b.second);

        if (n1 != n2){
            return n1<n2;
        }
        return x1<x2;

    });
    for (auto [x, y] : a){
        cout << x << ' ' << y << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}