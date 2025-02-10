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
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
        --a[i];
    }

    vector<pair<int, int>> ans;
    vector<bool> vis(n);
    for (int i=0; i<n; ++i){
        vector<pair<int, int>> swp;
        if (!vis[i]){
            int p = i;
            while (a[p] != i){
                swp.emplace_back(p, a[p]);
                p = a[p];
                vis[p] = true;
            }
        }
        reverse(swp.begin(), swp.end());
        for (auto p : swp){
            ans.emplace_back(p);
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans){
        cout << "1 " << x+1 << ' ' << y+1 << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    solve();
}