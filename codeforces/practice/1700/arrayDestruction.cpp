#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool test(multiset<int> a, int i, vector<pair<int, int>>& ops){
    int prev = *--a.end();
    multiset<int>::iterator bgn = a.begin();
    advance(bgn, i);
    a.erase(bgn);
    a.erase(--a.end());
    ops.clear();
    while (a.size() > 1){
        int mx2 = *--a.end(); a.erase(--a.end());
        multiset<int>::iterator it = a.find(prev-mx2);
        if (it == a.end()){
            return false;
        } else {
            ops.emplace_back(*it, mx2);
            a.erase(it);
            prev = mx2;
        }
    }

    return true;
}

void solve(){
    int n; cin >> n;
    multiset<int> a;
    for (int i=0; i<2*n; ++i){
        int v; cin >> v;
        a.insert(v);
    }

    vector<pair<int, int>> ops;
    for (int i=0; i<2*n - 1; ++i){
        if (test(a, i, ops)){
            multiset<int>::iterator bgn = a.begin();
            advance(bgn, i);
            cout << "YES\n";
            cout << *--a.end() + *bgn << '\n';
            cout << *--a.end() << ' ' << *bgn << '\n';
            for (auto [x, y] : ops) cout << x << ' ' << y << '\n';
            return;
        }
    }
    
    cout << "NO\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

