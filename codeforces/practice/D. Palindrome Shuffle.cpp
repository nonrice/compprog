#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    string s; cin >> s;
    const int n = s.size();
    
    map<char, int> f;
    int l = -1;
    int r = -1;
    for (int i=0; i<n; ++i){
        if (s[i] != s[n-i-1]){
            ++f[s[i]];
            r = i;
            if (l == -1){
                l = i;
            }
        }
    }

    if (l == -1){
        cout << "0\n";
        return;
    }
    
    for (auto& [x, y] : f){
        f[x] /= 2;
    }
    map<char, int> g(f);
    debug(g);
    int ans = -1;
    for (int i=l; i<n; ++i){
        if (s[i] != s[n-i-1]){
            if (f.count(s[i])){
                --f[s[i]];
                if (f[s[i]] == 0){
                    f.erase(s[i]);
                }
            }
            debug(s[i], f);
            if (f.size() == 0){
                ans = i-l+1;
                break;
            }
        }
    }
    for (int i=r; i>=0; --i){
        if (s[i] != s[n-i-1]){
            if (g.count(s[i])){
                --g[s[i]];
                if (g[s[i]] == 0){
                    g.erase(s[i]);
                }
            }
            if (g.size() == 0){
                ans = min(ans, r-i+1);
                break;
            }
        }
    }

    assert(ans != -1);

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
