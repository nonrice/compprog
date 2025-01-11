#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    int ans = n*m;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> g[i][j];
            if (g[i][j] == 0){
                --ans;
            }
        }
    }

    for (int d=0; d<n+m; ++d){
        int r = 0;
        for (int a=0; a<=d; ++a){
            if (d-a<n && a<m){
                if (g[d-a][a] == 1){
                    ++r;
                }
                if (g[d-a][a] == 2 && r>0){
                    --r;
                    --ans;
                }
            }
        }

        int w = 0;
        for (int a=0; a<=d; ++a){
            if (a<n && d-a<m){
                if (g[a][d-a] == 2){
                    ++w;
                }
                if (g[a][d-a] == 1 && w>0){
                    --ans;
                    --w;
                }
            }
        }
    }

    cout << ans << '\n';
}