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
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }
    
    int ma = 0, mb = 0;
    for (int i=0; i<n; ++i){
        ma = max(a[i], ma);
        mb = max(b[i], mb);
        if (a[i] > b[i]){
            cout << "NO\n";
            return;
        }
    }
    if (ma != mb){
        cout << "NO\n";
        return;
    }

    for (int h=1; h<=ma; ++h){
        bool o = false;
        for (int i=0; i<n; ++i){
            if (a[i] == h){
                o = true;
            }
            if (b[i] < h || a[i] > h){
                o = false;
            }
            if (o){
                a[i] = h;
            }
        }
        for (int i=n-1; i>=0; --i){
            if (a[i] == h){
                o = true;
            }
            if (b[i] < h || a[i] > h){
                o = false;
            }
            if (o){
                a[i] = h;
            }
        }
    }
    
    debug(a);
    for (int i=0; i<n; ++i){
        if (a[i] != b[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
