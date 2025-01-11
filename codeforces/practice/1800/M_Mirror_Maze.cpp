#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int ts[] = { 1, 0, 3, 2 };
int tb[] = { 3, 2, 1, 0 };

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<string> g(n);
    int cnt = 0;
    for (int r=0; r<n; ++r){
        cin >> g[r];
        cnt += m;
        for (int c=0; c<m; ++c){
            cnt -= g[r][c] == '.';
        }
    }
    debug(cnt);

    vector<vector<int>> jn(n, vector<int>(m, -1));
    for (int r=1; r<n; ++r){
        for (int c=0; c<m; ++c){
            jn[r][c] = jn[r-1][c];
            if (g[r-1][c] != '.'){
                jn[r][c] = r-1;
            }
        }
    }
    vector<vector<int>> jw(n, vector<int>(m, -1));
    for (int c=1; c<m; ++c){
        for (int r=0; r<n; ++r){
            jw[r][c] = jw[r][c-1];
            if (g[r][c-1] != '.'){
                jw[r][c] = c-1;
            }
        }
    }
    vector<vector<int>> js(n, vector<int>(m, -1));
    for (int r=n-2; r>=0; --r){
        for (int c=0; c<m; ++c){
            js[r][c] = js[r+1][c];
            if (g[r+1][c] != '.'){
                js[r][c] = r+1;
            }
        }
    }
    vector<vector<int>> je(n, vector<int>(m, -1));
    for (int c=m-2; c>=0; --c){
        for (int r=0; r<n; ++r){
            je[r][c] = je[r][c+1];
            if (g[r][c+1] != '.'){
                je[r][c] = c+1;
            }
        }
    }
    array<vector<vector<int>>*, 4> jt({ &jn, &je, &js, &jw });

    auto check = [&](int d, int r, int c)->bool{
        int rem = cnt;
        vector<vector<bool>> vis(n, vector<bool>(m));
        if (g[r][c] != '.'){
            --rem;
            vis[r][c] = true;
            if (g[r][c] == '/'){
                d = ts[d];
            } else {
                d = tb[d];
            }
        }


        while ((*jt[d])[r][c] != -1){
            if (d == 0 || d == 2){
                r = (*jt[d])[r][c];
            } else {
                c = (*jt[d])[r][c];
            }
            if (g[r][c] == '/'){
                d = ts[d];
            } else {
                d = tb[d];
            }
            if (!vis[r][c]){
                --rem;
                vis[r][c] = true;
            }
            debug(r, c, d, rem);
        }
        return rem == 0;
    };

    vector<pair<char, int>> ans;
    for (int c=0; c<m; ++c){
        if (check(0, n-1, c)){
            ans.emplace_back('S', c+1);
        }
    }
    for (int r=0; r<n; ++r){
        if (check(1, r, 0)){
            ans.emplace_back('W', r+1);
        }
    }
    for (int c=0; c<m; ++c){
        if (check(2, 0, c)){
            ans.emplace_back('N', c+1);
        }
    }
    for (int r=0; r<n; ++r){
        if (check(3, r, m-1)){
            ans.emplace_back('E', r+1);
        }
    }

    cout << ans.size() << '\n';
    for (auto [d, i] : ans){
        cout << d << i << ' ';
    }
    cout << '\n';
}