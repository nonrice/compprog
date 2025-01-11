#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr pair<int, int> dv[] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

struct vert {
    int r, c, p, e, d;
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<string> g(n);

    int sr, sc, tr, tc;
    for (int i=0; i<n; ++i){
        cin >> g[i];
        for (int j=0; j<m; ++j){
            if (g[i][j] == 'S'){
                sr = i;
                sc = j;
            } else if (g[i][j] == 'T'){
                tr = i;
                tc = j;
            }
        }
    }

    queue<vert> q;
    q.push({ sr, sc, 0, 0, 0 });
    vector<vector<array<array<bool, 4>, 4>>> vis(n, vector<array<array<bool, 4>, 4>>(m));
    while (!q.empty()){
        auto [r, c, p, e, d] = q.front(); q.pop();
        if (r == tr && c == tc){
            cout << d << '\n';
            goto arrived;
        }

        for (int i=0; i<4; ++i){
            if (e != 3 || i != p){
                auto [dr, dc] = dv[i];
                if (g[r+dr][c+dc] != '#'){
                    int ep = (p==i) ? e+1 : 1;
                    if (!vis[r+dr][c+dc][i][ep]){
                        q.push({ r+dr, c+dc, i, (p==i) ? e+1 : 1, d+1 });
                        vis[r+dr][c+dc][i][ep] = true;
                    }
                }
            }
        }
    }
    
    cout << "-1\n";
    arrived:
}