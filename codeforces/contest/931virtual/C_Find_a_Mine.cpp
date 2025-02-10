#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int ask(int x, int y){
    cout << "? " << x << ' ' << y << endl;
    int d; cin >> d;
    return d;
}

void solve(){
    int n, m; cin >> n >> m;

    int d1 = ask(1, 1);
    int d2 = ask(m, n);
    int d3 = ask(m, 1);


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}