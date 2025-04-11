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

    if (k%2){
        for (int i=0; i<n-1; ++i){
            cout << n << ' '; 
        }
        cout << n-1 << '\n';
    } else {
        for (int i=0; i<n-2; ++i){
            cout << n-1 << ' ';
        }
        cout << n << ' ' << n-1 << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
