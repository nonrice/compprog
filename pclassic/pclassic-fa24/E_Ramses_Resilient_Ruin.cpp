#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
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

    map<int, int> br, bc;
    for (int d=n+m-2; d>=0; --d){
        stack<int> r;
        for (int a=0; a<=d; ++a){
            if (d-a<n && a<m){

                if (g[d-a][a] == 1){
                    r.push(a);
                }

                if (g[d-a][a] == 2){
                    if (bc.count(a) && (!r.empty() && bc[a] < d-r.top())){
                        --ans;
                    } else{
                        if (!r.empty()){
                            while (true){
                                if (r.empty() || !br.count(d-r.top()) || br[d-r.top()] > a){
                                    break;
                                }
                                if (br.count(d-r.top())){
                                    --ans;
                                }
                                r.pop();
                            }

                            if (!r.empty()){
                                int b = r.top(); r.pop();
                                if (!bc.count(a)){
                                    bc[a] = d-b;
                                } else {
                                    bc[a] = min(bc[a], d-b);
                                }
                                if (!br.count(d-b)){
                                    br[d-b] = a;
                                } else {
                                    br[d-b] = min(br[d-b], a);
                                }
                                ans -= 2;
                            } else {
                                if (bc.count(a)){
                                    ans -= 1;
                                } 
                            }
                        } else {
                            if (bc.count(a)){
                                ans -= 1;
                            }
                        }
                    }
                }
            }
        }

        //debug(d);
        //debug(bc);
        //debug(br);

        while (!r.empty()){
            if (br.count(d-r.top())){
                ans -= 1;
            }
            r.pop();
        }
        debug(ans);
    }

    cout << ans << '\n';
    debug(br);
    debug(bc);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    //int t; cin >> t;
    solve();

}