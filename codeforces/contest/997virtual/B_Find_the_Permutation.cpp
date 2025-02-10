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

    int h = 0;
    vector<int> p(n);
    vector<pair<int, int>> t(n);
    for (int i=0; i<n; ++i){
        string s; cin >> s;
        bool r = false, l = false;
        for (int j=0; j<n; ++j){
            if (p[j] == p[i] && j != i){
                if ((s[j] == '0')){
                    if (!l){
                        l = true;
                        t[p[i]].first = ++h;
                    }
                    p[j] = t[p[i]].first;
                } else {
                    if (!r){
                        r = true;
                        t[p[i]].second = ++h;
                    }
                    p[j] = t[p[i]].second;
                }
            }
        }
        debug(p);
    }


    vector<int> f(3*n);
    for (int i=0; i<n; ++i){
        f[p[i]] = i+1;
    }
    debug(t);


    auto dfs = ycomb([&](const auto& self, int u)->void{
        if (t[u].first != 0){
            self(t[u].first);
        }
        cout << f[u] << ' ';
        if (t[u].second != 0){
            self(t[u].second);
        }
    });

    dfs(0);
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}