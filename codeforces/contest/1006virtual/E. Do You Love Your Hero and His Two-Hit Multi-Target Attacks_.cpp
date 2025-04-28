#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int k; cin >> k;

    vector<pair<int, int>> ans;
    int c=0;
    int x=0, y=0;
    int l=0;
    while (c < k){
        if (c+l > k){
            l = 0;
            ++y;
        }
        ans.emplace_back(x, y);
        c += l;
        ++x;
        ++l;
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans){
        cout << x << ' ' << y << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
