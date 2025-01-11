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

    for (int x=min(a, b); x<=a*b; ++x){
        if (x%a == x%b){
            cout << x << '\n';
            return;
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}