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

    bool m = false;
    bool r = false;
    bool b = true;
    for (int i=0; i<n; ++i){
        if (s[i] == 'M'){
            if (r || !b){
                goto bad;
            }
            m = true;
            b = false;
        } else if (s[i] == 'I'){
            if (!m || r){
                goto bad;
            }
            r = true;
            b = true;
        } else if (s[i] == 'T'){
            if (!m || !r){
                goto bad;
            }
            r = false;
            b = true;
        } else {
            goto bad;
        }
    }   

    if (r || b==false){
        goto bad;
    }

    cout << "YES\n";
    return;

    bad:
    cout << "NO\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}