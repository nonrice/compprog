#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct cart {
    int d, r, c;
    bool s;
};

void print(cart c)
{
    cerr << "(" << c.d << ' ' << c.r << ' ' << c.c << ' ' << c.s << ")";
}

void solve(){
    int n, m; cin >> n >> m;

    vector<cart> a;
    vector<vector<int>> g (n, vector<int>(m));
    int rem = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            int x; cin >> x;
            if (x != 0){
                g[i][j] = 1;
                ++rem;
                a.push_back({ x, i, j, false });
            }
        }
    }


    int ans = 0;
    while (rem > 0){
        for (auto& [d, r, c, s] : a){
            if (s){
                continue;
            }
            if (d==1){
                --g[r][c];
                if (c == m-1){
                    ++ans;
                    --rem;
                    s = true;
                } else {
                    ++c;
                    ++g[r][c];
                }
            } else if (d==2){
                --g[r][c];
                if (r == n-1){
                    ++ans;
                    --rem;
                    s = true;
                } else {
                    ++r;
                    ++g[r][c];
                }
            }
        }
        for (auto& [d, r, c, s] : a){
            if (!s && g[r][c] > 1){
                --rem;
                s = true;
                continue;
            }
        }
    }

    cout<<ans << '\n';
    debug(g);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

  
    solve();
}