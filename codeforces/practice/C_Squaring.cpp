#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long binpow(long long a, int b){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}


void solve(){
    int n; cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    int d = 0;
    long long ans = 0;
    for (int i=1; i<n; ++i){
        if (a[i] == 1){
            if (a[i-1] > 1){
                cout << "-1\n";
                return;
            } else {
                continue;
            }
        }

        int p = 0;
        if (a[i] <= a[i-1]){
            while (binpow(a[i], binpow(2, p)) < a[i-1]){
                ++p;
            }
        } else {
            while (binpow(a[i-1], binpow(2, -p)) < a[i]){
                --p;
            }
        }
        d = p+d;
        d = max(0, d);
        debug(p, d);
        ans += d;
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