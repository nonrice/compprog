#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;

    if (k <= (2*n-2)*2){
        cout << (k+1)/2 << '\n';
    } else {
        cout << 2*n-2 + (k-(2*n-2)*2) << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}