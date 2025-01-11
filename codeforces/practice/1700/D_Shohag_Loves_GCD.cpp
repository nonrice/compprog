#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int MXN = 100000;

vector<int> fs[MXN+1];

void solve(){
    int n, m; cin >> n >> m;
    vector<int> s(m);
    for (int i=0; i<m; ++i){
        cin >> s[i];
    }
    sort(s.rbegin(), s.rend());

    vector<int> ans(n+1);
    for (int i=1; i<=n; ++i){
        // debug(i, fs[i]);
        vector<bool> v(m);
        v[0] = true;
        int p = 0;
        for (int f : fs[i]){
            v[ans[f]] = true;
            while (v[p]){
                if (p == m-1){
                    goto fail;
                }
                ++p;
            }
        }
        ans[i] = p;
    }

    // debug(ans);
    for (int i=1; i<=n; ++i){
        cout << s[ans[i]] << ' ';
    }
    cout << '\n';
    return;

    fail:
    cout << "-1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (int f=2; f<=MXN; ++f){
        for (int x=f; x<=MXN; x+=f){
            fs[x].push_back(f);
        }
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}