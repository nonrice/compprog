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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin >> a[i][j];
        }
        reverse(a[i].begin(), a[i].end());
    }

    sort(a.rbegin(), a.rend());
    debug(a);

    int ans = 0;
    for (int k=0; k<n; ++k){
        for (int i=k; i<n; ++i){
            for (int j=0; j<i-k; ++j){
                if (a[i][j] != 1){
                    ans = max(ans, i-k);
                    goto cont;
                }
            }
        }
        ans = max(ans, n-k);
cont:
        continue;
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