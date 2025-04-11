#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n; cin >> n;
    int k; cin >> k;

    if (n == 1){
        if (k == 2){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    
    if (k != 1){
        cout << "NO\n";
        return;
    }

    for (int f=2; f*f<=n; ++f){
        if (n%f == 0){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
