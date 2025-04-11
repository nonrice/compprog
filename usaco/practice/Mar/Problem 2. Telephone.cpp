#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct vert {
    int i;
    int s;
    bool r;
    int d;
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<int> b(n);
    for (int i=0; i<n; ++i){
        cin >> b[i];
        --b[i];
    }
    debug(b);
    vector<string> s(k);
    for (int i=0; i<k; ++i){
        cin >> s[i];
    }
    
    queue<vert> q({ { 0, b[0], true, 0 } });
    vector<vector<array<bool, 2>>> vis(k, vector<array<bool, 2>>(n));
    vis[b[0]][0][true] = true;
    while (!q.empty()){
        auto u = q.front(); q.pop();
        debug(u.i, u.s, u.r, u.d);
        if (u.i == n-1 && s[u.s][b[u.i]]=='1'){
            cout << u.d << '\n';
            return 0;
        }
                
        if (u.r){
            vert r({ u.i+1, u.s, u.r, u.d+1 });
            if (u.i+1<n && !vis[u.s][u.i+1][u.r]){
                vis[u.s][u.i+1][u.r] = true;
                q.push(r);
            }
        } else {
            vert l({ u.i-1, u.s, u.r, u.d+1 });
            if (u.i-1>=0 && !vis[u.s][u.i-1][u.r]){
                vis[u.s][u.i-1][u.r] = true;
                q.push(l);
            }
        }

        vert cr({ u.i+1, b[u.i], true, u.d+1 }), cl({ u.i-1, b[u.i], false, u.d+1 });
        if (u.i+1<n && s[u.s][b[u.i]]=='1' && !vis[b[u.i]][u.i+1][true]){
            vis[b[u.i]][u.i+1][true] = true;
            q.push(cr);
        }
        if (u.i-1>=0 && s[u.s][b[u.i]]=='1' && !vis[b[u.i]][u.i-1][false]){
            vis[b[u.i]][u.i-1][false] = true;
            q.push(cl);
        }
    }

    cout << "-1\n";
}
