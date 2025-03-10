#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1e9+7;

long long binpow(long long a, long long b, long long m=M){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

struct polyhash {
    long long m, b;
    vector<long long> p;
    
    polyhash(const vector<bool>& s, long long m, long long b) : m(m), b(b) {
        p = vector<long long>(s.size()+1);
        long long bp = 1;
        for (size_t i=1; i<=s.size(); ++i){
            p[i] = (p[i-1] % m + s[i-1] * bp % m) % m;
            bp = bp*b % m;
        }
    }
 
    long long substr(int l, int r){
        return ((p[r]-p[l]+m)%m) * binpow(binpow(b, l, m), m-2, m)%m;
    }
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m, q; cin >> n >> m >> q;

    vector<int> d(n+1);
    while (m--){
        int l, r; cin >> l >> r;
        --l, --r;
        ++d[l];
        --d[r+1];
    }
    for (int i=1; i<=n; ++i){
        d[i] += d[i-1];
    }

    vector<bool> a(n);
    for (int i=0; i<n; ++i){
        a[i] = d[i]%2;
    }

    vector<int> p(n+1);
    for (int i=1; i<=n; ++i){
        p[i] += p[i-1] + a[i-1];
    }
    auto cnt = [&](int l, int r){
        return p[r]-p[l];
    };

    reverse(a.begin(), a.end());
    polyhash h(a, M, 2);
    while (q--){
        int l, r, k; cin >> l >> r >> k;
        --l, --r;

        auto chk = [&](int x){
            int c = cnt(x, r+1);
            return cnt(l, r+1)-c + (r-x+1) <= k;
        };
        int x = r+1;
        for (int s=r; s>=1; s/=2){
            while (x-s>=l && chk(x-s)){
                x -= s;
            }
        }

        long long w = h.substr(n-(r+1), n-x);
        long long s = binpow(2, r+1-x)%M * (binpow(2, k-1 - (r+1-x) + 1) + M - 1)%M;
        cout << (w+s)%M << '\n';
    }
}