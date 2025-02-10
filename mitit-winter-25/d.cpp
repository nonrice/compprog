#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<pair<vector<int>, int>> g;
    for (int i=0; i<n; ++i){
        g.push_back(make_pair(vector<int>(k), i));
    }
    for (int i=0; i<n; ++i){
        for (int j=0; j<k; ++j){
            cin >> g[i].first[j];
        }
    }

    sort(g.begin(), g.end(), [&](const auto& a, const auto& b){
        return a.first < b.first;
    });

    for (int i=1; i<n; ++i){
        for (int j=0; j<k; ++j){
            if (g[i].first[j] < g[i-1].first[j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i=0; i<n; ++i){
        cout << g[i].second+1 << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    solve();
}