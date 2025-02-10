#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr long long M = 998244353;

long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

long long NCR(int n, int k, long long m){
    long long ans = 1;
    
    for (int d=0; d<k; ++d){
        ans = ans*(n-d) % M;
        ans = ans * binpow(d+1, M-2, M) % M;
    }

    return ans;
}
//1984 pwease
template<class Fun> class ycomb_result {
    Fun fun_;
public:
    template<class T> explicit ycomb_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) ycomb(Fun &&fun) { return ycomb_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int MAXK = 100000;

vector<int> fs[MAXK+1];

void solve(){
    int k; cin >> k;
    long long n; cin >> n;

    cout << n << ' ';

    vector<vector<int>> mem(k+1, vector<int>(17, -1));
    auto dp = ycomb([&](const auto& self, int v, int m)->long long{
        if (mem[v][m] != -1){
            return mem[v][m];
        }

        if (m == 0){
            return mem[v][m] = (v==1);
        }
        if (v == 1){
            return mem[v][m] = (m==0);
        }
        
        long long ans = self(1, m-1);

        for (int f : fs[v]){
            if (v % f == 0){
                ans = (ans + self(v/f, m-1)) % M;
                if (v/f != f){
                    ans = (ans + self(f, m-1)) % M;
                }
            }
        }
        return mem[v][m] = ans;
    });

    for (int x=2; x<=k; ++x){
        long long ans = 0;
        for (int m=1; m<=16; ++m){
            ans = (ans + dp(x, m) * NCR(n+1, m+1, M) % M) % M;
        }
        cout << ans << ' ';
    }

    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (int x=2; x<=MAXK; ++x){
        for (int f=2; f*f<=x; ++f){
            if (x % f == 0){
                fs[x].push_back(f);
            }
        }
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}
