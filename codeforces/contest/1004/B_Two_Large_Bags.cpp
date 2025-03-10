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
    sort(a.begin(), a.end());

    int d = 0;
    for (int i=0; i<n; ++i){
        for (int j=n-1; j>=2; --j){
            if (a[j]==a[j-1] && a[j]==a[j-2]){
                ++a[j];
                ++d;
            }
        }
    }

    debug(a, d);

    map<int, int> f;
    for (int i=0; i<n; ++i){
        ++f[a[i]];
    }
    for (auto [x, v] : f){
        if (v%2){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}