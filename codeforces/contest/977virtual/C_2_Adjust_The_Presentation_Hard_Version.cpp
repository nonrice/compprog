#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct query {
    int s, t, i;
};

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<int> p(n+1), b(m);
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        p[x]= i;
    }
    for (int i=0; i<m; ++i){
        cin >> b[i];
        b[i] = p[b[i]];
    }

    vector<int> f(n);
    set<int> v(n);
    for (int i=0; )



}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}