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
    long long s = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        s += a[i];
    }

    long long ans = 2*a[n-1]-s;
    long long p = 0;
    for (int i=0; i<n-1; ++i){

        ans = max(ans, a[n-1]-(a[i]-p)-(s-p-a[i]-a[n-1]));

        p += a[i];




        
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