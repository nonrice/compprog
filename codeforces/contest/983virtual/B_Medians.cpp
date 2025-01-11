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

    if (n == 1){
        cout << "1\n1\n";
        return;
    }

    if (k == 1 || k == n){
        cout << "-1\n";
        return;
    }

    if (k%2 == 0){
        cout << "3\n";
        cout << "1 " << k << ' ' << k+1 << '\n';
    } else {
        cout << "5\n";
        int w = min(k-2, n-k-1);
        cout << "1 " << k - w << ' ' << k << ' ' << k+1 << ' ' << k + w + 1 << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}