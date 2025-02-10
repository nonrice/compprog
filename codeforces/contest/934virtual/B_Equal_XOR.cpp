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
    vector<int> a(2*n);
    for (int i=0; i<2*n; ++i){
        cin >> a[i];
    }

    map<int, vector<int>> ps;
    for (int i=0; i<2*n; ++i){
        ps[a[i]].push_back(i);
    }

    for (auto& [x, p] : ps){
        if (p[0] > p[1]){
            swap(p[0], p[1]);
        }
    }

    deque<int> l, r;
    for (auto& [x, p] : ps){
        if (l.size() == 2*k && r.size() == 2*k){
            break;
        }
        if (p[0] < n && p[1] >= n){
            l.push_back(p[0]);
            r.push_back(p[1]);
        }
    }

    for (auto& [x, p] : ps){
        if (l.size() >= 2*k && r.size() >= 2*k){
            break;
        }
        if (p[0] < n && p[1] < n && l.size() < 2*k){
            l.push_back(p[0]);
            l.push_back(p[1]);
        }
        if (p[0] >= n && p[1] >= n && r.size() < 2*k){
            r.push_back(p[0]);
            r.push_back(p[1]);
        }
    }

    if (l.size() > 2*k){
        l.pop_front();
        r.pop_front();
    }

    for (auto x : l){
        cout << a[x] << ' ';
    }
    cout << '\n';
    for (auto x : r){
        cout << a[x] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}