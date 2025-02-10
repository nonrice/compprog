#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

template<class Fun> class ycomb_result {
    Fun fun_;
public:
    template<class T> explicit ycomb_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) ycomb(Fun &&fun) { return ycomb_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

void solve(){
    long long k, x, a; cin >> k >> x >> a;

    map<pair<long long, int>, long long> mem;
    auto g = ycomb([&](const auto& self, long long u, int w)->long long{
        if (mem.count({ u, w })){
            return mem[{ u, w }];
        }

        if (w == x){
            return mem[{ u, w }] = (k-1)*u;
        }

        long long v = u;
        for (long long s=u; s>=1; s/=2){
            while (v-s>=0 && (v-s)*(k-1) > self(u-(v-s), w+1)-(v-s)){
                v -= s;
            }
        }

        long long ans = min(v*(k-1), self(u-v, w+1)-v);
        if (v > 0){
            ans = max(ans, min((v-1)*(k-1), self(u-(v-1), w+1)-(v-1)));
        }

        return mem[{ u, w }] = ans;
    });

    long long r = g(a, 0);
    debug(r);
    if (r > 0){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}