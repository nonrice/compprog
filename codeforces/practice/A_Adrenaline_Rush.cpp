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

    int n; cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        --x;
        p[x] = i;
    }

    vector<int> a(n);
    vector<pair<int, int>> ans;
    set<pair<int, int>> vis;
    iota(a.begin(), a.end(), 0);
    for (int i=0; i<n; ++i){
        for (int j=0; j+1<n; ++j){
            if (p[a[j]] > p[a[j+1]]){
                ans.emplace_back(a[j+1]+1, a[j]+1);
                vis.emplace(a[j+1]+1, a[j]+1);
                swap(a[j], a[j+1]);
            } else {
                if (!vis.count(make_pair(a[j+1]+1, a[j]+1)) && !vis.count(make_pair(a[j]+1, a[j+1]+1))){
                    ans.emplace_back(a[j+1]+1, a[j]+1);
                    ans.emplace_back(a[j]+1, a[j+1]+1);
                    vis.emplace(a[j+1]+1, a[j]+1);
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans){
        cout << x << ' ' << y << '\n';
    }
}
