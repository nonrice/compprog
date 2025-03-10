#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int x, y; cin >> x >> y;

    if (x <= y){
        if (y-x == 1){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if ((x-y+1)%9 == 0){
            cout << "Yes\n";
        } else {
            cout << "No\n";
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