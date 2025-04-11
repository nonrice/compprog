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
    string s; cin >> s;

    if (count(s.begin(), s.end(), 'E') % 2){
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    int e=2, o=1;
    bool p = true;
    for (int i=0; i<n; ++i){
        if (s[i] == 'E'){
            if (p){
                cout << o << ' ' << o+2 << '\n';
                o += 4;
            } else {
                cout << e << ' ' << e+2 << '\n';
                e += 4;
            }
            p ^= true;
        } else {
            cout << o << ' ' << e << '\n';
            o += 2;
            e += 2;
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
