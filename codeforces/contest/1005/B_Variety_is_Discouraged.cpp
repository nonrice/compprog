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
    vector<int> a(n);
    map<int, int> f;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        ++f[a[i]];
    }

    int al=-1, ar=-1;
    int l = -1;
    for (int i=0; i<n; ++i){
        if (f[a[i]] > 1){
            l = -1;
        } else {
            if (l == -1){
                l = i;
            }
            if (i-l >= ar-al){
                ar = i;
                al = l;
            }
        }
    }

    if (al == -1){
        cout << "0\n";
    } else {
        cout << al+1 << ' ' << ar+1 << '\n';
    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}