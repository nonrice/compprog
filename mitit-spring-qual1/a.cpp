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

    if (n % 2 == 0){
        cout << "2025";
        for (int i=0; i+4<n; ++i){
            cout  << '0';
        }
        cout << '\n';
    } else {
        cout << "42025";
        for (int i=0; i+5<n; ++i){
            cout << '0';
        }
        cout << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
