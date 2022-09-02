#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll binpow(ll a, ll b){
    ll ans = 1;
    for (ll i=1; i<=b; i<<=1){
        if (b&i) ans = ans*a % MOD;
        a = a*a % MOD;
    }
    return ans;
}

int main(){
    int n; cin >> n;

    ll y=1; // 2^n (mod MOD)
    ll x=0, prev=1; // fib(n) (mod MOD)
    for (int i=1; i<=n; ++i){
        y = (y<<1) % MOD;
        swap(x, prev);
        x = (x+prev) % MOD;
    }
    
    // Fermat's little theorem
    // y^-1 = y^(MOD-2) (mod MOD)
    // requires gcf(y, MOD) = 1
    cout << x * binpow(y, MOD-2) % MOD << '\n';
}

