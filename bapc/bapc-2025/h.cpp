#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

inline int pref(uint32_t x, int p){
    return (x<<(32-p))>>(32-p);
}

void solve(){
    int n;
    int x;
    string s;
    cin >> n >> x >> s;

    for (int i=0; i<s.size(); ++i){
        int p = 31-__builtin_clz(x);

        if (s[i] == 'U'){
            if (x == 1){
                cout << "-1\n";
                return;
            }
            x -= 1<<p;
            x |= 1<<(p-1);
            continue;
        }

        bool v = ((n >> (p+1)) + ((n >> (p+1))) - (pref(n, p+1) < x) - (pref(n, p+1) < (x-(1<<p)))) % 2;
        if ((s[i] == 'L') != v){
            x |= 1<<(p+1);
        } else {
            x -= 1<<p;
            x |= 1<<(p+1);
        }

        if (x > n){
            cout << "-1\n";
            return;
        }
    }

    cout << x << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);


    debug(pref(15, 3));

    int t; cin >> t;
    while (t--){
        solve();
    }
}