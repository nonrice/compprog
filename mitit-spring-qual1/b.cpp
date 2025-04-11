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

    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    

    long long mn = INT_MAX;
    long long ans = INT_MAX;
    for (int i=1; i<n; ++i){
        ans = min(ans, mn+a[i]-a[i-1]);
        
        if (i >= 2){
            mn = min(mn, a[i-1]-a[i-2]);
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
