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

pair<int, int> dd[90];

char ds[] = "URDL";
char dso[] = "DLUR";

void solve(){
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i=0; i<n; ++i){
        cin >> g[i];
    }

    for (int r=0; r<n; ++r){
        for (int c=0; c<m; ++c){
            if (g[r][c] == '?'){
                for (int d=0; d<4; ++d){
                    auto [dr, dc] = dd[ds[d]];
                    if (r+dr>=0 && r+dr<=n-1 && c+dc>=0 && c+dc<=m-1 && g[r+dr][c+dc] == dso[d]){
                        g[r][c] = ds[d];
                        break;
                    }
                }
            }
        }
    }

    vector<vector<int>> s(n, vector<int>(m));
    // 0 unvisited
    // 1 visited-undetermined
    // 2 visited-current
    // 3 visited-good
    // 4 visited-bad
    auto dfs1 = [&](int r, int c)->void{
        stack<pair<int, int>> dfs;
        dfs.emplace(r, c);

        while (true){
            auto [ur, uc] = dfs.top();

            s[ur][uc] = 2;
            auto [dr, dc] = dd[g[ur][uc]];
            int vr = ur+dr;
            int vc = uc+dc;

            if (vr < 0 || vr >= n || vc < 0 || vc >= m || s[vr][vc] == 3){
                s[ur][uc] = 3;
                break;
            } else if (s[vr][vc] == 2 || s[vr][vc] == 4){
                s[ur][uc] = 4;
                break;
            } else if (s[vr][vc] == 1 || g[vr][vc] == '?'){
                s[ur][uc] = 1;
                break;
            } else {
                dfs.emplace(vr, vc);
                //s[ur][uc] = s[vr][vc];
            }
        }

        while (dfs.size() > 1){
            int c = s[dfs.top().first][dfs.top().second];
            dfs.pop();
            auto [ur, uc] = dfs.top();
            s[ur][uc] = c;
        }
    };
    for (int r=0; r<n; ++r){
        for (int c=0; c<m; ++c){
            if (g[r][c] == '?'){
                s[r][c] = 1;
                continue;
            }
            dfs1(r, c);
        }
    }
    // debug(s);
    // debug(g);
    int ans = 0;
    for (int r=0; r<n; ++r){
        for (int c=0; c<m; ++c){
            if (s[r][c] == 4){
                ++ans;
                continue;
            }
            if (g[r][c] == '?'){
                for (int d=0; d<4; ++d){
                    auto [dr, dc] = dd[ds[d]];
                    if (r+dr>=0 && r+dr<=n-1 && c+dc>=0 && c+dc<=m-1){
                        if (g[r+dr][c+dc] == '?' || s[r+dr][c+dc] == 4){
                            s[r][c] = 4;
                            // debug(r, c);
                            ++ans;
                            break;
                        } 
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    dd['U'] = { -1, 0 };
    dd['D'] = { 1, 0 };
    dd['R'] = { 0, 1 };
    dd['L'] = { 0, -1 };

    int t; cin >> t;
    while (t--){
        solve();
    }
}