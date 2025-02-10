#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template <typename T>
struct BIT {
    vector<T> s;
    int n;

    // construct empty tree for array of size n
    BIT(int n) : n(n) {
        s.resize(n+1);
    }

    // compute sum on range [0, r)
    T query(int r){
        T ans = 0;
        while (r >= 0){
            ans += s[r];
            r = (r & (r+1)) - 1;
        }
        return ans;
    }
    
    // compute sum on range [l, r)
    T query(int l, int r){
        return query(r) - query(l);
    }

    // increment index i by d
    void inc(int i, T d){
        i += 1;
        while (i <= n){
            s[i] += d;
            i |= i+1;
        }
    }
};

template<int M>
struct mint {
    long long x;

    // construct modular integer x under mod M
    mint(long long x = 0) : x((x % M + M) % M) {}

    // addition operator
    mint operator+(const mint& o) const {
        return mint(x + o.x);
    }

    // addition compound assignment operator
    mint& operator+=(const mint& o) {
        x = (x + o.x) % M;
        return *this;
    }

    // subtraction operator
    mint operator-(const mint& o) const {
        return mint(x - o.x);
    }

    // subtraction compound assignment operator
    mint& operator-=(const mint& o) {
        x = (x - o.x + M) % M;
        return *this;
    }

    // multiplication operator
    mint operator*(const mint& o) const {
        return mint(x * o.x);
    }

    // multiplication compound assignment operator
    mint& operator*=(const mint& o) {
        x = (x * o.x) % M;
        return *this;
    }

    // compute a^b quickly
    mint pow(long long b) const {
        mint ans(1), a(*this);
        while (p){
            if (p & 1){
                ans *= *this;
            }
            a = a*a;
            b >>= 1;
        }
        return ans;
    }

    // compute multiplicative inverse under modulo M
    mint inv() const {
        long long a = x, m = M, u = 1, v = 0;
        while (m) {
            long long t = a / m;
            a -= t * m; swap(a, m);
            u -= t * v; swap(u, v);
        }
        return mint(u);
    }

    // division operator
    mint operator/(const mint& o) const {
        return *this * o.inv();
    }

    // division compound operator
    mint& operator/=(const mint& o) {
        return *this *= o.inv();
    }

    // print value
    friend ostream& operator<<(ostream& os, const mint& x) {
        os << x.x;
        return os;
    }
};

template<long long M>
mint<M> binpow(mint<M> a, long long b){
    mint<M> ans = 1;
    while (b){
        if (b&1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}

constexpr long long M = 998244353;

void solve(){
    string s; cin >> s;
    const int n = s.size();

    BIT<mint<M>> o1(n), o2(n), z1(n), z2(n);
    for (int i=0; i<n; ++i){
        if (s[i] == '1'){
            o1.inc(i, binpow<M>(2, i));
            o2.inc(i, binpow<M>(2, n-i-1));
        } else {
            z1.inc(i, binpow<M>(2, i));
            z2.inc(i, binpow<M>(2, n-i-1));
        }
    }

    mint<M> ans;
    for (int i=0; i<n; ++i){
        if (s[i] == '1'){
            ans += binpow<M>(2, n-i-1) * (z1.query(0, i)+1);
        } else {
            ans += binpow<M>(2, n-i-1) * (o1.query(0, i)+1);
        }
    }

    int q; cin >> q;
    while (q--){
        int i; cin >> i;
        --i;

        if (s[i] == '1'){
            s[i] = '0';
            ans -= binpow<M>(2, n-i-1) * (z1.query(0, i)+1) + binpow<M>(2, i)*z2.query(i+1, n);
            ans += binpow<M>(2, n-i-1) * (o1.query(0, i)+1) + binpow<M>(2, i)*o2.query(i+1, n);
            o1.inc(i, mint<M>(0)-binpow<M>(2, i));
            o2.inc(i, mint<M>(0)-binpow<M>(2, n-i-1));
            z1.inc(i, binpow<M>(2, i));
            z2.inc(i, binpow<M>(2, n-i-1));
        } else {
            s[i] = '1';
            ans -= binpow<M>(2, n-i-1) * (o1.query(0, i)+1) + binpow<M>(2, i)*o2.query(i+1, n);
            ans += binpow<M>(2, n-i-1) * (z1.query(0, i)+1) + binpow<M>(2, i)*z2.query(i+1, n);
            z1.inc(i, mint<M>(0)-binpow<M>(2, i));
            z2.inc(i, mint<M>(0)-binpow<M>(2, n-i-1));
            o1.inc(i, binpow<M>(2, i));
            o2.inc(i, binpow<M>(2, n-i-1));
        }

        cout << ans << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while (t--){
        solve();
    }
}