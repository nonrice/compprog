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
    set<int> s;
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        s.insert(x);
    }

    int p = 0;
    vector<int> d;
    for (auto x : s){
        d.push_back(x-p);
        p = x;
    }

    int l = 0;
    for (int i=0; i<d.size(); ++i){
        if (d[i] == 1){
            ++l;
        } else {
            break;
        }
    }

    debug(d);

    if (l == d.size()){
        if (l%2 == 1){
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        return;
    }

    if (l%2 == 0){
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}