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
    vector<pair<int, int>> p(n);
    for (int i=0; i<n; ++i){
        cin >> p[i].first;
    }
    for (int i=0; i<n; ++i){
        cin >> p[i].second;
    }

    sort(p.begin(), p.end());
    for (int i=0; i<n; ++i){
        cout << p[i].first << ' ';
    }
    cout << '\n';
    for (int i=0; i<n; ++i){
        cout << p[i].second << ' ';
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