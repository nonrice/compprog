#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int a, b; cin >> a >> b;
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    
    set<pair<int, int>> d({
        { a, b },
        { -a, b },
        { a, -b },
        { -a, -b },
        { b, a },
        { -b, a },
        { b, -a },
        { -b, -a }
    });

    set<pair<int, int>> p;
    for (auto [da, db] : d){
        p.emplace(x1+da, y1+db);
    }

    int ans = 0;
    for (auto [da, db] : d){
        if (p.count({ x2+da, y2+db })){
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
