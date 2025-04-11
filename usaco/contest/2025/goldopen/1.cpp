#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

template<long long M>
struct mod_int {
    long long x;
 
    mod_int(long long x = 0) : x((x % M + M) % M) {}
 
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
 
    mod_int inv() const {
        return this->pow(M-2);
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
};

template<int N, long long M>
struct NCR {
    mod_int<M> f[N+1], fi[N+1];

    NCR(){
        f[0] = 1;
        fi[0] = 1;
        for (int x=1; x<=N; ++x){
            f[x] = f[x-1]*x;
            fi[x] = fi[x-1]/x;
        }
    }

    mod_int<M> operator()(int n, int r){
        if (n<r){
            return 0;
        }
        return f[n]*fi[n-r]*fi[r];
    }
};

using mint = mod_int<M>;

NCR<1000000, M> ncr;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int k, n; cin >> k >> n;
    long long l; cin >> l;
    string s; cin >> s;

    mint ans = 1;
    int r = 0;
    for (int i=n-1; i>=0; --i){
        if (s[i] == 'O'){
            ++r;
            continue;
        }
    
        ans *= ncr(r, k);
        r -= k;
    }

    ans = ans.pow(l);

    cout << ans << '\n';
}
