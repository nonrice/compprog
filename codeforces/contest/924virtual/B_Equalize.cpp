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

    int ans = 0;
    map<int, int> f;
    sort(a.begin(), a.end());
    int j = 0;
    for (int i=0; i<a.size(); ++i){
        ++f[a[i]];
        while (a[i] - a[j] >= n){
            --f[a[j]];
            if (f[a[j]] == 0){
                f.erase(a[j]);
            }
            ++j;
        }
        ans = max(ans, (int)f.size());
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