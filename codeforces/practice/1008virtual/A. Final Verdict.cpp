#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x; cin >> n >> x;
    long long s = 0;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        s += x;
    }

    if (s%n == 0 && s/n == x){
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
