#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1){
            ans = ans*a%m;
        }
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    long long p; cin >> p;
    long long k; cin >> k;
    
    map<long long, int> f;
    for (int i=0; i<n; ++i){
        long long x; cin >> x;
        x = x*x%p * x %p;
        ++f[x];
    }
    
    long long ans = 0;
    for (auto [u, h] : f){
        if (u*u%p == k){
            ans += h*(h-1)/2;
        }
        long long v = k * binpow(u, p-2, p) % p;
        if (v < u){
            ans += h*f[v];
        }
    }

    cout << ans << '\n';
}
