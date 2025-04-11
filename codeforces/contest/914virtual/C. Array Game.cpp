#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    if (k >= 3){
        cout << "0\n";
        return;
    }

    sort(a.begin(), a.end());
    if (k == 1){
        long long ans = a[0];
        for (int i=1; i<n; ++i){
            ans = min(ans, a[i]-a[i-1]);
        }
        cout << ans << '\n';
    } else {
        long long ans = a[0];
        for (int i=0; i<n; ++i){
            for (int j=i+1; j<n; ++j){
                ans = min(ans, a[j]-a[i]);
                auto it = upper_bound(a.begin(), a.end(), a[j]-a[i]);
                if (it != a.end()){
                    ans = min(ans, *it - (a[j]-a[i]));
                }
                if (it != a.begin()){
                    ans = min(ans, (a[j] - a[i]) - *(--it));
                }
            }
        }
        cout << ans << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
