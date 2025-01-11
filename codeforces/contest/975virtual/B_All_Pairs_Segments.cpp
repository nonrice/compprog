#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    map<long long, long long> ans;
    for (long long i=1; i<n; ++i){
        ans[i * (n-i)] += a[i]-a[i-1]-1;
    }
    for (long long i=0; i<n; ++i){
        ans[(i+1)*(n-i)-1] += 1;
    }


    while (q--){
        long long k; cin >> k;

        cout << ans[k] << ' ';
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