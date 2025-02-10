#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;

    array<string, 2> g;
    cin >> g[0] >> g[1];

    map<pair<int, int>, int> q1({ { { 0, 0 }, 1 }}), q2;
    stringstream ans;
    ans << g[0][0];
    for (int i=0; i<n; ++i){
        bool z = false;
        for (auto [p, v] : q1){
            auto [r, c] = p;
            if (r == 0){
                q2[{ r+1, c }] += v;
                z |= (g[r+1][c] == '0');
            }
            if (c+1 < n){
                q2[{ r, c+1 }] += v;
                z |= (g[r][c+1] == '0');
            }
        }
        
        if (z){
            ans << '0';
        } else {
            ans << '1';
        }

        for (auto it=q2.begin(); it!=q2.end();){
            auto [r, c] = it->first;
            if (z && g[r][c]=='1'){
                it = q2.erase(it);
            } else {
                ++it;
            }
        }

        swap(q1, q2);
        q2.clear(); 
    }

    int ans_f = 0;
    for (auto [p, v] : q1){
        ans_f += v;
    }

    cout << ans.str() << '\n' << ans_f << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}