#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;

    int x=0, y=0;
    int mx_x=0, mx_y=0;
    int x0=0, y0=0;
    for (int i=0; i<n; ++i){
        int dx, dy; cin >> dx >> dy;
        if (i == 0){
            x0 = dx;
            y0 = dy;
        }
        x += dx;
        y += dy;
        mx_x = max(mx_x, x);
        mx_y = max(mx_y, y);
    }

    cout << 2*(mx_x + m + mx_y + m - x0 - y0) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}