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

    list<int> a(n);
    multiset<int> s;
    for (auto it = a.begin(); it != a.end(); ++it){
        cin >> *it;
        s.insert(*it);
    }

    vector<int> b;
    for (auto it = a.begin(); it != a.end();){
        s.erase(s.find(*it));
        debug(s);
        debug(a);
        if (!s.empty() && *s.begin() < *it){
            b.push_back(*it + 1);
            s.insert(*it + 1);
            it = a.erase(it);
        } else {
            ++it;
        }
    }

    sort(b.begin(), b.end());

    for (auto v : a){
        cout << v << ' ';
    }
    for (auto v : b){
        cout << v << ' ';
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