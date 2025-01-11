#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n; cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long ans = n*(n+1)/2;
    for (int i=n-1; i>=0; --i){
        long long s = n-1-i;

        long long k = 1e6;
        for (int st = k; st>=1; st/=2){
            while (k-st>=s && (k-st)*(k-st+1)/2 - (s-1)*s/2 > a[i]){
                k -= st;
                debug(k);
            }
        }
        debug(k*(k+1)/2 - (s-1)*s/2);
        if (s == 0){
            --k;
        }
        if (k*(k+1)/2 - (s+1)*s/2 <= a[i]){
            ans = min(ans, max(a[i], k*(k+1)/2));
            debug(a[0], ans, k, s);
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