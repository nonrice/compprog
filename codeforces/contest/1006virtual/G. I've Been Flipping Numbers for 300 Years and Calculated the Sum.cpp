#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template<long long M>
struct mod_int {
    long long x;
 
    mod_int() {}
 
    template <typename T, std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, long long>, int> = 0>
    mod_int(T x = 0) : x((x % M + M) % M) {}
 
    mod_int operator+(const mod_int& o) const {
        return mod_int(x + o.x);
    }
 
    mod_int& operator+=(const mod_int& o) {
        x = (x + o.x) % M;
        return *this;
    }
 
    mod_int operator-(const mod_int& o) const {
        return mod_int(x - o.x);
    }
 
    mod_int& operator-=(const mod_int& o) {
        x = (x - o.x + M) % M;
        return *this;
    }
 
    mod_int operator*(const mod_int& o) const {
        return mod_int(x * o.x);
    }
 
    mod_int& operator*=(const mod_int& o) {
        x = (x * o.x) % M;
        return *this;
    }
 
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
 
    // multiplicative inverse with ext. GCD 
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
 
    mod_int operator/(const mod_int& o) const {
        return *this * o.inv();
    }
 
    mod_int& operator/=(const mod_int& o) {
        return *this *= o.inv();
    }
 
    friend ostream& operator<<(ostream& os, const mod_int& x) {
        os << x.x;
        return os;
    }
 
    friend istream& operator>>(istream& is, mod_int& x) {
        is >> x.x;
        return is;
    }
 
    friend void print(mod_int x){
        cerr << x.x;
    }
};

long long isqrt(long long n){
    long long y = 0;
    for (int s=n; s>=1; s/=2){
        while ((y+s)*(y+s) <= n){
            y += s;
        }
    }
    return y;
}

int rev(int n, int p){
    vector<int> d;
    while (n){
        d.push_back(n % p);
        n /= p;
    }
    reverse(d.begin(), d.end());
    int s = 0;
    int h = 1;
    for (auto c : d){
        s += c*h;
        h *= p;
    }
    return s;
}

long long sq_sum(long long n){
    return n*(n+1)*(2*n+1)/6;
}

constexpr long long M = 1000000007;

using mint = mod_int<M>;

void solve(){
    long long n, k; cin >> n >> k;
    
    mint y = 0;

    y += max(0LL, 1LL*(k-n)%M * n%M);

    for (int p=2; p<=k && p*p<=n; ++p){
        y += rev(n, p);
    }
    debug(y);

    int p = 1+isqrt(n);
    debug(n, y, (p-1)*(p-1));
    int l = min(n, k);
    y += max(0LL, 1LL*n * (l-p+1)*(l+p)/2);
    while (p<=l){
        int q=p;
        for (int s=q; s>=1; s/=2){
            while (n/p == n/(q+s)){
                q += s;
            }
        }

        q = min(q, l);
        y += 1LL * n/p * (q-p+1);
        y -= (sq_sum(q) - sq_sum(p-1)) * (n/p);

        debug((sq_sum(q) - sq_sum(p-1)) * (n/p));
        p = q+1;
    }

    cout << y << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
