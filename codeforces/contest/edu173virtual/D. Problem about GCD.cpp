#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

// https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

void solve(){
    u64 l, r, g; cin >> l >> r >> g;
    
    l = (l+g-1)/g;
    r = r/g;
    if (r < l){
        cout << "-1 -1\n";
        return;
    }
    u64 p1=l;
    while (p1!=1 && !MillerRabin(p1) && p1<r){
        ++p1;
    }
    u64 p2=r;
    while (p2!=1 && !MillerRabin(p2) && p2>l){
        --p2;
    }
    debug(p1, p2, l, r);

    u64 d = 0;
    u64 a, b;
    if (l<=1 && r>=1){
        a=1, b=1;
    } else {
        a=2, b=2;
    }
    for (u64 u=l; u<=p1; ++u){
        for (u64 v=max(p2, u+d+1); v<=r; ++v){
            if (gcd(u, v)==1){
                d = max(d, max(v, u)-min(v, u));
                a=min(u, v);
                b=max(u, v);
            }
        }
    }
    debug(a, b);

    if (gcd(a, b) != 1 || (a>1 && a==b)){
        cout << "-1 -1\n";
        return;
    }
    cout << a*g << ' ' << b*g << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
