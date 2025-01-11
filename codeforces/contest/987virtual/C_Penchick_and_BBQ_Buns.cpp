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

    if (n%2 == 0){
        for (int i=1; i<=n; ++i){
            cout << (i+1)/2 << ' ';
        }
        cout << '\n';
        return;
    } else {
        if (n < 27){
            cout << "-1\n";
            return;
        }

        cout << "1 2 3 4 5 2 3 4 5 1 6 7 8 9 6 7 8 9 10 10 11 11 12 13 13 1 12 ";

        for (int i=28; i<=n; ++i){
            cout << (i)/2 << ' ';
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