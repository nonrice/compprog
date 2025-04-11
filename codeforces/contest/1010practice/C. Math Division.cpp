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

using mint = mod_int<1000000007>;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    mint dp0 = int(s[n-1]=='0');
    mint dp1 = int(s[n-1]=='1');
    for (int i=n-2; i>=0; --i){
        if (s[i] == '0'){
            dp1 = dp1/2 + (s[i+1]=='1' ? dp0 : 0);
        } else {
            dp1 = dp1/2 + (s[i+1]=='0' ? dp0 : 0);
        }
        dp0 = mint(1)-dp1;
    }

    cout << (dp1*(n-1) + dp0*n) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
