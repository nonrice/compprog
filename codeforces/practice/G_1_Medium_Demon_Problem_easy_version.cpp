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
    vector<int> p(n);
    for (int i=0; i<n; ++i){
        cin >> p[i];
        --p[i];
    }

    vector<int> vis(n);
    vector<int> d(n);
    for (int i=0; i<n; ++i){
        stack<int> dfs;
        if (vis[i]){
            continue;
        }

        dfs.push(i);
        while (!vis[dfs.top()]){
            vis[dfs.top()] = 1;
            dfs.push(p[dfs.top()]);
        }

        if (vis[dfs.top()] == 1){
            int e = dfs.top(); dfs.pop();
            while (dfs.top() != e){
                vis[dfs.top()] = 2;
                dfs.pop();
            }
            vis[dfs.top()] = 2;
        }

        int v = dfs.top();
        dfs.pop();
        while (!dfs.empty()){
            vis[dfs.top()] = 2;
            d[dfs.top()] = d[v] + 1;
            v = dfs.top();
            dfs.pop();
        }
    }

    debug(d);
    cout << *max_element(d.begin(), d.end())+2 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
