#include <bits/stdc++.h>
using namespace std;

#ifdef LOCA
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template<long long M>
struct mod_int {
    long long x;

    // explicit default constructor
    mod_int() {}

    // construct modular integer x under mod M
    template <typename T, std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, long long>, int> = 0>
    mod_int(T x = 0) : x((x % M + M) % M) {}

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

using mint = mod_int<1000000007>;

void solve(){
    mint n, k;
    int m;
    cin >> n >> m >> k;

    mint fs = 0;
    int z;
    for (int i=0; i<m; ++i){
        cin >> z >> z;
        mint f; cin >> f;
        fs += f;
    }

    mint n2 = n*(n-1)/2;

    cout << k*fs/n2 + (k*(k-1)/2 * m)/(n2*n2) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}