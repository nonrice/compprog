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

    int n; cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    auto check = [&](long long x) -> bool{
        vector<long long> dp1(n+1), dp2(n+1);
        dp1[0] = x;
        dp2[0] = 2*x;
        bool f1 = false;
        for (int i=1; i<=n; ++i){
            if (!f1){
                dp1[i] = dp1[i-1] + a[i-1];
            }
            if (dp1[i] <= 0){
                f1 = true;
            }
            dp2[i] = max(dp1[i-1]*2 + a[i-1], dp2[i-1] + a[i-1]);
            if (dp2[i] <= 0){
                return false;
            }
        }
        return true;
    };


    long long ans = 0;
    for (long long s=1e14; s>=1; s/=2){
        while (check(ans + s) == false){
            ans += s;
        }
    }

    cout << ans+1 << '\n';
}