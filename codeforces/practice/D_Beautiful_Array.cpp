#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, x; cin >> n >> x;
    vector<long long> a(n+1);
    for (int i=1; i<=n; ++i){
        cin >> a[i];
    }

    vector<long long> dp1(n+1), dp2(n+1), dp3(n+1);
    long long ans = 0;
    for (int i=1; i<=n; ++i){
        dp1[i] = max(dp1[i-1]+a[i], 0LL);
        dp2[i] = max(dp2[i-1]+a[i]*x, max(dp1[i-1]+a[i]*x, 0LL));
        dp3[i] = max(dp3[i-1]+a[i], max(dp2[i-1]+a[i], 0LL));
        ans = max(dp1[i], max(dp2[i], max(dp3[i], ans)));
    }

    // debug(dp1);
    // debug(dp2);
    // debug(dp3);

    cout << ans << '\n';
}