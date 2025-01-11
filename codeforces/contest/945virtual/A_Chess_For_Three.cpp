#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){

    int a, b, c; cin >> a >> b >> c;

    int s = a+b+c;
    if (s % 2){
        cout << "-1\n";
        return;
    }

    cout << min(s/2, s-max(a, max(b, c))) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}