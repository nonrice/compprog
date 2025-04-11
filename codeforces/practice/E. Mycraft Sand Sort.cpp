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

template<typename T, T (*F)(T, T), T D = T{}>
struct segtree {
    int n;
    vector<T> t;

    segtree(int n) : n(n){
        t = vector<T>(2*n, D);
    }

    segtree(vector<T>& a) : n(a.size()){
        t = vector<T>(2*n);
        copy(a.begin(), a.end(), t.begin()+n);
        for (int i=n-1; i>=0; --i){
            t[i] = F(t[i*2], t[i*2+1]);
        }
    }

    void set(int i, T v){
        i += n;
        t[i] = v;
        while (i/2 > 0){
            t[i/2] = F(t[i], t[i^1]);
            i /= 2;
        }
    }
    
    // query [l, r)
    T query(int l, int r){
        T ans = D;
        l += n;
        r += n;
        while (l < r){
            if (l&1){
                ans = F(ans, t[l]);
                ++l;
            }
            if (r&1){
                --r;
                ans = F(ans, t[r]);
            }
            l /= 2;
            r /= 2;
        }

        return ans;
    }
};

int max(int a, int b){
    return max(a, b);
}

void solve(){
    int n; cin >> n;
    vector<int> p(n), c(n);
    for (int i=0; i<n; ++i){
        cin >> p[i];
        --p[i];
    }
    for (int i=0; i<n; ++i){
        cin >> c[i];
    }

    vector<int> q(n);
    for (int i=0; i<n; ++i){
        q[p[i]] = i;
    }


}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
