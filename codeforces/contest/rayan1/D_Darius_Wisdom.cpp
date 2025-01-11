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
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<pair<int, int>> ans;

    set<int> p[3];
    for (int i=0; i<n; ++i){
        p[a[i]].insert(i);
    }
    for (int i=0; i<n; ++i){
        if (a[i] == 0 && b[i] == 1){
            int j = *p[1].begin();
            p[1].erase(j);
            p[0].erase(i);
            p[0].insert(j);
            ans.emplace_back(i, j);
        } else if (a[i] == 1 && b[i] == 2){
            int j = *p[2].begin();
            p[2].erase(j);
            p[1].erase(i);
            p[1].insert(j);
            ans.emplace_back(i, j);
        } else if (a[i] == 0 && b[i] == 2){
            int k = *p[1].begin();
            int j = *p[2].begin();
            p[0].erase(i);
            p[0].insert(j);
            p[2].erase(j);
            ans.emplace_back(i, k);
            ans.emplace_back(i, j);
            ans.emplace_back(j, k);
        } else if (b[i] == 0 && a[i] == 1){
            int j = *p[0].begin();
            p[0].erase(j);
            p[1].erase(i);
            p[1].insert(j);
            ans.emplace_back(i, j);
        } else if (b[i] == 1 && a[i] == 2){
            int j = *p[1].begin();
            p[2].erase(j);
            p[2].insert(i);
            p[1].erase(i);
            ans.emplace_back(i, j);
        } else if (b[i] == 0 && a[i] == 2){
            int k = *p[1].begin();
            int j = *p[0].begin();
            p[0].erase(i);
            p[2].erase(i);
            p[2].insert(i);
            ans.emplace_back(i, k);
            ans.emplace_back(i, j);
            ans.emplace_back(j, k);
        } 
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans){
        cout << a+1 << ' ' << b+1 << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}