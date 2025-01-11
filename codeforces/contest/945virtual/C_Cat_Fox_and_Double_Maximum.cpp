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
    vector<int> p(n);
    for (int i=0; i<n; ++i){
        cin >> p[i];
    }

    vector<int> c(n);
    int e = -1;
    for (int i=0; i<n; ++i){
        c[i] = n+1 - p[i];
        if (c[i] == n){
            e = i;
        }
    }
    vector<pair<int, int>> s;
    for (int i = 2 - (e%2==0); i<n-1; i+=2){
        s.emplace_back(c[i], i);
    }
    s.emplace_back(n, e);
    sort(s.begin(), s.end());

    for (int i=1; i<s.size(); ++i){
        swap(c[s[i-1].second], c[s[i].second]);
    }

    for (int i=0; i<n; ++i){
        cout << c[i] << ' ';
    }
    cout << '\n';

    vector<int> g(n);
    for (int i=0; i<n; ++i){
        g[i] = c[i] + p[i];
    }
    debug(g);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}