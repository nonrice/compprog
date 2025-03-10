#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

// fast computation of a^b mod m
long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

constexpr int NCR_MAX = 300001;
long long f[NCR_MAX+1] = { 1 }, fi[NCR_MAX+1] = { 1 };

// precompute factorials and inverse factorials modulo m up to NCR_MAX
void NCR_precomp(long long m){
    for (int i=1; i<=NCR_MAX; ++i){
        f[i] = f[i-1]*i%m;
        fi[i] = binpow(f[i], m-2, m);
    }
}

// compute n choose k modulo m
long long NCR(int n, int k, long long m){
    if (n<k){
        return 0;
    }
    return f[n]*fi[n-k]%m*fi[k]%m;
}

template<long long M>
struct mod_int {
    long long x;

    // construct modular integer x under mod M
    mod_int(long long x = 0) : x((x % M + M) % M) {}

    // construct modular integer x under mod M with integer type
    mod_int(int x = 0) : x((x % M + M) % M) {}

    // addition operator
    mod_int operator+(const mod_int& o) const {
        return mod_int(x + o.x);
    }

    // addition compound assignment operator
    mod_int& operator+=(const mod_int& o) {
        x = (x + o.x) % M;
        return *this;
    }

    // subtraction operator
    mod_int operator-(const mod_int& o) const {
        return mod_int(x - o.x);
    }

    // subtraction compound assignment operator
    mod_int& operator-=(const mod_int& o) {
        x = (x - o.x + M) % M;
        return *this;
    }

    // multiplication operator
    mod_int operator*(const mod_int& o) const {
        return mod_int(x * o.x);
    }

    // multiplication compound assignment operator
    mod_int& operator*=(const mod_int& o) {
        x = (x * o.x) % M;
        return *this;
    }

    // compute a^b quickly
    mod_int pow(long long b) const {
        mod_int ans(1), a(*this);
        while (b){
            if (b & 1){
                ans *= a;
            }
            a = a*a;
            b >>= 1;
        }
        return ans;
    }

    // compute multiplicative inverse under modulo M
    mod_int inv() const {
        long long a = x, m = M, u = 1, v = 0;
        while (m) {
            long long t = a / m;
            a -= t * m;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        return mod_int(u);
    }

    // division operator
    mod_int operator/(const mod_int& o) const {
        return *this * o.inv();
    }

    // division compound operator
    mod_int& operator/=(const mod_int& o) {
        return *this *= o.inv();
    }

    // print value
    friend ostream& operator<<(ostream& os, const mod_int& x) {
        os << x.x;
        return os;
    }

    // input value
    friend istream& operator>>(istream& is, mod_int& x) {
        is >> x.x;
        return is;
    }

    // debug value
    friend void print(mod_int x){
        cerr << x.x;
    }
};

constexpr long long M = 1000000007;

using mint = mod_int<M>;

void solve(){
    int n, k; cin >> n >> k;

    int x = n;
    for (int i=0; i<k; ++i){
        int r, c; cin >> r >> c;
        if (r == c){
            x -= 1;
        } else {
            x -= 2;
        }
    }

    debug(x);
    mint ans = 0;
    for (int c=0; c<=x; ++c){
        if ((x-c)%2 == 0){
            ans += mint(NCR(x, c, M)) * mint(f[x-c])/mint(f[(x-c)/2]);
        }
        debug(ans);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    NCR_precomp(M);
    int t; cin >> t;
    while (t--){
        solve();
    }
}