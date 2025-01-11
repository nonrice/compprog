#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, r; cin >> n >> r;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    int m = 0;
    for (int i=0; i<n; ++i){
        if (a[i]%2){
            ++m;
        }
    }
    int s = accumulate(a.begin(), a.end(), 0) - m;

    int y = (2*r-s)/2;

    cout << (s + y-abs(y-m)) << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}