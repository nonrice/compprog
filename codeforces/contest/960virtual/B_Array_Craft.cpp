#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x, y; cin >> n >> x >> y;
    --x, --y;

    vector<int> a(n, 1);

    for (int i=x+1; i<n; i+=2){
        a[i] = -1;
    }
    for (int i=y-1; i>=0; i-=2){
        a[i] = -1;
    }

    for (auto x : a){
        cout << x << ' ';
    }
    cout << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}