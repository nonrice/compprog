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
    vector<long long> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }

    long long s = LLONG_MAX, w=0;
    bool f = false;
    for (int i=0; i<n; ++i){
        if (a[i] >= b[i]){
            s = min(s, a[i]-b[i]);
        } else {
            if (f){
                cout << "NO\n";
                return;
            }
            w = b[i]-a[i];
            f = true;
        }
    }
    
    if (w <= s){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}