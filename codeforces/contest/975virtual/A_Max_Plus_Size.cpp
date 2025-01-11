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

    int me=0, mo=0;
    for (int i=0; i<n; ++i){
        if (i%2){
            mo = max(mo, a[i]);
        } else {
            me = max(me, a[i]);
        }
    }
    
    cout << max(mo + n/2, me + (n+1)/2) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}