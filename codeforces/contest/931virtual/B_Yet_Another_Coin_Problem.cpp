#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int c[30] = { 0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 3, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 4, 3, 2, 3, 4, 3, 4 };

void solve(){
    int n; cin >> n;

    cout << n/15-1 + c[n - 15*(n/15-1)] << '\n';


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}