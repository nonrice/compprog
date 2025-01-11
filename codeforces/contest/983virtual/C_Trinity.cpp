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

    int ans = n-1;
    int r = n-1;
    for (int i=n-1; i>=1; --i){
        while (a[i]+a[i-1] <= a[r]){
            --r;

            if (r < 0 || r < i){
                cout << ans << '\n';
                return;
            }
        }
        // ans = min(ans, int((lower_bound(a.begin(), a.end(), a[i-1])-a.begin()) + (a.end()-upper_bound(a.begin(), a.end(), a[r]))));
        ans = min(ans, i-1+(n-r-1));
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