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
    set<int> a, b;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        a.insert(x);
    }
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        b.insert(x);
    }

    if (a.size() + b.size() > 3){
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