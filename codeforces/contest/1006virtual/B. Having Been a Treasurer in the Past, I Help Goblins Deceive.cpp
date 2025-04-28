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
    string s; cin >> s;

    int p=0, q=0;
    for (auto c : s){
        if (c == '-'){
            ++p;
        } else {
            ++q;
        }
    }

    cout << 1LL * q * (p/2) * ((p+1)/2) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
