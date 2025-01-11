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

    long long k; cin >> k;
    long long s = 0;
    long long h = 0;
    for (int i=0; i<n; ++i){
        long long x; cin >> x;
        s += x;
        h = max(h, x);
    }

    long long w = 0;
    for (long long w=n; w>=1; --w){
        if (k >= max(h, (s+w-1)/w)*w - s){
            cout << w << '\n';
            return;
        }
        // while (w+t<=n && k >= max(h, (s + (w+t)-1)/(w+t)) * (w+t) - s){
        //     w += t;
        // }
    }

    cout << w << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}