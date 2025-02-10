#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int a, b; cin >> a >> b;
    if (a > b){
        swap(a, b);
    }

    if (a % 2 == 0){
        int c = 2*b;
        int d = a/2;
        if (c > d){
            swap(c, d);
        }

        if (a != c || b != d){
            cout << "YES\n";
            return;
        }

    }

    if (b % 2 == 0){
        int c = 2*a;
        int d = b/2;
        if (c > d){
            swap(c, d);
        }

        if (a != c || b != d){
            cout << "YES\n";
            return;
        }
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