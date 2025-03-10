#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    vector<string> b(n);
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }

    for (int i=0; i<n; ++i){
        int r1=0, r2=0;
        for (int j=0; j<m; ++j){
            r1 = (r1 + (a[i][j]-'0')) % 3;
            r2 = (r2 + (b[i][j]-'0')) % 3;
        }
        if (r1 != r2){
            cout << "NO\n";
            return;
        }
    }
    for (int j=0; j<m; ++j){
        int r1=0, r2=0;
        for (int i=0; i<n; ++i){
            r1 = (r1 + (a[i][j]-'0')) % 3;
            r2 = (r2 + (b[i][j]-'0')) % 3;
        }
        if (r1 != r2){
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