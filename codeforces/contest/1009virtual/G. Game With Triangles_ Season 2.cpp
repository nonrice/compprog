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
    int n; cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    map<pair<int, int>, long long> mem;
    auto dp = ycomb([&](const auto& self, int l, int r)->long long{
        if (mem.count({l, r})){
            return mem[{l, r}];
        }

        if (l+1 >= r){
            return mem[{l, r}] = 0;
        }
        return mem[{l, r}] = max(self(l+2, r-1) + a[l]*a[r]*a[l+1], self(l+1, r-2) + a[l]*a[r]*a[r-1]);
    });
    
    long long ans = 0;
    for (int i=0; i<n; ++i){
        rotate(a.begin(), a.begin()+1, a.end());
        mem.clear();
        ans = max(ans, dp(0, n-1));
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
