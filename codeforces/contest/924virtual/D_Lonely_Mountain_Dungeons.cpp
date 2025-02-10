#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long c2(long long x){
    return x*(x-1)/2;
}

long long h(long long c, int k){
    return c2(c) - (k - c%k)*c2(c/k) - (c%k)*c2((c+k-1)/k);
}

void solve(){
    int n, b, x; cin >> n >> b >> x;
    vector<long long> c(n);
    for (int i=0; i<n; ++i){
        cin >> c[i];
    }   

    auto f = [&](int k){
        long long t = -1LL*(k-1)*x;
        for (int i=0; i<n; ++i){
            t += h(c[i], k)*b;
        }
        return t;
    };

    int k = 1;
    for (int s=*max_element(c.begin(), c.end()); s>=1; s/=2){
        while (f(k+s) > f(k+s-1)){
            k += s;
        }
    }

    cout << f(k) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}