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
    
    int s1=0, s2=0;
    for (int i=0; i<n; ++i){
        int s = false;
        for (int j=0; j<m; ++j){
            s = (s + (a[i][j]=='1')) % 2;
        }
        s1 += s;
    }
    for (int j=0; j<m; ++j){
        int s = false;
        for (int i=0; i<n; ++i){
            s = (s + (a[i][j]=='1')) % 2;
        }
        s2 += s;
    }

    cout << (s1+s2)/2 + max(s1,s2)-(s1+s2)/2 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
