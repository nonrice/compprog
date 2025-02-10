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

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n+2);
    for (int i=1; i<=n; ++i){
        cin >> a[i];
    }

    vector<int> dp(n+2), b(n+2);
    vector<bool> h(n+2);
    for (int i=1; i<=n+1; ++i){
        dp[i] = dp[i-1]+a[i];
        b[i] = i-1;

        int s = a[i-1];
        for (int j=i-2; j>=0; --j){
            int c = max((i-j-1)*(i-j-1), s);
            if (dp[j]+c+a[i] > dp[i]){
                b[i] = j;
                dp[i] = dp[j]+c+a[i];
                h[i] = (i-j-1)*(i-j-1) > s;
            }
            s += a[j];
        }
    }

    vector<pair<int, int>> ans;
    auto mkmex = ycomb([&](const auto& self, int l, int r){
        if (l == r){
            return;
        }
        self(l+1, r);
        ans.emplace_back(l, r);
        ans.emplace_back(l+1, r);
        self(l+1, r);
    });

    debug(dp);
    debug(b);

    int i=n+1;
    while (i != 0){
        if (b[i] == i-1){
            --i;
            continue;
        }
        if (h[i]){
            ans.emplace_back(b[i]+1, i-1);
            if (!(i-b[i]-1 == 1 && a[i-1] == 1)){
                ans.emplace_back(b[i]+1, i-1);
            }
            mkmex(b[i]+1, i-1);
            ans.emplace_back(b[i]+1, i-1);
        }
        i = b[i];
    }

    cout << dp[n+1] << ' ' << ans.size() << '\n'; 
    for (auto [l, r] : ans){
        cout << l << ' ' << r << '\n';
    }
}