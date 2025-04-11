#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i=0; i<m; ++i){
        cin >> a[i];
        if (a[i] == n){
            --a[i];
        }
    }

    long long ans = 0;
    long long s = 0;
    sort(a.begin(), a.end());
    int j = m;
    for (int i=0; i<m-1; ++i){
        while (i >= j){
            s -= a[j];
            ++j;
        }
        while (j-1>i && a[i] + a[j-1] >= n){
            --j;
            s += a[j];
        }
        //debug(i, j, a[i]+a[j]);

        ans += 1LL*(m-j)*2*(a[i]-n+1) + 2*s;
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
