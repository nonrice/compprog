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
    vector<int> e, o;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        if (x%2){
            o.push_back(i+1);
        } else {
            e.push_back(i+1);
        }
    }

    if (o.size() >= 3){
        cout << "YES\n" << o[0] << ' ' << o[1] << ' ' << o[2] << '\n';
        return;
    }

    if (o.size() >= 1 && e.size() >= 2){
        cout << "YES\n" << o[0] << ' ' << e[0] << ' ' << e[1] << '\n';
        return;
    }

    cout << "NO\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}