#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int x, n, m; cin >> x >> n >> m;
    if (n > 32){
        cout << "0 0\n";
        return;
    }
    m = min(m, 32);
    
    int a1=x, a2=x;
    for (int i=0; i<n; ++i){
        a1>>=1;
    }
    for (int i=0; i<m; ++i){
        a1 = (a1+1)/2;
    }
    for (int i=0; i<m; ++i){
        a2 = (a2+1)/2;
    }
    for (int i=0; i<n; ++i){
        a2>>=1;
    }

    cout << a2 << ' ' << a1 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
