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
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    int l=1, r=1, d=0;
    for (int i=0; i<n; ++i){
        int c=0;
        for (int j=i+1; j<n; ++j){
            if (a[i] < a[j]){
                ++c;
            } else if (a[i] > a[j]) {
                --c;
            }

            if (c < d){
                l=i+1;
                r=j+1;
                d = c;
            }
        }
    }

    debug(d);
    cout << l << ' ' << r << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
